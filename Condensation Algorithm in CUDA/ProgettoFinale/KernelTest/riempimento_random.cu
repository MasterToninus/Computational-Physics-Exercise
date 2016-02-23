/*//---------------------------------------------------------------------------------------------------------
| faccio eseguire un semplice riempimento di vettore alla scheda, riempie con l'indice del thread
| stare attenti pero' al limite di memoria allocabile!
| 
*///---------------------------------------------------------------------------------------------------------





#include <iostream>
#include <stdio.h>
using namespace std;
#include <cstdlib>


// IMPLEMENTO I RANDOOM!
#include <cuda_runtime_api.h>	//tutto cio per richiamare il curand
#include <curand.h>
#include <curand_kernel.h>

#include <ctime>		//per inizializzare il seed con time

__global__ void initRandom(curandState *  State, const unsigned int seed){

  unsigned int tid = blockIdx.x * blockDim.x + threadIdx.x;
  curand_init(seed, tid, 0, &State[tid]);

}



__global__ void riempimento_random(float*V, int N, curandState *  State, float Min, float Max){

  unsigned int tid = blockIdx.x * blockDim.x + threadIdx.x;
  unsigned int Nthreads = blockDim.x * gridDim.x;	 //Numero totale di threads istanziati dalla chiamata del kernel

  unsigned int k=tid;	
 
  curandState localState = State[tid];

  while(k<N){
	V[k]= Min + curand_uniform(&localState) *(Max-Min);
	k+= Nthreads;	      // se il vettore ha più elementi del numero di thread chiamati faccio si che ogni thread sommi più di un elemento
  } 

  State[tid]=localState;


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
*/
	unsigned int Block_Width=128;//prop.maxThreadsDim[0]/2;
	unsigned int Grid_Width=512;//prop.maxGridSize[0]/2;
/*
	dim3 dimBlock(Block_Width,1);
	dim3 dimGrid(Grid_Width,1);
*/
	unsigned int nThreads=Block_Width*Grid_Width;

//Inizializzo i seed per il random ogni thread avra' il suo seed
	curandState *dev_State ;
	cudaMalloc( (void **)&dev_State, nThreads*sizeof(curandState) );
	int seed =time( 0 );
//Riempio le variabili device

	initRandom<<<Grid_Width,Block_Width>>>(dev_State,seed);
	//riempimento_random<<<dimGrid,dimBlock>>>(A_dev,N,dev_State,seed,0.5,2.);
	riempimento_random<<<Grid_Width,Block_Width>>>(A_dev,N,dev_State,0.5,2.);
	
//riempio le variabili host
	cudaMemcpy( A_host, A_dev, N*sizeof(float), cudaMemcpyDeviceToHost);

//controllo!
	for(int i=0; i<N; i++)printf("A[%d] = %f \n",i,A_host[i]);

  //Disalloco la memoria riservata sulla scheda
	cudaFree( dev_State);
	cudaFree( A_dev);


  return 0;
}


