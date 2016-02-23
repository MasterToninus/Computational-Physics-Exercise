#include <iostream>
#include <math.h>
#include <fstream>

#include "problemicauchy.h"
using namespace std;




double pendolo1(double t, double x, double v) 
{double R, b=0.5, a=0.9, w0=0.666666667;
R= -b*v -sin(x) +a*cos(w0*t);
return(R);
}

double pendolo2(double t, double x, double v) 
{double R, b=0.5, a=1.07, w0=0.666666667;
R= -b*v -sin(x) +a*cos(w0*t);
return(R);
}

double pendolo3(double t, double x, double v) 
{double R, b=0.5, a=1.47, w0=0.666666667;
R= -b*v -sin(x) +a*cos(w0*t);
return(R);
}

double pendolo4(double t, double x, double v) 
{double R, b=0.5, a=1.5, w0=0.666666667;
R= -b*v -sin(x) +a*cos(w0*t);
return(R);
}

int main(){
        
	unsigned long int N=10000;	// numero di punti
	double dt=0.075;	// passo di campionatura	

	double t[N]; 	//vettori delle variabili x,y,y'
	double Th[N];
	double w[N];    

	
	t[0]=0;		//valore iniziale
    	Th[0]=M_PI/2;
	w[0] =0;
     
 



	Runge_Kutta_secondo(pendolo1,t,Th,w,dt,N);
	ofstream myfile1("dati/pendolo1",ios::trunc);
	for(unsigned long int i=0;i<N;i++){myfile1<<t[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile1.close();

	Runge_Kutta_secondo(pendolo2,t,Th,w,dt,N);
	ofstream myfile2("dati/pendolo2",ios::trunc);
	for(unsigned long int i=0;i<N;i++){myfile2<<t[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile2.close();

	Runge_Kutta_secondo(pendolo3,t,Th,w,dt,N);
	ofstream myfile3("dati/pendolo3",ios::trunc);
	for(unsigned long int i=0;i<N;i++){myfile3<<t[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile3.close();

	Runge_Kutta_secondo(pendolo4,t,Th,w,dt,N);
	ofstream myfile4("dati/pendolo4",ios::trunc);
	for(unsigned long int i=0;i<N;i++){myfile4<<t[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile4.close();

return(0);
	}
