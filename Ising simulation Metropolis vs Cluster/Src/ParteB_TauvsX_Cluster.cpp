/*
STUDIO ANDAMENTO DEL TEMPI DI AUTOCORRELAZIONE VS X 
	(ALGORITMO SWENDEN WANG)
	produce un grafico tau vs x

*/




#include <iostream>
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
	microstato sistema(100);				//inizializzo la classe microstato

	int Nmarkov=5000;					//numero di elementi della catana di markov su cui produco la statistica
	double O[Nmarkov];					//array dei valori assunti dall Osservabile istantaneo sulla catena

	int t_max=100;				//# massimo valore di sfasamento tra campio di M elementi (quindi troncamento per la serie di tau)

	int n_dots_1=30, n_dots_2 = 3 * n_dots_1, n_dots_3 = n_dots_1; 
	int n_dots_tot=n_dots_1 +n_dots_2 + n_dots_3; 					//# punti per sezione / # punti totali
	double X[n_dots_tot] , Y[n_dots_tot];		//array ascissa ordinata del grafico

	int k = 0;
	double x_min=-0.15,x_max=-0.05;													//Primo intervallo_ prima della zona critica
	double x_step= (x_max-x_min)/n_dots_1;
	while (k < n_dots_1){	
		double x = x_min + k*x_step;
		double beta= beta_crit*(x + 1);
		cout<<"\n>>>>> "<<k<<"-sima Raccolta tau su "<<n_dots_tot<<"(beta = "<<beta<<" )"<<endl;
		X[k] = x;
		sistema.evol_SwenWang(beta, 100);
		sistema.Raccolta_H_Cluster( beta, O, Nmarkov);
		Y[k]=Tau(O, Nmarkov, t_max);
		k++;
	}
	x_min = x_max,	x_max = 0.05;													//Secondo intervallo_  zona critica
	x_step= (x_max-x_min)/(n_dots_2);
	while (k < n_dots_1 + n_dots_2){	
		double x = x_min + (k - n_dots_1)*x_step;
		double beta= beta_crit*(x + 1);
		cout<<"\n>>>>> "<<k<<"-sima Raccolta tau su "<<n_dots_tot<<"(beta = "<<beta<<" )"<<endl;
		X[k] = x;
		sistema.evol_SwenWang(beta, 100);
		sistema.Raccolta_H_Cluster( beta, O, Nmarkov);
		Y[k]=Tau(O, Nmarkov, t_max);
		k++;
	}
	x_min = x_max,	x_max = 0.15;													//Terzo intervallo_  dopo zona critica
	x_step= (x_max-x_min)/(n_dots_3);
	while (k < n_dots_tot){	
		double x = x_min + (k - (n_dots_1 + n_dots_2))*x_step;
		double beta= beta_crit*(x + 1);
		cout<<"\n>>>>> "<<k<<"-sima Raccolta tau su "<<n_dots_tot<<"(beta = "<<beta<<" )"<<endl;
		X[k] = x;
		sistema.evol_SwenWang(beta, 100);
		sistema.Raccolta_H_Cluster( beta, O, Nmarkov);
		Y[k]=Tau(O, Nmarkov, t_max);
		k++;
	}

	string nomeFile= "Output/ParteB/Tau/Cluster_TauHvsX.dat";
	cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;
	grafico(n_dots_tot, X, Y, nomeFile);
return(0);
}
