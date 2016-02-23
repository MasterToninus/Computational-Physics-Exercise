/*
PRELIMINIRI diffusione delle diffusione delle particelle del sistema nei volumi limitrofe	

PRODUCE:
		- 5 grafici delle posizioni delle particelle del sistema dopo la termalizzazione senza applicare il bordo periodico. 

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
#include "vettori_fisici.h"
#include "tempi_collisione.h"
#include "STRUTTURONA_sfere_rigide.h"


int main()
{

	int d= 2;
	int N=11;


	double Dt = 1;
	int n_graf = 4;
	double eta_max= 0.72, eta_min=0.32;
	double eta_step= (eta_max - eta_min)/n_graf;


	for(int i = 0; i<= n_graf; i++){
		double eta = eta_max - eta_step*i;
		sistema_rigido sistema(d, N, eta);
		sistema.CheckSovrapposizione();
		sistema.Termalizzazione(20*sistema.M);	//termalizzo: 1000 urti per ogni particella
		sistema.CheckSovrapposizione();
		sistema.stampa_stato("Test/prova.dat");

		stringstream sstm;
		sstm << "Preliminari/Diffusione/Eta"<<i<<"_"<<d<<"D";
		string nomeFile = sstm.str()	;

	
		sistema.stampa_Diffusione( Dt, nomeFile);
	sistema.CheckSovrapposizione();
	}



return(0);
}
