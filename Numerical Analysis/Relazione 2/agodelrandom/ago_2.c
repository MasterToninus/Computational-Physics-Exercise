#include <iostream>
#include <math.h>
#include <cstdlib> 
#include <iostream>
#include <ctime> 
#include <fstream>
#include "ago.h"
using namespace std;

//sul errore statistico stampo la deviazione standard sulla media  in funzione dei numero di lanci di cui è composto l'esperimento
//GRAFICO DELLA DEVIAZIONE STANDARD

int main()
{

srand((unsigned)time(0));

double k= 0.5; // k=R/T
double K= 500; // #° esperimenti

ofstream myfile("ago_2.txt",ios::trunc);
// N= numero dei lanci!
for(int N= 100; N< 10000; N= N+100)
	{
	double somma=0;
	double quad=0;
	for(int i=0 ; i<K ; i++)
			{ 
			double x=buffon(N,k);
			somma= somma + x;
			quad= quad + x*x;
			}
	srand((unsigned)time(0)+N);// ad ogni giro cambio il seed!
	double media= somma/(double)K; 
      	double varianza=quad/K-media*media;
      	double stddev=sqrt(varianza/(double)K);
	myfile<<N<<"\t"<<stddev<<endl;
	}
myfile.close();
return(0);}
