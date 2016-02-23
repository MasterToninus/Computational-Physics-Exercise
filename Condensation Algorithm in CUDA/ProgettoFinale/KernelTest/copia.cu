//kernel che copia i primi N elementi di un array in un altro array
/*
input: 
	puntatore destinatatio
	puntatore partenza
	numero di elementi
*/



__global__ void copy_vec( float *a, float *b,int Ncomponents){

  int tid = blockIdx.x*blockDim.x + threadIdx.x; //identità del thread (al solito metto in fila ogni thread a partire dal primo blocco)
  int Nthreads = blockDim.x * gridDim.x;	 //Numero totale di threads istanziati dalla chiamata del kernel

  while(tid<Ncomponents){
	a[tid]=b[tid]; //qui copia
	tid+= Nthreads;	      // se il vettore ha più elementi del numero di thread chiamati faccio si che ogni thread sommi più di un elemento
	}
  
}



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

