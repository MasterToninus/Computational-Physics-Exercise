/*
PROBLEMA 6 Parte 2 (raffinamento)
Studiare la dipendenza della pressione da eta. (Nfisso - 3D) intorno alla fase metastabile.
In questo range di eta lo stato finale (dopo la termalizzazione) del sistema è strettamente dipendente dallo stato iniziale
PRODUCE GRAFICO P vs rho

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
	int N=5; // numero di particellle lungo un lato
	double eta=0.68;

	string nomeFile ="Output/Problema6/PvsEta_3D_ZonaMeta.dat";
	grafico_start(nomeFile,"#Eta\t\t#<P/N>\t\t#sigmaP/N");

	int Nc = 100000;//sistema.M;
	double Y,Z;

	int n_dots = 80;
	double eta_max= 0.55, eta_min=0.49;
	double eta_step= (eta_max - eta_min)/n_dots;

	for(int i=0;i<=n_dots;i++){
		eta = eta_max - eta_step*i;
		printf("#- %d-sima evoluzione --- reimposto impacchettamento a eta = %f \n",i,eta);
		sistema_rigido sistema(d, N, eta);
		sistema.Termalizzazione(50*sistema.M);	//termalizzo: 1000 urti per ogni particella
		if(sistema.CheckSovrapposizione()==false){ cout<<"\t a eta= "<<eta<<" le particelle sono sovrapposte"<<endl;break;}

		sistema.P_Osservabile( Nc, &Y, 25, &Z);
		grafico_add(nomeFile, 3, (double)eta, (double)Y, (double)Z);
	}

return(0);
}
