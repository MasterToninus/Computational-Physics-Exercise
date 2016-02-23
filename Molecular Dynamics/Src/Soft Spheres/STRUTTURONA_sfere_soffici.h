//    Classe SISTEMA sfere soffici 
//


#define t_step  0.001				//intervallo di tempo elementare su cui viene applicato l'algoritmo di Velocity-Verlet
class sistema_soffice {
//Attributi di sistema
	int d; 						// dimensione spaziale 2d 3d (dimensioni diverse non implementate)
	int M; 						// M :numero di particelle (numero esatto in BCC)
	double sigma; 				// distanza di annullamento del potenziale d'interazione (posto ad 1)
	double epsilon; 			// minimo del potenziale (posto ad 1)

public:
	double L; 					// lunghezza lato

//Attributi di stato
	vector<vettore> P0; //vector delle posizioni delle particelle
	vector<vettore> v0; //vector dei vettori velocità delle particelle
	vector<vettore> a0; //vector dei vettori accelerazione delle particelle
/*|||*/	vector<vettore> Pdiffusa; 	//vector delle posizioni delle particelle quando le condizioni di bordo non vengono applicate

	int *NPOINT;    	// lista dei "puntatori" elemento i restituisce l'ingresso di list dove cominciano i vicini a P[i]
	vector<int> LIST; 	// lista dei vicini

	double rL; //distanza di vicinanza
	double rC; //distanza di cut

//Attributi di controllo
	clock_t start,end;						//variabili di controllo tempo di esecuzione
	double tempo;



public:
	sistema_soffice() //costruttore SISTEMA DI TEST
	{
		d=2;
		M=4; // M :numero di particelle 
		L = 10.;
		epsilon=1.;		sigma=1.; //unità naturali del sistema
		cout<<"#----------------------------------------------------------------------------------------------------#"<<  endl;
		printf("#---- Inizializzazione sistema %dD DI PROVA---------------#\n",d,M,epsilon);		
		start=clock();	

		P0.push_back(vettore(sigma/2,L-sigma/2) );				P0.push_back(vettore(L-sigma/2,sigma/2) );
		P0.push_back(vettore(L/4+sigma/2,L/4+sigma/2) );		P0.push_back(vettore(3*L/4-sigma/2,3*L/4-sigma/2) );

/*|||*/		Pdiffusa.resize(M,0);
/*|||*/		CollassaDiffusione();

	// 2° fase. costruzione lista dei vicini
		//allocazione dinamica della memoria per la lista Npoint
		NPOINT =(int*)malloc( M * sizeof(int) );
		rL= 2.8*sigma;
		rC= 2.5*sigma;
		cout<<"#- Costruzione Lista dei vicini con rL= "<<rL<<" in corso ..."<<endl;
		CostruzioneListaVicini();

	// 3° fase. inizializzione delle velocità
		double vel=sigma/2;
		v0.push_back(vettore(vel,-vel));					v0.push_back(vettore(-vel,vel));
		v0.push_back(vettore(vel,vel));						v0.push_back(vettore(-vel,-vel));

	// 5° fase inizializzazione delle accelerazioni
		for(int i=0; i<M; i++)a0.push_back(vettore(0));
		CalcoloAccelerazioni();

		cout<<"#---- Fine Inizializzazione del sistema  \t \t ------------ \t\t t_esec = "<<tempo_esec()<<" secondi"<<" -----#"<<endl;
		cout<<"#---------------------------------------------------------------------------------------------------------#"<<endl<<"#-"<<endl;

	}

	// Copy constructor. http://en.wikipedia.org/wiki/Copy_constructor Mi serve visto che uso array dinamici!
    sistema_soffice(const sistema_soffice& sistema_copiato)
    {
		start=clock();	
		epsilon= sistema_copiato.epsilon;		
		sigma= sistema_copiato.sigma;
		d= sistema_copiato.d;
		M= sistema_copiato.M;
		L= sistema_copiato.L;

		rL= sistema_copiato.rL;
		rC= sistema_copiato.rC;

		for(int j=0; j<M; j++){ 
			P0.push_back(sistema_copiato.P0[j]);
			v0.push_back(sistema_copiato.v0[j]);
			a0.push_back(sistema_copiato.a0[j]);
			Pdiffusa.push_back(sistema_copiato.Pdiffusa[j]);
		}		
		//allocazione dinamica della memoria per la lista Npoint
		NPOINT =(int*)malloc( M * sizeof(int) );
		CostruzioneListaVicini();
    }


