/*
STUDIO CA (StS0) funzione di correlazione tra linee diverse in funzione della distanza tra le linee 
	(ALGORITMO SWENDEN WANG)

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

#include "funzioni_statistica.h"
#include "funzioni_utili.h"
#include "Matrici.h"
#include "microstati_struttura.h"


#define beta_crit log( 1.+ sqrt(2.))/2.


int main()
{
	int L= 220;							// # di spin su una linea
	microstato sistema(L);				//inizializzo la classe microstato

	int Nmarkov=100;					//numero di elementi della catana di markov su cui produco la statistica
	int t_max=(L-L%2)/2;				//massima distanza tra due linee del modello 
	int n_dots= t_max+1;				//ho un punto per ogni t + il punto t=0
	int Nsample = 2*L*Nmarkov;

	matrice O(n_dots,Nsample);
	
	double X, Y, Z;			//array ascissa ordinata del grafico
	
	double beta= beta_crit;
	sistema.evol_SwenWang(beta, 30);
	double m=sistema.Raccolta_St_Cluster( beta, O, Nmarkov);	

	//grafico primo metodo
	double S0S0 = O.media_riga(0);

		stringstream sstm;
		sstm << "Output/ParteC/"<<"test_1"<<".dat";
		string nomeFile = sstm.str();
		cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;

		for(int t=0;t<n_dots;t++){
			cout<<"\t \t"<<t<<" / "<<n_dots<<" punto" << string(300,'\b');
			X = t;
			Y = O.media_riga(t)/S0S0;
			Z = O.jackknife_riga(t)/S0S0;
			grafico_add( X, Y, Z, nomeFile);
		}

	//grafico secondo metodo
	S0S0 = O.media_riga(0) -m*m;


		stringstream sstm2;
		sstm2 << "Output/ParteC/"<<"test_2"<<".dat";
		nomeFile = sstm2.str();
		cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;

		for(int t=0;t<n_dots;t++){
			cout<<"\t \t"<<t<<" / "<<n_dots<<" punto" << string(300,'\b');
			X = t;
			Y = (O.media_riga(t)- m*m)/S0S0;
			Z = O.jackknife_riga(t)/S0S0;
			grafico_add( X, Y, Z, nomeFile);
		}




return(0);
}
