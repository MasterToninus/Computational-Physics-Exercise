#include <iostream>
#include <stdio.h>
using namespace std;
#include <cstdlib>
#include <stdlib.h>     /* srand, rand */ //http://www.cplusplus.com/reference/cstdlib/rand/
#include <fstream>	//http://www.cplusplus.com/doc/tutorial/files/


#include "MatrixTemplate.h"
#include <complex>

int main(void){

	int n1=5;
	int n2=4;
	cout<<"matrice iniziale #righe ="<<n1<<" #colonne = "<<n2<<endl;
	matrice< complex<float> > matA (n1,n2);
	matA.Init_Rand(15);
	matA.print();

	n1=2;n2=1;
	cout<<"eliminazione riga "<<n1<<" colonna "<<n2<<endl;
	matrice< complex<float> > matB = matA.minor_submatrix(n1,n2);
 	matB.print();

	cout<<"Swap delle colonne "<<n1<<" e "<<n2<<endl;
	matB = matB.swap_column(n1,n2);
 	matB.print();

	cout<<"Swap delle righe "<<n1<<" e "<<n2<<endl;
	matB = matB.swap_row(n1,n2);
 	matB.print();



/*	matrice<int> matB = matA;

	matrice<int> mat1 = matA.transpose();
	matrice<int> mat2 = mat1;
	mat1.print();

        mat1*=matA;
	mat1.print();

	matB= mat2*matA;
	matB.print();
	cout<<"elemento [1][0] ="<<matB[1][0]<<endl;
*/


  return 0;
}

