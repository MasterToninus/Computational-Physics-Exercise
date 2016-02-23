#include <iostream>
#include <math.h>
#include <fstream>
#include <ctime> 
#include "trasformazione_fourier_2.h"

using namespace std;


	
void sampling(double (*F)(double),double x0,double dx,int N,double *x, double *y)
	{
	for(int i=0; i<N; i++)
		{
		x[i]=x0+i*dx;
		y[i]=F(x[i]);
		}
	}

double h (double t) 
{
  double r;
r=sin(2*M_PI*(0.143)*t) + ((double)rand()/RAND_MAX-0.5)*0.05;
  return (r);
}



int main()
{

srand((unsigned)time(0));

double dt= 0.2; // intervallo di tempo
int N=5000; //numero di samplaggi

double h1[N],h1fitto[N];

//samplaggio
for(int i=0;i<N;i++)	{
			h1[i]=h((double)i*dt);
			h1fitto[i]=h((double)i*dt/10);
			}
ofstream file1("rumore",ios::trunc);
for(int i=0;i<N;i++){			
		double tn =(double)i*dt/10 ;
		file1<<tn<<"\t\t\t"<<h1fitto[i] + 0.1<<endl;}
file1.close();


double H[N];
trasf_antitrasf(dt ,N ,h1, H );
ofstream file("filtro",ios::trunc);
	for(int i=0;i<N;i++){
		double tn =(double)i*dt ;
		file<< tn <<"\t\t\t"<< H[i] - 0.1 <<endl;}
	file.close();


return(0);}
