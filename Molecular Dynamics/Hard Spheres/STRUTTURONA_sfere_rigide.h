//    Classe SISTEMA sfere rigide



class sistema_rigido {
	double eta; 	// Frazione d'impacchettamento del sistema
	int d; 			// Dimensione spaziale 2d 3d ecc
	double sigma; 	// Diametro delle particelle
	double L ;

public:
	int M; 	// M :numero di particelle (numero esatto in BCC)
//Attributi di stato
	vector<vettore> P0; 			//vector delle posizioni
/*|||*/	vector<vettore> Pdiffusa; 	//vector delle posizioni del particelle quando le condizioni di bordo non vengono applicate
	vector<vettore> v0; 			//vector dei vettori velocità
	double **Tc; 					//matrice tavola di collisione

//Attributi di controllo
	clock_t start,end;				//variabili di controllo tempo di esecuzione
	double tempo;

	sistema_rigido() //costruttore SISTEMA DI TEST
	{
		d=2;
		M=4; // M :numero di particelle (numero esatto in BCC)
		L = 1.;
		sigma= 1./10;
		cout<<"#----------------------------------------------------------------------------------------------------#"<<  endl;
		printf("#---- Inizializzazione sistema %dD DI PROVA---------------#\n",d,M,eta);		
		start=clock();	

		P0.push_back(vettore(sigma/2,L-sigma/2) );				P0.push_back(vettore(L-sigma/2,sigma/2) );
		P0.push_back(vettore(L/4+sigma/2,L/4+sigma/2) );		P0.push_back(vettore(3*L/4-sigma/2,3*L/4-sigma/2) );

/*|||*/		Pdiffusa.resize(M,0);
/*|||*/		CollassaDiffusione();
		bool p = CheckSovrapposizione();
		if(p==false)cout<<"errore! particelle compenetrate\n\n\n\n\n\n\n TERMINARE ctrl + z \n\n "<<endl;

		double vel=sigma/2;
		v0.push_back(vettore(vel,-vel));					v0.push_back(vettore(-vel,vel));
		v0.push_back(vettore(vel,vel));						v0.push_back(vettore(-vel,-vel));

		// 4° fase. costruisco tavola collisione
			//allocazione dinamica della memoria per la tavola collisioni http://www.hwupgrade.it/forum/showthread.php?t=1332311
			/* allocazione vettore righe (ogni elemento del vettore è un puntatore) */
				Tc = (double**)malloc( M * sizeof(double) );
			/* Per ogni riga si allocano le colonne */
				for(int i=0; i<M; i++) Tc[i] = (double*)malloc( M * sizeof(double) );
		Tc[M][M]; //matrice tavola di collisione
			//cout<<"#- Costruzione Tavola Collisioni in corso ..."<<endl;
		CostruzioneTavolaCollisione();
		
		cout<<"#---- Fine Inizializzazione del sistema  \t ------------ \t t_esec = "<<tempo_esec()<<" secondi"<<"\t ------------#"<<endl;
		cout<<"#----------------------------------------------------------------------------------------------------#"<<endl<<"#"<<endl;
	}
	
