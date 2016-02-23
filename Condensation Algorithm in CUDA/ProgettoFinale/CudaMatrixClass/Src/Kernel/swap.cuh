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

__global__ void swapCol(float * A, int j1, int j2, int numAColumns, int numARow) 
{
// OGNI thread copia un elemento di riga nel suo registo ed esegue lo swap
   unsigned int tid = blockIdx.x * blockDim.x + threadIdx.x;
   unsigned int Nthreads = blockDim.x * gridDim.x;	
   float temp;

  while(tid<numARow){
	temp= A[tid*numAColumns + j1];
	A[tid*numAColumns + j1] = A[tid*numAColumns + j2];
	A[tid*numAColumns + j2] = temp;
	tid+= Nthreads;	      // se il vettore ha più elementi del numero di thread chiamati faccio si che ogni thread sommi più di un elemento
  }

}
