	sistema_soffice(int dim, int N_in,double rho) //costruttore inizializza il sistema e calcola la matrice dei tempi di collisione ad >>>>>>>>>>>>>>energia e temperatura non fissate! si fissano nel metodo di termalizzazione
	{
		epsilon=1.;		sigma=1.; //unità naturali del sistema
		d=dim;
		M=N_in;	// M :numero di particelle (numero esatto in BCC)

		L=sigma*pow(M/rho, 1./d);
		cout<<"\n#---------------------------------------------------------------------------------------------------------#"<<  endl;
		printf("#---- Inizializzazione sistema %dD composto da %d particelle con rho* = %1.3f e L = %1.2f ----------------#\n",d,M,rho,L);
		start=clock();	
		cout<<"#---------------------------------------------------------------------------------------------------------#"<<  endl;


		int N=1;		
		while(M>2*PowInt(N,d))N++;				//trovo il più piccolo reticolo che riesce a contenere tutte le particelle 	
		double passo= L/N; 						//passo della configurazione iniziale

	// 1° fase. dispongo le particelle in BCC secondo il reticolo precedente
		if(d==2)
		{
			for(int i=0; i<N; i++){for(int j=0; j<N; j++){ 
				P0.push_back(vettore(passo/2 + i*passo,passo/2 + j*passo));
			}}
			for(int i=0; i<N; i++){for(int j=0; j<N; j++){ //facce centrali
				P0.push_back(vettore((i)*passo,(j)*passo));
			}}
		}	
		if(d==3)
		{
			for(int i=0; i<N; i++){for(int j=0; j<N; j++){for(int k=0; k<N; k++){ 
				P0.push_back(vettore(passo/2 + i*passo,passo/2 + j*passo,passo/2 + k*passo)+vettore(sigma/2,sigma/2,sigma/2));
			}}}
			for(int i=0; i<N; i++){for(int j=0; j<N; j++){for(int k=0; k<N; k++){  //facce centrali
				P0.push_back(vettore((i)*passo, (j)*passo, (k)*passo)+vettore(sigma/2,sigma/2,sigma/2));
			}}}
		}
		//ora sono di più! tolgo dalla lista precedente le particelle superflue!//http://www.cplusplus.com/reference/stl/vector/		
		P0.erase (P0.begin()+M,P0.end());

	// 1.5° fase. Inizializzo vector delle posizioni diffuse
/*|||*/		Pdiffusa.resize(M,0);
/*|||*/		CollassaDiffusione();

	// 2° fase. costruisco lista dei vicini
		//allocazione dinamica della memoria per la lista Npoint
		NPOINT =(int*)malloc( (M) * sizeof(int) ); // ho M indice in modo che venga salvato l'indice dei vicini all'ultima particella (che non ci sono)
		rL= 2.8*sigma;		//valore di "vicinanza"
		rC= 2.5*sigma;		//valore di taglio del potenziale
		//cout<<"#- Costruzione Lista dei vicini con rL= "<<rL<<" in corso ..."<<endl;
		CostruzioneListaVicini();

	// 3° fase. inizializzo le velocità
		//cout<<"#- inizializzo velocità ..."<<endl;
		srand((unsigned)time(0)); // inizializzo il seed del generatore random una sola volta nel costrutture
		double a=2; //ampiezza distribuzione velocità
		if(d==2){
			for(int j=0; j<M; j++){ v0.push_back(vettore( ((double)rand()/RAND_MAX)*a-a/2 ,((double)rand()/RAND_MAX)*a-a/2));}}
		if(d==3){
			for(int j=0; j<M; j++){ v0.push_back(vettore( ((double)rand()/RAND_MAX)*a-a/2 ,((double)rand()/RAND_MAX)*a-a/2,((double)rand()/RAND_MAX)*a-a/2));}}

	// 4° fase riscalare la velocità   
		//velocità totale
		vettore vtot=Ptot();
		//scalare le velocità per avere momento nullo
		for(int j=0; j<M; j++){v0[j] -= vtot/M;}
			
	// 5° fase inizializzo le accelerazioni
		for(int i=0; i<M; i++)a0.push_back(vettore(0));
		CalcoloAccelerazioni();

		cout<<"#---- Fine Inizializzazione del sistema  \t \t ------------ \t\t t_esec = "<<tempo_esec()<<" secondi"<<" -----#"<<endl;
		cout<<"#---------------------------------------------------------------------------------------------------------#"<<endl<<"#-"<<endl;
	}

//Metodi di "Servizio"
void Rinizializza(int N_new, double rho_new);
void Espandi( double rho_new);
/*|||*/ void CollassaDiffusione();//pone tutte le posizioni del sistema diffuso come quelle del sistema con bordo
private:

vettore Delta_r(int i_1,int i_0);	//Vettore di separazione tra particella P(i1) e P(i0)
double D(int i_1,int i_0); 	// vettore distanza P(i1) - P(i0)
void CostruzioneListaVicini(); 		//scorre tutte le particelle e segna quali sono vicine

double u(double r);			//funzione potenziale di lennard-jones (non è necessario che sia un metodo della classe
double F(double r);
double u_s(int i_1,int i_0); 	// Potenziale reciproco "tagliato-scalato" generato da P(i1) e P(i0)
vettore F_s(int i_1,int i_0);	// Forza "tagliata-scalata"
void CalcoloAccelerazioni();

double distanza_immagini(vettore P1, vettore P2); //dati due vettori qualsisasi restituisce il vettore separazione con bordo (generalizza i metodi precedenti a punti qualsiasi


public:
//METODI DI STATO
vettore Ptot();  		//restituisce momento totale del sistema
double Ktot();			//restituisce energia cinetica totale del sistema
double Utot(); 			//restituisce energia potenziale totale del sistema
vettore Ftot(); 		//restituisce vettore Forza totale
double kT_stato();		//restituisce kT istantaneo
double termP_stato();	//restituisce Z istantaneo
/*|||*/ double H_Boltzman();	//restituisce funzione di boltzman istantanea valutata su istogramma di M/2 colonne
/*|||*/ double H_Boltzman(int Ncolonne);

//Met0di di controllo
double tempo_esec();	//restituisce il tempo trascorso dall'inizializzazione del sistema		
void   stampa_stato_completo(string riga);
void stampa_stato_diffusione(string riga);
void stampa_vicini();
void stampa_vicini(string riga);
void stampa_potenziali(string riga);

//Metodi di evoluzione del sistema
void evoluzione();

void evoluzione(int Npassi);
void evoluzione_muto(int Npassi);//come metodo precedente ma senza avvisi
void termalizzazione_kTfissa(int Npassi, double T_D); //termalizzo sistema alla temperatura richiesta
void termalizzazione_Efissa(int Npassi, double E_D); //termalizzo sistema alla energia richiesta

void evoluzione( double Dt);
void evoluzione_muto( double Dt);//come metodo precedente ma senza avvisi
void termalizzazione_kTfissa(double Dt, double T_D); //termalizzo sistema alla temperatura richiesta
void termalizzazione_Efissa(double Dt, double E_D); //termalizzo sistema alla energia richiesta


//Met0di di controllo Evoluzione
void evoluzione_Check(int Npassi);

void evoluzione_conmoto(int Npassi,string riga);  //funzione evoluzione che stampa la traiettoria di 3 particelle
void evoluzione_condiffusione(int Npassi,string riga) ;
void evoluzione_conmoto(double Dt,string riga);
void evoluzione_condiffusione(double Dt,string riga) ;

void stampa_Diffusione(int Npassi,string riga);
void stampa_Diffusione(double Dt,string riga);

void animazione_completo(int N_snap, string riga) ;
void animazione_diffusione(int N_snap, string riga);


//Metodi di Raccolta dati
void Raccolta_P(int Nconfigurazioni,double Dt, double *O);
void Raccolta_T(int Nconfigurazioni,double Dt, double *O);
void Raccolta_U(int Nconfigurazioni,double Dt, double *O);
void Raccolta_Stato_Completo(int Nconfigurazioni,double Dt, double *P, double *T, double *U);

void Raccolta_Vx(int Nconfigurazioni,double Dt, double *O);
void Raccolta_Vquad(int Nconfigurazioni,double Dt, double *O);
void Raccolta_FxR(int Nconfigurazioni,double Dt, double *O);
void Raccolta_Nvicini(int Nconfigurazioni,double Dt, double *O);

void Raccolta_dS_conBordo(int Ncampionature, int Nstep_campionature, int Nstep_Dt, double step_Dt, double *O);
void Raccolta_dS_quad(int Ncampionature, int Nstep_campionature, int Nstep_Dt, double step_Dt, double *O);

void Raccolta_Ordine(int Ncampionature, int Nstep_campionature, int Nstep_Dt, double step_Dt, double *dS_quad,double *Nvici, double *Z);


//Metodi di Produzione
double P_Osservabile(int Ncampionature, double Dt_campionature);
double kT_Osservabile(int Ncampionature, double Dt_campionature);

double Stampa_HBoltzman_Vx(int Ncolonne,int Nconfigurazioni, double Dt, string nomeFile);

void Stampa_dS_conBordoVsStep(int Ncampionature, int Nstep_Dt_Max, double step_Dt, string nomeFile);
void Stampa_dS_quadVsStep(int Ncampionature, int Nstep_Dt_Max, double step_Dt, string nomeFile);

};