	sistema_rigido(int dim, int N, double eta_in) //costruttore inizializza il sistema e calcola la matrice dei tempi di collisione
	{
		d=dim;eta=eta_in;
		M=2*PowInt(N,d); // M :numero di particelle (numero esatto in BCC)
		L = 1.;
		double passo= 1./N; //passo della configurazione iniziale (L = 1.)
		cout<<"#----------------------------------------------------------------------------------------------------#"<<  endl;
		printf("#---- Inizializzazione sistema %dD composto da %d particelle con impacchettamento %1.3f---------------#\n",d,M,eta);		
		start=clock();	
		cout<<"#----------------------------------------------------------------------------------------------------#"<<  endl;

	// 0° fase. calcolo la sigma
		if(d==2)	sigma= pow(4*eta/(M*M_PI),(double)1/2) ;
		else if(d==3)	sigma= pow(6*eta/(M*M_PI),(double)1/3) ;
		else{cout<< " non so ancora farlo con dimensione "<< d<<endl;}
		if(sigma >= passo*sqrt(d)/2)cout<<"errore! particelle compenetrate\n\n\n\n\n\n\n TERMINARE ctrl + z \n\n "<<endl;	
	
	// 1° fase. dispongo le particelle in BCC
		if(d==2)
		{
			for(int i=0; i<N; i++)for(int j=0; j<N; j++){ 
				P0.push_back(vettore(sigma/2,sigma/2) + vettore(passo/2 + i*passo,passo/2 + j*passo));
			}
			for(int i=0; i<N; i++)for(int j=0; j<N; j++){ //facce centrali
				P0.push_back(vettore(sigma/2,sigma/2) + vettore((i)*passo,(j)*passo));
			}
		}	
		if(d==3)
		{
			for(int i=0; i<N; i++)for(int j=0; j<N; j++)for(int k=0; k<N; k++){ 
				P0.push_back(vettore(passo/2 + i*passo,passo/2 + j*passo,passo/2 + k*passo));
			}
			for(int i=0; i<N; i++)for(int j=0; j<N; j++)for(int k=0; k<N; k++){  //facce centrali
				P0.push_back(vettore((i)*passo, (j)*passo, (k)*passo));
			}
		}			

	// 1.5° fase. Inizializzo vector delle posizioni diffuse
/*|||*/		Pdiffusa.resize(M,0);
/*|||*/		CollassaDiffusione();

		bool p= CheckSovrapposizione();
		if(p==false)cout<<"errore! particelle compenetrate\n\n\n\n\n\n\n TERMINARE ctrl + z \n\n "<<endl;
		else{
		// 2° fase. inizializzo le velocità
			srand((unsigned)time(0)); // togliere da quiiii!!!! andrebbe messo fuori...<<<<<<<<<<<<<<<<<<<<<[@@@@@@@@@@@]
			double a=0.5; //ampiezza distribuzione velocità
			if(d==2){
				for(int j=0; j<M; j++){ v0.push_back(vettore( ((double)rand()/RAND_MAX)*a-a/2 ,((double)rand()/RAND_MAX)*a-a/2));}}
			if(d==3){
				for(int j=0; j<M; j++){ v0.push_back(vettore( ((double)rand()/RAND_MAX)*a-a/2 ,((double)rand()/RAND_MAX)*a-a/2,((double)rand()/RAND_MAX)*a-a/2));}}

		// 3° fase. riscalare le velocità
			//velocità totale
			vettore vtot=MomentoTotale();
			//scalare le velocità per avere momento nullo
			for(int j=0; j<M; j++){v0[j] -= vtot/M;}
			//scalare la velocità per avere kt unitario (è unità di misura dell'energia)
			double fattore = sqrt(1/kT());
			for(int j=0; j<M; j++){v0[j] *= fattore;}

			printf("#----- \t Px: %1.4f \t-----\tE_Tot: %1.2f \t-----\tkT: %1.2f ------------------------------------#\n", MomentoTotale().x(),EnergiaTotale(),kT());
		// 4° fase. costruisco tavola collisione
			//allocazione dinamica della memoria per la tavola collisioni http://www.hwupgrade.it/forum/showthread.php?t=1332311
			/* allocazione vettore righe (ogni elemento del vettore è un puntatore) */
				Tc = (double**)malloc( M * sizeof(double) );
			/* Per ogni riga si allocano le colonne */
				for(int i=0; i<M; i++) Tc[i] = (double*)malloc( M * sizeof(double) );
			Tc[M][M]; //matrice tavola di collisione
			//cout<<"#- Costruzione Tavola Collisioni in corso ..."<<endl;
			CostruzioneTavolaCollisione();
			}
		cout<<"#---- Fine Inizializzazione del sistema  \t ------------ \t t_esec = "<<tempo_esec()<<" secondi"<<"\t ------------#"<<endl;
		cout<<"#----------------------------------------------------------------------------------------------------#"<<endl<<"#"<<endl;
	}


