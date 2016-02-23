/*
PROBLEMA 7 parte 2
Studiare la distribuzione  degli spostamenti con bordo  a vari rho. (Nfisso - 3D)
Produrre istogramma della distribuzione di probabilità dello spostamento per vari valori di eta
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
	sistema.Termalizzazione(50*sistema.M);	//termalizzo: 100 urti per ogni particella
	sistema.CheckSovrapposizione();sistema.stampa_stato("Test/prova.dat");

	int Ncampionature = 800;
	int Ndati = Ncampionature*sistema.M;
	int Nstep_campionature = 10;
	int Nstep_Dt = 10000;
	double t_step = 0.001;

	double O[Ndati];


	int n_graf = 3;
	double eta_max= eta, eta_min=0.165;
	double eta_step= (eta_max - eta_min)/n_graf;

for(int i=0;i<=n_graf;i++){
	eta = eta_max - eta_step*i;
	printf("\n#- %d-simo Grafico --- reimposto impacchettamento a eta = %f \n",i,eta);
	sistema.Rinizializza(eta);
	if(sistema.CheckSovrapposizione()==false){ cout<<"\t a eta= "<<eta<<" le particelle sono sovrapposte"<<endl;break;}
	sistema.Termalizzazione(5*sistema.M);

	stringstream sstm;
	sstm << "Output/Problema7/DistrodS_eta"<<i<<".dat";
	string nomeFile = sstm.str();
	cout<<"##--- Costruzione istogramma : "<<nomeFile<<endl;sistema.stampa_stato("Test/prova.dat");

	sistema.Raccolta_dS_conBordo( Ncampionature, Nstep_campionature, Nstep_Dt, t_step, O);
	istogramma( sistema.M, O, Ndati,nomeFile);
}

return(0);
}
