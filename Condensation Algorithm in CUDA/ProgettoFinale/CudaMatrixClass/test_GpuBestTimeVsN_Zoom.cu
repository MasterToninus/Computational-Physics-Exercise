/*//------------------------------------------------------------------------------------------------------------
| TEST del tempo d'esecuzione della routine Gpu Texture in funzione del numero N di elementi per lato
|	
|       
*///------------------------------------------------------------------------------------------------------------


#include <iostream>
#include <stdio.h>
using namespace std;
#include <cstdlib>
#include <stdlib.h>     /* srand, rand */ //http://www.cplusplus.com/reference/cstdlib/rand/
#include <fstream>	//http://www.cplusplus.com/doc/tutorial/files/


#include "Src/Ausiliary/CudaCrono.cuh"
#include "Src/Ausiliary/Statistics.h"
#include "Src/Cuda_FloatMatrixClass.cuh"

int main(void){

	int device_id =0;
	cudaSetDevice(device_id);
	cudaDeviceProp prop;
	cudaGetDeviceProperties( &prop, device_id);
	printf("Scheda Utilizzata:  %s \n\n", prop.name);

	//Parametri per il grafico
	int Nmax =600;
	int Nstep =10;
	ofstream myfile;
  	myfile.open ("Output/GpuBestTimeVsN_Zoom.dat",ofstream::app);
	int n=10;
	float Dati[n];

	float media;
	float errore;


	//Eventi per le statistiche
	cudaEvent_t T1, T2;
        cudaEventCreate(&T1);
	cudaEventCreate(&T2);
	float diff_time;



	 matrice matA (1,1);


	for(int i=50; i<Nmax; i+=Nstep){
		float pivot[i];
		for(int k=0; k<n; k++){
			matA.Resize(i,i);
 			matA.Cpu_Init_Rand(-10,10);
			matA.sync_HostToDevice();

			cudaEventRecord(T1,0);	
			matA.Gpu_Condensation_Best(pivot);
 			cudaEventRecord(T2,0);
			cudaEventSynchronize(T2);
      			cudaEventElapsedTime(&diff_time,T1,T2);
        		//cout << "tempo=" << diff_time<<"\n";
			Dati[k]=diff_time;
		}
		media = Media(Dati,n);
		errore = Errore(Dati,n, media);
		cout<< " N = "<<i<<" \t time = "<<media<< " +o- "<<errore<<endl;
		myfile <<i<<"\t"<<media<<"\t"<<errore<<endl;
	}






	myfile.close();
	cudaEventDestroy(T1);
	cudaEventDestroy(T2);

  return 0;
}

