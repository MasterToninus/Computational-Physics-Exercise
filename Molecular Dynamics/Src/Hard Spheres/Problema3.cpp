/*
PROBLEMA 3
Studiare la distribuzione dei tempi di collisione. (Nfisso - 2D)
PRODUCE UN'ISTOGRAMMA DELLA DISTRIBUZIONE DI PROBABILITÀ DEI TEMPI DI COLLISIONE per vari valori di eta
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
	double eta=0.75;
	sistema_rigido sistema(d, N, eta);
	sistema.CheckSovrapposizione();
	sistema.Termalizzazione(50*sistema.M);	//termalizzo: 1000 urti per ogni particella
	sistema.CheckSovrapposizione();sistema.stampa_stato("Test/prova.dat");

	int Nc = 50*sistema.M;
	double O[Nc];

	int n_graf = 3;
	double eta_max= eta , eta_min=0.32;
//	double eta_step= (eta_max - eta_min)/n_graf;
	double eta_step= 0.05;

for(int i=0;i<=n_graf;i++){
	eta = eta_max - eta_step*i*i;
	printf("\n#- %d-simo Grafico --- reimposto impacchettamento a eta = %f \n",i,eta);
	sistema.Rinizializza(eta);
	if(sistema.CheckSovrapposizione()==false){ cout<<"\t a eta= "<<eta<<" le particelle sono sovrapposte"<<endl;break;}
	sistema.Termalizzazione(3*sistema.M);

	stringstream sstm;
	sstm << "Output/Problema3/DistroTc_"<<i<<".dat";
	string nomeFile = sstm.str();
	cout<<"##--- Costruzione istogramma : "<<nomeFile<<endl;

	sistema.Raccolta_TempiCollisione(Nc, O);
	istogramma( sistema.M/2, O, Nc,nomeFile);
}

return(0);
}
