/*//------------------------------------------------------------------------------------------------------------
| TEST delle funzioni di base della classe (funzionalita'):
|	inizializzazione della matrice
|       print
|	inizializzazione Random
|	resize
*///------------------------------------------------------------------------------------------------------------


#include <iostream>
#include <stdio.h>
using namespace std;
#include <cstdlib>
#include <stdlib.h>     /* srand, rand */ //http://www.cplusplus.com/reference/cstdlib/rand/
#include <fstream>	//http://www.cplusplus.com/doc/tutorial/files/


#include "Src/Ausiliary/CudaCrono.cuh"
#include "Src/Cuda_FloatMatrixClass.cuh"

int main(void){

	int n1=5;
	int n2=5;
	//cout<<" #righe = ";cin>>n1;cout<<endl;
	//cout<<" #colonne = ";cin>>n2;cout<<endl;




	//Eventi per le statistiche
	cudaEvent_t T1, T2, T3, T4;
        cudaEventCreate(&T1);
	cudaEventCreate(&T2);
	cudaEventCreate(&T3);
	cudaEventCreate(&T4);
	float diff_time;

	matrice matA (n1,n2);

	cout<<"matrice iniziale con GPU"<<endl;
	cudaEventRecord(T3,0);
	matA.Gpu_Init();
	matA.sync_DeviceToHost();

	cudaEventRecord(T4,0);
  	cudaEventSynchronize(T4);
	cudaEventElapsedTime(&diff_time,T3,T4);
	cout << "tempo=" << diff_time<<"\n";
	matA.Gpu_print();

	cout<<"matrice iniziale con CPU"<<endl;
	cudaEventRecord(T1,0);
	matA.Cpu_Init();
	matA.sync_HostToDevice();
	cudaEventRecord(T2,0);
  	cudaEventSynchronize(T2);
	cudaEventElapsedTime(&diff_time,T1,T2);
	cout << "tempo=" << diff_time<<"\n";
	matA.Cpu_print();

	cout<<"matrice Hilbert con GPU"<<endl;
	cudaEventRecord(T3,0);
	matA.Gpu_Hilbert_Init();
	matA.sync_DeviceToHost();

	cudaEventRecord(T4,0);
  	cudaEventSynchronize(T4);
	cudaEventElapsedTime(&diff_time,T3,T4);
	cout << "tempo=" << diff_time<<"\n";
	matA.Gpu_print();

	cout<<"matrice Hilbert con CPU"<<endl;
	cudaEventRecord(T1,0);
	matA.Cpu_Hilbert_Init();
	matA.sync_HostToDevice();
	cudaEventRecord(T2,0);
  	cudaEventSynchronize(T2);
	cudaEventElapsedTime(&diff_time,T1,T2);
	cout << "tempo=" << diff_time<<"\n";
	matA.Cpu_print();



	cout<<"matrice iniziale random con GPU"<<endl;
	cudaEventRecord(T3,0);
	matA.Gpu_Init_Rand(0.95,1.05);
	matA.sync_DeviceToHost();

	cudaEventRecord(T4,0);
  	cudaEventSynchronize(T4);
	cudaEventElapsedTime(&diff_time,T3,T4);
	cout << "tempo=" << diff_time<<"\n";
	matA.Gpu_print();

	cout<<"matrice iniziale random con CPU"<<endl;
	cudaEventRecord(T1,0);
	matA.Cpu_Init_Rand(0.95,1.05);
	matA.sync_HostToDevice();

	cudaEventRecord(T2,0);
  	cudaEventSynchronize(T2);
	cudaEventElapsedTime(&diff_time,T1,T2);
	cout << "tempo=" << diff_time<<"\n";
	matA.Cpu_print();

	cout<<"Resize e Rinit con GPU"<<endl;
	cudaEventRecord(T3,0);
	matA.Resize(10,10);
	matA.Gpu_Init_Rand(0.95,1.05);
	matA.sync_DeviceToHost();

	cudaEventRecord(T4,0);
  	cudaEventSynchronize(T4);
	cudaEventElapsedTime(&diff_time,T3,T4);
	cout << "tempo=" << diff_time<<"\n";
	matA.Gpu_print();

	cout<<"Resize con CPU"<<endl;
	cudaEventRecord(T1,0);
	matA.Resize(10,10);
	matA.Cpu_Init_Rand(0.95,1.05);
	matA.sync_HostToDevice();

	cudaEventRecord(T2,0);
  	cudaEventSynchronize(T2);
	cudaEventElapsedTime(&diff_time,T1,T2);
	cout << "tempo=" << diff_time<<"\n";
	matA.Cpu_print();

cout<<"Commenti:\nDa questa implementazione banale dell'inizializzazione si scopre che il curand della gpu non e' particolarmente efficiente, il motivo e' imputabile alla non ideale ottimizzazione del numero di thread scelto per la chiamata del kernel."<<endl;


	cudaEventDestroy(T1);
	cudaEventDestroy(T2);
	cudaEventDestroy(T3);
	cudaEventDestroy(T4);

  return 0;
}

