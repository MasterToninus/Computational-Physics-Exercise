/*
PROBLEMA 7 parte 1
Studiare andamento degli spostamenti quadratici in Dt[t] al variare di rho. (Nfisso - 3D)
PRODUCE  GRAFICO dS^2(Dt) vs RHO
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

	int d= 3;
	int N=5;// numero di particellle lungo un lato
	double eta=0.68;
	sistema_rigido sistema(d, N, eta);
	sistema.CheckSovrapposizione();
	sistema.Termalizzazione(100*sistema.M);	//termalizzo: 100 urti per ogni particella
	sistema.CheckSovrapposizione();sistema.stampa_stato("Test/prova.dat");

	int Ncampionature = 500;
	int Ndati = Ncampionature*sistema.M;
	int Nstep_campionature = 10;
	int Nstep_Dt = 100;
	double t_step = 0.0005;

	double O[Ndati];
	double Y,Z;

	stringstream sstm;
	sstm << "Output/Problema7/dS_quad_vsEta.dat";
	string nomeFile = sstm.str();
	grafico_start(nomeFile,"\t#eta\t\t#<dS_quad>\t\t#sigmadS_quad");

	int n_dots = 150;
	double eta_max= eta, eta_min=0.18;
	double eta_step= (eta_max - eta_min)/n_dots;

for(int i=0;i<=n_dots;i++){
	eta = eta_max - eta_step*i;
	printf("#- %d-sima evoluzione --- reimposto impacchettamento a eta = %f \n",i,eta);
	sistema.Rinizializza(eta);
	if(sistema.CheckSovrapposizione()==0){ cout<<"\t a eta= "<<eta<<" le particelle sono sovrapposte"<<endl;break;}
	sistema.Termalizzazione(10*sistema.M);

	sistema.Raccolta_dS_quad( Ncampionature, Nstep_campionature, Nstep_Dt, t_step, O);
	Y = media(O, Ndati);
	Z = deviazione_standard(O, Ndati);
	grafico_add(nomeFile, 3, (double)eta, (double)Y, (double)Z);
//	grafico_add(nomeFile, 3, (double)rho_star(eta, d), (double)Y, (double)Z);
}



return(0);
}
