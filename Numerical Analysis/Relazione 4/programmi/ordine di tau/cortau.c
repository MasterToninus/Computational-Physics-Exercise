#include <iostream>
#include <math.h>
#include <fstream>
#include "funzioni.h"
#include "problemicauchy.h"
using namespace std;




int main(){
        
	int N=2000;	// numero di punti
	double h=0.05;	// passo di campionatura	

	double x[N]; 	//vettori delle variabili x,y
	double y[N];   
	double dummy;
	double x0=0.;		//valore iniziale	double y0=1.;



	correttore(lineare,x0,y0,h,y,N);
    	ofstream myfile1("correttore/lineare",ios::trunc);
	for(int i=0;i<N;i++)
	{
		x[i]=x0+i*h;
		dummy=fabs(y[i]-(3*x[i]+1.));	
		myfile1<<i<<"\t\t\t"<<dummy<<endl;	}
	myfile1.close();

	correttore(quadrato,x0,y0,h,y,N);
    	ofstream myfile2("correttore/quadratico",ios::trunc);
	for(int i=0;i<N;i++)
	{
		x[i]=x0+i*h;
		dummy=fabs(y[i]-(3*pow(x[i],2)/2+1.));
		myfile2<<i<<"\t\t\t"<<dummy<<endl;	}
	myfile2.close();
	
	correttore(cubo,x0,y0,h,y,N);
    	ofstream myfile3("correttore/cubico",ios::trunc);
	for(int i=0;i<N;i++)
	{
		x[i]=x0+i*h;
		dummy=fabs(y[i]-(pow(x[i],3)+1.));
		myfile3<<i<<"\t\t\t"<<dummy<<endl;	}
	myfile3.close();


return(0);
	}
