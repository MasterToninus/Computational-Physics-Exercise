#include <iostream>
#include <math.h>
#include "gauss.h"
#include "funzioni.h"
using namespace std;

int main()
{
int n=12; //ordine di gauss
double a0=0; //punto iniziale
double b0=M_PI; //punto finale
cout<<"Calcolo valore integrale di sin(x) tra "<<a0<<" e "<<b0 <<endl;

double I= IntGauss(funzC,n,a0,b0);
cout<<"\n valore integrale : "<< I<<endl;
 
int N= 100; //numero passi
I=MultiGauss(funzC,n,a0,b0,100);
cout<<"\n valore integrale : "<< I<<endl;
return(0);}