	//~sistema_rigido();

//Metodi di "Servizio"
	int Rinizializza( double eta_new);
	void CollassaDiffusione();//pone tutte le posizioni del sistema diffuso come quelle del sistema con bordo
private:
	double Tempo_Collisione_Immagini(int i_1, int i_2);	//calcola il tempo di collisione tra due particelle con metodo immagini
	void CostruzioneTavolaCollisione();					//costruisce tavola di collisione
	double CalcoloTempoCollisione(int *i_urto, int *j_urto);	//determina il minimo della matrice e le particelle urtanti
	void EvoluzionePosizioniParticelle(double t_urto);			//evolve le particelle di un tempo t_urto e applica le condizioni period
	vettore vettoreseparazione_immagini(int i,int j);			//calcola il vettore separazione tra due particelle considerando period
	double distanza_immagini(int i,int j);
	double EvoluzioneVelocitaParticelle(int i_urto, int j_urto);//evolve velocità delle particelle urtanti (restituisce modulo della variazione)
	void AggiornamentoTavolaCollisione(double Tc, int i_urto, int j_urto);
	double distanza_immagini(vettore P1, vettore P2);


public:
//Metodi di stato
vettore MomentoTotale();
double EnergiaTotale(); 
double kT();
double H_Boltzman();
double H_Boltzman(int Ncolonne);

//Met0di di controllo
double tempo_esec();
bool CheckSovrapposizione();
void stampa_stato(string riga); // in ingresso una stringa
void stampa_stato_diffusione(string riga);
void stampa_tavolacollisioni();
void stampa_tavolacollisioni(string riga);


//Metodi di evoluzione del sistema
double evoluzione();
double evoluzione(int Npassi);
double evoluzione_muto(int Npassi);
void Termalizzazione(int Nc);

int evoluzione(double Dt);
int evoluzione_muto(double Dt);


//Met0di di controllo Evoluzione
void evoluzione_Check(int Npassi);
void evoluzione_Check(int Npassi,double t_step);

void evoluzione_conmoto(int Npassi,string riga);  //funzione evoluzione che stampa la traiettoria di 3 particelle
void evoluzione_condiffusione(int Npassi,string riga) ;
void evoluzione_conmoto(double Dt,string riga);
void evoluzione_condiffusione(double Dt,string riga) ;

void stampa_Diffusione(int Nc,string riga);
void stampa_Diffusione(double Dt,string riga);

void animazione_completo(int N_snap,double Dt, string riga) ;
void animazione_diffusione(int N_snap,double Dt, string riga);


//Metodi di Raccolta
double Raccolta_DeltaV(int Nc, double *O);
void Raccolta_DeltaV(int Nc, double *DeltaV, double *TempiC);
double Raccolta_TempiCollisione(int Nc, double *O);
double Raccolta_LiberoCammino(int Nc, double *O);

double Raccolta_Vx(int Nconfigurazioni, int Nc_campionature, double *O);
double Raccolta_dS(int Ncampionature, int Nc_campionature, int Nc_Dt, double *O);
double Raccolta_dS_quad(int Ncampionature, int Nc_campionature, int Nc_Dt, double *O);

int Raccolta_Vx(int Nconfigurazioni, double Dt, double *O);
int Raccolta_dS_conBordo(int Ncampionature, int Nstep_campionature, int Nstep_Dt, double t_step, double *O);
int Raccolta_dS_quad(int Ncampionature, int Nstep_campionature, int Nstep_Dt, double t_step, double *O);


//Metodi di Produzione
double P_Osservabile(int Nc);
void P_Osservabile(int Nc,double *P,int m, double *sigmaP);
double TempoCollisione_medio(int Nc);
double Stampa_HBoltzman_Vx(int Ncolonne,int Nconfigurazioni, int Ncollisioni, string nomeFile);

void Stampa_dS_conBordoVsStep(int Ncampionature, int Nstep_Dt_Max, double t_step, string nomeFile);
void Stampa_dS_quadVsStep(int Ncampionature, int Nstep_Dt_Max, double t_step, string nomeFile);

};

int sistema_rigido::Rinizializza(double eta_new){
	cout<<"#----------------------------------------------------------------------------------------------------#"<<  endl;
	printf("#---- RiInizializzazione sistema %dD composto da %d particelle con impacchettamento %1.3f---------------#\n",d,M,eta_new);		
	start=clock();	
	cout<<"#----------------------------------------------------------------------------------------------------#"<<  endl;

	int check=0;	
	if(eta_new <= eta){
		check=1;
		eta=eta_new;
		if(d==2){sigma= pow(4*eta_new/(M*M_PI),(double)1/2) ;}
		else if(d==3){	sigma= pow(6*eta_new/(M*M_PI),(double)1/3) ;}
	}
	else cout<<"errore, nuovo sigma è maggiore del vecchio, c'è rischio di sovrapposizione!"<<endl;
	CostruzioneTavolaCollisione();
	return(check);
}

