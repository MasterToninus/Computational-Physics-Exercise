#include <iostream>
#include <math.h>
#include <fstream>
#include <cstdlib> 
#include <ctime> 
#include "mappa.h"
using namespace std;

int main()

{
unsigned long N = 20000; //numero di punti
srand((unsigned)time(0));
int n=20000; //numero iterazioni
long double ri= 3.845361L , rf = 3.85417L ; //riniziale e rfinnale
long double k= (rf - ri)/N ;	//incrementi 
int biforcazioni = 500;

cout<<".......calcolo......"<<endl;

	FILE * pFile;
	pFile = fopen ("grafici/mappa4/vicinocaos3","w");

  for(unsigned long i=1 ; i<=N ;i=i+1)
	{
	
	long double r= ri + k*(long double)i;
	long double x=((long double)rand()/RAND_MAX); //rispetto a prima il punto iniziale è casuale!
	
	
	x=mappalogistica(r,x,n);
	for(int j=0; j<biforcazioni; j++){
		x=mappalogistica(r,x);
		fprintf (pFile, "%21.20Lf \t %21.20Lf \n",r,x);
		}
	}
fclose (pFile);


return(0);}
