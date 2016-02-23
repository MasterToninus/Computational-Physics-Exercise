/*//------------------------------------------------------------------------------------------------------------
| TEST funzionamento dell' overload dell'operatore -
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



	matrice matA (n1,n2);
	matA.Init_Rand(-5.0,5.0);
	matrice matB (n1,n2);
	matB.Init();

	cout<<"\n\n Sottrazione secondo la cpu"<<endl;
	matA.Cpu_print();
	cout<<"\t - "<<endl;
	matB.Cpu_print();
	cout<<"\t = "<<endl;
	matA.Cpu_subtract(matB);
	matA.Cpu_print();

	cout<<"\n\n Sottrazione secondo la Gpu"<<endl;
	matA.Gpu_print();
	cout<<"\t - "<<endl;
	matB.Gpu_print();
	cout<<"\t = "<<endl;
	matA.Gpu_subtract(matB);
	matA.Gpu_print();


	matA.Init();
	matB.Init();
	cout<<"\n\n Overload -="<<endl;
	cout<<"A ="<<endl;
	matA.print();
	cout<<"B = "<<endl;
	matB.print();
	matA+=matB;
	cout<<"A -= B"<<endl;
	matA.print();

	cout<<"\n\n Overload -"<<endl;
	matrice matC(0);
	matC=matA-matB;
	cout<<"A ="<<endl;
	matA.print();
	cout<<"B = "<<endl;
	matB.print();
	cout<<"C = A - B"<<endl;
	matC.print();



  return 0;
}

