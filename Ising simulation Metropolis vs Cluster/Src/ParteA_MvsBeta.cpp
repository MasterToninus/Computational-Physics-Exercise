/*
STUDIO DIPENDENZA DELLA mAGNETIZZAZIONE <M/V> DA BETA CON L'ALGORITMO A MULTICLUSTER in zona critica 
	produce un grafico |M| vs B con errore

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

	int n_dots_1=30, n_dots_2 = 3 * n_dots_1, n_dots_3 = n_dots_1; 		//# punti per sezione 
	int n_dots_tot=n_dots_1 +n_dots_2 + n_dots_3; 						// # punti totali
	double X[n_dots_tot] , Y[n_dots_tot], Z[n_dots_tot];				//array ascissa ordinata del grafico

	int Nmarkov=1500;						//numero di elementi della catana di markov su cui produco la statistica
	double O[Nmarkov];					//array dei valori assunti dall Osservabile istantaneo sulla catena

	double beta_min=0.025, beta_max= beta_crit -0.085;			//Primo pezzo_ prima della zona critica
	double step= (beta_max-beta_min)/n_dots_1;
	int k = 0;
	while (k < n_dots_1){															
		double beta= beta_min + k*step;
		cout<<"\n>>>>> "<<k<<"-sima Raccolta di M su "<< n_dots_tot <<" (beta = "<<beta<<" )"<<endl;
		X[k] = beta;
		sistema.evol_SwenWang(beta, 30);
		//sistema.Raccolta_M_abs_Metropolis(beta, O, Nmarkov); //
		sistema.Raccolta_M_Cluster_Improved(beta, O, Nmarkov);
		Y[k]=media(O,Nmarkov);
		Z[k]=jackknife(O,Nmarkov);
		k++;		
	}
	int k_end= k;

	beta_min = beta_max, beta_max= beta_crit +0.085;			//secondo pezzo_ intorno alla temperatura critica
	step= (beta_max-beta_min)/(n_dots_2);
	while (k < k_end + n_dots_2){													
		double beta= beta_min + (k - k_end)*step;
		cout<<"\n>>>>> "<<k<<"-sima Raccolta di M su "<< n_dots_tot <<" (beta = "<<beta<<" )"<<endl;
		X[k] = beta;
		sistema.evol_SwenWang(beta, 30);
		sistema.Raccolta_M_Cluster_Improved(beta, O, Nmarkov);
		Y[k]=media(O,Nmarkov);
		Z[k]=jackknife(O,Nmarkov);
		k++;
	}
	k_end = k;

	beta_min = beta_max, beta_max= 0.90;						//terzo pezzo_ dopo la temperatura critica
	step= (beta_max-beta_min)/n_dots_3;
	while (k < n_dots_tot){															
		double beta= beta_min + (k - k_end)*step;
		cout<<"\n>>>>> "<<k<<"-sima Raccolta di M su "<<n_dots_tot<<" (beta = "<<beta<<" )"<<endl;
		X[k] = beta;
		sistema.evol_SwenWang(beta, 30);
		sistema.Raccolta_M_abs_Metropolis(beta, O, Nmarkov);
		Y[k]=media(O,Nmarkov);
		Z[k]=jackknife(O,Nmarkov);
		k++;
	}



		stringstream sstm;
		sstm << "Output/ParteA/"<<"MvsBeta_N"<< N <<".dat";
		string nomeFile = sstm.str();
		cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;
		grafico(n_dots_tot, X, Y, Z, nomeFile);

return(0);
}
