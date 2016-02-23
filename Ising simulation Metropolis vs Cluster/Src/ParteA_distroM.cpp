/*
STUDIO DISTRIBUZIONE DEI VALORI CAMPIONATI DI <M> A DIVERSI VALORI DI BETA CON L'ALGORITMO A MULTICLUSTER
	produce 5 istogrammi che danno la distribuzio dei valori di |M|  P vs H

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
	int N=100;							//numero di nodi in una linea
	microstato sistema(N);				//inizializzo la classe microstato

	int Nmarkov=1500;					//numero di elementi della catana di markov su cui produco la statistica
	double O[Nmarkov];					//array dei valori assunti dall Osservabile istantaneo sulla catena

	int n_int= 100;						//# intervalli del istogramma
	double Omin=0;						//valore minimo dell'osservabile
	double Omax=1;						//valore max


	int n_graf_1= 2, n_graf_2= 3, n_graf_3 = n_graf_1;
	int n_graf_tot = n_graf_1 + n_graf_2 + n_graf_3; 

	double beta_min=log( 1.+ sqrt(2.))/2. - 0.4;				//Primo pezzo_ prima della zona critica
	double beta_step= 0.2;
	int n = 0;
	while (n < n_graf_1){															
		double beta= beta_min +beta_step*n;
		cout<<"\n>>>>>["<<n<<"] Costruzione Distribuzione M_improved a beta = "<<beta<<endl;
		sistema.evol_SwenWang(beta, 30);
		sistema.Raccolta_M_Cluster_Improved( beta, O, Nmarkov);
	
		stringstream sstm;
		sstm << "Output/ParteA/DistribuzioneValori/"<<"distroM_"<< n <<".dat";
		string nomeFile = sstm.str();
		cout<<"##--- Costruzione istogramma : "<<nomeFile<<endl;
		istogramma_v1(n_int, O ,Omin,Omax,Nmarkov,nomeFile);
		n++;		
	}

	beta_min=log( 1.+ sqrt(2.))/2. - 0.02;						//secondo pezzo_ intorno alla temperatura critica
	beta_step= 0.02;
	while (n < n_graf_1 + n_graf_2){													
		double beta= beta_min + (n - (n_graf_1))*beta_step;
		cout<<"\n>>>>>["<<n<<"] Costruzione Distribuzione M_improved a beta = "<<beta<<endl;
		sistema.evol_SwenWang(beta, 30);
		sistema.Raccolta_M_Cluster_Improved( beta, O, Nmarkov);
	
		stringstream sstm;
		sstm << "Output/ParteA/DistribuzioneValori/"<<"distroM_"<< n <<".dat";
		string nomeFile = sstm.str();
		cout<<"##--- Costruzione istogramma : "<<nomeFile<<endl;
		istogramma_v1(n_int, O ,Omin,Omax,Nmarkov,nomeFile);
		n++;
	}

	beta_min=log( 1.+ sqrt(2.))/2. + 0.2;						//terzo pezzo_ dopo la temperatura critica
	beta_step= 0.2;
	while (n < n_graf_tot){															
		double beta= beta_min + (n - (n_graf_1 + n_graf_2))*beta_step;;
		cout<<"\n>>>>>["<<n<<"] Costruzione Distribuzione M_improved a beta = "<<beta<<endl;
		sistema.evol_SwenWang(beta, 30);
		sistema.Raccolta_M_Cluster_Improved( beta, O, Nmarkov);
	
		stringstream sstm;
		sstm << "Output/ParteA/DistribuzioneValori/"<<"distroM_"<< n <<".dat";
		string nomeFile = sstm.str();
		cout<<"##--- Costruzione istogramma : "<<nomeFile<<endl;
		istogramma_v1(n_int, O ,Omin,Omax,Nmarkov,nomeFile);
		n++;
	}

return(0);
}
