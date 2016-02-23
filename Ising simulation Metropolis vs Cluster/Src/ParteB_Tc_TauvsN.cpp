/*
RACCOLTA ANDAMENTO DI TAU INTEGRALE VS N (TAGLIA DEL RETICOLO) A BETA = bETAcrit
	(ALGORITMO METROPOLIS)
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
	int N_in=150;
	int n_dots=180;
	double X, Y;				//array ascissa ordinata del grafico

	int Nmarkov=100000;					//numero di elementi della catana di markov su cui produco la statistica
	double O[Nmarkov];					//array dei valori assunti dall Osservabile istantaneo sulla catena

	int t_max=1000;				//# massimo valore di sfasamento tra campio di M elementi (quindi troncamento per la serie di tau)

	double beta = beta_crit;


	for(int n=0;n<n_dots;n++){ 
		int N= N_in-n;
		microstato sistema(N);					//inizializzo la classe microstato
		cout<<"\n>>>>> "<<n<<"-sima RACCOLTA H PER GRAFICO  (N = "<<N<<" )"<<endl;
		sistema.evol_SwenWang(beta, 30);
		sistema.Raccolta_H_Metropolis( beta, O, Nmarkov);
		X = N;
		Y= Tau(O, Nmarkov, t_max);

		string nomeFile= "Output/ParteB/TCritica/Metro_Tc_TauHvsN.dat";
		cout<<"\n>>>>> Costruzione grafico Finale"<<nomeFile<<endl;
		grafico_add(X,Y,nomeFile);
	}

	Nmarkov=10200;							//numero di elementi della catana di markov su cui produco la statistica
	double O_1[Nmarkov];							//array dei valori assunti dall Osservabile istantaneo sulla catena

	t_max=200;				//# massimo valore di sfasamento tra campio di M elementi (quindi troncamento per la serie di tau)
	for(int n=0;n<n_dots;n++){ 
		int N= N_in-n;
		microstato sistema(N);					//inizializzo la classe microstato
		cout<<"\n>>>>> "<<n<<"-sima RACCOLTA H PER GRAFICO  (N = "<<N<<" )"<<endl;
		sistema.evol_SwenWang(beta, 30);
		sistema.Raccolta_H_Cluster( beta, O_1, Nmarkov);
		X = N;
		Y =Tau(O_1, Nmarkov, t_max);

		string nomeFile= "Output/ParteB/TCritica/Cluster_Tc_TauHvsN.dat";
		cout<<"\n>>>>> Costruzione grafico Finale"<<nomeFile<<endl;
		grafico_add(X,Y,nomeFile);
	}






return(0);
}
