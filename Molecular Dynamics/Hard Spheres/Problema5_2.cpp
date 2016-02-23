/*
PROBLEMA 5 parte 2
Studiare la distribuzione  degli spostamenti con bordo  a vari rho. (Nfisso)
PRODUCE UN ISTOGRAMMA DELLA DISTRIBUZIONE DI PROBABILITÀ DEI VALORI DELLO SPOSTAMENTO PER VARI ETA
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
	int N=15; // numero di particellle lungo un lato
	double eta=0.785;
	sistema_rigido sistema(d, N, eta);
	sistema.CheckSovrapposizione();
	sistema.Termalizzazione(50*sistema.M);	//termalizzo: 1000 urti per ogni particella
	sistema.CheckSovrapposizione();sistema.stampa_stato("Test/prova.dat");

	int Ncampionature = 500;
	int Ndati = Ncampionature*sistema.M;
	int Nstep_campionature = 50;
	int Nstep_Dt = 500;
	double t_step = 0.001;

	double O[Ndati];


	int n_graf = 3;
	double eta_max= eta, eta_min=0.5;
	double eta_step= (eta_max - eta_min)/n_graf;

for(int i=0;i<=n_graf;i++){
	eta = eta_max - eta_step*i;
	printf("\n#- %d-simo Grafico --- reimposto impacchettamento a eta = %f \n",i,eta);
	sistema.Rinizializza(eta);
	if(sistema.CheckSovrapposizione()==false){ cout<<"\t a eta= "<<eta<<" le particelle sono sovrapposte"<<endl;break;}
	sistema.Termalizzazione(5*sistema.M);

	stringstream sstm;
	sstm << "Output/Problema5/DistrodS_eta"<<i<<".dat";
	string nomeFile = sstm.str();
	cout<<"##--- Costruzione istogramma : "<<nomeFile<<endl;sistema.stampa_stato("Test/prova.dat");

	sistema.Raccolta_dS_conBordo( Ncampionature, Nstep_campionature, Nstep_Dt, t_step, O);
	istogramma( sistema.M, O, Ndati,nomeFile);
}

	sistema_rigido sistema2(d, N, 0.70);
	sistema2.Termalizzazione(150*sistema2.M);	//termalizzo: 1000 urti per ogni particella
	sistema2.Raccolta_dS_conBordo( Ncampionature, Nstep_campionature, Nstep_Dt*500, t_step, O);
	istogramma( sistema2.M, O, Ndati,"Output/Problema5/DistrodS_Meta0.dat");

	sistema2.Rinizializza(0.3);
	sistema2.Termalizzazione(150*sistema2.M);	//termalizzo: 1000 urti per ogni particella
	sistema2.Termalizzazione(5*sistema.M);
	sistema2.Raccolta_dS_conBordo( Ncampionature, Nstep_campionature, Nstep_Dt*500, t_step, O);
	istogramma( sistema2.M, O, Ndati,"Output/Problema5/DistrodS_eta4.dat");



return(0);
}
