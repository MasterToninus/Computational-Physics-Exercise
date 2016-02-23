/*
PRELIMINARI Cammino di una particella di test a vari eta

PRODUCE:
		- 4 grafici dei punti in cui la particella di test urta (unendoli si ha la traiettoria)
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


int main()
{

	int d= 2;
	int N=15;// numero esatto di particellle

	double eta = 0.72;
	sistema_rigido sistema(d, N, eta);sistema.stampa_stato("Test/prova.dat");
	sistema.Termalizzazione(20*sistema.M);


	double Dt = 1.;
	
	int n_graf = 4;
	double eta_max= eta, eta_min=0.22;
	double eta_step= (eta_max - eta_min)/n_graf;

	for(int i=0;i<=n_graf;i++){
		eta = eta_max - eta_step*i;
		printf("\n#- %d-simo Grafico --- reimposto impacchettamento a eta = %f \n",i,eta);
		sistema.Rinizializza(eta);
		if(sistema.CheckSovrapposizione()==0){ cout<<"\t a eta= "<<eta<<" le particelle sono sovrapposte"<<endl;break;}
		sistema.Termalizzazione(10*sistema.M);
	
		stringstream sstm;
		sstm << "Preliminari/LiberoCammino/Moto_P"<<d<<"D_Eta"<<i<<".dat";
		string nomeFile = sstm.str();
		sistema.evoluzione_conmoto(Dt, nomeFile);  //funzione evoluzione che stampa la traiettoria di 3 particelle

	}

return(0);
}
