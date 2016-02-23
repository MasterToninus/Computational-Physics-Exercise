/*
PROBLEMA 2
Studiare la dipendenza del Tempo di collisione medio da rho. (Nfisso - 2D)
( Tc è una stima dell'intervallo di tempo che intercorre tra 2 urti successivi di una stessa particella)
PRODUCE UN GRAFICO Tc VS RHO
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
	sistema.Termalizzazione(50*sistema.M);	//termalizzo: 1000 urti per ogni particella
	sistema.CheckSovrapposizione();sistema.stampa_stato("Test/prova.dat");

	string nomeFile ="Output/Problema2/TcvsEta_2D.dat";
	grafico_start(nomeFile,"\t#eta\t\t#<Tc>\t\tsigmaTc\t");
	double Y,Z;
	int Nc = 50*sistema.M;
	double O[Nc];

	int n_dots = 160;
	double eta_max= eta, eta_min=0.1;
	double eta_step= (eta_max - eta_min)/n_dots;

for(int i=0;i<=n_dots;i++){
	eta = eta_max - eta_step*i;
	printf("#- %d-sima evoluzione --- reimposto impacchettamento a eta = %f \n",i,eta);
	sistema.Rinizializza(eta);
	if(sistema.CheckSovrapposizione()==false){ cout<<"\t a eta= "<<eta<<" le particelle sono sovrapposte"<<endl;break;}
	sistema.Termalizzazione(3*sistema.M);
	sistema.Raccolta_TempiCollisione( Nc, O);

	Y = media(O,Nc);
	Z = deviazione_standard(O,Nc);
	grafico_add(nomeFile, 3, (double)eta, (double)Y, (double)Z);
}



return(0);
}
