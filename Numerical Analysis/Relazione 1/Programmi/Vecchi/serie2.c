#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;


float rovescio(long int N)
	{
	float sum2=0;
	for(unsigned int j=0 ; j<=N-1 ;j=j+1)
		{
		float i= (float)(N-j);
		float a= 1/((float)i*i);
		sum2= sum2+a;
		}
	}

int main()
{
cout<<".......studio del resto della serie......"<<endl;
unsigned int N = 1000000; //massimo intero per cui calcolo la somma

const double Pi=3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679L;
double result=(Pi*Pi)/6;//valore atteso

cout<<".......calcolo......"<<endl;


	FILE * pFile;
	pFile = fopen ("grafici/sommatoria","w");

float sum1=0;
for(unsigned int i=1 ; i<=N ;i=i+1)
{
float a= 1/((double)i*i);
sum1= sum1+a;
float resto = fabs(result-sum1);
fprintf (pFile, "%d \t %21.20Lf \n",i,resto;
}

	FILE * pFile1;
	pFile1 = fopen ("grafici/sommatoria_rovescio","w");
	
float sum2=0;
for(unsigned int i=1 ; i<=N ;i=i+1)
{
sum2 = rovescio(i);
float resto = fabs(result-sum1);

fprintf (pFile, "%d \t %21.20Lf \n",i,resto);
}



return(0);}
