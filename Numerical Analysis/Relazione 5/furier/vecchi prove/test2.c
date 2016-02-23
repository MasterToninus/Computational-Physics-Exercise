#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

#include "trasformazione_fourier"
using namespace std;

double funz1 (double t) 
{
  double r;
r=sin(3*t);
if(t>0 && t<1)r=1;
else r=0;
  return (r);
}

int main()
{

double dt= 0.1; // intervallo di tempo
int N=10000; //numero di samplaggi
//double T= N*dt; //periodo di samplaggio

double t[N],h[N],ReH[N], ImH[N];


for(int i=0;i<N;i++)	{
			t[i]= i*dt;
			h[i]=funz1(t[i]);
			}

for(int i=0;i<N;i++)	{
			int n= -N/2+i;
			double fn= n/(N*dt);
			ReH[i]=H_fn_Re (N,dt,fn,h);
			ImH[i]=H_fn_im  (N,dt,fn,h);
			}



ofstream file("trasformata.txt");
	for(int i=0;i<N;i++){
	double mod=sqrt(ReH[i]*ReH[i] + ImH[i]*ImH[i]);
	int n= -N/2+i;
	double fn= n/(N*dt);
	file<<fn<<"\t"<<mod<<endl;}
	file.close();



return(0);}
