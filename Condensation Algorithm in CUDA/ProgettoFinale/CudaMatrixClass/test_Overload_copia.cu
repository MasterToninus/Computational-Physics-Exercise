/*//------------------------------------------------------------------------------------------------------------
| TEST funzionamento dell' overload dell'operatore =
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
	matrice matB (n1-1,n2-1);
	matB.Init();

	matA.print();
	cout<<"\t "<<endl;
	matB.print();
	cout<<"\t A = B secondo la cpu"<<endl;
	matA.Cpu_copy(matB);
	matA.Cpu_print();

	matA.Init_Rand(-5.0,5.0);
	matB.Init();
	matA.Gpu_print();
	cout<<"\t "<<endl;
	matB.Gpu_print();
	cout<<"\t B = A secondo la gpu"<<endl;
	matB.Gpu_copy(matA);
	matB.Gpu_print();

	matA.Init_Rand(-5.0,5.0);
	matB.Init();
	matA.print();
	cout<<"\t "<<endl;
	matB.print();
	cout<<"\t B = A secondo l'overload"<<endl;
	matB=(matA);
	matB.print();



  return 0;
}

