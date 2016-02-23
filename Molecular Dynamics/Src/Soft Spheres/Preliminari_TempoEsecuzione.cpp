/*
PRELIMINARI - TEMPO DI ESECUZIONE
Si studia il tempo medio necessario alla macchina per calcolare l'evoluzione del sistema di uno step temporale. (più il sistema è denso più la lista dei vicini è lunga quindi maggiore è il tempo di calcolo delle accelerazioni)

PRODUCE:
	- 3 grafici di T_Esecuzione vs N simulazione a 3 diversi valori di rho

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
#include "vettori_fisici_check.h"
#include "STRUTTURONA_sfere_soffici.h"


int main()
{


	int N_in=1000;
	int n_dots = 125;
	double X, Y;

	int Npassi= 50000;	

	clock_t start,end;//variabili di controllo tempo di esecuzione
	double tempo;

	int n_graf=4;
	double rho[n_graf];
	rho[0] = 0.2;
	rho[1] = 0.7;
	rho[2] = 0.9;
	rho[3] = 0.11;




	for(int d= 2;d<=3; d++)	for(int k=0; k<n_graf;k++){
		sistema_soffice sistema(d, N_in,rho[k]);	
		stringstream sstm;
		sstm << "Output/Preliminari/TempoEsecuzione/"<<"T_esec_Rho"<<k<<"_"<< d <<"D.dat";
		string nomeFile = sstm.str();
		grafico_start(nomeFile);
		cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;
		for(int n=0;n<n_dots;n++){ 		
			int N= N_in - 6*n;
			sistema.Rinizializza(N,rho[k]);
			cout<<"\n>>>>> "<<n<<" / "<<n_dots<<" CRONOMETRO ALGORITMI (N = "<<N<<" )"<<endl;
			start=clock();	
			sistema.evoluzione( Npassi)	;

			end=clock();tempo=((double)(end-start))/CLOCKS_PER_SEC;

			X = (double)N;
			Y = tempo/Npassi;
			grafico_add(nomeFile, 2 ,X,Y);
			cout<<X<<"\t = "<<Y<<endl;
		}
	}
	
return(0);
}
