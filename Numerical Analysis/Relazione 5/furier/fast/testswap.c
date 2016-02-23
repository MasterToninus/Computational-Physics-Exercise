#include <iostream>
#include <math.h>
#include <fstream>

#include "FFT.h"

using namespace std;

int main()
{
unsigned long nn=8, NN= (nn << 1) +1; // se ho 8 punti campionati devo avere 8*2 +1 cifre double per storarli in un array

double X[NN], Y[NN];


for(unsigned long i=0;i<NN;i++){ X[i]= (double)i ; Y[i]= (double)i;}


bitreverse( Y , nn);


cout << "\n" << endl;
for(unsigned long i=1;i<NN;i++)	cout << X[i] << "\t\t\t" << Y[i] << endl;


return(0);}
