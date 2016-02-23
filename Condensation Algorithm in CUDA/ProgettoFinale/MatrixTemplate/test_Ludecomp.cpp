#include <iostream>
#include <stdio.h>
using namespace std;
#include <cstdlib>
#include <stdlib.h>     /* srand, rand */ //http://www.cplusplus.com/reference/cstdlib/rand/
#include <fstream>	//http://www.cplusplus.com/doc/tutorial/files/


#include "MatrixTemplate.h"
#include <complex>



int main(void){
	
	int N=17;
	cin >>N;

	matrice< float > matA (N);

	matA.Init_Rand();
	matA.print_tomath("file.dat");
	matA.print();

cout<<"versione test"<<endl;
	matA.LUDecomposition();

cout<<"versione rightLooking"<<endl;
	matrice< float > matB (N);
	matB =	matA.LUDecomposition_rightlooking();
	matB.print();

cout<<"versione leftLooking"<<endl;
	matB =	matA.LUDecomposition_leftlooking();
	matB.print();

cout<<"versione crout"<<endl;
	matB =	matA.LUDecomposition_crout();
	matB.print();


  return 0;
}

