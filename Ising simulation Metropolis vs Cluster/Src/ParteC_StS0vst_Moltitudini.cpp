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

void grafico_spazio(int k,string nomeFile){
	ofstream myfile(nomeFile.c_str(),ios::app);
	myfile<< endl<<endl<<"# NUMERO"<<k<<endl;
	myfile.close();
}

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
	int n_graf_1=40, n_graf_2=40;
	int n_graf_tot= n_graf_1 + n_graf_2;

	double beta_min=0.01;
	double beta_max=0.4;
	double beta_step= (beta_max-beta_min)/(n_graf_1);

		stringstream sstm;
		sstm << "Output/ParteC/"<<"molti_S0Stvst_"<<".dat";
		string nomeFile = sstm.str();


	for(int k=0;k<n_graf_1;k++){
		double beta= beta_min + beta_step*k;
		cout<<"\n>>>>> "<<k<<" / "<< n_graf_tot <<" RACCOLTA S_0 * S_t PER GRAFICO  (beta = "<<beta<<" )"<<endl;
		sistema.evol_SwenWang(beta, 30);
		sistema.Raccolta_St_Cluster( beta, O, Nmarkov);	

		double S0S0 = O.media_riga(0);
		cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;

		for(int t=0;t<n_dots;t++){
			cout<<"\t \t"<<t<<" / "<<n_dots<<" punto" << string(300,'\b');
			X = t;
			Y = O.media_riga(t)/S0S0;
			Z = O.jackknife_riga(t)/S0S0;
			grafico_add( X, Y, Z, nomeFile);
		}
		grafico_spazio(k+1,nomeFile);
	}


	beta_min=beta_max;								
	beta_max=beta_crit;
	beta_step= (beta_max-beta_min)/(n_graf_2);

	for(int k=n_graf_1;k<=n_graf_tot;k++){
		double beta= beta_min + beta_step*(k-n_graf_1);
		cout<<"\n>>>>> "<<k<<" / "<< n_graf_tot <<" RACCOLTA S_0 * S_t PER GRAFICO  (beta = "<<beta<<" )"<<endl;
		sistema.evol_SwenWang(beta, 30);
		sistema.Raccolta_St_Cluster( beta, O, Nmarkov);	

		double S0S0 = O.media_riga(0);

		for(int t=0;t<n_dots;t++){
			cout<<"\t \t"<<t<<" / "<<n_dots<<" punto" << string(300,'\b');
			X = t;
			Y = O.media_riga(t)/S0S0;
			Z = O.jackknife_riga(t)/S0S0;
			grafico_add( X, Y, Z, nomeFile);
		}
		grafico_spazio(k+1,nomeFile);
	}
return(0);
}
