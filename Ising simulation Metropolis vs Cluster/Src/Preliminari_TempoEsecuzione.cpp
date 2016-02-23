/*
 MISURAZIONE IN SECONDI DELL'ALGORITMO
		produce grafici tempo vs L
*/


#include <iostream>
#include <string>
#include <sstream> //per giocare con la classe string

#include <math.h>
#include <cstdlib> 
#include <ctime> 
#include <fstream>
#include <vector>

using namespace std;

#include "funzioni_statistica.h"
#include "funzioni_utili.h"
#include "Matrici.h"
#include "microstati_struttura.h"

#define beta_crit log( 1.+ sqrt(2.))/2.


int main()
{
	int N_in=80;
	microstato sistema(N_in);					//inizializzo la classe microstato
	int n_dots=N_in-5;
	double X[n_dots], Y_1[n_dots], Y_2[n_dots], Y_3[n_dots];;				//array ascissa ordinata del grafico

	int Nmarkov=100;						//numero di elementi della catana di markov su cui produco la statistica
	double O[Nmarkov];							//array dei valori assunti dall Osservabile istantaneo sulla catena

	double beta = beta_crit;

	clock_t start,end;//variabili di controllo tempo di esecuzione
	double tempo;

	for(int n=0;n<n_dots;n++){ 		
		int N= N_in - n;
		sistema.rinizializza(N);

		cout<<"\n>>>>> "<<n<<" / "<<n_dots<<" CRONOMETRO ALGORITMI (N = "<<N<<" )"<<endl;
		start=clock();	
		sistema.evol_SwenWang(beta, Nmarkov);
		end=clock();tempo=((double)(end-start))/CLOCKS_PER_SEC;

		X[n] = N;
		Y_1[n] = tempo/Nmarkov;

		start=clock();	
		sistema.evol_montecarlo(beta, Nmarkov);
		end=clock();tempo=((double)(end-start))/CLOCKS_PER_SEC;

		Y_2[n] = tempo/Nmarkov;


		start=clock();	
		double Pbond = 1-exp(-2*beta);
		sistema.evol_SwenWang_V2(Pbond, Nmarkov);
		end=clock();tempo=((double)(end-start))/CLOCKS_PER_SEC;

		Y_3[n] = tempo/Nmarkov;
	}

	string nomeFile= "Output/Preliminari/TempoEsecuzione/Cluster_TimevsN.dat";
	cout<<"\n>>>>> Costruzione grafico Finale"<<nomeFile<<endl;
	grafico_append(n_dots, X, Y_1, nomeFile);

	nomeFile= "Output/Preliminari/TempoEsecuzione/Metro_TimevsN.dat";
	cout<<"\n>>>>> Costruzione grafico Finale"<<nomeFile<<endl;
	grafico_append(n_dots, X, Y_2, nomeFile);

	nomeFile= "Output/Preliminari/TempoEsecuzione/Cluster_V2_TimevsN.dat";
	cout<<"\n>>>>> Costruzione grafico Finale"<<nomeFile<<endl;
	grafico_append(n_dots, X, Y_3, nomeFile);


return(0);
}
