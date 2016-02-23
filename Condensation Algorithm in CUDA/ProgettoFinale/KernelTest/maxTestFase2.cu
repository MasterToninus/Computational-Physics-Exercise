
 #include <iostream>
using namespace std;
#include <cstdlib>

#include "cuda_runtime.h"
#include "lock.h"


#define THREAD_PER_BLOCK 2
#define BLOCK_PER_GRID 2

#include "max.cuh"

int main( void ){


  unsigned int threadsPerBlock= THREAD_PER_BLOCK;
  unsigned int blocksPerGrid = BLOCK_PER_GRID;
  unsigned int Nthread=THREAD_PER_BLOCK*BLOCK_PER_GRID;

 //Definisco i puntatori alle variabli host
	float *A_host;
	float *A_test_host;
	int   *Index_test_host;
//Definisco i puntatori alle variabli device
	float *A_dev;
	float *A_test_dev;
	int   *Index_test_dev;



//alloco le variabili host
  	int N=7;  
	A_host = new float[N] ();
	A_test_host = new float[Nthread] ();
	Index_test_host = new int[Nthread] ();

//Alloco le variabili device
  	cudaMalloc( (void **)&A_dev, N*sizeof(float)  );
 
  	cudaMalloc( (void **)&A_test_dev, Nthread*sizeof(float)  );
  	cudaMalloc( (void **)&Index_test_dev, Nthread*sizeof(int)  );





//Riempio le variabili host
  for( int i=0; i<N; i++){
    A_host[i] = -N+2*N*i;
    cout<<"A_host[ "<<i<<" ] = "<<A_host[i]<<endl;
  };

//Riempio le variabili Device
 cudaMemcpy( A_dev,  A_host, N*sizeof(float), cudaMemcpyHostToDevice);


//Testo fase 1, compressione del vettorone ad tot blocchi di tot thread
cout<<"FASE 1"<<endl;

  MaxValueFase1<<<blocksPerGrid,threadsPerBlock>>>(A_dev,N,
							A_test_dev,Index_test_dev);

//Pull back dei risultati
  cudaMemcpy( A_test_host,  A_test_dev, Nthread*sizeof(float), cudaMemcpyDeviceToHost);
  cudaMemcpy( Index_test_host,  Index_test_dev, Nthread*sizeof(int), cudaMemcpyDeviceToHost);

  for( int i=0; i<Nthread; i++){
 
    cout<<"tread[ "<<i<<"] , idx = "<< Index_test_host[i] <<" val = "<<A_test_host[i] <<endl;
  }

//Testo fase 2, compressione del vettorone ad tot blocchi di tot thread
cout<<"FASE 2"<<endl;

  MaxValueFase2<<<blocksPerGrid,threadsPerBlock>>>(A_dev,N,
							A_test_dev,Index_test_dev);

//Pull back dei risultati
  cudaMemcpy( A_test_host,  A_test_dev, Nthread*sizeof(float), cudaMemcpyDeviceToHost);
  cudaMemcpy( Index_test_host,  Index_test_dev, Nthread*sizeof(int), cudaMemcpyDeviceToHost);

  for( int i=0; i<Nthread; i++){
 
    cout<<A_test_host[i]<<" "<< Index_test_host[i] <<endl;
  }


  return 0;
}




