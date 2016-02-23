/*//------------------------------------------------------------------------------------------------------------
| TEST funzionamento del metodo di Condensazione Completo
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

	int n=10;

	cudaEvent_t T1, T2;
        cudaEventCreate(&T1);
	cudaEventCreate(&T2);
	float diff_time;


	matrice matA (n);
	matA.Init_Rand(-10,10);
	matA[n-1][n-1]=1;
	matA[0][1]=0;
	matA.sync_HostToDevice();
	matA.print();
	matA.print_tomath("Output/file.dat");

	float pivot[n];
	float result;

	cout<<"\n Condensation Procedura Secondo la CPU"<<endl;
	cudaEventRecord(T1,0);
	matA.Cpu_Condensation(pivot);
	cudaEventRecord(T2,0);
  	cudaEventSynchronize(T2);
	cudaEventElapsedTime(&diff_time,T1,T2);
	cout << "tempo=" << diff_time<<"\n";
	for(int i=0; i<n;i++)cout<<pivot[i]<<endl;

//	matA.print();
	result=matA.Cpu_Determinant_Condensation();
	cout<<"\n Determinante ="<<result<<endl;

	matA.sync_DeviceToHost();

	cout<<"\n Condensation Procedura Secondo la GPU "<<endl;
	cudaEventRecord(T1,0);
	matA.Gpu_Condensation(pivot);
	cudaEventRecord(T2,0);
  	cudaEventSynchronize(T2);
	cudaEventElapsedTime(&diff_time,T1,T2);
	cout << "tempo=" << diff_time<<"\n";
//	matA.print();
	result=matA.Gpu_Determinant_Condensation();
	cout<<"\n Determinante ="<<result<<endl;
	for(int i=0; i<n;i++)cout<<pivot[i]<<endl;

	matA.sync_HostToDevice();

	cout<<"\n Condensation Procedura Secondo la GPU  (versione TEXTURE)"<<endl;
	cudaEventRecord(T1,0);
	matA.Gpu_Condensation_Best(pivot);
	cudaEventRecord(T2,0);
  	cudaEventSynchronize(T2);
	cudaEventElapsedTime(&diff_time,T1,T2);
	cout << "tempo=" << diff_time<<"\n";
//	matA.print();
	result=matA.Gpu_Determinant_Condensation_Best();
	cout<<"\n Determinante ="<<result<<endl;
	for(int i=0; i<n;i++)cout<<pivot[i]<<endl;




  return 0;
}

