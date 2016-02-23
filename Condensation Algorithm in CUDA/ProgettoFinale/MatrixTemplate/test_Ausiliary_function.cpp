#include <iostream>
#include <stdio.h>
using namespace std;
//#include <cstdlib>
//#include <stdlib.h>     /* srand, rand */ //http://www.cplusplus.com/reference/cstdlib/rand/
//#include <fstream>	//http://www.cplusplus.com/doc/tutorial/files/


#include "Ausiliary_Function.h"

int main(void){

	unsigned int P[5] = { 3, 2, 1, 4, 0 };
	for(int i=0; i<5;i++)cout<<P[i]<<" ";
	cout<<endl;
	int S = parity(P,5);
	for(int i=0; i<5;i++)cout<<P[i]<<" ";
	cout<<endl;
	cout<<"parita' = "<< S<<endl;	
	


  return 0;
}

