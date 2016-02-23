#include <cstdlib> 
#include <iostream>
#include <ctime> 
#include <fstream>
#include <math.h>
#include "integrazioneMonteCarlo.h"
#include "funzione1.h"
using namespace std;

//test per montecarlo
int main()
{

int N=10000; 
double a0=0; //punto iniziale
double b0=M_PI; //punto finale
double min=0;
double max=1;


double I=MonteCarlo(funzC,a0,b0,min,max,N);


cout<<"\nArea seno da\t"<<a0<<"\t"<<b0<<"\t"<<I<<endl;
cout<<I-2<<endl;

a0=0; //punto iniziale
b0=3*M_PI/2; //punto finale
min=-1;
max=1;

I=MonteCarlo(funzC,a0,b0,min,max,N);


cout<<"\nArea seno da\t"<<a0<<"\t"<<b0<<"\t"<<I<<endl;
cout<<I-1<<"\n "<<endl;


return(0);}
