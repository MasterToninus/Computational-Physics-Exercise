/*//---------------------------------------------------------------------------------------------------------
|
|  Test del miglior Kernel che non utilizza la memoria texture di tutta la matrice ( mostrare l'aumento delle prestazioni con una corretta dimensionalizzazione dei thread)
|
*///---------------------------------------------------------------------------------------------------------
//OGNI thread alloca 5 unsigned int e 2 float ---> 7*4= 28 byte



#include <iostream>
#include <stdio.h>
using namespace std;
#include <cstdlib>
#include <stdlib.h>     /* srand, rand */ //http://www.cplusplus.com/reference/cstdlib/rand/
#include <fstream>	//http://www.cplusplus.com/doc/tutorial/files/


// Numero di thread prudente
#define DIM_GRID 128
#define DIM_BLOCK 128
#define THREAD_PER_BLOCK 128
#include "condensation_tentative.cuh"


/*     DIMENSIONALIZZAZIONE DEI THREAD    */
// Numero di thread "Limite"
#define imin(a,b) (a<b?a:b)

//trucco per ottimizzare il numero di blocchi
//const int blocksPerGrid = imin(32,(N+threadsPerBlock-1)/threadsPerBlock);

#define MAX_DIM_BLOCK 512
#define MAX_DIM_GRID 524288 //in realtà il max numero di thrad è un po' di piu', questa è la potenza di 2 più vicina
#define DIM_WARP 32






//kernel che copia una colonna della matrice in un segmento lineare di memoria
/*
input: 
	puntatore destinatatio
	puntatore matricepartenza
	indice della colonna da copiare
	numero di elementi
*/

__global__ void copy_Col( float *a, float *A,int j1, int numAColumns, int numARow){

  int tid = blockIdx.x*blockDim.x + threadIdx.x; //identità del thread (al solito metto in fila ogni thread a partire dal primo blocco)
  int Nthreads = blockDim.x * gridDim.x;	 //Numero totale di threads istanziati dalla chiamata del kernel

  while(tid<numARow){
	a[tid]=A[tid*numAColumns + j1]; //qui copia
	tid+= Nthreads;	      // se il vettore ha più elementi del numero di thread chiamati faccio si che ogni thread sommi più di un elemento
	}
  
}

void print(float *A, int ROW, int COL){
		for(int i=0 ; i<ROW ; i++){
			for(int j=0 ; j<COL ; j++){
				//printf(" %.1f ",A[i*COL+j]);
				cout<< A[i*COL+j] << " ";
			}
			cout<<endl;
		}
		cout<<endl;  
}







int main(void){

	int ROW=10000;
	int COL=ROW;
	int N = COL*ROW;
	int Nb= (ROW-1)*(COL-1);
	srand (time(NULL));  

   //Punto La memoria
	float * A_host; float *B_host;
	float * A_dev; float *B_dev;

   //Alloco la matrice
	A_host = new float[N] ();
	B_host = new float[Nb] ();


   //Alloco le matrice device (riservo la memoria richiesta)
	unsigned int ByteSize = N*sizeof(float);
	cudaMalloc( (void **)&A_dev, ByteSize  );
	ByteSize = Nb*sizeof(float);
	cudaMalloc( (void **)&B_dev, ByteSize  );


   //Riempio la Matrice Host
	//float min = -10, max = 10 , delta = max-min; 
	for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++)A_host[i*COL+j] =  (rand() % 10 );
        A_host[N-1]=1;

   //Riempio La Matrice Device
	cudaMemcpy( A_dev, A_host, N*sizeof(float), cudaMemcpyHostToDevice);

   //Check Matrice Creata
	//	print(A_host,ROW,COL);



	//Creo degli eventi per la statistica
	cudaEvent_t T1,T2;
	cudaEventCreate(&T1);
	cudaEventCreate(&T2);
	float diff_time;



