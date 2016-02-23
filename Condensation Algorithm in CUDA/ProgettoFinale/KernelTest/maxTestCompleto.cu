
 #include <iostream>
using namespace std;
#include <cstdlib>

#include "cuda_runtime.h"
#include "lock.h"


#define THREAD_PER_BLOCK 128
#define BLOCK_PER_GRID 64

#include "max.cuh"

int main( void ){


  unsigned int threadsPerBlock= THREAD_PER_BLOCK;
  unsigned int blocksPerGrid = BLOCK_PER_GRID;
  unsigned int Nthread=THREAD_PER_BLOCK*BLOCK_PER_GRID;

 //Definisco i puntatori alle variabli host
	float *A_host;
//Definisco i puntatori alle variabli device
	float *A_dev;
	float *max_Value_dev;
	int   *max_Index_dev;



//alloco le variabili host
  	int N=10000;  
	A_host = new float[N] ();
	float max_Value_host;
	int   max_Index_host;

//Alloco le variabili device
  	cudaMalloc( (void **)&A_dev, N*sizeof(float)  );

 	cudaMalloc( (void **)&max_Value_dev, sizeof(float)  );
  	cudaMalloc( (void **)&max_Index_dev, sizeof(int)  );
 
//Riempio le variabili host
  for( int i=0; i<N; i++) A_host[i] = drand48();
  A_host[17]=-100.9;
  for( int i=0; i<N; i++) cout<<"A_host[ "<<i<<" ] = "<<A_host[i]<<endl;

    max_Value_host = A_host[0];
    max_Index_host=0;


//Riempio le variabili Device
  cudaMemcpy( A_dev,  A_host, N*sizeof(float), cudaMemcpyHostToDevice);
  cudaMemcpy( max_Value_dev,  &max_Value_host, sizeof(float), cudaMemcpyHostToDevice);
  cudaMemcpy( max_Index_dev,  &max_Index_host, sizeof(int), cudaMemcpyHostToDevice);

//KERNEL!

	Lock lock;
  MaxValueCompleto<<<blocksPerGrid,threadsPerBlock>>>(lock,A_dev,N,
							max_Value_dev,max_Index_dev);

//Pull back dei risultati
  cudaMemcpy( &max_Value_host,  max_Value_dev, sizeof(float), cudaMemcpyDeviceToHost);
  cudaMemcpy( &max_Index_host,  max_Index_dev, sizeof(int), cudaMemcpyDeviceToHost);



cout<<"max ="<<max_Value_host<<" idx = "<< max_Index_host <<endl;
  return 0;
}




