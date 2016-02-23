/*//---------------------------------------------------------------------------------------------------------
| faccio eseguire un semplice riempimento di vettore alla scheda, riempie con l'indice del thread
| 	
| 
*///---------------------------------------------------------------------------------------------------------





#include <iostream>
#include <stdio.h>
using namespace std;
#include <cstdlib>

#define DIM_BLOCK 256
#define DIM_GRID 1024

__global__ void riempimento(float*V, int N){

  unsigned int tid = blockIdx.x * blockDim.x + threadIdx.x;
  unsigned int Nthreads = blockDim.x * gridDim.x;	 //Numero totale di threads istanziati dalla chiamata del kernel

  while(tid<N){
	V[tid]=(float)tid;
	tid+= Nthreads;	      // se il vettore ha più elementi del numero di thread chiamati faccio si che ogni thread sommi più di un elemento
  } 

}




int main(){

//Definisco i puntatori alle variabli host
	float *A_host; 
//Definisco i puntatori alle variabli device
	float *A_dev;

//alloco le variabili host
  	int N=100000000;  
	A_host = new float[N] ();

//Alloco le variabili device
  cudaMalloc( (void **)&A_dev, N*sizeof(float)  );

//Setup della configurazione di esecuzione
/*	cudaDeviceProp prop; //cudaDeviceProp e' una struttura di dati, prop e' il nome della variabile di questo tipo
	cudaGetDeviceProperties( &prop, 0); //salva in prop le caratteristiche della prima scheda
	unsigned int Block_Width=prop.maxThreadsDim[0];
	unsigned int Grid_Width=prop.maxGridSize[0];

	dim3 dimBlock(Block_Width,1);
	dim3 dimGrid(Grid_Width,1);
*/

//Riempio le variabili device
	riempimento<<<DIM_GRID,DIM_BLOCK>>>(A_dev,N);
	
//riempio le variabili host
	cudaMemcpy( A_host, A_dev, N*sizeof(float), cudaMemcpyDeviceToHost);

//controllo!
	for(int i=N-1000; i<N; i++)printf(" %f \n",A_host[i]);


  return 0;
}


