#include <iostream>
#include <math.h>
#include <cstdlib> 
#include <iostream>
#include <ctime> 
#include <fstream>
#include "ago.h"
using namespace std;

//sul errore statistico stampo la deviazione standard tra valore atteso (non valore medio!) e valore ottenuto in funzione dei numero di lanci di cui è composto l'esperimento
//GRAFICO DELLA DEVIAZIONE STANDARD

int main()
{

srand((unsigned)time(0));

double k= 0.5; // caso T> L
double p_atteso= 2*k/M_PI;
double K= 1000; // #° esperimenti


// questo grafico rappresenta l'andamento dell'errore tra risultato sperimentale e risultato atteso in funzione dei lanci
ofstream myfile("dev2.txt",ios::trunc);

// N= numero dei lanci!
for(int N= 500; N< 10000; N= N+200)
	{
	double quad=0;
	for(int i=0 ; i<K ; i++)
			{ 
			double p=buffon(N,k);
			//double disp= p - p_atteso;
				quad+=p*p;
			}
	srand((unsigned)time(0)+N);// ad ogni giro cambio il seed!
      
      double varianza=quad/K-p_atteso*p_atteso;
      	double stddev=sqrt(quad/(double)K);
	myfile<<N<<" "<<stddev<<endl;
	}


myfile.close();

return(0);}
