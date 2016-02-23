/*//------------------------------------------------------------------------------------------------------------
| TEST funzionamento del metodo di swap necessario per il pivoting
|
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

	int n1=3;
	int n2=4;
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
	matA.Init_Rand(-5.0,5.0);
	matA.print();


	cout<<"\n SWAP RIGA 0 1, secondo la cpu"<<endl;
	cudaEventRecord(T3,0);
	matA.Cpu_Swap_Row(0,1);
	cudaEventRecord(T4,0);
  	cudaEventSynchronize(T4);
	cudaEventElapsedTime(&diff_time,T3,T4);
	matA.Cpu_print();
	cout << "tempo=" << diff_time<<"\n";

	cout<<"\n SWAP Col 0 1, secondo la cpu"<<endl;
	cudaEventRecord(T3,0);
	matA.Cpu_Swap_Col(0,1);
	cudaEventRecord(T4,0);
  	cudaEventSynchronize(T4);
	cudaEventElapsedTime(&diff_time,T3,T4);
	matA.Cpu_print();
	cout << "tempo=" << diff_time<<"\n";

	cout<<"\n SWAP RIGA 0 1, secondo la gpu"<<endl;
	cudaEventRecord(T3,0);
	matA.Gpu_Swap_Row(0,1);
	cudaEventRecord(T4,0);
  	cudaEventSynchronize(T4);
	cudaEventElapsedTime(&diff_time,T3,T4);
	matA.Gpu_print();
	cout << "tempo=" << diff_time<<"\n";

	cout<<"\n SWAP Col 0 1, secondo la gpu"<<endl;
	cudaEventRecord(T3,0);
	matA.Gpu_Swap_Col(0,1);
	cudaEventRecord(T4,0);
  	cudaEventSynchronize(T4);
	cudaEventElapsedTime(&diff_time,T3,T4);
	matA.Gpu_print();
	cout << "tempo=" << diff_time<<"\n";


  return 0;
}

