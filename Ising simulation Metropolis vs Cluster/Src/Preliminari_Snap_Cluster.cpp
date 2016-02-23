/*
EXTRA: PRODUZIONE DI UN'ANIMAZIONE DELL'EVOLUZIONE DELLO STATO DEL SISTEMA ALGORITMO SWEN WANG

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
	int L= 100;
	double beta= 0.008;
	microstato sistema(L);				//inizializzo la classe microstato

	int N_step=5;
	int t=0;
	sistema.congela();
	for(int n=0;n<10;n++){ 				//stampo 5 istogrammi con diverso beta
		cout<<"\n>>>>>["<<n<<"] Costruzione snapshot riscaldamento a beta = "<<beta<<endl;	
		t=n;
		stringstream sstm;
		sstm << "Preliminari/Snapshot/"<<"Cluster_Riscaldamento_"<<t<<".dat";
		string nomeFile = sstm.str();
		sistema.flip(0,0);
		sistema.animazione_SwenWang(nomeFile,1,beta);
		//sistema.evol_montecarlo(beta, N_step-1);
	}

	beta=1.2;
	for(int n=0;n<10;n++){ 				//stampo 5 istogrammi con diverso beta
		cout<<"\n>>>>>["<<n<<"] Costruzione snapshot riscaldamento a beta = "<<beta<<endl;	
		t=n;
		stringstream sstm;
		sstm << "Preliminari/Snapshot/"<<"Cluster_Raffreddamento_"<<t<<".dat";
		string nomeFile = sstm.str();
		sistema.animazione_Metro(nomeFile,1,beta);
		sistema.evol_SwenWang(beta,1);
	}

return(0);
}
