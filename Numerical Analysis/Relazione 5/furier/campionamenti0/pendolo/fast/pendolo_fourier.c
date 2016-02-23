#include <iostream>
#include <math.h>
#include <fstream>

#include "FFT.h"
#include "problemicauchy.h"
using namespace std;


double linearizzato(double t, double x, double v) 
{double R;
R= -x;
return(R);
}

double semplice(double t, double x, double v) 
{double R, b=0, a=0, w0=0;
R= -b*v -sin(x) +a*cos(w0*t);
return(R);
}

double smorzato(double t, double x, double v) 
{double R, b=0.5, a=0, w0=0;
R= -b*v -sin(x) +a*cos(w0*t);
return(R);
}

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
        
	unsigned long int nn=131072;	// numero di punti
	double dt=0.05;	// passo di campionatura	

	double t[nn]; 	//vettori delle variabili x,y,y'
	double Th[nn];
	double w[nn];    

	unsigned long  int N = (nn << 1) +1;
	double h[N]; // vettori per la fft
	double  H[nn];
	
	unsigned long int hn = nn >> 1;
	
	t[0]=0;		//valore iniziale
    	Th[0]=M_PI/2;
	w[0] =0;
     
 



	Runge_Kutta_secondo(pendolo4,t,Th,w,dt,nn);
	for(unsigned long  i=0, j=1 ; i<nn ; i++ , j=j+2){h[j] = w[i];	h[j+1] = 0;}
	FFT( h , nn , 1);
	for(unsigned long  i=0, j=1 ; i<nn ; i++ , j=j+2)H[i]= sqrt( h[j]*h[j] + h[j+1]*h[j+1])*dt;
	
	ofstream file("Dati/spettro_pendolo4",ios::trunc);
	//frequenza positive 
	for(unsigned long  int i=0 ; i<=hn ; i++)
		{double fn =	(double) i/((double)nn*dt) ;	
		file<< fn <<"\t\t\t"<<H[i]<<endl;}
	file.close();

return(0);
	}
