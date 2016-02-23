/*
PROBLEMA 11 parte 2 (A : T_D fissa, vario rho)
Studiare la distribuzione  degli spostamenti (la funzione di distribuzione radiale) con bordo  a vari rho. (Nfisso, T_D fissa)

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
	double rho =1.265;
	int N=256;// numero esatto di particellle
	sistema_soffice sistema(d, N, rho);	sistema.evoluzione(500);			


	int n_graf=4;
	double T_D=0.9;
	double Rho[n_graf];
	Rho[0]=	1.25;
	Rho[1]=	0.87;
	Rho[2]=	0.5;
	Rho[3]=	0.15;

	int Npassi = 10000;			//passi di termalizzazione
	int Ncampionature = 2000;	// N Campionature
	double step_Dt= 0.05; 		
	int Nstep_Dt = 3000; 		//Tempo di diffusione, N di step tra i campionamenti
	int Nstep_campionature = 10;//intervallo tra i campionamenti
	int Ndati = Ncampionature*N;
	double O[Ndati];

	for(int i=0 ;i<n_graf;i++){
		printf("\n#- %d-simo Grafico --- reimposto densità a Rho = %f \n",i,Rho[i]);
		sistema.Espandi( Rho[i]);
		sistema.termalizzazione_kTfissa( Npassi, T_D);

		stringstream sstm;
		sstm << "Output/Problema11/DistrodS_Rho"<<i<<".dat";
		string nomeFile = sstm.str();
		cout<<"##--- Costruzione istogramma : "<<nomeFile<<endl;

		sistema.Raccolta_dS_conBordo( Ncampionature,  Nstep_campionature,  Nstep_Dt,  step_Dt,  O);
		//i valori di ds sono in unità di sigma! normalizzo ad unità di lato
		for(int k=0 ;k<Ndati;k++)O[k] = O[k]/sistema.L;

		istogramma( N, O, Ndati,nomeFile);
	}


return(0);
}
