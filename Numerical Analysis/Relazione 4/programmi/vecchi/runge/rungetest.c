#include <iostream>
#include <math.h>
#include <fstream>
#include "funzioni.h"
#include "problemicauchy.h"
using namespace std;

//http://www.ba.infn.it/~zito/museo/frame4.html
//http://gerlos.altervista.org/primi-passi-gnuplot
//http://complex.umd.edu/~dpl/phy374/jay/pendulum.html



int main(){
        
	int N=2000;	// numero di punti
	double dt=0.05;	// passo di campionatura	

	double t[N]; 	//vettori delle variabili x,y,y'
	double Th[N];
	double w[N];    

	t[0]=0;		//valore iniziale
    	Th[0]=(M_PI)*0.25;
	w[0] =0;

	Runge_Kutta_secondo(F,t,Th,w,dt,N);
    	ofstream myfile("pendolo_RK",ios::trunc);
	for(int i=0;i<N;i++){	myfile<<t[i]<<"\t\t\t"<<Th[i]<<endl;	}
	myfile.close();

	eulero(F,t,Th,w,dt,N);
    	ofstream myfile2("pendolo_eulero",ios::trunc);
	for(int i=0;i<N;i++){	myfile2<<t[i]<<"\t\t\t"<<Th[i]<<endl;	}
	myfile2.close();
	
	double Y[N];
	double x0=0,y0=0;
	double h=0.05;

	ofstream myfile1("grafici/2_1.txt");
	Runge4(funz,x0,y0,h,Y,N);
    
	for(int i=0;i<N;i++){	myfile1<<x0+i*h<<"\t\t\t"<<Y[i]<<endl;	}
	myfile1.close();
	
	eulero(funz,x0,y0,h,Y,N);
    	ofstream myfile4("grafici/2_2.txt",ios::trunc);
	for(int i=0;i<N;i++){	myfile4<<x0+i*h<<"\t\t\t"<<Y[i]<<endl;	}
	myfile4.close();

return(0);
	}
