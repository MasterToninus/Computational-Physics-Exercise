/*
PROBLEMA 11 parte 2 ( B, rho fisso (basso) vario  T_D alzando la temperatura, parto da configurazione centrale congelata
Studiare la distribuzione  degli spostamenti (la funzione di distribuzione radiale) con bordo  a vari T_D. (Nfisso)

PRODUCE:
		- 4 istogrammi della distribuzione di probabilità dei valorid ello spostamento (g_t(r)) A DIVERSI VALORI DI kT 
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
	double rho = 1.2;
	int N=256;// numero esatto di particellle
	sistema_soffice sistema(d, N, rho);	sistema.evoluzione(500);	
	sistema.Rinizializza( N, 0.725); //bisogna dilatare un pò se no il sistema esplode
	rho = 0.25;
	sistema.Espandi( rho);		

	int n_graf=4;
	double T_D[n_graf];
	T_D[0]=	0.005;
	T_D[1]=	0.45;
	T_D[2]=	0.75;
	T_D[3]=	1.005;

	int Npassi = 10000;			//passi di termalizzazione
	int Ncampionature = 2000;	// N Campionature
	double step_Dt= 0.05; 		//intervallo tra i campionamenti
	int Nstep_Dt = 3000; 		//Tempo di diffusione, N di step tra i campionamenti
	int Nstep_campionature = 10;
	int Ndati = Ncampionature*N;
	double O[Ndati];

	for(int i=0 ;i<n_graf;i++){
		printf("\n#- %d-simo Grafico --- reimposto Temperatura a T_D = %f \n",i,T_D[i]);
		sistema.termalizzazione_kTfissa( Npassi, T_D[i]);

		stringstream sstm;
		sstm << "Output/Problema11/DistrodS_RhoBassa_TD"<<i<<".dat";
		string nomeFile = sstm.str();
		cout<<"##--- Costruzione istogramma : "<<nomeFile<<endl;

		sistema.Raccolta_dS_conBordo( Ncampionature,  Nstep_campionature,  Nstep_Dt,  step_Dt,  O);
		//i valori di ds sono in unità di sigma! normalizzo ad unità di lato
		for(int k=0 ;k<Ndati;k++)O[k] = O[k]/sistema.L;
		istogramma( N, O, Ndati,nomeFile);
	}


return(0);
}
