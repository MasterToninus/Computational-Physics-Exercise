/*
STUDIO ANDAMENTO FUNZIONE DI CORRELAZIONE CA(t) vs t(step del algoritmo) PER L'OSSERVABILE H CAMPIONATO A DIVERSI VALORI DI BETA
	(ALGORITMO METROPOLIS)
con step intendo step per sito, quindi per ogni step dell'algoritmo si  prova a flippare tanti spin quanti sono i nodi
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
	microstato sistema(100);				//inizializzo la classe microstato

	int Nmarkov=51000;					//numero di elementi della catana di markov su cui produco la statistica
	double O[Nmarkov];					//array dei valori assunti dall Osservabile istantaneo sulla catena

	int t_max=1000;				//# massimo valore di sfasamento tra campio di M elementi (quindi troncamento per la serie di tau)

	int n_graf = 4;
	double beta_min = 0.38, beta_max = beta_crit;
	double beta_step= (beta_max - beta_min)/n_graf;

	for(int k=1;k<=n_graf;k++){
		double beta= beta_min + beta_step*k;
		
		cout<<"\n>>>>> "<<k<<"-sima RACCOLTA H PER GRAFICO  (beta = "<<beta<<" )"<<endl;
		sistema.evol_montecarlo(beta, 8000);
		sistema.Raccolta_H_Metropolis( beta, O, Nmarkov);	

		stringstream sstm;
		sstm << "Output/ParteB/Autocorrelazione/"<<"Metro_CAvst_"<< k <<".dat";
		string nomeFile = sstm.str();
		cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;
		stampa_CAvst(O, Nmarkov, t_max, nomeFile);
		cout<<" Tau = "<< Tau(O,Nmarkov,t_max)<<endl;
	}


return(0);
}