//METODO DI RINIZIALIZZAZIONE__________________________
void sistema_soffice::Rinizializza(int N_new, double rho_new){
	if(N_new>M){cout<<" non è possibile rinizzializare in questo modo! N nuovo > Nvecchio"<<endl;}
	else{		
		double L_old=L;
	
		L=sigma*pow(N_new/rho_new, 1./d);
		
		cout<<"#---------------------------------------------------------------------------------------------------------#"<<  endl;
		printf("#---- RInizializzazione sistema %dD composto da %d particelle con L = %1.2f ----------------#\n",d,M,L);
		start=clock();	
		cout<<"#---------------------------------------------------------------------------------------------------------#"<<  endl;

		if(N_new<M){
			P0.erase (P0.begin()+M,P0.end());		//cancellazione particelle superflue
			v0.erase (v0.begin()+M,v0.end());
			a0.erase (a0.begin()+M,a0.end());
		}
		M= N_new;

		for(int i=0; i<M; i++) P0[i] *= (L/L_old);							//riscalamento posizioni
		for(int i=0; i<M; i++) v0[i] *= (L/L_old);							//riscalamento velocità

		CostruzioneListaVicini();
		CalcoloAccelerazioni();
	
		cout<<"#---- Fine RiInizializzazione del sistema  \t \t ------------ \t\t t_esec = "<<tempo_esec()<<" secondi"<<" -----#"<<endl;
		cout<<"#---------------------------------------------------------------------------------------------------------#"<<endl<<"#-"<<endl;
	}	
}
void sistema_soffice::Espandi( double rho_new){
	double L_old=L;
	L=sigma*pow(M/rho_new, 1./d);
	printf("#---- Espansione volume del sistema. Nuovo L  = %1.2f ----------------#\n",L);
	if(L<=L_old)cout<<"ATTENZIONE. L nuovo < L vecchio, si sta comprimendo il sistema"<<endl;
	//traslazione del sistema nel centro per motivi estetici
		if(d==2)	for(int i=0; i<M; i++)	P0[i] += vettore((L-L_old)/2,(L-L_old)/2);
		else if(d==2)	for(int i=0; i<M; i++)	P0[i] += vettore((L-L_old)/2,(L-L_old)/2,(L-L_old)/2);


	CostruzioneListaVicini();
	CalcoloAccelerazioni();
}


