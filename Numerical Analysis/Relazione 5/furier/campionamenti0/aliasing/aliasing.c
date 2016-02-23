#include <iostream>
#include <math.h>
#include <fstream>
#include <ctime> 
#include "trasformazione_fourier_2.h"

using namespace std;


	
double h (double t) 
{
  double r, fc= 1/(2*0.1)= 5;
r=sin(2*M_PI*(fc*2)*t);
  return (r);
}



int main()
{

srand((unsigned)time(0));

double dt= 0.1; // intervallo di tempo
int N=5000; //numero di samplaggi

double h1[N], H[N];

//samplaggio
for(int i=0;i<N;i++)	{
			h1[i]=h((double)i*dt);			
			}
modH(dt ,N ,h1, H );
ofstream file("sottocampionato",ios::trunc);
	for(int i=0 ; i<N ; i++)
		{double fn =(-0.5 + (double)i/N)/dt ;	
		file<< fn <<"\t\t\t"<<H[i]<<endl;}
	file.close();

dt= 0.05;
//samplaggio
for(int i=0;i<N;i++)	{
			h1[i]=h((double)i*dt);			
			}
modH(dt ,N ,h1, H );
ofstream file1("criticocampionato",ios::trunc);
	for(int i=0 ; i<N ; i++)
		{double fn =(-0.5 + (double)i/N)/dt ;	
		file1<< fn <<"\t\t\t"<<H[i]<<endl;}
	file1.close();
dt= 0.01;
//samplaggio
for(int i=0;i<N;i++)	{
			h1[i]=h((double)i*dt);			
			}
modH(dt ,N ,h1, H );
ofstream file2("sovracampionato",ios::trunc);
	for(int i=0 ; i<N ; i++)
		{double fn =(-0.5 + (double)i/N)/dt ;	
		file2<< fn <<"\t\t\t"<<H[i]<<endl;}
	file2.close();

return(0);}
