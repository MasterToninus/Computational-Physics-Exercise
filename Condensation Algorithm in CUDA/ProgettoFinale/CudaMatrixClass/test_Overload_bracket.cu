/*//------------------------------------------------------------------------------------------------------------
| TEST funzionamento dell' overload dell'operatore [] per uno scalare
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
	matA.print();

	cout<<"\t elemento (1,1) secondo la cpu "<<matA.Cpu_pick(1,1)<<endl;
	cout<<"\t elemento (1,1) secondo la gpu "<<matA.Gpu_pick(1,1)<<endl;
	cout<<"\t elemento (1,1) secondo [][]  " <<matA[1][1]<<endl;



  return 0;
}

