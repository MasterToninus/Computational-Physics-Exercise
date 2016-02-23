#include <iostream>
#include <math.h>
#include <fstream>
#include <cstdlib> 
#include <ctime> 
#include "mappa.h"
using namespace std;

int main()

{
unsigned long N = 5000; //numero di punti
srand((unsigned)time(0));
int n=100000; //numero iterazioni
long double ri= 3.445L , rf = 3.57L ; //riniziale e rfinnale
long double xmin= 0.3L , xmax = 0.6L ;


long double k= (rf - ri)/N ;	//incrementi 
int biforcazioni = 64;




cout<<".......calcolo zoom1......"<<endl;

	FILE * pFile;
	pFile = fopen ("grafici/mappa6/zoom1","w");

  for(unsigned long i=1 ; i<=N ;i=i+1)
	{
	
	long double r= ri + k*(long double)i;
	long double x=((long double)rand()/RAND_MAX); //rispetto a prima il punto iniziale è casuale!
	

	x=mappalogistica(r,x,n);
	int j=0;
	while( j<biforcazioni){
		x=mappalogistica(r,x);
		if(x < xmax && x > xmin){fprintf (pFile, "%21.20Lf \t %21.20Lf \n",r,x);j++;}
		}
	}
fclose (pFile);

cout<<".......calcolo zoom2......"<<endl;
	FILE * pFile2;
	pFile2 = fopen ("grafici/mappa6/zoom2","w");

	ri= 3.5435L , rf = 3.57L ;
	xmin= 0.46L , xmax = 0.58L ;
	k= (rf - ri)/N ;

  for(unsigned long i=1 ; i<=N ;i=i+1)
	{
	
	long double r= ri + k*(long double)i;
	long double x=((long double)rand()/RAND_MAX); //rispetto a prima il punto iniziale è casuale!
	

	x=mappalogistica(r,x,n);
	int j=0;
	while( j<biforcazioni){
		x=mappalogistica(r,x);
		if(x < xmax && x > xmin){fprintf (pFile2, "%21.20Lf \t %21.20Lf \n",r,x);j++;}
		}
	}
fclose (pFile2);

cout<<".......calcolo zoom3......"<<endl;
	FILE * pFile3;
	pFile3 = fopen ("grafici/mappa6/zoom3","w");

	ri= 3.5635L , rf = 3.57L ;
	xmin= 0.47L , xmax = 0.51L ;
	k= (rf - ri)/N ;

  for(unsigned long i=1 ; i<=N ;i=i+1)
	{
	
	long double r= ri + k*(long double)i;
	long double x=((long double)rand()/RAND_MAX); //rispetto a prima il punto iniziale è casuale!
	

	x=mappalogistica(r,x,n);
	int j=0;
	while( j<biforcazioni){
		x=mappalogistica(r,x);
		if(x < xmax && x > xmin){fprintf (pFile3, "%21.20Lf \t %21.20Lf \n",r,x);j++;}
		}
	}
fclose (pFile3);

cout<<".......calcolo zoom4......"<<endl;
	FILE * pFile4;
	pFile4 = fopen ("grafici/mappa6/zoom4","w");

	ri= 3.5687L , rf = 3.57L ;
	xmin= 0.495L , xmax = 0.512L ;
	k= (rf - ri)/N ;

  for(unsigned long i=1 ; i<=N ;i=i+1)
	{
	
	long double r= ri + k*(long double)i;
	long double x=((long double)rand()/RAND_MAX); //rispetto a prima il punto iniziale è casuale!
	

	x=mappalogistica(r,x,n);
	int j=0;
	while( j<biforcazioni){
		x=mappalogistica(r,x);
		if(x < xmax && x > xmin){fprintf (pFile4, "%21.20Lf \t %21.20Lf \n",r,x);j++;}
		}
	}
fclose (pFile3);

return(0);}