/*|||*/	void sistema_soffice::CollassaDiffusione(){
/*|||*/		for(int j=0; j<M; j++)Pdiffusa[j] = P0[j];
/*|||*/ }



// _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
// METODI PRIVATI /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/-

vettore sistema_soffice::Delta_r( int i,int j){// vettore Separazione P(i)-P(j)
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
	//cout<<"deltar size = "<<Deltar.size()<<endl;
	return(R);
}
double sistema_soffice::D(int i,int j){				//Distanza P(i)-P(j)
	vettore R= Delta_r( i, j);
	return(mod(R));
}


void sistema_soffice::CostruzioneListaVicini(){
	LIST.erase (LIST.begin(),LIST.end());		//svuoto la lista in modo da ripoter richiamare questa funzione più volte nel programma

	NPOINT[0] = 0;                 				//la particella zero comincia la lista dei vicini
	for(int i=0; i<M-1; i++){					//scorro tutte le particelle _i
		int contatore_i=0;         				//contatore del numero di particelle j>i misurate vicine ad i
		for(int j = i+1; j<M; j++){				// scorro altre particelle con indice j>i
			double Distanza = D(i,j);         	//calcolo la distanza
			if(Distanza <= rL){					//se j è vicina ad i
				LIST.push_back(j);				//salvo nella lista gli indici j delle particelle vicine ad i
				contatore_i++;					//aumento di uno il contatore dei vicini ad i	
			}
		NPOINT[i+1]=NPOINT[i] + contatore_i;	//il puntatore della lista vicini di i+1 sarà il puntatore dei vicini i + N vicini
		}
	}
/*
	for(int i=0; i<M-1; i++){
		for(int j=NPOINT[i];j<NPOINT[i+1];j++){ //scorro tutti gli elementi listati vicini alla particella i
			cout<<"P[ "<<i<<"] vicino a P["<<LIST[j]<<" ]"<<endl;
		}
	}*/
}

