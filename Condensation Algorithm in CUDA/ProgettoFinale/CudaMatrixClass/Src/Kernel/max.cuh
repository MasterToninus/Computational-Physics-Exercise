//MEMENTO! compilare cosi' " nvcc -arch sm_11 " per usare il lock!
#include "cuda_runtime.h"
#include "lock.cuh"


//VERSIONE CHE FUNZIONA ANCHE SE IL NUMERO DI THREAD SUPERA IL NUMERO DI ELEMENTI! in tal caso i thread extra hanno uno zero come valore!
__global__ void MaxValue(Lock lock,float * A, int numAColumns,float *maxValue, int *maxIndex) 
{
   unsigned int tid = blockIdx.x * blockDim.x + threadIdx.x;	//indice complessivo del thread
   int cacheIndex = threadIdx.x;   				//indice nelle somme parziali del blocco.
   unsigned int Nthreads = blockDim.x * gridDim.x;	 	//Numero totale di threads istanziati dalla chiamata del kernel

   //fase zero, ogni thread si copia nella shared: 
   __shared__ float A_shared[THREAD_PER_BLOCK]; 		//il valore assoluto del vettore corrispondente al tid
   __shared__ unsigned int Index_shared[THREAD_PER_BLOCK];	// l'indice come elemento di matrice dell'elemento salvato nella shared

   float temp;
   if(tid<numAColumns){
	temp=A[tid];
	if(temp<0)temp=-temp;  
	A_shared[cacheIndex]=temp;
	Index_shared[cacheIndex]=tid;
   }
   else{
	A_shared[cacheIndex]=0;
	Index_shared[cacheIndex]=tid;
   }


   //Fase 1; concentro il vettore in uno che ha tanti elementi quanti sono i blocchi ogniuno contenente una potenza di 2 di elementi (quindi telescopicizzabile)http://www.cuvilib.com/Reduction.pdf

   unsigned int dummyid=tid+Nthreads;

  while(dummyid<numAColumns){
		temp=A[dummyid];
   		if(temp<0)temp=-temp;
		if(A_shared[cacheIndex]<temp){
			A_shared[cacheIndex]=temp;
			Index_shared[cacheIndex]=dummyid;
		}

	dummyid+= Nthreads;	      // se il vettore ha più elementi del numero di thread chiamati faccio si che ogni thread sommi più di un elemento
  }
  __syncthreads();//Sincronizzo per assicurarmi che ogni thread del blocco abbia caricato gli elementi.


   //Fase 2, riduco in modo telescopico il vettore
   dummyid=blockDim.x/2;
  while(dummyid!=0){
    if (cacheIndex < dummyid)
	if(A_shared[cacheIndex]<A_shared[cacheIndex+dummyid]){
	      A_shared[cacheIndex]=A_shared[cacheIndex + dummyid];
	      Index_shared[cacheIndex]=Index_shared[cacheIndex + dummyid];
	}
      __syncthreads(); 
       dummyid/=2;
  }

//A questo punto nell'elemento A_shared[0] di ogni blocco si trova un massimo parziale
   //Fase 3, stabilisco qual'e' il massimo di ogni blocco in modo atomic
  if (cacheIndex ==0 && tid<numAColumns){
    lock.lock();
    if(*maxValue< A_shared[0]){
	*maxValue=A_shared[0];
	*maxIndex=Index_shared[0];
	}
    lock.unlock();
  }
}



















