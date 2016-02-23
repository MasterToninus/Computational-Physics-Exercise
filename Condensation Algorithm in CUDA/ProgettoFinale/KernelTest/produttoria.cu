#include <iostream>
using namespace std;
#include <cstdlib>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cuda.h>
#include <cuda_runtime.h>
#include "lock.h"


//va compilato cosi'; nvcc -arch=sm_20 -I/home/vicini/NVIDIA_GPU_Computing_SDK/CUDALibraries/common/inc/ -I/home/vicini/NVIDIA_GPU_Computing_SDK/shared/inc/ -I../../common/ -I/usr/local/cuda/include/ produttoria.cu

const int threadsPerBlock = 128;
const int blocksPerGrid = 512;

__global__ void produttoria(Lock mylock, float*V, int N, float *ris){

  unsigned int tid = blockIdx.x * blockDim.x + threadIdx.x;	//indice complessivo del thread
  int cacheIndex = threadIdx.x;   				//indice nelle somme parziali del blocco.
  unsigned int Nthreads = blockDim.x * gridDim.x;	 	//Numero totale di threads istanziati dalla chiamata del kernel


//Fase 1; concentro il vettore in uno che ha tanti elementi quanti sono i blocchi
  __shared__ float Prodotto_parziale[threadsPerBlock]; //il blocco si alloca la sua bella memoria shared il valore deve essere una costante!
  Prodotto_parziale[cacheIndex]=V[tid];                 //ogni thread del blocco la riempie con un valore iniziale

  unsigned int k=tid+Nthreads;	
  while(k<N){// se il vettore ha più elementi del numero di thread chiamati faccio si che ogni thread sommi più di un elemento
	Prodotto_parziale[cacheIndex]=Prodotto_parziale[cacheIndex]*V[k];
	k+= Nthreads;	      
  } 
__syncthreads();//Sincronizzo per assicurarmi che ogni thread del blocco abbia caricato gli elementi.


//Fase 2; calcolo la produttoria di ogni blocco con metodo telescopico
 //si puo' quindi passare a valutare la somma parziale dei risultati dei vari threads di un blocco
  int i=blockDim.x/2;
// divido i thread del blocco in 2 meta'

  while(i!=0){
    if (cacheIndex < i) // i thread che sono nella prima meta' li produco con il corrispondente nella seconda meta'. solo una meta' dei thread lavoro effettivamente ma comunque partono tutti insieme! e' il parallelismo!
      //questa somma combina i valori della meta' superiore del blocco di threads con quelli della 
      //meta' inferiore e li associa a indici della meta' inferiore
      Prodotto_parziale[cacheIndex]*=Prodotto_parziale[cacheIndex+i];
    //e' necessario attendere che tutti i threads abbiano effettuato la somma
    __syncthreads(); // visto che solo meta' dei thread lavoro e necessario che si sincronizzano
    //tutti gli elementi rilevanti hanno indici da zero a meta' del blocco
    //nella seconda iterazione si sommano gli elementi del secondo quarto con quelli del primo
    //quarto del blocco, e cosi' via
    i/=2; // dimezzo ancora il blocco
    //poiche' i e' una variabile intera, nel caso 1/2 = 0.5 viene restituito 0
  };

//A questo punto nell'elemento Prodotto_parziale[0] di ogni blocco si trova una somma parziale


//Fase 3; ogni blocco accumula il valore in una variabile nella global (il primo che arriva agisce)
 if(cacheIndex==0){
	 mylock.lock() ;
	 *ris=*ris*Prodotto_parziale[threadIdx.x];
 	mylock.unlock() ;
 }

}


int main(){

//Definisco i puntatori alle variabli host
	float *A_host; 
//Definisco i puntatori alle variabli device
	float *A_dev; float *value_dev;

//alloco le variabili host
  	int N=1000000;  
	A_host = new float[N] ();
	float value_host;

//Alloco le variabili device
  cudaMalloc( (void **)&A_dev, N*sizeof(float)  );
  cudaMalloc( (void **)&value_dev, sizeof(float)  );

//riempio le variabili Device
        srand (time(NULL));	/* initialize random seed: */			 
        for(int i=0; i<N; i++)A_host[i]= ((float) rand() /RAND_MAX)*(0.01)+0.995;//genero tanti random molto vicini a 1
	cudaMemcpy( A_dev, A_host, N*sizeof(float), cudaMemcpyHostToDevice);

	value_host =1;
	cudaMemcpy( value_dev , &value_host, sizeof(float), cudaMemcpyHostToDevice);

        for(int i=0; i<N; i++)value_host*=A_host[i];
	cout<<"produttoria secondo la cpu :"<< value_host<<endl;


//Setup della configurazione di esecuzione

	dim3 dimBlock(threadsPerBlock,1);
	dim3 dimGrid(blocksPerGrid,1);

//Il lock lo passo come argomento del kernel
	Lock lock;

//Riempio le variabili device
	produttoria<<<dimGrid,dimBlock>>>( lock,A_dev, N, value_dev);
//riempio le variabili host
	cudaMemcpy( &value_host, value_dev, sizeof(float), cudaMemcpyDeviceToHost);
	cout<<"produttoria secondo la gpu :"<< value_host<<endl;


  return 0;
}


