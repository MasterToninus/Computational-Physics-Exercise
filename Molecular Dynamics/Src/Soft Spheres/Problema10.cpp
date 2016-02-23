/*
	PROBLEMA 10
Studiare la fluttazione del valore istantaneo delle osservabili macroscopiche istantanee PTU a densità rho*=0.6, a N=108 fisso e  termalizzando a temperatura <KT>*=1.22

PRODUCE:
	- 3 grafici di O_istantanea verso tempo di evoluzione
	- 3 istogrammi della distribuzione dei valori di O_istantanea campionati

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
	double rho = 0.6;	double T_D=1.22;
	int N=108;// numero esatto di particellle
	double Dt= 0.015;
	sistema_soffice sistema(d, N, rho);



	int Nconfigurazioni = 10000;	
	double P[Nconfigurazioni];						
	double T[Nconfigurazioni];					
	double U[Nconfigurazioni];		
	sistema.evoluzione_muto(10);			
	sistema.termalizzazione_kTfissa(5000, T_D);	//Termalizzo per 500 passi

	sistema.Raccolta_Stato_Completo(Nconfigurazioni, Dt, P, T, U);

	int n_int = 150;

	string nomeFile = "Output/Problema10/IstoP.dat";
	cout<<"\n#- >>>>> Costruzione istogramma delle distribuzioni di P_istantanea : "<<nomeFile<<endl;
	istogramma( n_int, P, Nconfigurazioni,nomeFile);

	nomeFile = "Output/Problema10/IstoT.dat";
	cout<<"\n#- >>>>> Costruzione istogramma delle distribuzioni di T_istantanea : "<<nomeFile<<endl;
	istogramma( n_int, T, Nconfigurazioni,nomeFile);

	nomeFile = "Output/Problema10/IstoU.dat";
	cout<<"\n#- >>>>> Costruzione istogramma delle distribuzioni di U_istantanea : "<<nomeFile<<endl;
	istogramma( n_int, U, Nconfigurazioni,nomeFile);


	string FileU ="Output/Problema10/UvsStep.dat";
	stringstream sstm1;
	sstm1 << "# U_media "<<media(U,Nconfigurazioni)<<"\t +/-"<<deviazione_standard(U,Nconfigurazioni);
	grafico_start(FileU,sstm1.str());

	string FileT ="Output/Problema10/TvsStep.dat";
	stringstream sstm2;
	sstm2 << "# T_media "<<media(T,Nconfigurazioni)<<"\t +/-"<<deviazione_standard(T,Nconfigurazioni);
	grafico_start(FileT,sstm2.str());

	string FileP ="Output/Problema10/PvsStep.dat";
	stringstream sstm3;
	sstm3 << "# P_media "<<media(P,Nconfigurazioni)<<"\t +/-"<<deviazione_standard(P,Nconfigurazioni);
	grafico_start(FileP,sstm3.str());

	cout<<"\n#- >>>>> Costruzione Grafici andamento delle Osservabili istantanee : "<<endl;
	cout<<FileP<<"\t"<<FileT<<"\t"<<FileU<<endl;
	for(int i = 0; i< Nconfigurazioni; i++){
	double t = Dt + Dt*i;
	grafico_add(FileP, 2, (double)t, (double)P[i]);
	grafico_add(FileT, 2, (double)t, (double)T[i]);
	grafico_add(FileU, 2, (double)t, (double)U[i]);
	}


	sistema.stampa_stato_completo("/Problema10/Stato_Finale.dat");

return(0);
}
