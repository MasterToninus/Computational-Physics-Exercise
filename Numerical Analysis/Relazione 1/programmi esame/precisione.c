#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main()

{
  float somma=0;
  float precisione= 1.f;
  int bit = 0;
  while(somma!=1)
	{
	bit= bit +1;
	somma=1.f+precisione;
	precisione=precisione/2;
	}
cout<<"La precisione di macchina per il float e': "<<4*precisione<<"\n  il numero di bit è "<<bit-1<<endl<<endl;
//moltiplico per due perchè il ciclo esce quando supera la precisione, quindi il primo x2 mi da l'ultimo numero, siccome il resto di un troncamento di float è paragonabile all'ultima cifra vuol dire che la precisione è fino alla cifra precedente quindi altro 2

/*
Funzionamento: salvo 1 come double e gli sommo valori sempre più piccoli,(nel senso: 2^-n dove n è l'iterazione) quando il valore viene inglobato nel 1 ho la precisione massima
*/
	double sommad=0;
	double precisioned=1.;
	bit = 0;
	while(sommad!=1)
    {
	bit++;
      sommad=1.+precisioned;
      precisioned=precisioned/2;
    }
cout<<"La precisione di macchina per il double e': "<<4*precisioned<<"\n  il numero di bit è "<<bit-1<<endl<<endl;

	long double sommald=0;
	long double precisioneld=1.L;
	bit = 0;
	while(sommald!=1)
    {
	bit++;
      sommald=1L+precisioneld;
      precisioneld=precisioneld/2;
    }
cout<<"La precisione di macchina per il long double e': "<<4*precisioneld<<"\n  il numero di bit è "<<bit-1<<endl<<endl;

}
