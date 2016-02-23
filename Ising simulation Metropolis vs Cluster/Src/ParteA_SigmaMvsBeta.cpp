/*
STUDIO DIPENDENZA DELLA sigma NELLA MISURA DI <H> AL VARIARE DI BETA
	produce un grafico siggma H vs Beta

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

#define beta_crit 0.4406868

int main()
{
	int N_i=100;							//numero di nodi in una linea
	microstato sistema(N_i);				//inizializzo la classe microstato

	int n_dots_1=30, n_dots_2 = 3 * n_dots_1, n_dots_3 = n_dots_1; 
	int n_dots_tot=n_dots_1 +n_dots_2 + n_dots_3; 					//# punti per sezione / # punti totali
	double X[n_dots_tot] , Y_1[n_dots_tot], Y_2[n_dots_tot];		//array ascissa ordinata del grafico

	int Nmarkov=1500;						//numero di elementi della catana di markov su cui produco la statistica
	double O[Nmarkov];					//array dei valori assunti dall Osservabile istantaneo sulla catena
	int m= 12; 							//ampiezza del campione di binnig con cui calcolo l'errore

	for(int n=0;n<2;n++){ //stampo 4 grafici con diversi N
		int N= N_i-20*n;
		sistema.rinizializza(N);

		double beta_min=0.105, beta_max= beta_crit -0.085;					//Primo intervallo_ prima della zona critica
		double step= (beta_max-beta_min)/n_dots_1;
		int k = 0;
		while (k < n_dots_1){															
			double beta= beta_min + k*step;
			cout<<"\n>>>>> "<<k<<"-sima Raccolta di M su "<<n_dots_tot<<" (beta = "<<beta<<" )"<<endl;
			X[k] = beta;
			sistema.evol_SwenWang(beta, 30);
			sistema.Raccolta_M_Cluster_Improved(beta, O, Nmarkov);
			Y_1[k]=jackknife(O,Nmarkov);
			Y_2[k]=binning(O,Nmarkov,m);
			k++;		
		}

		beta_min = beta_max, beta_max= beta_crit +0.085;					//secondo intervallo_ intorno alla temperatura critica
		step= (beta_max-beta_min)/(n_dots_2);
		while (k < n_dots_1 + n_dots_2 ){															
			double beta= beta_min + (k - n_dots_1)*step;
			cout<<"\n>>>>> "<<k<<"-sima Raccolta di M su "<<n_dots_tot<<" (beta = "<<beta<<" )"<<endl;
			X[k] = beta;
			sistema.evol_SwenWang(beta, 30);
			sistema.Raccolta_M_Cluster_Improved( beta, O, Nmarkov);
			Y_1[k]=jackknife(O,Nmarkov);
			Y_2[k]=binning(O,Nmarkov,m);
			k++;
		}

		beta_min = beta_max, beta_max= 0.90;								//ultimo intervallo_ intorno alla temperatura critica
		step= (beta_max-beta_min)/n_dots_3;
		while (k < n_dots_tot){															
			double beta= beta_min + (k - (n_dots_1 + n_dots_2))*step;
			cout<<"\n>>>>> "<<k<<"-sima Raccolta di M su "<<n_dots_tot<<" (beta = "<<beta<<" )"<<endl;
			X[k] = beta;
			sistema.evol_SwenWang(beta, 30);
			sistema.Raccolta_M_abs_Metropolis(beta, O, Nmarkov);
			Y_1[k]=jackknife(O,Nmarkov);
			Y_2[k]=binning(O,Nmarkov,m);
			k++;
		}


		stringstream sstm;
		sstm << "Output/ParteA/DistribuzioneValori/"<<"M_SigmaJackvsBeta_N"<< N <<".dat";
		string nomeFile = sstm.str();
		cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;
		grafico(n_dots_tot, X, Y_1, nomeFile);

		stringstream sstm2;
		sstm2 << "Output/ParteA/DistribuzioneValori/"<<"M_SigmaBinvsBeta_N"<< N <<".dat";
		nomeFile = sstm2.str();
		cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;
		grafico(n_dots_tot, X, Y_2, nomeFile);

	}

return(0);
}
