/*
PROBLEMA 5_0
Studiare andamento dello spostamenti quadratico medio (di diffusione, quindi senza applicare le condizioni di bordo) in funzione del intervallo di tempo Dt[t] di diffusione. (Nfisso - 2D)
PRODUCE GRAFICO dS vs Dt A DIVERSI VALORI DI ETA
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

double rho_star(double eta,int d){return(eta*d*2/M_PI);}

int main()
{

	int d= 2;
	int N=15;  // numero di particellle lungo un lato
	double eta=0.785;
	sistema_rigido sistema(d, N, eta);
	sistema.CheckSovrapposizione();
	sistema.Termalizzazione(50*sistema.M);	//termalizzo: 100 urti per ogni particella
	sistema.CheckSovrapposizione();sistema.stampa_stato("Test/prova.dat");

	int Ncampionature = 2000;
	int Nstep_Dt_Max = 2000;
	double t_step = 0.001;

	int n_graf = 3;
	double eta_max= eta, eta_min=0.5;
	double eta_step= (eta_max - eta_min)/n_graf;

for(int i=0;i<=n_graf;i++){
	eta = eta_max - eta_step*i;
	printf("\n#- %d-simo Grafico --- reimposto impacchettamento a eta = %f \n",i,eta);
	sistema.Rinizializza(eta);
	if(sistema.CheckSovrapposizione()==false){ cout<<"\t a eta= "<<eta<<" le particelle sono sovrapposte"<<endl;break;}
	sistema.Termalizzazione(25*sistema.M);

	stringstream sstm;
	sstm << "Output/Problema5/dS_quad_vsDt_eta"<<i<<".dat";
	string nomeFile = sstm.str();

	sistema.Stampa_dS_quadVsStep( Ncampionature,  Nstep_Dt_Max, t_step, nomeFile);
}



return(0);
}
