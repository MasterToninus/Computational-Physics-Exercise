/*//---------------------------------------------------------------------------------------------------------
| faccio eseguire il calcolo del prodotto tra matrici
| 
*///---------------------------------------------------------------------------------------------------------

#define Tile_size=32


//kernel che intende che io ho allocato su gpu le 2 matrci A, B da produrre e la matrice C in cui mettere il risultato
// quindi si attende che numAColumns = numBRows; numCRows = numARows ; numCColumns = numAColumns
__global__ void matrixMultiplyShared(float * A, float * B, float * C,
                                    int numARows, int numAColumns,
                                    int numBRows, int numBColumns,
                                    int numCRows, int numCColumns) 
{
    __shared__ float A_shared[Tile_size][Tile_size];   // Tile size of 32x32 
    __shared__ float B_shared[Tile_size][Tile_size];

    unsigned int Thread_i = threadIdx.y;
    unsigned int Thread_j = threadIdx.x;	

    unsigned int Tile_i = blockIdx.y*Tile_size;	     //indici del primo elemento della tile (
    unsigned int Tile_j = blockIdx.x*Tile_size;  	


    while(Tile_j<numCColumns)
    {
	    while(Tile_i<numCRows){
		//... conto del tile	//ogni thread calcola 1 o piu' elementi della matrice c
		    float Cvalue = 0.0; 		
		    A_shared[Thread_i][Thread_j] = 0.0;
		    B_shared[Thread_i][Thread_j] = 0.0;



		
		// riempio la memoria shared necessaria per il calcolo del tile
	//ricordare, per ogni tile della matrice C servono due liste di tile: una orizzontale nella matrice A e una verticale nella matrice B
		    for (int k = 0; k < (((numAColumns - 1)/ Tile_size) + 1); k++)
    		    {	
			//indice dell elemento di matrice C corrispondente al dato thread
			unsigned int Mat_i = Tile_i + Thread_i , Mat_j = Tile_j + Thread_j ;	
			
		        if ( (Mat_i < numARows) && (Thread_j + (k*32)) < numAColumns)
		        {
		            A_shared[Thread_i][Thread_j] = A[(Mat_i*numAColumns) + threadIdx.x + (k*32)];
		        }
		        else
		        {
		            A_shared[Thread_i][Thread_j] = 0.0;
		        }            
		        if ( (Mat_j < numBColumns) && (Thread_i + k*32) < numBRows)
		        {
		            B_shared[Thread_i][Thread_j] = B[(threadIdx.y + k*32)*numBColumns + Mat_j];
		        }
		        else
		        {
		            B_shared[Thread_i][Thread_j]= 0.0;
		        }            
		        __syncthreads();

		        for (int j = 0; j < Tile_size; ++j)
		        {
		            Cvalue += A_shared[Thread_i][j] * B_shared[j][Thread_j];
		        }
 
			if (Mat_i < numCRows && Mat_j < numCColumns)
    			{	
		            C[Mat_i*numCColumns + Mat_j] = Cvalue;
    			}


   		  }
		Tile_i+=Tile_size*gridDim.y;
	    }	
	Tile_j+=Tile_size*gridDim.x;
    }	


}



/*
// SCOPIAZZATO
*/



#include <stdio.h>
#include <cuda.h>
#include <stdlib.h>

// This code assumes that your device support block size of 1024
#define MAX_RANGE 9999

#define funcCheck(stmt) do {                                                    \
        cudaError_t err = stmt;                                               \
        if (err != cudaSuccess) {                                             \
            printf( "Failed to run stmt %d ", __LINE__);                       \
            printf( "Got CUDA error ...  %s ", cudaGetErrorString(err));    \
            return -1;                                                        \
        }                                                                     \
    } while(0)




