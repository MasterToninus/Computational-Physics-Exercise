//Passo il divisore per valore

void divisoria_Cpu_v1(float * A,float divisore, int Ncomponents){
  int tid=0;
  while(tid<Ncomponents){
	A[tid]/=divisore; //qui somma
	tid++;	  // se il vettore ha più elementi del numero di thread chiamati faccio si che ogni thread sommi più di un elemento
	}

}





__global__ void divisoria_Cuda_v1(float * A,float divisore, int Ncomponents){
  int tid = blockIdx.x*blockDim.x + threadIdx.x; //identità del thread (al solito metto in fila ogni thread a partire dal primo blocco
  int Nthreads = blockDim.x * gridDim.x;	 //Numero totale di threads istanziati dalla chiamata del kernel

  while(tid<Ncomponents){
	float dummy=A[tid]/divisore;
	A[tid]=dummy; //qui somma
	tid+= Nthreads;	  // se il vettore ha più elementi del numero di thread chiamati faccio si che ogni thread sommi più di un elemento
	}

}

//Passo il divisore per indirizzo dopo averlo bindato nella static
__global__ void divisoria_v2(float * A, int N,
				float *divisore){



}


//ipotetica versione 3, passo l'indice del divisore per argomento, il kernel non puo' salvarselo nella static! quindi necessariamente dovrebbe andare copiata nella chace!