/*
cout<<"CONDENSAZIONE VERSIONE 1"<<endl; 
	//registro il primo tempo
	cudaEventRecord(T1, 0);

   //Kernel
	stepCondensationSimple_v1<<<DIM_GRID,DIM_BLOCK>>>(B_dev,A_dev, COL-1,ROW-1);		
   //PullBack del risultato
	cudaMemcpy( B_host, B_dev, Nb*sizeof(float), cudaMemcpyDeviceToHost);

	//registro il secondo evento alla fine del kernel
	cudaEventRecord(T2, 0);
	cudaEventSynchronize(T2);

   //check
	//	print(B_host,ROW-1,COL-1);
	cudaEventElapsedTime(&diff_time, T1, T2);
	cout<<"Tempo esecuzione = "<<diff_time<<" ms"<<endl;

cout<<"CONDENSAZIONE VERSIONE 2"<<endl; 
	//registro il primo tempo
	cudaEventRecord(T1, 0);

   //Kernel
	stepCondensationSimple_v2<<<DIM_GRID,DIM_BLOCK>>>(B_dev,A_dev, COL-1,ROW-1);		
   //PullBack del risultato
	cudaMemcpy( B_host, B_dev, Nb*sizeof(float), cudaMemcpyDeviceToHost);

	//registro il secondo evento alla fine del kernel
	cudaEventRecord(T2, 0);
	cudaEventSynchronize(T2);

   //check
	//	print(B_host,ROW-1,COL-1);
	cudaEventElapsedTime(&diff_time, T1, T2);
	cout<<"Tempo esecuzione = "<<diff_time<<" ms"<<endl;

cout<<"CONDENSAZIONE VERSIONE 3"<<endl; 
	//registro il primo tempo
	cudaEventRecord(T1, 0);
   //Kernel
	stepCondensationSimple_v3<<<DIM_GRID,DIM_BLOCK>>>(B_dev,A_dev, COL-1,ROW-1);		
   //PullBack del risultato
	cudaMemcpy( B_host, B_dev, Nb*sizeof(float), cudaMemcpyDeviceToHost);

	//registro il secondo evento alla fine del kernel
	cudaEventRecord(T2, 0);
	cudaEventSynchronize(T2);

   //check
	//	print(B_host,ROW-1,COL-1); 
	cudaEventElapsedTime(&diff_time, T1, T2);
	cout<<"Tempo esecuzione = "<<diff_time<<" ms"<<endl;
*/
cout<<"CONDENSAZIONE VERSIONE 4 (1 texture)"<<endl; 
	//registro il primo tempo
	cudaEventRecord(T1, 0);

// --------- Preparo Texture
	float *pivot_Column = 0;
	unsigned int numBytes = ROW*sizeof(float);
	//Alloco la memoria lineare sulla gpu dove caricare la colonna di pivot
	cudaMalloc((void**)&pivot_Column, numBytes);

	//Chiamo kernel che mette la colonna in memoria lineare
	copy_Col<<<DIM_GRID,DIM_BLOCK>>>(pivot_Column, A_dev ,COL-1, COL, ROW);

	//Bindo a texture la memoria lineare
	cudaBindTexture(NULL, texRef, pivot_Column);
// --------- 


   //Kernel
	stepCondensationSimple_v4<<<DIM_GRID,DIM_BLOCK>>>(B_dev,A_dev, COL-1,ROW-1);		
   //PullBack del risultato
	cudaMemcpy( B_host, B_dev, Nb*sizeof(float), cudaMemcpyDeviceToHost);

// --------- Preparo Texture
	//unbind della texture
	cudaUnbindTexture ( texRef );
	cudaFree (pivot_Column);
// --------- 

	//registro il secondo evento alla fine del kernel
	cudaEventRecord(T2, 0);
	cudaEventSynchronize(T2);

   //check
	//	print(B_host,ROW-1,COL-1);
	cudaEventElapsedTime(&diff_time, T1, T2);
	cout<<"Tempo esecuzione = "<<diff_time<<" ms"<<endl;


