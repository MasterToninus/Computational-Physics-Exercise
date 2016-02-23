/*
PROBLEMA 4
Studiare la dipendenza del libero cammino medio da rho. (Nfisso - 2D)
PRODUCE UN GRAFICO DI LIBERO CAMMINO MEDIO vs RHO, OGNI PUNTO È CALCOLATO DOPO NC COLLISIONI

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
	sistema.Termalizzazione(50*sistema.M);	//termalizzo: 100 urti per ogni particella
	sistema.CheckSovrapposizione();sistema.stampa_stato("Test/prova.dat");

	string nomeFile ="Output/Problema4/Lc_mediovsRho_2D.dat";
	grafico_start(nomeFile,"\t#rho\t\t#<Lc>\t\t#sigmaLc");

	int Nc = 50*sistema.M;
	double O[Nc];
	double Y,Z;

	int n_dots = 120;
	double eta_max= 0.725, eta_min=0.3;
	double eta_step= (eta_max - eta_min)/n_dots;

for(int i=0;i<=n_dots;i++){
	eta = eta_max - eta_step*i;
	printf("#- %d-sima evoluzione --- reimposto impacchettamento a eta = %f \n",i,eta);
	sistema.Rinizializza(eta);
	if(sistema.CheckSovrapposizione()==false){ cout<<"\t a eta= "<<eta<<" le particelle sono sovrapposte"<<endl;break;}
	sistema.Termalizzazione(3*sistema.M);

	sistema.Raccolta_LiberoCammino(Nc, O);
	Y = media(O, Nc);
	Z = deviazione_standard(O, Nc);
	grafico_add(nomeFile, 3, (double)rho_star(eta, d), (double)Y, (double)Z);
}



return(0);
}
