//kernel che somma i primi N elementi di due array di interi a e b (precedentemente copiati sulla memoria ) e li copia nell'array c
/*
input: 
	numero di elementi
	puntatore ai vettori a e b da sommare
	il risultato viene rimesso nel vettore a
*/



__global__ void add_vec( float *a, float *b,int Ncomponents){

  int tid = blockIdx.x*blockDim.x + threadIdx.x; //identità del thread (al solito metto in fila ogni thread a partire dal primo blocco)
  int Nthreads = blockDim.x * gridDim.x;	 //Numero totale di threads istanziati dalla chiamata del kernel

  while(tid<Ncomponents){
	a[tid]+=b[tid]; //qui somma
	tid+= Nthreads;	      // se il vettore ha più elementi del numero di thread chiamati faccio si che ogni thread sommi più di un elemento
	}
  
}


__global__ void sub_vec( float *a, float *b,int Ncomponents){

  int tid = blockIdx.x*blockDim.x + threadIdx.x; //identità del thread (al solito metto in fila ogni thread a partire dal primo blocco)
  int Nthreads = blockDim.x * gridDim.x;	 //Numero totale di threads istanziati dalla chiamata del kernel

  while(tid<Ncomponents){
	a[tid]-=b[tid]; //qui somma
	tid+= Nthreads;	      // se il vettore ha più elementi del numero di thread chiamati faccio si che ogni thread sommi più di un elemento
	}
  
}


__global__ void linear_vec( float *a, float lambda,int Ncomponents){

  int tid = blockIdx.x*blockDim.x + threadIdx.x; //identità del thread (al solito metto in fila ogni thread a partire dal primo blocco)
  int Nthreads = blockDim.x * gridDim.x;	 //Numero totale di threads istanziati dalla chiamata del kernel

  while(tid<Ncomponents){
	a[tid]*=lambda; 
	tid+= Nthreads;	      // se il vettore ha più elementi del numero di thread chiamati faccio si che ogni thread sommi più di un elemento
	}
  
}