cout<<"CONDENSAZIONE VERSIONE 4 (1 texture), versione ottimizzata"<<endl; 
	//registro il primo tempo
	cudaEventRecord(T1, 0);

// --------- Preparo Texture
//	*pivot_Column = 0;
	numBytes = ROW*sizeof(float);
	//Alloco la memoria lineare sulla gpu dove caricare la colonna di pivot
	cudaMalloc((void**)&pivot_Column, numBytes);

	//Chiamo kernel che mette la colonna in memoria lineare
	copy_Col<<<DIM_GRID,DIM_BLOCK>>>(pivot_Column, A_dev ,COL-1, COL, ROW);

	//Bindo a texture la memoria lineare
	cudaBindTexture(NULL, texRef, pivot_Column);
// --------- 
	dim3 block(THREAD_PER_BLOCK );  // 512 x 1 x 1	

	unsigned int block_per_row = ROW/THREAD_PER_BLOCK + 1;
	unsigned int block_per_col =  imin(COL, MAX_DIM_GRID / block_per_row);
	dim3 grid( block_per_row, block_per_col );         // 512 x 1 x 1

	cout<<"blocchi : "<<MAX_DIM_BLOCK<<" x 1 x 1 "<<endl;
	cout<<"griglia : "<< block_per_row <<" x "<< block_per_col << " x 1"<<endl;

   //Kernel
	stepCondensationSimple_v4<<<grid,block>>>(B_dev,A_dev, COL-1,ROW-1);		
   //PullBack del risultato
	cudaMemcpy( B_host, B_dev, Nb*sizeof(float), cudaMemcpyDeviceToHost);

// --------- Preparo Texture
	//unbind della texture
	cudaUnbindTexture ( texRef );
	cudaFree (pivot_Column);
// --------- 

	//registro il secondo evento alla fine del kernel
	cudaEventRecord(T2, 0);
	cudaEventSynchronize(T2);

   //check
	//	print(B_host,ROW-1,COL-1);
	cudaEventElapsedTime(&diff_time, T1, T2);
	cout<<"Tempo esecuzione = "<<diff_time<<" ms"<<endl;


cout<<"CONDENSAZIONE VERSIONE 4 (1 texture), versione ottimizzata 2"<<endl; 
	//registro il primo tempo
	cudaEventRecord(T1, 0);

// --------- Preparo Texture
//	*pivot_Column = 0;
	numBytes = ROW*sizeof(float);
	//Alloco la memoria lineare sulla gpu dove caricare la colonna di pivot
	cudaMalloc((void**)&pivot_Column, numBytes);

	//Chiamo kernel che mette la colonna in memoria lineare
	copy_Col<<<DIM_GRID,DIM_BLOCK>>>(pivot_Column, A_dev ,COL-1, COL, ROW);

	//Bindo a texture la memoria lineare
	cudaBindTexture(NULL, texRef, pivot_Column);
// --------- 
	dim3 block1(THREAD_PER_BLOCK );  // 512 x 1 x 1	

	 block_per_row = ROW/THREAD_PER_BLOCK + 1;
	 block_per_col =1;//  imin(COL, MAX_DIM_GRID / block_per_row);
	dim3 grid1( block_per_row, block_per_col );         // 512 x 1 x 1

	cout<<"blocchi : "<<MAX_DIM_BLOCK<<" x 1 x 1 "<<endl;
	cout<<"griglia : "<< block_per_row <<" x "<< block_per_col << " x 1"<<endl;

   //Kernel
	stepCondensationSimple_v4<<<grid1,block1>>>(B_dev,A_dev, COL-1,ROW-1);		
   //PullBack del risultato
	cudaMemcpy( B_host, B_dev, Nb*sizeof(float), cudaMemcpyDeviceToHost);

