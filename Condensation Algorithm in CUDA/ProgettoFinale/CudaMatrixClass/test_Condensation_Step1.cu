/*//------------------------------------------------------------------------------------------------------------
| TEST tempistiche del metodo di Step di condensazione per matrici pivotizzate, ovvero con elemento angolo basso destra =1
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

	int device_id =0;
	cudaSetDevice(device_id);
	cudaDeviceProp prop;
	cudaGetDeviceProperties( &prop, device_id);
	printf("Scheda Utilizzata:  %s \n\n", prop.name);

	int n=5000;

	cudaEvent_t T1, T2;
        cudaEventCreate(&T1);
	cudaEventCreate(&T2);
	float diff_time;


	matrice matA (n);
	matA.Init();
	matA[n-1][n-1]=1;
	matA.sync_HostToDevice();
	//matA.print();


	cout<<"\n Condensation step secondo la cpu "<<endl;
	cudaEventRecord(T1,0);
	matA.Cpu_Step_Condensation_Simple();
	cudaEventRecord(T2,0);
  	cudaEventSynchronize(T2);
	cudaEventElapsedTime(&diff_time,T1,T2);
	//matA.Cpu_print();
	cout << "tempo=" << diff_time<<"\n";

	cout<<"\n Condensation step secondo la Gpu"<<endl;
	matrice matB (n);
	matB.Init();
	matB[n-1][n-1]=1;
	matB.sync_HostToDevice();
	//matB.print();
	cudaEventRecord(T1,0);
	matB.Gpu_Step_Condensation_Simple();
	cudaEventRecord(T2,0);
  	cudaEventSynchronize(T2);
	cudaEventElapsedTime(&diff_time,T1,T2);
	//matB.Gpu_print();
	cout << "tempo=" << diff_time<<"\n";




	cout<<"\n Condensation step secondo la Gpu (texture ver.)"<<endl;
	matrice matC (n);
	matC.Init();
	matC[n-1][n-1]=1;
	matC.sync_HostToDevice();
	//matC.print();
	cudaEventRecord(T1,0);
	matC.Gpu_Step_Condensation_Simple_Best();
	cudaEventRecord(T2,0);
  	cudaEventSynchronize(T2);
	cudaEventElapsedTime(&diff_time,T1,T2);
	//matC.Gpu_print();
	cout << "tempo=" << diff_time<<"\n";



	cudaEventDestroy(T1);
	cudaEventDestroy(T2);

  return 0;
}

