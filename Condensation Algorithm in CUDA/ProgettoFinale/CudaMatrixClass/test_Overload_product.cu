#include <iostream>
#include <stdio.h>
using namespace std;
#include <cstdlib>
#include <stdlib.h>     /* srand, rand */ //http://www.cplusplus.com/reference/cstdlib/rand/
#include <fstream>	//http://www.cplusplus.com/doc/tutorial/files/


#include "Src/Ausiliary/CudaCrono.cuh"
#include "Src/Cuda_FloatMatrixClass.h"

int main(void){

	int n1=3;
	int n2=4;
	//cout<<" #righe = ";cin>>n1;cout<<endl;
	//cout<<" #colonne = ";cin>>n2;cout<<endl;



	matrice matA (n1,n2);
	matA.Cpu_Init();
	matA.print();
	matrice matB (n2,n1-1);
	matB.Cpu_Init();
	matB.print();
	matA.Cpu_matrixproduct(matB);
	matA.print();
	matA.Gpu_print();
	








  return 0;
}

