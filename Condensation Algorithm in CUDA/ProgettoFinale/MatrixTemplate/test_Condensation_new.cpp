#include <iostream>
#include <stdio.h>
using namespace std;
#include <cstdlib>
#include <stdlib.h>     /* srand, rand */ //http://www.cplusplus.com/reference/cstdlib/rand/
#include <fstream>	//http://www.cplusplus.com/doc/tutorial/files/



#include <complex>
#include <cmath>        // std::abs
#include "Src/Ausiliary_Function.h"
#include "Src/MatrixTemplate.h"

int main(void){

	int N,max;
	cout<<"#elementi = "; cin >>N;
	cout<<"Max Size = "; cin >>max;	

	matrice< float > matA (N);
	matA.Init_Rand(max);
	matA[0][0]=0;
	matA[0][1]=0;
	matA.print();
	int k;

	cout<<"test = "<<matA.SalemSaid_Pivoting(&k)<<"\t";
	cout<<" Valore A[0]["<<k<<"]="<<matA[0][k]<<endl;

	cout<<"test = "<<matA.Max_Pivoting(&k)<<"\t";
	cout<<" Valore A[0]["<<k<<"]="<<matA[0][k]<<endl;

	matrice< float > matB (N-1);
cout<<"\n INIZIO LA PROVA DI CONDENSAZIONE_STEP!"<<endl;\
	cout<<" Salem Said!"<<endl;
	matA.Init_Rand();
	matA.print();
	cout<<"test = "<<matA.SalemSaid_Pivoting(&k)<<"\t";
	cout<<" Valore A[0]["<<k<<"]="<<matA[0][k]<<endl;
	matB = matA.Step_Condensation(k);
	matB.print();

	cout<<" Mia!"<<endl;
	cout<<"test = "<<matA.Max_Pivoting(&k)<<"\t";
	cout<<" Valore A[0]["<<k<<"]="<<matA[0][k]<<endl;
	matB = matA.Step_Condensation(k);
	matB.print();

cout<<"\n INIZIO LA PROVA DI CONDENSAZIONE COMPLETA!"<<endl;\
	cout<<" Salem Said!"<<endl;
	matA.Init_Rand();
	matA[0][0]=0;
	matA.print();
	matA.print_tomath("Output/file.dat");
	float determinante=matA.SalemSaid_Determinant();
	cout<<"Determinante = " << determinante<<endl;
	
	cout<<" Mia!"<<endl;
	matA.print();
	determinante=matA.Mia_Determinant();
	cout<<"Determinante = " << determinante<<endl;

  return 0;
}

