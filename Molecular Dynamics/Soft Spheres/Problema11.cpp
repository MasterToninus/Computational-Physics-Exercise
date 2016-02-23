/*
PROBLEMA 11 parte 1
Studiare andamento dello spostamenti quadratico medio (di diffusione, quindi senza applicare le condizioni di bordo) in funzione del intervallo di tempo Dt[t] di diffusione. (Nfisso - 3D)

PRODUCE:
		- 4 grafici di dS^2 vs Dt A DIVERSI VALORI DI kT
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
	double rho = 0.9;
	int N=256;// numero esatto di particellle
	double step_Dt= 0.015; //intervallo tra i campionamenti
	sistema_soffice sistema(d, N, rho);	sistema.evoluzione(500);			

	int n_graf=4	;
	double T_D[n_graf];
	T_D[0]= 0.05;
	T_D[1]= 0.4;
	T_D[2]= 0.8;
	T_D[3]= 1.087;;

	int Npassi = 10000;		//Passi di termalizzazione
	int Ncampionature = 4000;
	int Nstep_Dt_Max = 2000; //Tempo di diffusione massimo in cui si stampa il grafico

	for(int i=0;i<n_graf;i++){

		printf("\n#- %d-simo Grafico --- reimposto temperatura a T_D = %f \n",i,T_D[i]);
		sistema.termalizzazione_kTfissa( Npassi, T_D[i]);

		stringstream sstm;
		sstm << "Output/Problema11/dS_quad_vsDt_TD"<<i<<".dat";
		string nomeFile = sstm.str();

		sistema.Stampa_dS_quadVsStep( Ncampionature, Nstep_Dt_Max, step_Dt, nomeFile);
	}


return(0);
}
