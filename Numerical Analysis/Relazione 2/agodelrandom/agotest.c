#include <iostream>
#include <math.h>
#include <cstdlib> 
#include <iostream>
#include <ctime> 
#include <fstream>
#include "ago.h"
using namespace std;

//Test della funzione creata per l'esperimento dell'ago di buffon, analisi statistica sui possibili risultati che può dare lo stesso esperimento con gli stessi parametri sperimentali

int main()
{
srand((unsigned)time(0));
int K = 1000; //#° di esperimenti
int N= 100; // #° lanci
double k= 0.5;
double p_atteso= 2*k/M_PI;

/*calcola media ed errore sulla probabilità di K esperimenti con N lanci*/
double somma=0;
double quad=0;
for(int i=0 ; i<K ; i++){ 
			double x=buffon(N,k);
			somma= somma + x;
			quad= quad + x*x;
			}
double media= somma/(double)K;
double varianza=(quad/K-media*media);
double stddev=sqrt(fabs(varianza)/(double)K);
 
cout << "risultato medio di P di" <<  N << "lanci su "<< K<< "esperimenti"<< endl;
cout <<"media = " << media<<"\t deviazione standard = "<< stddev << endl;
cout <<"differenza p_ottenuto - p_atteso = "<< media- p_atteso<< endl;
cout <<"pi = " << 2*k/media  << endl;
return(0);}
