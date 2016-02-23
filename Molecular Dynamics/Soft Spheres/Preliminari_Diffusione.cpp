/*
PRELIMINARI - Istananee di diffusione del sistema (2D)

PRODUCE:
	- 4 figure delle posizioni delle particelle componenti il sistema dopo una termalizzazione a temperature diverse

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

#include "funzioni_utili.h"
#include "vettori_fisici_check.h"
#include "STRUTTURONA_sfere_soffici.h"


int main()
{

	int d= 3;
	int N=100;// numero esatto di particellle
	int Npassi = 20000;

	int n_graf = 2;
	double T_D_min= 0.05, T_D_max= 1.2;				
	double rho_min= 0.05, rho_max= 1.2;
	double T_D_step = (T_D_max - T_D_min)/n_graf;
	double rho_step = (rho_max - rho_min)/n_graf;


	for(int i = 0; i<= n_graf; i++)for(int j = 0; j<= n_graf; j++){
		double T_D = T_D_min + T_D_step*i; 
		double rho = rho_min + rho_step*j;	
		sistema_soffice sistema(d, N, rho);			
		sistema.evoluzione_muto(500);
		sistema.termalizzazione_kTfissa(Npassi, T_D); //termalizzo sistema alla temperatura richiesta

		stringstream sstm;
		sstm << "Preliminari/Diffusione/T"<<i<<"_Rho"<<j;
		string nomeFile = sstm.str()	;
		sistema.stampa_Diffusione(Npassi,nomeFile);
	}



return(0);
}
