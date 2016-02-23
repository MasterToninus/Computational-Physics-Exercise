#include <iostream>
#include <math.h>
#include <fstream>
#include <cstdlib> 
#include <ctime> 
#include "mappa.h"
using namespace std;

int main()

{
unsigned long N = 500000; //numero di punti
srand((unsigned)time(0));
int n=10000; //numero iterazioni
long double ri= 3.56L , rf = 3.58L ; //riniziale e rfinnale
long double k= (rf - ri)/N ;	//incrementi 

long double x=((long double)rand()/RAND_MAX),y; //rispetto a prima il punto iniziale è casuale!
	
	
	


cout<<".......calcolo......"<<endl;

	FILE * pFile;
	pFile = fopen ("grafici/mappa7/zoomcaos","w");

  for(unsigned long i=1 ; i<=N ;i=i+1)
	{
	
	long double r= ri + k*(long double)i;
	y=mappalogistica(r,x,n);
		fprintf (pFile, "%21.20Lf \t %21.20Lf \n",r,y);
	}
fclose (pFile);


return(0);}
