/*//---------------------------------------------------------------------------------------------------------
| faccio eseguire un semplice riempimento di vettore alla scheda, riempie con l'indice del thread
| 	
| 
*///---------------------------------------------------------------------------------------------------------


__global__ void riempimento(float*V, int N){

  unsigned int tid = blockIdx.x * blockDim.x + threadIdx.x;
  unsigned int Nthreads = blockDim.x * gridDim.x;	 //Numero totale di threads istanziati dalla chiamata del kernel

  while(tid<N){
	V[tid]=(float)tid;
	tid+= Nthreads;	      // se il vettore ha più elementi del numero di thread chiamati faccio si che ogni thread sommi più di un elemento
  } 

}

//http://en.wikipedia.org/wiki/Hilbert_matrix
__global__ void riempimento_Hilbert(float*A, int numAColumns, int numARow){

   unsigned int tid_i = blockDim.y * blockIdx.y + threadIdx.y;
   unsigned int tid_j = blockDim.x * blockIdx.x + threadIdx.x ;
   const unsigned int incremento_verticale = blockDim.y*gridDim.y;
   const unsigned int incremento_orizzontale = blockDim.x * gridDim.x;

  while(tid_j<numAColumns){// per ogni macro colonna
	while(tid_i<numARow){	
		A[tid_i*numAColumns+tid_j]=1/((float)tid_i+tid_j+1);
		tid_i += incremento_verticale;
	}
  	tid_j+= incremento_orizzontale;
  }

}
