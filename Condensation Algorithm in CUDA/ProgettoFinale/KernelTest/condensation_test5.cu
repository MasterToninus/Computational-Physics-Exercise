/*//---------------------------------------------------------------------------------------------------------
|
|  Test dell'ultima versione del kernel, usa una shared  larga come il warp e una copia texture dell'intera matrice.
|  questa ultima versione e' pensata per essere usata con blocchi 2D 
|
*///---------------------------------------------------------------------------------------------------------
//OGNI thread alloca 5 unsigned int e 2 float ---> 7*4= 28 byte



#include <iostream>
#include <stdio.h>
using namespace std;
#include <cstdlib>
#include <stdlib.h>     /* srand, rand */ //http://www.cplusplus.com/reference/cstdlib/rand/
#include <fstream>	//http://www.cplusplus.com/doc/tutorial/files/


// Numero di thread prudente
#define DIM_GRID 128
#define DIM_BLOCK 128
#define THREAD_PER_BLOCK 128



/*     DIMENSIONALIZZAZIONE DEI THREAD    */
// Numero di thread "Limite"
#define imin(a,b) (a<b?a:b)

//trucco per ottimizzare il numero di blocchi
//const int blocksPerGrid = imin(32,(N+threadsPerBlock-1)/threadsPerBlock);

#define MAX_DIM_BLOCK 512
#define MAX_DIM_GRID 524288 //in realtà il max numero di thrad è un po' di piu', questa è la potenza di 2 più vicina
#define DIM_WARP 32


#include "condensation_tentative.cuh"




void print(float *A, int ROW, int COL){
		for(int i=0 ; i<ROW ; i++){
			for(int j=0 ; j<COL ; j++){
				//printf(" %.1f ",A[i*COL+j]);
				cout<< A[i*COL+j] << " ";
			}
			cout<<endl;
		}
		cout<<endl;  
}







int main(void){

	int ROW=10000;
	int COL=ROW;
	int N = COL*ROW;
	int Nb= (ROW-1)*(COL-1);
	srand (time(NULL));  

   //Punto La memoria
	float * A_host; float *B_host;
	float * A_dev; float *B_dev;

   //Alloco la matrice
	A_host = new float[N] ();
	B_host = new float[Nb] ();


   //Alloco le matrice device (riservo la memoria richiesta)
	unsigned int ByteSize = N*sizeof(float);
	cudaMalloc( (void **)&A_dev, ByteSize  );
	ByteSize = Nb*sizeof(float);
	cudaMalloc( (void **)&B_dev, ByteSize  );


   //Riempio la Matrice Host
	//float min = -10, max = 10 , delta = max-min; 
	for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++)A_host[i*COL+j] =  (rand() % 10 );
        A_host[N-1]=1;

   //Riempio La Matrice Device
	cudaMemcpy( A_dev, A_host, N*sizeof(float), cudaMemcpyHostToDevice);

   //Check Matrice Creata
	//	print(A_host,ROW,COL);



	//Creo degli eventi per la statistica
	cudaEvent_t T1,T2;
	cudaEventCreate(&T1);
	cudaEventCreate(&T2);
	float diff_time;




cout<<"CONDENSAZIONE VERSIONE 6 (1 sola  texture grande)"<<endl; 
	//registro il primo tempo
	cudaEventRecord(T1, 0);

// --------- Preparo Texture
	//Bindo a texture tutta la matrice in modo che e' bindato anche il vettore che mi interessa
	 cudaBindTexture(NULL, texRef2, A_dev);
// ---------

        dim3 block3(DIM_BLOCK );  // 512 x 1 x 1    

        unsigned int block_per_row = DIM_GRID;
        unsigned int block_per_col = 1;// imin(COL, MAX_DIM_GRID / block_per_row);
        dim3 grid3( block_per_row, block_per_col );         // 512 x 1 x 1

        cout<<"blocchi : "<<DIM_BLOCK<<" x 1 x 1 "<<endl;
        cout<<"griglia : "<< block_per_row <<" x "<< block_per_col << " x 1"<<endl;



   //Kernel
	stepCondensationSimple_v6<<<grid3,block3>>>(B_dev,A_dev, COL-1,ROW-1);		
   //PullBack del risultato
	cudaMemcpy( B_host, B_dev, Nb*sizeof(float), cudaMemcpyDeviceToHost);


