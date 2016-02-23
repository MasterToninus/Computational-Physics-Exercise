/*//---------------------------------------------------------------------------------------------------------
| kernel ausiliari
| 
*///---------------------------------------------------------------------------------------------------------


__global__ void swapRow(float * A, int i1, int i2, int numAColumns) 
{
// OGNI thread copia un elemento di riga nel suo registo ed esegue lo swap
   unsigned int tid = blockIdx.x * blockDim.x + threadIdx.x;
   unsigned int Nthreads = blockDim.x * gridDim.x;	
   float temp;

  while(tid<numAColumns){
	temp= A[i1*numAColumns + tid];
	A[i1*numAColumns + tid] = A[i2*numAColumns + tid];
	A[i2*numAColumns + tid] = temp;
	tid+= Nthreads;	      // se il vettore ha più elementi del numero di thread chiamati faccio si che ogni thread sommi più di un elemento
  }

}

#ifndef MAX_FLOAT(a,b)
#define MAX_FLOAT(a,b) (a>b?a:b)


//fare attenzione! non lanciare piu' thread del necessario! Nthread sempre minore del numero di componenti!
// kernel si aspetta: 	Nthread totali minore del numero di elementi
//			Nthread per blocco potenza di 2

__global__ void MaxValueinRow(float * A, int i1, int numAColumns) 
{
   unsigned int tid = blockIdx.x * blockDim.x + threadIdx.x;	//indice complessivo del thread
   int cacheIndex = threadIdx.x;   				//indice nelle somme parziali del blocco.
   unsigned int Nthreads = blockDim.x * gridDim.x;	 	//Numero totale di threads istanziati dalla chiamata del kernel

   //fase zero, ogni thread si copia nella shared: 
   __shared__ float A_shared[blockDim.x]; 		//il valore assoluto del vettore corrispondente al tid
   __shared__ unsigned int Index_shared[blockDim.x];	// l'indice come elemento di matrice dell'elemento salvato nella shared
//   if(tid<numAColumns) //questo if e' superfluo! questo kernel presume di lanciare sempre un numero di thread minore o uguale al numero di elementi!
   float temp=A[tid];
   if(temp<0)temp=-temp;  
   A_shared[cacheIndex]=temp;
   Index_shared[cacheIndex]=tid;

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
      A_shared[cacheIndex]=MAX_FLOAT(A_shared[cacheIndex],A_shared[cacheIndex+dummyid]);
      __syncthreads(); 
       dummyid/=2;
  }

//A questo punto nell'elemento A_shared[0] di ogni blocco si trova un massimo parziale
   //Fase 3, stabilisco qual'e' il massimo di ogni blocco







}

