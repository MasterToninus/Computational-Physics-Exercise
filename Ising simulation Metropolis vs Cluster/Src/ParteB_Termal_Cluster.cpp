/*
STUDIO andamento M/VOL VS STEP PER VARI VALORI DI BETA algoritmo swen wang

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
	int N = 100;
	microstato sistema(N);				//inizializzo la classe microstato

	int Nmarkov=300;					//numero di elementi della catana di markov su cui produco la statistica
	double M[Nmarkov];					//array dei valori assunti dall Osservabile istantaneo sulla catena
	double M_quad[Nmarkov];					//array dei valori assunti dall Osservabile istantaneo sulla catena
	double H[Nmarkov];					//array dei valori assunti dall Osservabile istantaneo sulla catena

	double beta_h= 2, beta_c= beta_crit , beta_l= 0.01;

//RACCOLTA A PARTIRE DA FASE PARAMAGNETICA

//	sistema.sciogli();
	cout<<"\n>>>>> RACCOLTA M,H CON BETA = "<<beta_l<<endl;
	sistema.Raccolta_Tutto_Cluster( beta_l, M,M_quad,H, Nmarkov);	
	string nomeFile = "Output/ParteB/Termalizzazione/Cluster_Mvsstep_TH_para.dat"; 
	cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;
	grafico(Nmarkov, 1, 1, M, nomeFile);
	nomeFile = "Output/ParteB/Termalizzazione/Cluster_Hvsstep_TH_para.dat"; 
	grafico(Nmarkov, 1, 1, H, nomeFile);


	sistema.sciogli();
	sistema.rinizializza(N);
	sistema.Raccolta_Tutto_Cluster( beta_c, M,M_quad,H, Nmarkov);	
	nomeFile = "Output/ParteB/Termalizzazione/Cluster_Mvsstep_Tc_para.dat"; 
	cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;
	grafico(Nmarkov, 1, 1, M, nomeFile);
	nomeFile = "Output/ParteB/Termalizzazione/Cluster_Hvsstep_Tc_para.dat"; 
	grafico(Nmarkov, 1, 1, H, nomeFile);

	sistema.sciogli();
	sistema.rinizializza(N);
	sistema.Raccolta_Tutto_Cluster( beta_h, M,M_quad,H, Nmarkov);	
	nomeFile = "Output/ParteB/Termalizzazione/Cluster_Mvsstep_TL_para.dat"; 
	cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;
	grafico(Nmarkov, 1, 1, M, nomeFile);
	nomeFile = "Output/ParteB/Termalizzazione/Cluster_Hvsstep_TL_para.dat"; 
	grafico(Nmarkov, 1, 1, H, nomeFile);

//RACCOLTA A PARTIRE DA FASE FERROMAGNETICA

	sistema.congela();
	cout<<"\n>>>>> RACCOLTA M,H CON BETA = "<<beta_h<<endl;
	sistema.Raccolta_Tutto_Cluster( beta_h, M,M_quad,H, Nmarkov);	
	nomeFile = "Output/ParteB/Termalizzazione/Cluster_Mvsstep_TL_ferro.dat"; 
	cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;
	grafico(Nmarkov, 1, 1, M, nomeFile);
	nomeFile = "Output/ParteB/Termalizzazione/Cluster_Hvsstep_TL_ferro.dat"; 
	grafico(Nmarkov, 1, 1, H, nomeFile);

	sistema.congela();
	cout<<"\n>>>>> RACCOLTA M,H CON BETA = "<<beta_c<<endl;
	sistema.Raccolta_Tutto_Cluster( beta_c, M,M_quad,H, Nmarkov);	
	nomeFile = "Output/ParteB/Termalizzazione/Cluster_Mvsstep_Tc_ferro.dat"; 
	cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;
	grafico(Nmarkov, 1, 1, M, nomeFile);
	nomeFile = "Output/ParteB/Termalizzazione/Cluster_Hvsstep_Tc_ferro.dat"; 
	grafico(Nmarkov, 1, 1, H, nomeFile);

	sistema.congela();
	cout<<"\n>>>>> RACCOLTA M,H CON BETA = "<<beta_l<<endl;
	sistema.Raccolta_Tutto_Cluster( beta_l, M,M_quad,H, Nmarkov);	
	nomeFile = "Output/ParteB/Termalizzazione/Cluster_Mvsstep_TH_ferro.dat"; 
	cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;
	grafico(Nmarkov, 1, 1, M, nomeFile);
	nomeFile = "Output/ParteB/Termalizzazione/Cluster_Hvsstep_TH_ferro.dat"; 
	grafico(Nmarkov, 1, 1, H, nomeFile);

return(0);
}
