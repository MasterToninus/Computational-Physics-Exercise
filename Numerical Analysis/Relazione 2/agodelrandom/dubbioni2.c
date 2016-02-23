#include <iostream>
#include <math.h>
#include <cstdlib> 
#include <ctime> 
#include <fstream>
#include "ago.h"
#include "isto.h"
using namespace std;

//dubbioni: perchè è necessario fare la media su più esperimenti????????? dovrebbe essere sempre una cosa lagata alla casualità del generatore
//stampo istogramma sui possibili risultati del esperimento

int main()
{
srand((unsigned)time(0));

double k= 0.5;
double p_atteso= 2*k/M_PI;

int N= 10; // #° di lanci
int K = 1000; //#° di esperimenti

double P[K];
for(int i=0 ; i<K ; i++)
		{ 
		P[i]=p_atteso - buffon(N,k);cout<<P[i]<<endl;
		}

//costruzione istogramma
double centro= 0;
double range= 1.2;
histodouble(P,K,centro,range,12);

return(0);}
