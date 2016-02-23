#include <iostream>
#include <math.h>
#include <fstream>
#include <cstdlib> 
#include <ctime> 
#include "mappa.h"
using namespace std;

int main()

{

srand((unsigned)time(0));

int n=50000; //numero iterazioni della mappa
long double r=4L ; //riniziale e rfinnale
long double x=((long double)rand()/RAND_MAX); //punto iniziale è casuale!
x=mappalogistica(r,x,n);	// calcolo i primi 100000 giusto per controllare di non avere problemi di convergenza
	
	
unsigned long N = 1000000; //numero di punti
int D = 5000; // numero colonne istogramma
unsigned long isto[D];for(int i=0; i<D; i++)isto[i]=0; //azzeramento vettore dell istogramma
long double h=1/(double)D; //larghezza colonne

	

  for(unsigned long i=1 ; i<=N ;i=i+1)
	{
	x=mappalogistica(r,x);
	for(int j=0; j<D; j++)if( x > h*j && x <= h*(j+1)){isto[j] = isto[j] +1;break;}	
	}
	
FILE * pFile;
pFile = fopen ("grafici/mappacaos/superisto","w");
for(int j=0; j<D; j++)fprintf (pFile, "%21.20Lf \t %21.20f \n",((double)j+0.5L)*h,(double)isto[j]/N);
fclose (pFile);


return(0);}
