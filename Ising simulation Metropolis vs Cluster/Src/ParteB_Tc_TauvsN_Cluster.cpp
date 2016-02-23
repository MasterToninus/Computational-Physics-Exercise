/*
RACCOLTA ANDAMENTO DI TAU INTEGRALE VS N (TAGLIA DEL RETICOLO) A BETA = bETAcrit
	(ALGORITMO SWENDEN WANG)
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
	int N_in=120;
	microstato sistema(N_in);					//inizializzo la classe microstato
	int n_dots=8;
	double X[n_dots], Y[n_dots];				//array ascissa ordinata del grafico

	int Nmarkov=10200;							//numero di elementi della catana di markov su cui produco la statistica
	double O[Nmarkov];							//array dei valori assunti dall Osservabile istantaneo sulla catena

	int t_max=200;				//# massimo valore di sfasamento tra campio di M elementi (quindi troncamento per la serie di tau)

	double beta = beta_crit;


	for(int n=0;n<n_dots;n++){ 
		int N= N_in-15*n;
		sistema.rinizializza(N);
		cout<<"\n>>>>> "<<n<<"-sima RACCOLTA H PER GRAFICO  (N = "<<N<<" )"<<endl;
		sistema.evol_SwenWang(beta, 100);
		sistema.Raccolta_H_Cluster( beta, O, Nmarkov);
		X[n] = N;
		Y[n]=Tau(O, Nmarkov, t_max);
		stringstream sstm;
		sstm << "Output/ParteB/TCritica/"<<"Cluster_Tc_CAvst_N"<< N <<".dat";
		string nomeFile = sstm.str();
		cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;
		stampa_CAvst(O, Nmarkov, t_max, nomeFile);
	}

	string nomeFile= "Output/ParteB/TCritica/Cluster_Tc_TauHvsN.dat";
	cout<<"\n>>>>> Costruzione grafico Finale"<<nomeFile<<endl;
	grafico(n_dots, X, Y, nomeFile);





return(0);
}
