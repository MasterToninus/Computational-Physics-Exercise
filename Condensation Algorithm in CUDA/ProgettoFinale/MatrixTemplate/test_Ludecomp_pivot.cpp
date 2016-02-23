#include <iostream>
#include <stdio.h>
using namespace std;
#include <cstdlib>
#include <stdlib.h>     /* srand, rand */ //http://www.cplusplus.com/reference/cstdlib/rand/
#include <fstream>	//http://www.cplusplus.com/doc/tutorial/files/


#include "MatrixTemplate.h"
#include <complex>
#include <cmath>        // std::abs



int main(void){
	
	int N=17;
	cin >>N;

	matrice< float > matA (N);

	matA.Init_Rand();
	matA.print_tomath("file.dat");
	matA.print();
	
	int n1=0;
	cout<<"il massimo della colonna "<<n1<<" e' l'elemento = "<<matA.max_incolumn_rowindex(n1)<<endl;



cout<<"versione test"<<endl;
	int P[N];
	int sign;
	
	matrice< float > matB (N);
	matB =	matA.LUDecomposition_rightlooking_Pivot(P,sign);
	matB.print();

	cout<<"parita' = "<<sign<<endl;
	for(int j=0 ; j<N ; j++)cout<<P[j]<<" , ";

	cout<<"\n Permutazione"<<endl;
	matrice< float > matC (N);
	matC =matA.permutation_row(P);
	matC.print();
	
	

  return 0;
}

