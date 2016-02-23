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



	Runge4(lineare,x0,y0,h,y,N);
    	ofstream myfile("kutta/lineare",ios::trunc);
	for(int i=0;i<N;i++)
	{
		x[i]=x0+i*h;
		dummy=fabs(y[i]-(3*x[i]+1.));	
		myfile<<i<<"\t\t\t"<<dummy<<endl;	}
	myfile.close();

	Runge4(quadrato,x0,y0,h,y,N);
    	ofstream myfile1("kutta/quadratico",ios::trunc);
	for(int i=0;i<N;i++)
	{
		x[i]=x0+i*h;
		dummy=fabs(y[i]-(3*pow(x[i],2)/2+1.));
		myfile1<<i<<"\t\t\t"<<dummy<<endl;	}
	myfile1.close();
	
	Runge4(cubo,x0,y0,h,y,N);
    	ofstream myfile2("kutta/cubico",ios::trunc);
	for(int i=0;i<N;i++)
	{
		x[i]=x0+i*h;
		dummy=fabs(y[i]-(pow(x[i],3)+1.));
		myfile2<<i<<"\t\t\t"<<dummy<<endl;	}
	myfile2.close();

	Runge4(quarto,x0,y0,h,y,N);
    	ofstream myfile3("kutta/quarto",ios::trunc);
	for(int i=0;i<N;i++)
	{
		x[i]=x0+i*h;
		dummy=fabs(y[i]-(pow(x[i],4)*(3./4.)+1.));
		myfile3<<i<<"\t\t\t"<<dummy<<endl;	}
	myfile3.close();

	Runge4(quinto,x0,y0,h,y,N);
    	ofstream myfile4("kutta/quinto",ios::trunc);
	for(int i=0;i<N;i++)
	{
		x[i]=x0+i*h;
		dummy=fabs(y[i]-(pow(x[i],5)*(3./5.)+1.));
		myfile4<<i<<"\t\t\t"<<dummy<<endl;	}
	myfile4.close();


return(0);
	}