//Funzioni forza, potenziale , non serve che siano metodi di classe!
double sistema_soffice::u(double r){				//potenziale Lennard_Jones a distanza r dalla particella
	return(4*epsilon*(pow(sigma/r,12)-pow(sigma/r,6)));
}
double sistema_soffice::F(double r){				//forza applicata da una particella ad un'altra particella a distanza r
	return(24*epsilon/sigma*(2*pow(sigma/r,13)-pow(sigma/r,7)));
}

double sistema_soffice::u_s(int i, int j){	//Termine di energia potenziale tra le particelle i e j	 
	double r= D(i,j);
	double U=0;
	if (r<= rC)	U= u(r) -u(rC) -( r-rC ) *(-F(rC));
	return(U);
}
vettore sistema_soffice::F_s(int i, int j){ //forza generata sulla particella i dalla particella j
	vettore V = (Delta_r(i,j)); 
	double r = (mod(V)) 	;

	double modF = 0;
	if (r<= rC){
			modF= F(r)-F(rC) ;
	}
	//	if(r==0)printf("#- Errore |r=0 r1=( %f, %f) e r2=( %f, %f)  \n", r1.x(), r1.y(), r0.x(), r0.y());
	//printf("\t \t r = %f modF= %f)  \n", r, modF);
	return((modF/r)*V);
}



void sistema_soffice::CalcoloAccelerazioni(){
	if(d==2)for(int i=0; i<M; i++)a0[i]=vettore(0,0);
	if(d==3)for(int i=0; i<M; i++)a0[i]=vettore(0,0,0);

	for(int i=0;i<M-1;i++){
		for(int j=NPOINT[i];j<NPOINT[i+1];j++){ //scorro tutti gli elementi listati vicini alla particella i
			vettore Forza=F_s(i,LIST[j]);//forza applicata a P0[i] dalla particella P0[vicino di i]
			a0[i]+=Forza;
			a0[LIST[j]]-=Forza;
//	cout<<"forza su "<<i<<" applicata da "<<LIST[j]<<" Fx = "<< Forza.x() <<"\t Fy = "<< Forza.y() <<endl;
		}
	}
//	cout<<" controllo : vettore forza totale = [ "<<Ftot().x()<<" , "<<Ftot().y()<<" ] "<<endl;
}

double sistema_soffice::distanza_immagini(vettore P1, vettore P2){
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

//METODI DI RACCOLTA DATI/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/-
#include "Raccolta.h"

//METODI DI PRODUZIONE/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/-
#include "Produzione.h"

