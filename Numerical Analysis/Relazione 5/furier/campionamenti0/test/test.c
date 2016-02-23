#include <iostream>
#include <math.h>
#include <fstream>

#include "trasformazione_fourier_2.h"
#include "funzioni.h"

using namespace std;

double h (double t) 
{
  double r;
r=sin(2*M_PI*(0.143)*t) + cos(2*M_PI*0.7*t) + sin(2*M_PI*0.3*t);
  return (r);
}

int main()
{
double dt= 0.5; // intervallo di tempo
int N=5000; //numero di samplaggi
double h1[N], H[N]; //saplaggio di h e di trasformata



//samplaggio
for(int i=0;i<N;i++)	{
			h1[i]=h((double)i*dt);
			}
modH (dt ,N ,h1, H );

ofstream file("sinusoidale",ios::trunc);
	for(int i=0;i<N;i++){
		double fn =(-0.5 + (double)i/N)/dt ;	
		file<< fn <<"\t\t\t"<<H[i]<<endl;}
	file.close();

//samplaggio
for(int i=0;i<N;i++)	{
			h1[i]=gaussiana((double)i*dt);
			}
modH (dt ,N ,h1, H );

ofstream file1("gaussiana",ios::trunc);
	for(int i=0;i<N;i++){
		double fn =(-0.5 + (double)i/N)/dt ;	
		file1<< fn <<"\t\t\t"<<H[i]<<endl;}
	file1.close();

//samplaggio
for(int i=0;i<N;i++)	{
			h1[i]=gradino((double)i*dt);
			}
modH (dt ,N ,h1, H );

ofstream file2("gradino",ios::trunc);
	for(int i=0;i<N;i++){
		double fn =(-0.5 + (double)i/N)/dt ;	
		file2<< fn <<"\t\t\t"<<H[i]<<endl;}
	file2.close();


return(0);}
