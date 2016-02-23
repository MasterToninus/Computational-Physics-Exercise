/*
STUDIO andamento H/VOL VS STEP PER VARI VALORI DI BETA

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

#define beta_crit 0.4406868


int main()
{
	int N = 100;
	microstato sistema(N);				//inizializzo la classe microstato

	

	int Nmarkov=700;					//numero di elementi della catana di markov su cui produco la statistica
	double O[Nmarkov];					//array dei valori assunti dall Osservabile istantaneo sulla catena
	double beta= 0.3;

//RACCOLTA A PARTIRE DA FASE PARAMAGNETICA

	cout<<"\n>>>>> RACCOLTA M CON BETA = "<<beta<<endl;
	sistema.Raccolta_M_Metropolis( beta, O, Nmarkov);	
	string nomeFile = "Output/ParteB/Termalizzazione/Confronto_Metro_M.dat"; 
	cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;
	grafico(Nmarkov, 1, 1, O, nomeFile);


	cout<<"\n>>>>> RACCOLTA |M| CON BETA = "<<beta<<endl;
	sistema.Raccolta_M_abs_Metropolis( beta, O, Nmarkov);	
	nomeFile = "Output/ParteB/Termalizzazione/Confronto_Metro_M_abs.dat"; 
	cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;
	grafico(Nmarkov, 1, 1, O, nomeFile);


	cout<<"\n>>>>> RACCOLTA M improved CON BETA = "<<beta<<endl;
	sistema.Raccolta_M_Cluster_Improved( beta, O, Nmarkov);	
	nomeFile = "Output/ParteB/Termalizzazione/Confronto_Cluster_M.dat"; 
	cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;
	grafico(Nmarkov, 1, 1, O, nomeFile);


return(0);
}
