/*
PROBLEMA 1
Studiare la dipendenza della pressione da eta. (Nfisso - 2D)
PRODUCE GRAFICO <P> vs rho

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
	double eta=0.75;
	sistema_rigido sistema(d, N, eta);
	sistema.CheckSovrapposizione();
	sistema.Termalizzazione(50*sistema.M);	//termalizzo: 1000 urti per ogni particella
	sistema.CheckSovrapposizione();sistema.stampa_stato("Test/prova.dat");

	string nomeFile ="Output/Problema1/PvsEta_2D.dat";
	grafico_start(nomeFile,"\t#Eta\t\t#<P/N>\t\t#sigmaP/N");
	double Y,Z;
	int Nc = 100*sistema.M;


	int n_dots = 120;
	double eta_max= eta, eta_min=0.345;
	double eta_step= (eta_max - eta_min)/n_dots;

	for(int i=0;i<=n_dots;i++){
		eta = eta_max - eta_step*i;
		printf("#- %d-sima evoluzione --- reimposto impacchettamento a eta = %f \n",i,eta);
		sistema.Rinizializza(eta);
		if(sistema.CheckSovrapposizione()==false){ cout<<"\t a eta= "<<eta<<" le particelle sono sovrapposte"<<endl;break;}
		sistema.Termalizzazione(3*sistema.M);
	
		sistema.P_Osservabile( Nc, &Y, 25, &Z);
		grafico_add(nomeFile, 3, (double)eta, (double)Y, (double)Z);

	}

return(0);
}