void matMultiplyOnHost(float * A, float * B, float * C, int numARows,
                        int numAColumns, int numBRows, int numBColumns,
                        int numCRows, int numCColumns)
{
    for (int i=0; i < numARows; i ++)
    {
        for (int j = 0; j < numAColumns; j++)
        {
            C[i*numCColumns + j ] = 0.0;
            for (int k = 0; k < numCColumns; k++)
            {
                C[i*numCColumns + j ] += A[i*numAColumns + k] * B [k*numBColumns + j];
            }
        }
    }
    return;
}







int main() {
    float * hostA; // The A matrix
    float * hostB; // The B matrix
    float * hostC; // The output C matrix
    float * hostComputedC;
    float * deviceA;
    float * deviceB;
    float * deviceC;

    // Please adjust rows and columns according to you need.
    int numARows = 12; // number of rows in the matrix A
    int numAColumns = 15; // number of columns in the matrix A
    int numBRows = 15; // number of rows in the matrix B
    int numBColumns = 3; // number of columns in the matrix B

    int numCRows; // number of rows in the matrix C (you have to set this)
    int numCColumns; // number of columns in the matrix C (you have to set this)

    hostA = (float *) malloc(sizeof(float)*numARows*numAColumns);
    hostB = (float *) malloc(sizeof(float)*numBRows*numBColumns);

    for (int i = 0; i < numARows*numAColumns; i++)
    {
        hostA[i] = (rand() % MAX_RANGE) / 2.0;
    }
    for (int i = 0; i < numBRows*numBColumns; i++)
    {
        hostB[i] = (rand() % MAX_RANGE) / 2.0;
    }

    // Setting numCRows and numCColumns
    numCRows = numARows;
    numCColumns = numBColumns;

    hostC = (float *) malloc(sizeof(float)*numCRows*numCColumns);    
    hostComputedC = (float *) malloc(sizeof(float)*numCRows*numCColumns);    

    // Allocating GPU memory
    funcCheck(cudaMalloc((void **)&deviceA, sizeof(float)*numARows*numAColumns));
    funcCheck(cudaMalloc((void **)&deviceB, sizeof(float)*numBRows*numBColumns));
    funcCheck(cudaMalloc((void **)&deviceC, sizeof(float)*numCRows*numCColumns));

    // Copy memory to the GPU 
    funcCheck(cudaMemcpy(deviceA, hostA, sizeof(float)*numARows*numAColumns, cudaMemcpyHostToDevice));
    funcCheck(cudaMemcpy(deviceB, hostB, sizeof(float)*numBRows*numBColumns, cudaMemcpyHostToDevice));

    // Initialize the grid and block dimensions 
    dim3 dimBlock(32, 32, 1);    
    dim3 dimGrid((numCColumns/32) + 1, (numCRows/32) + 1, 1);

    //@@ Launch the GPU Kernel here
    matrixMultiplyShared<<<dimGrid, dimBlock>>>(deviceA, deviceB, deviceC, numARows, numAColumns, numBRows, numBColumns, numCRows, numCColumns);    

    cudaError_t err1 = cudaPeekAtLastError();
    cudaDeviceSynchronize();
    printf( "Got CUDA error ... %s \n", cudaGetErrorString(err1));

    // Copy the results in GPU memory back to the CPU    
    funcCheck(cudaMemcpy(hostC, deviceC, sizeof(float)*numCRows*numCColumns, cudaMemcpyDeviceToHost));

    matMultiplyOnHost(hostA, hostB, hostComputedC, numARows, numAColumns, numBRows, numBColumns, numCRows, numCColumns);

    for (int i=0; i < numCColumns*numCRows; i++)
    {
        if (hostComputedC[i]  != hostC[i] )
        {
            printf("Mismatch at Row = %d Col = %d hostComputed[] = %f --device[] %f\n", i / numCColumns, i % numCColumns, hostComputedC[i], hostC[i]);
            break;
        }
    }
    // Free the GPU memory
    funcCheck(cudaFree(deviceA));
    funcCheck(cudaFree(deviceB));        
    funcCheck(cudaFree(deviceC));    

    free(hostA);
    free(hostB);
    free(hostC);
    free(hostComputedC);

    return 0;
}

