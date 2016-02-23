#include <iostream>
#include <math.h>
#include <fstream>
#include <cstdlib> 
#include <ctime> 
#include "mappa.h"
using namespace std;

int main()
//questo programma serve a mostratre visivamente in che punto inizia il regime caotico, stampa al variare di r sempre il 1000 step a partire dal medesimo x0, nel momento in cui il grafico incomincia ad oscillare è il caos.(le biforcazioni prima del caos non sono visibili perchè stampo sempre la millesima iterazione!)
{
unsigned long N = 2000; //numero di punti
srand((unsigned)time(0));
int n=4000000; //numero iterazioni
long double ri= 3.44947L , rf = 3.44952L ; //riniziale e rfinnale
long double k= (rf - ri)/N ;	//incrementi 
int biforcazioni = 32;
cout<<".......calcolo......"<<endl;



	FILE * pFile;
	pFile = fopen ("grafici/mappa2/seconda_biforcazione","w");

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