/*|||*/	void sistema_rigido::CollassaDiffusione(){
/*|||*/		for(int j=0; j<M; j++)Pdiffusa[j] = P0[j];
/*|||*/ }

// _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
// METODI PRIVATI /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/-
double sistema_rigido::Tempo_Collisione_Immagini(int i_1, int i_2){		//Calcola il tempo di collisione tra due particelle
//	double Tc= tempo_collisione( P0[i_1] , P0[i_2] , v0[i_1] , v0[i_2] , sigma);//variabile tempo di collisione
	double Tc= tmax;
 
	if(i_1==i_2)Tc=tmax;
	else if(Tc >= tmax-1.){						//la particelle non urtano o urtano con un immagine
		if(d==2){
/*!!!*///	if(tempo_collisione( P0[i_1] , P0[i_2] , v0[i_1] , v0[i_2] , sigma)<tmax-1)cout<<"urto ( "<<i_1<<" X "<<i_2<<" )"<<endl;
			vettore P2imm(0,0);
			for(int i1=-1; i1<2; i1++){for(int i2=-1; i2<2; i2++){ 
       			P2imm = P0[i_2] + vettore((i1*L),(i2*L));
				double Tc_imm=tempo_collisione( P0[i_1] , P2imm , v0[i_1] , v0[i_2] , sigma);
				if(Tc_imm<Tc)Tc=Tc_imm;
/*!!!*///		if(tempo_collisione( P0[i_1] , P0[i_2] , v0[i_1] , v0[i_2] , sigma)<tmax-1){if(Tc_imm >tmax-1)cout<<"\t  x  ";else printf("\t%1.4f",Tc_imm);}
				}			/*!!!*///cout<<endl;
			}
/*!!!*///		if(tempo_collisione( P0[i_1] , P0[i_2] , v0[i_1] , v0[i_2] , sigma)<tmax-1)cout<<"minimo = "<<Tc<<endl<<endl;
		}
		else if(d==3){
			vettore P2imm(0,0,0);
			for(int i1=-1; i1<2; i1++)for(int i2=-1; i2<2; i2++)for(int i3=-1; i3<2; i3++){
				P2imm = P0[i_2] + vettore((i1*L),(i2*L),(i3*L));
				double Tc_imm=tempo_collisione( P0[i_1] , P2imm , v0[i_1] , v0[i_2] , sigma);
				if(Tc_imm<Tc)Tc=Tc_imm;
			}
		}	
	}
/*!!!*///		if(tempo_collisione( P0[i_1] , P0[i_2] , v0[i_1] , v0[i_2] , sigma)>Tc &&tempo_collisione( P0[i_1] , P0[i_2] , v0[i_1] , v0[i_2] , sigma)<tmax-1){ cout<<"\n\n\n \t\t ATTENZIONEEE \n\n\n";Tc = tempo_collisione( P0[i_1] , P0[i_2] , v0[i_1] , v0[i_2] , sigma);}
	return(Tc);
}

void sistema_rigido::CostruzioneTavolaCollisione()		//Passa in rassegna tutte le coppie e assegna i tempi di collisione
{ 
	for(int i=0;i<M;i++){Tc[i][i]= tmax;
		for(int j=i+1;j<M;j++){
			Tc[i][j] = Tempo_Collisione_Immagini(i,j); 
			Tc[j][i] = Tc[i][j];
	}}
}

double sistema_rigido::CalcoloTempoCollisione(int *i_urto, int *j_urto){ //trova il minimo della tavola di collisione e riempe indice delle particelle urtanti
	double t_urto = tmax;
	for(int i=0;i<M;i++)for(int j=i+1;j<M;j++){
		if(Tc[i][j]<t_urto){t_urto = Tc[i][j]; *i_urto=i; *j_urto=j;}
	}
/*!!!*/ if(t_urto<=0){cout<<"Errore scansione tavola di collisione! : c'è un t_urto <= 0 = "<<t_urto<<endl;}
/*!!!*/ else if(t_urto>=tmax-1){cout<<"Errore scansione tavola di collisione! :c'è un t_urto = tmax = "<<tmax<<endl;}
return(t_urto);
}

