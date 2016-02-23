#include <iostream>
#include <math.h>
#include <cstdlib> 
#include <iostream>
#include <ctime> 
#include <fstream>
#include "ago.h"
using namespace std;

//sul errore statistico stampo la differenza tra buffon di N lanci e valore atteso in funzione dei lanci voglio vedere la convergenza a P di P(n)
//GRAFICO DEL MODULO DELLA MEDIA DELLA DISPERSIONE

int main()
{

srand((unsigned)time(0));

double k= 0.5; // caso T> L
double p_atteso= 2*k/M_PI;
double K= 1000; // #° esperimenti


// questo grafico rappresenta l'andamento dell'errore tra risultato sperimentale e risultato atteso in funzione dei lanci
ofstream myfile("ago_3.txt",ios::trunc);

// N= numero dei lanci!
for(int N= 500; N< 50000; N= N+1000)
	{
	double sommatoria=0;
	for(int i=0 ; i<K ; i++)
			{ 
			double p=buffon(N,k);
			double disp= p - p_atteso;
				sommatoria+=disp;
			}
	srand((unsigned)time(0)+N);// ad ogni giro cambio il seed!lo faccio perchè K*N diventa maggiore del periodo del rand()
      	double dispersionemedia=fabs(sommatoria)/K;
      	double error=1/((double)2*N)+0.02*1/(sqrt((double)N));

	myfile<<N<<" "<<dispersionemedia<<"\t"<<error<<endl;
	}


myfile.close();

return(0);}
