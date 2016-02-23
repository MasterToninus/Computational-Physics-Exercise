/*
STUDIO COMPORTAMENTO DELLA DIPENDENZA DELLA mAGNETIZZAZIONE <M/V> DA BETA A SECONDA DELL'ALGORITMO USATO

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
	int N=100;							//numero di nodi in una linea
	microstato sistema(N);				//inizializzo la classe microstato

	int n_dots=120; 					//# punti del grafico
	double X[n_dots] , Y[n_dots], Z[n_dots];		//array ascissa ordinata del grafico

	double beta_min=beta_crit - 0.3, beta_max= beta_crit + 0.3;			//intervallo di beta su cui produco il grafico
	double step= (beta_max-beta_min)/n_dots;

	int Nmarkov_Metro=15000;						//numero di elementi della catana di markov su cui produco la statistica
	double O_1[Nmarkov_Metro];					//array dei valori assunti dall Osservabile istantaneo sulla catena
	int m_bin = 20; 							//ampiezza del campione di binnig con cui calcolo l'errore
											
	for(int k=0;k<n_dots;k++){							//PRIMO GRAFICO |M|VS BETA (METROPOLIS)
		double beta= beta_min + k*step;
		cout<<"\n>>>>> "<<k<<"-sima Raccolta di |M| su "<<n_dots<<" (beta = "<<beta<<" )"<<endl;
		X[k] = beta;
		sistema.evol_montecarlo(beta, 3000);
		sistema.Raccolta_M_abs_Metropolis(beta, O_1, Nmarkov_Metro);
		Y[k]=media(O_1,Nmarkov_Metro);
		Z[k]=binning(O_1,Nmarkov_Metro,m_bin);
	}										
		string nomeFile= "Output/Preliminari/Magnetizzazione/Metro_M_abs.dat";
		//cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;
		//grafico(n_dots, X, Y, Z, nomeFile); 

	sistema.congela();
	for(int k=0;k<n_dots;k++){							//SECONDO GRAFICO M VS BETA (METROPOLIS)
		double beta= beta_max - (k+1)*step;
		cout<<"\n>>>>> "<<k<<"-sima Raccolta di M su "<<n_dots<<" (beta = "<<beta<<" )"<<endl;
		X[k] = beta;
		sistema.evol_montecarlo(beta, 3000);
		sistema.Raccolta_M_Metropolis(beta, O_1, Nmarkov_Metro);
		Y[k]=media(O_1,Nmarkov_Metro);
		Z[k]=binning(O_1,Nmarkov_Metro,m_bin);
	}

		nomeFile= "Output/Preliminari/Magnetizzazione/Metro_M.dat";
		cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;
		grafico(n_dots, X, Y, Z, nomeFile);
											
	int Nmarkov_Cluster=1500;
	double O_2[Nmarkov_Cluster];					//array dei valori assunti dall Osservabile istantaneo sulla catena

	for(int k=0;k<n_dots;k++){							//TERZO GRAFICO M VS BETA (CLUSTER)
		double beta= beta_min + k*step;
		cout<<"\n>>>>> "<<k<<"-sima Raccolta di M_improved su "<<n_dots<<" (beta = "<<beta<<" )"<<endl;
		X[k] = beta;
		sistema.evol_SwenWang(beta, 50);
		sistema.Raccolta_M_Cluster_Improved(beta, O_2, Nmarkov_Cluster);
		Y[k]=media(O_2,Nmarkov_Cluster);
		Z[k]=binning(O_2,Nmarkov_Cluster,m_bin);
	}

		nomeFile= "Output/Preliminari/Magnetizzazione/Cluster_M.dat";
		cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;
		grafico(n_dots, X, Y, Z, nomeFile);
											
return(0);
}