// --------- Preparo Texture
	//unbind della texture
	cudaUnbindTexture ( texRef2 );
// --------- 

	//registro il secondo evento alla fine del kernel
	cudaEventRecord(T2, 0);
	cudaEventSynchronize(T2);

   //check
	//		print(B_host,ROW-1,COL-1);
	cudaEventElapsedTime(&diff_time, T1, T2);
	cout<<"Tempo esecuzione = "<<diff_time<<" ms"<<endl;



cout<<"CONDENSAZIONE VERSIONE 6 (1 sola  texture grande) versione ottimizzata"<<endl; 
	//registro il primo tempo
	cudaEventRecord(T1, 0);

// --------- Preparo Texture
	//Bindo a texture tutta la matrice in modo che e' bindato anche il vettore che mi interessa
	 cudaBindTexture(NULL, texRef2, A_dev);
// ---------

	unsigned int thread_per_row = DIM_WARP;//imin(COL,MAX_DIM_BLOCK);
        dim3 block4(thread_per_row );  // 512 x 1 x 1    

        block_per_row = ROW/THREAD_PER_BLOCK + 1;
        block_per_col =  imin(COL, MAX_DIM_GRID / block_per_row);
        dim3 grid4( block_per_row, block_per_col );         // 512 x 1 x 1

        cout<<"blocchi : "<<thread_per_row<<" x 1 x 1 "<<endl;
        cout<<"griglia : "<< block_per_row <<" x "<< block_per_col << " x 1"<<endl;



   //Kernel
	stepCondensationSimple_v6<<<grid4,block4>>>(B_dev,A_dev, COL-1,ROW-1);		
   //PullBack del risultato
	cudaMemcpy( B_host, B_dev, Nb*sizeof(float), cudaMemcpyDeviceToHost);


// --------- Preparo Texture
	//unbind della texture
	cudaUnbindTexture ( texRef2 );
// --------- 

	//registro il secondo evento alla fine del kernel
	cudaEventRecord(T2, 0);
	cudaEventSynchronize(T2);

   //check
	//		print(B_host,ROW-1,COL-1);
	cudaEventElapsedTime(&diff_time, T1, T2);
	cout<<"Tempo esecuzione = "<<diff_time<<" ms"<<endl;



cout<<"CONDENSAZIONE VERSIONE 7 (1 sola  texture grande e la shared) versione ottimizzata"<<endl; 
	//registro il primo tempo
	cudaEventRecord(T1, 0);

// --------- Preparo Texture
	//Bindo a texture tutta la matrice in modo che e' bindato anche il vettore che mi interessa
	 cudaBindTexture(NULL, texRef2, A_dev);
// ---------



	thread_per_row = DIM_WARP; 
        block_per_row = ROW/thread_per_row + 1;
	unsigned int thread_per_col = MAX_DIM_BLOCK/DIM_WARP;

        block_per_col =  1;//imin(COL, MAX_DIM_GRID / block_per_row);

        dim3 block0(thread_per_row, thread_per_col );  
        dim3 grid0( block_per_row, block_per_col );         // 512 x 1 x 1

        cout<<"blocchi : "<< thread_per_row <<" x "<< thread_per_col <<"  x 1 "<<endl;
        cout<<"griglia : "<< block_per_row <<" x "<< block_per_col << " x 1"<<endl;



   //Kernel
	stepCondensationSimple_v7<<<grid0,block0>>>(B_dev,A_dev, COL-1,ROW-1);		
   //PullBack del risultato
	cudaMemcpy( B_host, B_dev, Nb*sizeof(float), cudaMemcpyDeviceToHost);


// --------- Preparo Texture
	//unbind della texture
	cudaUnbindTexture ( texRef2 );
// --------- 

	//registro il secondo evento alla fine del kernel
	cudaEventRecord(T2, 0);
	cudaEventSynchronize(T2);

   //check
	//		print(B_host,ROW-1,COL-1);
	cudaEventElapsedTime(&diff_time, T1, T2);
	cout<<"Tempo esecuzione = "<<diff_time<<" ms"<<endl;





   cudaFree( A_dev);
   cudaFree( B_dev);



  return 0;
}

