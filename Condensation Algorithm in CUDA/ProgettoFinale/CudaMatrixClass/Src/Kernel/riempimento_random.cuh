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

