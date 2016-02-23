/*
	STUDIO DELLA TERMALIZZAZIONE
Per vari valori di eta ( prima, durante e dopo al zona metacritica ) si realizano 3 grafici
1) H di boltzman istantanea  (a partire dalla configurazione Bcc iniziale) in funzione del numero di step (urti)
2) H di Boltzman calcolata su N configurazioni successive( a partire dalla configurazione bcc) in funzione di N
3) Istogramma delle velocità vx campionate su alcune configurazioni prese ad un certo numero di urti di distanza

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
#include "vettori_fisici.h"
#include "tempi_collisione.h"
#include "STRUTTURONA_sfere_rigide.h"


int main()
{
	int d= 3;
	int N=7;// numero di particellle lungo un lato
	double eta=0.615;
	sistema_rigido sistema(d, N, eta);
	sistema.CheckSovrapposizione();

	int n_graf = 2;
	double eta_max= eta, eta_min=0.415;
	double eta_step= (eta_max - eta_min)/n_graf;

	int Ncollisioni = 5000;



	for(int i=0;i<=n_graf;i++){
		eta = eta_max - eta_step*i;
		printf("\n#- %d-simo Grafico --- reimposto impacchettamento a eta = %f \n",i,eta);
		string nomeFile;

		// --------- GRAFICO 1)  -----------
		sistema_rigido sistema1(d, N, eta);
		if(sistema1.CheckSovrapposizione()==false){ cout<<"\t a eta= "<<eta<<" le particelle sono sovrapposte"<<endl;break;}

		stringstream sstm;	
		sstm << "Output/Preliminari/Termalizzazione/HistvsStep_eta"<<i<<".dat";
		nomeFile = sstm.str();
		grafico_start(nomeFile,"#Nstep\t\t#H_istantaneo");
		cout<<"##--- Costruzione grafico (1) : "<<nomeFile<<endl;

		double H;
		for(int n=0; n<Ncollisioni; n++){
			cout<<"##--- Punto : "<<n<<" / "<<Ncollisioni-1 << string(500,'\b');
			H = sistema1.H_Boltzman(N*2);
			grafico_add(nomeFile, 2, (double)n, (double)H);
			sistema1.evoluzione();
		}
		cout<<endl;
	
		// --------- GRAFICO 2)  -----------
		sistema_rigido sistema2(d, N, eta);
		if(sistema2.CheckSovrapposizione()==false){ cout<<"\t a eta= "<<eta<<" le particelle sono sovrapposte"<<endl;break;}

		stringstream sstm2;	
		sstm2 << "Output/Preliminari/Termalizzazione/HmediovsStep_eta"<<i<<".dat";
		nomeFile = sstm2.str();
		grafico_start(nomeFile,"#Nstep\t\t#H_mediato");
		cout<<"##--- Costruzione grafico (2) : "<<nomeFile<<endl;

		int Ndati = Ncollisioni*sistema2.M;
		double Vx[Ndati];
		sistema2.Raccolta_Vx(Ncollisioni, 2, Vx);

		for(int n=0; n<Ncollisioni; n++){
			cout<<"##--- Punto : "<<n<<" / "<<Ncollisioni-1 << string(500,'\b');
			H = Boltzman(sistema2.M, Vx, sistema2.M*(n+1));
			grafico_add(nomeFile, 2, (double)n, (double)H);
		}
		cout<<endl;

		// --------- GRAFICO 2)  -----------
		stringstream sstm3;	
		sstm3 << "Output/Preliminari/Termalizzazione/IstoVx_eta"<<i<<".dat";
		nomeFile = sstm3.str();
		cout<<"##--- Costruzione istogramma finale: "<<nomeFile<<endl;sistema.stampa_stato("Test/prova.dat");
	
		sistema2.Raccolta_Vx(Ncollisioni, sistema2.M , Vx);
		istogramma( sistema.M, Vx, Ndati,nomeFile);
	
	}

return(0);
}
