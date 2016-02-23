#include <iostream>
#include <math.h>
#include <fstream>
#include "mappa.h"
using namespace std;

//grafici con vari r dell'andamento della funzione logistica in funzione del cambiamento della variabile x0 in ingresso
int main()
{
cout<<".......calcolo......"<<endl;
int N = 1000; //suddivisione intervallo
long double h= 1./N; //campionamento grafico 
double r;//parametro di evoluzione

r=2.99;
ofstream myfile1;
myfile1.open ("grafici/mappa1/r=2/n=1");
for(int i=1 ; i<=N ;i=i+1)
	{
	double x0= h*i;
	double x1=mappalogistica(r,x0);
	myfile1<<x0<<"\t"<<x1<<endl;
	}
myfile1.close();
myfile1.open ("grafici/mappa1/r=2/n=2");
for(int i=1 ; i<=N ;i=i+1)
	{
	double x0= h*i;
	double x1=mappalogistica(r,x0);
	x1=mappalogistica(r,x1);
	myfile1<<x0<<"\t"<<x1<<endl;
	}
myfile1.close();
myfile1.open ("grafici/mappa1/r=2/n=3");
for(int i=1 ; i<=N ;i=i+1)
	{
	double x0= h*i;
	double x1=mappalogistica(r,x0);
	x1=mappalogistica(r,x1);
	x1=mappalogistica(r,x1);
	myfile1<<x0<<"\t"<<x1<<endl;
	}
myfile1.close();
myfile1.open ("grafici/mappa1/r=2/n=4");
for(int i=1 ; i<=N ;i=i+1)
	{
	double x0= h*i;
	double x1=mappalogistica(r,x0);
	x1=mappalogistica(r,x1);
	x1=mappalogistica(r,x1);
	x1=mappalogistica(r,x1);
	myfile1<<x0<<"\t"<<x1<<endl;
	}
myfile1.close();
 
r=3.2;
myfile1.open ("grafici/mappa1/r=3/n=1");
for(int i=1 ; i<=N ;i=i+1)
	{
	double x0= h*i;
	double x1=mappalogistica(r,x0);
	myfile1<<x0<<"\t"<<x1<<endl;
	}
myfile1.close();
myfile1.open ("grafici/mappa1/r=3/n=2");
for(int i=1 ; i<=N ;i=i+1)
	{
	double x0= h*i;
	double x1=mappalogistica(r,x0);
	x1=mappalogistica(r,x1);
	myfile1<<x0<<"\t"<<x1<<endl;
	}
myfile1.close();
myfile1.open ("grafici/mappa1/r=3/n=3");
for(int i=1 ; i<=N ;i=i+1)
	{
	double x0= h*i;
	double x1=mappalogistica(r,x0);
	x1=mappalogistica(r,x1);
	x1=mappalogistica(r,x1);
	myfile1<<x0<<"\t"<<x1<<endl;
	}
myfile1.close();
myfile1.open ("grafici/mappa1/r=3/n=4");
for(int i=1 ; i<=N ;i=i+1)
	{
	double x0= h*i;
	double x1=mappalogistica(r,x0);
	x1=mappalogistica(r,x1);
	x1=mappalogistica(r,x1);
	x1=mappalogistica(r,x1);
	myfile1<<x0<<"\t"<<x1<<endl;
	}
myfile1.close();

r=3.5;
myfile1.open ("grafici/mappa1/r=3,5/n=1");
for(int i=1 ; i<=N ;i=i+1)
	{
	double x0= h*i;
	double x1=mappalogistica(r,x0);
	myfile1<<x0<<"\t"<<x1<<endl;
	}
myfile1.close();
myfile1.open ("grafici/mappa1/r=3,5/n=2");
for(int i=1 ; i<=N ;i=i+1)
	{
	double x0= h*i;
	double x1=mappalogistica(r,x0);
	x1=mappalogistica(r,x1);
	myfile1<<x0<<"\t"<<x1<<endl;
	}
myfile1.close();
myfile1.open ("grafici/mappa1/r=3,5/n=3");
for(int i=1 ; i<=N ;i=i+1)
	{
	double x0= h*i;
	double x1=mappalogistica(r,x0);
	x1=mappalogistica(r,x1);
	x1=mappalogistica(r,x1);
	myfile1<<x0<<"\t"<<x1<<endl;
	}
myfile1.close();
myfile1.open ("grafici/mappa1/r=3,5/n=4");
for(int i=1 ; i<=N ;i=i+1)
	{
	double x0= h*i;
	double x1=mappalogistica(r,x0);
	x1=mappalogistica(r,x1);
	x1=mappalogistica(r,x1);
	x1=mappalogistica(r,x1);
	myfile1<<x0<<"\t"<<x1<<endl;
	}
myfile1.close();

return(0);}
