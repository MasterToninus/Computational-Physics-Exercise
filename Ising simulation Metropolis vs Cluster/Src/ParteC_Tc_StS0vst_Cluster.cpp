/*
STUDIO CA(StS0) vs t con diversi N 
	(ALGORITMO SWENDEN WANG)
	Voglio mostrare che la lunghezza di correlazione con T = Tc aumenta all'aumentare di L, questo perchè diverge a Tc ma per il nostro modello finito non può essere più di L/2!

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
	int L_i= 30;							// # di spin su una linea
	int Nmarkov=100;					//numero di elementi della catana di markov su cui produco la statistica
	double beta = beta_crit;	

	int n_graf=30;

	for(int k=0;k<=n_graf;k++){
		int L = L_i + 10*k;
		int t_max=(L-L%2)/2;				//massima distanza tra due linee del modello 
		int n_dots= t_max+1;				//ho un punto per ogni t + il punto t=0
		int Nsample = 2*L*Nmarkov;
		matrice O(n_dots,Nsample);
		double X, Y, Z;						//array ascissa ordinata del grafico

		microstato sistema(L);				//inizializzo la classe microstato
		cout<<"\n>>>>> "<<k<<" / "<< n_graf <<" RACCOLTA S_0 * S_t PER GRAFICO con L = "<< L <<" (beta = "<<beta<<" )"<<endl;
		sistema.evol_SwenWang(beta, 30);
		double m = sistema.Raccolta_St_Cluster( beta, O, Nmarkov);	

		double S0S0 = O.media_riga(0);

		stringstream sstm;
		sstm << "Output/ParteC/TCritica/"<<"Cluster_Tc_S0Stvst_N"<< L <<".dat";
		string nomeFile = sstm.str();
		cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;

		for(int t=0;t<n_dots;t++){
			cout<<"\t \t"<<t<<" / "<<n_dots<<" punto" << string(300,'\b');
			X = t;
			Y = (O.media_riga(t))/ ( S0S0);
			Z = O.jackknife_riga(t)/S0S0;
			grafico_add( X, Y, Z, nomeFile);
		}


	}


return(0);
}
