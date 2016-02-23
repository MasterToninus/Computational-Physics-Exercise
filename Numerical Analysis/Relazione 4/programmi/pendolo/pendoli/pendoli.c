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
ofstream myfile1("semplice",ios::trunc);
	for(int i=0;i<N;i++){myfile1<<t[i]<<"\t\t\t"<<Th[i]/M_PI*180<<endl;}
	myfile1.close();

Runge_Kutta_secondo(forzato,t,Th,w,dt,N);
ofstream myfile2("forzato",ios::trunc);
	for(int i=0;i<N;i++){myfile2<<t[i]<<"\t\t\t"<<Th[i]/M_PI*180<<endl;}
	myfile2.close();
	
Runge_Kutta_secondo(smorzato,t,Th,w,dt,N);
ofstream myfile3("smorzato",ios::trunc);
	for(int i=0;i<N;i++){myfile3<<t[i]<<"\t\t\t"<<Th[i]/M_PI*180<<endl;}
	myfile3.close();	
	
Runge_Kutta_secondo(completo,t,Th,w,dt,N);
ofstream myfile4("completo",ios::trunc);
	for(int i=0;i<N;i++){myfile4<<t[i]<<"\t\t\t"<<Th[i]/M_PI*180<<endl;}
	myfile4.close();	




return(0);
	}
