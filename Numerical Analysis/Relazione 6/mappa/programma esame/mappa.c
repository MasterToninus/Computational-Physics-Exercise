#include <iostream>
#include <math.h>
#include <fstream>
#include <cstdlib> 
#include <ctime> 
#include "mappa.h"
using namespace std;

int main()

{
unsigned long N = 500000; //numero di punti del grafico
int n=10000; //numero iterazioni della mappa
long double ri= 3.56L , rf = 3.58L ; //Riniziale e Rfinnale
long double xmin = 0.2L ; xmax = 0.8L; // intervallo di ordinate considerata nel grafico
long double k= (rf - ri)/N ;	//incrementi 

srand((unsigned)time(0));
int biforcazioni = 256; // numero di punti stampati per lo stesso valore di r

cout<<".......calcolo......"<<endl;

	FILE * pFile;
	pFile = fopen ("grafico/mappa_logistica","w");

  for(unsigned long i=1 ; i<=N ;i=i+1)
	{
	long double r= ri + k*(long double)i;
	long double x=((long double)rand()/RAND_MAX); //il punto iniziale è casuale!
	
	x=mappalogistica(r,x,n);
	int j=0;
	while( j<biforcazioni){
		x=mappalogistica(r,x);
		if(x < xmax && x > xmin){fprintf (pFile, "%21.20Lf \t %21.20Lf \n",r,x);j++;}
		}
	}
fclose (pFile);
return(0);}
