/*
STUDIO ANDAMENTO FUNZIONE DI CORRELAZIONE CA(t) vs t(step del algoritmo) PER L'OSSERVABILE H CAMPIONATO A DIVERSI VALORI DI BETA
	(ALGORITMO SWENDEN WANG)
	produce 3 grafic CA(t) vs t

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

	int Nmarkov=5100;					//numero di elementi della catana di markov su cui produco la statistica
	double O[Nmarkov];					//array dei valori assunti dall Osservabile istantaneo sulla catena

	int t_max=100;				//# massimo valore di sfasamento tra campio di M elementi (quindi troncamento per la serie di tau)

	int n_graf = 4;
	double beta_min = 0.38, beta_max = beta_crit;
	double beta_step= (beta_max - beta_min)/n_graf;

	for(int k=1;k<=n_graf;k++){
		double beta= beta_min + beta_step*k;
		
		cout<<"\n>>>>> "<<k<<"-sima RACCOLTA H PER GRAFICO  (beta = "<<beta<<" )"<<endl;
		sistema.evol_SwenWang(beta, 100);
		sistema.Raccolta_H_Cluster( beta, O, Nmarkov);	

		stringstream sstm;
		sstm << "Output/ParteB/Autocorrelazione/"<<"Cluster_CAvst_"<< k <<".dat";
		string nomeFile = sstm.str();
		cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;
		stampa_CAvst(O, Nmarkov, t_max, nomeFile);
		cout<<" Tau = "<< Tau(O,Nmarkov,t_max)<<endl;

	}


return(0);
}
