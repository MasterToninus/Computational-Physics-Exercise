/*
PRELIMINARI - STUDIO DELLA TERMALIZZAZIONE
Mantenendo N e T_D/ E_D fissi si studia il numero di step necessari per termalizzare un sistema a rho definito.

PRODUCE:
1) Si stampa andamento degli osservabili istantanei P*,T*,U* istantanei  (a partire dalla configurazione Bcc iniziale termalizzata ad E_D) in funzione del numero di step (Tempo di evoluzione)
2) Si stampa H di Boltzman calcolata su N configurazioni successive a partire da una configurazione ottenuta dopo n passi di termalizzazione a temperatura definita in funzione del numero n di passi di termalizzazione
3) Istogramma delle velocità vx campionate su alcune configurazioni raccolte ad una certa distanza e campionate dopo tutte le evoluzioni precedenti

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
	int N=250;// numero esatto di particellle


	int n_graf=2;
	double E_D= 1;
	double T_D= 1;
	double rho_min= 0.6, rho_step=0.3;


	for(int i=0;i<=n_graf;i++){
		double rho = rho_min + rho_step*i;
		printf("\n#################\n#- %d-simo Grafico --- imposto densità a rho = %f \n#################\n",i,rho);
		string nomeFile;

		// ---------  GRAFICO 1)  -----------
		sistema_soffice sistema1(d, N,rho);	 			//inizializzo il sistema
		sistema1.termalizzazione_Efissa(0, E_D);

		double Dt= 0.001	;	//intervallo di tempo tra campionature
		int Nconfigurazioni = 5000;	
		double P[Nconfigurazioni];						
		double T[Nconfigurazioni];					
		double U[Nconfigurazioni];		
		cout<<"##--- Costruzione grafico (1) : "<<nomeFile<<endl;
		sistema1.Raccolta_Stato_Completo(Nconfigurazioni, Dt, P, T, U);

		stringstream sstm1_nome;
		sstm1_nome <<"Output/Preliminari/Termalizzazione/UvsStep_Rho"<<i<<".dat";
		string FileU = sstm1_nome.str();
		stringstream sstm1A;
		sstm1A << "# U_media "<<media(U,Nconfigurazioni)<<"\t +/-"<<deviazione_standard(U,Nconfigurazioni);
		grafico_start(FileU,sstm1A.str());

		stringstream sstm2_nome;
		sstm2_nome <<"Output/Preliminari/Termalizzazione/TvsStep_Rho"<<i<<".dat";
		string FileT = sstm2_nome.str();
		stringstream sstm1B;
		sstm1B << "# T_media "<<media(T,Nconfigurazioni)<<"\t +/-"<<deviazione_standard(T,Nconfigurazioni);
		grafico_start(FileT,sstm1B.str());

		stringstream sstm3_nome;
		sstm3_nome <<"Output/Preliminari/Termalizzazione/PvsStep_Rho"<<i<<".dat";
		string FileP = sstm3_nome.str();
		stringstream sstm1C;
		sstm1C << "# P_media "<<media(P,Nconfigurazioni)<<"\t +/-"<<deviazione_standard(P,Nconfigurazioni);
		grafico_start(FileP,sstm1C.str());

		for(int k = 0; k< Nconfigurazioni; k++){
			grafico_add(FileP, 2, (double)k, (double)P[k]);
			grafico_add(FileT, 2, (double)k, (double)T[k]);
			grafico_add(FileU, 2, (double)k, (double)U[k]);
		}

		cout<<endl;
	
		// ---------  GRAFICO 2)  -----------
		sistema_soffice sistema2(d, N, rho);	sistema2.stampa_stato_completo("Test/Stato_inizio.dat");

		int Npassi = 25; 		//# di campionature per calcolo della H
		int Ndati = Npassi*N;	//# di Dati per il calcolo di H
		double Vx[Ndati];		//# lista dei valori di vx per calcolare H
		Dt= 0.005;				//intervallo di tempo tra le campionature

		stringstream sstm2;	
		sstm2 << "Output/Preliminari/Termalizzazione/HmediovsStepTD_rho"<<i<<".dat";
		nomeFile = sstm2.str();
		grafico_start(nomeFile,"#NstepT_D\t\t#H_mediato");
		cout<<"##--- Costruzione grafico (2) : "<<nomeFile<<endl;

		for(int n=0; n<=Nconfigurazioni; n++){
			cout<<"##--- Punto : "<<n<<" / "<<Nconfigurazioni<< string(500,'\b');
			sistema2.termalizzazione_kTfissa(1, T_D);
//			sistema2.stampa_stato_completo("Test/Stato_test2.dat");
			sistema_soffice dummy(sistema2);
			dummy.Raccolta_Vx(Npassi, Dt, Vx);
			double H = Boltzman(Npassi*2, Vx, Ndati);
			grafico_add(nomeFile, 2, (double)n, (double)H);
//			sistema2.stampa_stato_completo("Test/Stato_test1.dat");
		}
		cout<<endl;

		// ---------  GRAFICO 3)  -----------

		stringstream sstm3;	
		sstm3 << "Output/Preliminari/Termalizzazione/IstoVx_TD_rho"<<i<<".dat";
		nomeFile = sstm3.str();
		cout<<"##--- Costruzione istogramma finale: "<<nomeFile<<endl;
		Dt= 0.05;
		Npassi= 5000;
		Ndati = Npassi*N;
		double Vx2[Ndati];	


		sistema2.termalizzazione_kTfissa(Npassi, T_D);
		sistema2.Raccolta_Vx(Npassi, Dt , Vx2);
		istogramma( N, Vx2, Ndati,nomeFile);
	}

return(0);
}