void sistema_rigido::EvoluzionePosizioniParticelle(double t_urto){ 		//evolve le posizioni di un tempo t_urto
	for(int i=0;i<M;i++){
		P0[i] += t_urto*v0[i];
		P0[i].riscalamento(L);	
/*|||*/	Pdiffusa[i] += t_urto*v0[i];
	}
}

vettore sistema_rigido::vettoreseparazione_immagini(int i,int j){ //restituisce il vettore separazione P(i)- P(j) considerando il bordo
	vettore R= (P0[i]-P0[j]);
	if(d==2){
		if( (R).x()> L/2)R-=vettore(L,0);
		else if( (R).x()< -L/2)R+=vettore(L,0);

		if( (R).y()> L/2)R-=vettore(0,L);
		else if( (R).y()< -L/2)R+=vettore(0,L);

		}
	else if(d==3){
		if( (R).x()> L/2)R-=vettore(L,0,0);
		else if( (R).x()< -L/2)R+=vettore(L,0,0);

		if( (R).y()> L/2)R-=vettore(0,L,0);
		else if( (R).y()< -L/2)R+=vettore(0,L,0);

		if( (R).z()> L/2)R-=vettore(0,0,L);
		else if( (R).z()< -L/2)R+=vettore(0,0,L);
	}
	return(R);
}
double sistema_rigido::distanza_immagini(int i,int j){
	return(mod(vettoreseparazione_immagini( i, j)));
}

double sistema_rigido::EvoluzioneVelocitaParticelle(int i_urto, int j_urto){ 
//chiamo questa funzione quando la particella ha già urtato! quindi il vettore congiungente le due particelle sarà quello a distanza minima tra tutte le immagini, sarà vettoreseparazioneimmagini
	vettore	Rij= vettoreseparazione_immagini(i_urto , j_urto);
	vettore delta_v = ((v0[i_urto] - v0[j_urto])*(Rij)/(Mod(Rij)))*Rij;		//le particelle di cui evolvo la velocità dovrebbero essere a contatto (separazione ha modulo sigma)
	v0[i_urto]-= delta_v;
	v0[j_urto]+= delta_v;
	return(mod(delta_v));
}


void sistema_rigido::AggiornamentoTavolaCollisione(double t_urto, int i_urto, int j_urto)
{
	//scalare il tempo
	for(int i=0;i<M;i++)for(int j=i+1;j<M;j++){ 
		if(Tc[i][j]<tmax-1.){Tc[i][j] -= t_urto;	Tc[j][i] = Tc[i][j];}
	}
	//aggiornare tempi di collisione delle particelle che hanno urtato
	for(int i=0;i<M;i++){ 
	//urti con la particella j_urto
		Tc[i][j_urto] = Tempo_Collisione_Immagini(i, j_urto);
		Tc[j_urto][i] = Tc[i][j_urto];	
	//urti con la particella i_urto
		Tc[i_urto][i] = Tempo_Collisione_Immagini(i_urto, i);
		Tc[i][i_urto] = Tc[i_urto][i];	
	}
}



double sistema_rigido::distanza_immagini(vettore P1, vettore P2){
	vettore R= (P1 - P2);
	if(d==2){
		if( (R).x()> L/2)R-=vettore(L,0);
		else if( (R).x()< -L/2)R+=vettore(L,0);

		if( (R).y()> L/2)R-=vettore(0,L);
		else if( (R).y()< -L/2)R+=vettore(0,L);

		}
	else if(d==3){
		if( (R).x()> L/2)R-=vettore(L,0,0);
		else if( (R).x()< -L/2)R+=vettore(L,0,0);

		if( (R).y()> L/2)R-=vettore(0,L,0);
		else if( (R).y()< -L/2)R+=vettore(0,L,0);

		if( (R).z()> L/2)R-=vettore(0,0,L);
		else if( (R).z()< -L/2)R+=vettore(0,0,L);
	}
	return(mod(R));
}



//METODI DI CONTROLLO/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/-
#include "Controllo.h"
#include "ControlloEvoluzione.h"

//METODI DI STATO/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/-
#include "Stato.h"

//METODI DI EVOLUZIONE/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/-
#include "Evoluzione.h"

//METODI DI RACCOLTA/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/-
#include "Raccolta.h"

//METODI DI PRODUZIONE/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/-
#include "Produzione.h"
