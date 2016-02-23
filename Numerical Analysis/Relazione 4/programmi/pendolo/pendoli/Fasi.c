#include <iostream>
#include <math.h>
#include <fstream>

#include "problemicauchy.h"
using namespace std;

double semplice(double t, double x, double v) 
{double R, g=9.8;
	
R= -(g)*(sin(x));
return(R);
}

double smorzato(double t, double x, double v) 
{double R, A=0.25, g=9.8;
	
R= -(A)*v-(g)*(sin(x));
return(R);
}

double forzato(double t, double x, double v) 
{double R, g=9.8, F0=1.5, W=0.66;
	
R=-(g)*(sin(x))+F0*cos(W*t);
return(R);
}

double completo(double t, double x, double v) 
{double R, A=0.25, g=9.8, F0=1.5, W=0.66;
	
R= -(A)*v-(g)*(sin(x))+F0*cos(W*t);
return(R);
}

void normalizza(double *Th, int N) 
{	//normalizzazione a pigreco
	for(int i=0;i<N;i++){
	double f= floor((Th[i])/(2*M_PI)+0.5);// parte intera di angolo + pi diviso 2 pi
	Th[i]=Th[i]-f*2*M_PI;};
}


int main(){
        
	int N=30000;	// numero di punti
	double dt=0.001;	// passo di campionatura	

	double t[N]; 	//vettori delle variabili x,y,y'
	double Th[N];
	double w[N];    

	t[0]=0;		//valore iniziale
    	Th[0]=(M_PI)/4;
	w[0] =0;
     
Runge_Kutta_secondo(semplice,t,Th,w,dt,N);
normalizza(Th,N);
ofstream myfile1("semplicefasi",ios::trunc);
	for(int i=0;i<N;i++){myfile1<<Th[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile1.close();

	
Runge_Kutta_secondo(forzato,t,Th,w,dt,N);
	normalizza(Th,N);
	ofstream myfile2("forzatofasi",ios::trunc);
	for(int i=0;i<N;i++){myfile2<<Th[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile2.close();	



Runge_Kutta_secondo(smorzato,t,Th,w,dt,N);
	normalizza(Th,N);
	ofstream myfile3("smorzatofasi",ios::trunc);
	for(int i=0;i<N;i++){myfile3<<Th[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile3.close();

Runge_Kutta_secondo(completo,t,Th,w,dt,N);
	normalizza(Th,N);
	ofstream myfile4("completofasi",ios::trunc);
	for(int i=0;i<N;i++){myfile4<<Th[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile4.close();

 



return(0);
	}
