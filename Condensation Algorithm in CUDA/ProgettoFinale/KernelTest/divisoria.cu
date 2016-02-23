
 #include <iostream>
using namespace std;
#include <cstdlib>


#define THREAD_PER_BLOCK 128
#define BLOCK_PER_GRID 128

#include "divisoria.cuh"

int main( void ){


  //Definisco i puntatori alle variabli host
	float *A_host;

//Definisco i puntatori alle variabli device
	float *A_dev;



//alloco le variabili host
  	int N=15;  
	A_host = new float[N] ();

//Alloco le variabili device
  	cudaMalloc( (void **)&A_dev, N*sizeof(float)  );
 
//Riempio le variabili host
  for( int i=0; i<N; i++)A_host[i] = drand48()*10;
  cout<<endl;for( int i=0; i<N; i++) cout<<A_host[i]<<endl;

//Riempio le variabili Device
 cudaMemcpy( A_dev,  A_host, N*sizeof(float), cudaMemcpyHostToDevice);

//Testo divisoria Gpu
	divisoria_Cuda_v1<<<N,1>>>(A_host,10.0,N);

//Pull back dei risultati
  cudaMemcpy( A_host,  A_dev, N*sizeof(float), cudaMemcpyDeviceToHost);

//Testo divisoria Cpu
	divisoria_Cpu_v1(A_host,10.0,N);
  cout<<endl;for( int i=0; i<N; i++) cout<<A_host[i]<<endl;





  cout<<endl;for( int i=0; i<N; i++) cout<<A_host[i]<<endl;


  return 0;
}





