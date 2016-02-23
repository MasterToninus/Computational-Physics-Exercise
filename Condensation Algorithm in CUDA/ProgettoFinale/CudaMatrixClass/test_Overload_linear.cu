/*//------------------------------------------------------------------------------------------------------------
| TEST funzionamento dell' overload dell'operatore * per uno scalare
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
	float lambda =0.5;
	matA.print();
	matrice matB (0);
	matB=matA;


	cout<<"\n\n A*0.5 secondo la cpu"<<endl;
	matA.Cpu_linearproduct(lambda);
	matA.Cpu_print();

	cout<<"\n\n A*0.5 secondo la Gpu"<<endl;
	matA=matB;
	matA.Gpu_linearproduct(lambda);
	matA.Gpu_print();


	cout<<"\n\n Overload A *= 0.5"<<endl;
	matA=matB;
	matA*=lambda;
	cout<<"A *= 0.5"<<endl;
	matA.print();

	cout<<"\n\n Overload A * 0.5"<<endl;
	matA=matB;
	matB=matA*lambda;
	cout<<"B = A * 0.5"<<endl;
	matB.print();



  return 0;
}

