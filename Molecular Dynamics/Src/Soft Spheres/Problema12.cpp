/*
PROBLEMA 12
Studiare l'andamento dei valori degli osservabili macroscopici medi in funzione del numero N di particella della simulazione( con densità rho*=0.7 e termalizzata a temperatura <KT>*=1.19) per determinare il valore d'aspettazione al limite termodinamico.

PRODUCE:
	-3 grafici di <O> vs N
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
	double rho = 0.7;	double E_D=-2.98;

	stringstream sstm1;
	sstm1 << "Output/Problema12/"<<"UvsN"<<".dat";
	string FileU = sstm1.str();
//	grafico_start(FileU);

	stringstream sstm2;
	sstm2 << "Output/Problema12/"<<"TvsN"<<".dat";
	string FileT = sstm2.str();
//	grafico_start(FileT);

	stringstream sstm3;
	sstm3 << "Output/Problema12/"<<"PvsN"<<".dat";
	string FileP = sstm3.str();
//	grafico_start(FileP);

	int Nconfigurazioni = 50000;	
	double P[Nconfigurazioni];						//per ogni punto Raccolgo Nconfigurazioni valori di temperatura istantanea
	double T[Nconfigurazioni];						//per ogni punto Raccolgo Nconfigurazioni valori di temperatura istantanea
	double U[Nconfigurazioni];						//per ogni punto Raccolgo Nconfigurazioni valori di temperatura istantanea

	int N_i=500;// numero esatto di particellle
	int N_dots=5, N_step= 100;
	for(int i = 4; i<= N_dots; i++){
		int N = N_i + N_step*i;
		sistema_soffice sistema(d, N, rho);	
		cout<<">>>>> Punto "<<i<<" / "<<N_dots<<" <<<<<< ( Nparticelle = "<<N<<") \n#"<<endl;


		sistema.termalizzazione_Efissa(1000, E_D);	//Termalizzo per 500 passi

		sistema.Raccolta_Stato_Completo(Nconfigurazioni, 0.05, P, T, U);

		grafico_add(FileP, 3, (double)N, (double)media(P,Nconfigurazioni), (double)deviazione_standard(P,Nconfigurazioni));
		grafico_add(FileT, 3, (double)N, (double)media(T,Nconfigurazioni), (double)deviazione_standard(T,Nconfigurazioni));
		grafico_add(FileU, 3, (double)N, (double)media(U,Nconfigurazioni), (double)deviazione_standard(U,Nconfigurazioni));

		if(N%50==0){
			int n_int = 200;

			//Uso i dati raccolti per realizzare l'istogramma
			stringstream sstm4;
			sstm4 << "Output/Problema12/"<<"IstoU_N"<< N<<".dat";
			string nomeFile = sstm4.str();
			cout<<"\n#- >>>>> Costruzione istogramma delle distribuzioni di U_istantanea : "<<nomeFile<<endl;
			istogramma( n_int, U, Nconfigurazioni,nomeFile);
	
			stringstream sstm5;
			sstm5 << "Output/Problema12/"<<"IstoT_N"<< N<<".dat";
			nomeFile = sstm5.str();
			cout<<"\n#- >>>>> Costruzione istogramma delle distribuzioni di T_istantanea : "<<nomeFile<<endl;
			istogramma( n_int, T, Nconfigurazioni,nomeFile);

			stringstream sstm6;
			sstm6 << "Output/Problema12/"<<"IstoP_N"<< N<<".dat";
			nomeFile = sstm6.str();
			cout<<"\n#- >>>>> Costruzione istogramma delle distribuzioni di P_istantanea : "<<nomeFile<<endl;
			istogramma( n_int, P, Nconfigurazioni,nomeFile);
		}

	cout<<endl;
	}



return(0);
}
