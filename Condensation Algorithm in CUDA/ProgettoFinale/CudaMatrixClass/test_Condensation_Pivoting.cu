/*//------------------------------------------------------------------------------------------------------------
| TEST funzionamento del metodo di pivoting (trova massimo e poi divide)
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

	cudaEvent_t T1, T2;
        cudaEventCreate(&T1);
	cudaEventCreate(&T2);
	float diff_time;

	matrice matA (n1,n2);
	matA.Init_Rand(-5.0,5.0);
	cout<<"Matrice : \n";
	matA.print();

	int pivot_idx;
	cudaEventRecord(T1,0);
	matA.Cpu_Max_Pivoting(&pivot_idx);
	cudaEventRecord(T2,0);
  	cudaEventSynchronize(T2);
	cudaEventElapsedTime(&diff_time,T1,T2);
	cout<<"Pivot secondo la cpu: A( "<<n1-1<<" , "<<pivot_idx<<" ) = "<<matA.Cpu_pick(n1-1,pivot_idx)<<endl;
	cout << "tempo=" << diff_time<<"\n";

	cudaEventRecord(T1,0);
	matA.Gpu_Max_Pivoting(&pivot_idx);
	cudaEventRecord(T2,0);
  	cudaEventSynchronize(T2);
	cudaEventElapsedTime(&diff_time,T1,T2);
	cout<<"Pivot secondo la Gpu: A( "<<n1-1<<" , "<<pivot_idx<<" ) = "<<matA.Gpu_pick(n1-1,pivot_idx)<<endl;
	cout << "tempo=" << diff_time<<"\n";

	float pivot_value;
	cudaEventRecord(T1,0);
	matA.Gpu_Max_Pivoting_Speedy(&pivot_idx, &pivot_value);
	cudaEventRecord(T2,0);
  	cudaEventSynchronize(T2);
	cudaEventElapsedTime(&diff_time,T1,T2);
	cout<<"Pivot secondo la Gpu speedy: A( "<<n1-1<<" , "<<pivot_idx<<" ) = "<<pivot_value<<endl;
	cout << "tempo=" << diff_time<<"\n";

	cout<<"Divido per il Pivot secondo la Gpu"<<endl;
	cudaEventRecord(T1,0);
	matA.Gpu_Division(pivot_idx);
	cudaEventRecord(T2,0);
  	cudaEventSynchronize(T2);
	cudaEventElapsedTime(&diff_time,T1,T2);
	cout << "tempo=" << diff_time<<"\n";
	matA.Gpu_print();

	cout<<"Divido per il Pivot secondo la Cpu"<<endl;
	cudaEventRecord(T1,0);
	matA.Cpu_Division(pivot_idx);
	cudaEventRecord(T2,0);
  	cudaEventSynchronize(T2);
	cudaEventElapsedTime(&diff_time,T1,T2);
	cout << "tempo=" << diff_time<<"\n";
	matA.Cpu_print();



  return 0;
}

