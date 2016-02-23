/*
	PROBLEMA 9
Studiare la fluttazione del valore istantaneo della densità di energia interna a densità rho*=0.7 termalizzando a temperatura <KT>*=1.19 a 2 diversi valori di N

PRODUCE:
	- due grafici di U*_istantanea verso tempo di evoluzione
	- 2 istogrammi della distribuzione dei valori di U_istantanea campionati
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

	int d= 3;
	double rho = 0.7;	double T_D=1.19;

	int N[2];// numero esatto di particellle
	N[0]=108;
	N[1]=500;

	int Nconfigurazioni = 100000;					//Numero di U_istantanei raccolti per ogni sistema
	double U[Nconfigurazioni];						//
	double Dt= 0.015;								//distanza temporale tra le configurazioni
	int n_int=200;									//numero di intervalli su cui si calcola l'istogramma

	for(int k = 0; k < 2 ; k++){
		sistema_soffice sistema(d, N[k], rho);
		sistema.termalizzazione_kTfissa(5000, T_D);	//Termalizzo per 500 passi

		sistema.Raccolta_U(Nconfigurazioni, Dt, U);

		//Uso i dati raccolti per costruire grafico dell'U istantanea verso gli step
		stringstream sstm;
		sstm << "Output/Problema9/"<<"UvsStep_N"<< N[k] <<".dat";
		string nomeFile = sstm.str();
		stringstream sstm2;
		sstm2 << "# U medio = "<< (double)media(U,Nconfigurazioni)<<" +/- "<<(double)deviazione_standard(U,Nconfigurazioni);
		string Titolo = sstm2.str();
		cout<<"\n#- >>>>> Costruzione Grafico U_i verso tempo : "<<nomeFile<<endl;
		grafico_start(nomeFile,Titolo);
		for(int i = 0; i< Nconfigurazioni; i++){
			double t = Dt + Dt*i;
			grafico_add(nomeFile, 2, (double)t, (double)U[i]);
		}

		//Uso i dati raccolti per realizzare l'istogramma
		stringstream sstm3;
		sstm3 << "Output/Problema9/"<<"IstoU_N"<< N[k] <<".dat";
		nomeFile = sstm3.str();
		cout<<"\n#- >>>>> Costruzione istogramma delle distribuzioni di U_istantanea : "<<nomeFile<<endl;
		istogramma( n_int, U, Nconfigurazioni,nomeFile);

	}

return(0);
}