// --------- Preparo Texture
	//unbind della texture
	cudaUnbindTexture ( texRef );
	cudaFree (pivot_Column);
// --------- 

	//registro il secondo evento alla fine del kernel
	cudaEventRecord(T2, 0);
	cudaEventSynchronize(T2);

   //check
	//	print(B_host,ROW-1,COL-1);
	cudaEventElapsedTime(&diff_time, T1, T2);
	cout<<"Tempo esecuzione = "<<diff_time<<" ms"<<endl;

cout<<"Conclusione: questo Kernel non trae grande vantaggio dall'utilizzare griglia 2d di blocchi 1d, anzi si ha un grande peggioramento dovuto al fatto che i blocchi incolonnati ricopiano più volte nella shared segmenti di meoria che sarebbe bastato copiare una sola volta in una shared di un blocco che si sviluppa anche in verticale!"<<endl;
/*
cout<<"CONDENSAZIONE VERSIONE 5 (2 texture)"<<endl; 
	//registro il primo tempo
	cudaEventRecord(T1, 0);

// --------- Preparo Texture
	// *pivot_Column = 0;
	 numBytes = ROW*sizeof(float);
	//Alloco la memoria lineare sulla gpu dove caricare la colonna di pivot
	cudaMalloc((void**)&pivot_Column, numBytes);

	//Chiamo kernel che mette la colonna in memoria lineare
	copy_Col<<<DIM_GRID,DIM_BLOCK>>>(pivot_Column, A_dev ,COL-1, COL, ROW);

	//Bindo a texture la memoria lineare
	cudaBindTexture(NULL, texRef, pivot_Column);
// --------- 
	//Bindo a texture tutta la matrice in modo che e' bindato anche il vettore che mi interessa
	 cudaBindTexture(NULL, texRef2, A_dev);
// ---------

   //Kernel
	stepCondensationSimple_v5<<<DIM_GRID,DIM_BLOCK>>>(B_dev,A_dev, COL-1,ROW-1);		
   //PullBack del risultato
	cudaMemcpy( B_host, B_dev, Nb*sizeof(float), cudaMemcpyDeviceToHost);



// --------- Preparo Texture
	//unbind della texture
	cudaUnbindTexture ( texRef );
	cudaUnbindTexture ( texRef2 );
	cudaFree (pivot_Column);
// --------- 

	//registro il secondo evento alla fine del kernel
	cudaEventRecord(T2, 0);
	cudaEventSynchronize(T2);

   //check
	//	print(B_host,ROW-1,COL-1);
	cudaEventElapsedTime(&diff_time, T1, T2);
	cout<<"Tempo esecuzione = "<<diff_time<<" ms"<<endl;




cout<<"CONDENSAZIONE VERSIONE 6 (1 sola  texture grande)"<<endl; 
	//registro il primo tempo
	cudaEventRecord(T1, 0);

// --------- Preparo Texture
	//Bindo a texture tutta la matrice in modo che e' bindato anche il vettore che mi interessa
	 cudaBindTexture(NULL, texRef2, A_dev);
// ---------

   //Kernel
	stepCondensationSimple_v6<<<DIM_GRID,DIM_BLOCK>>>(B_dev,A_dev, COL-1,ROW-1);		
   //PullBack del risultato
	cudaMemcpy( B_host, B_dev, Nb*sizeof(float), cudaMemcpyDeviceToHost);


// --------- Preparo Texture
	//unbind della texture
	cudaUnbindTexture ( texRef2 );
// --------- 

	//registro il secondo evento alla fine del kernel
	cudaEventRecord(T2, 0);
	cudaEventSynchronize(T2);

   //check
	//	print(B_host,ROW-1,COL-1);
	cudaEventElapsedTime(&diff_time, T1, T2);
	cout<<"Tempo esecuzione = "<<diff_time<<" ms"<<endl;
*/


   cudaFree( A_dev);
   cudaFree( B_dev);



  return 0;
}

