//    Classe SISTEMA Ising 2D (reticolo di spin +-1)
//		ultima modifica -/-/12
//


class microstato {

	int d;				//dimensione spaziale 2d 3d ecc
	int N;				// N :numero  di spin in una linea
	int N_nodi;			// numero totale di spin
	
public:

	int E;				//energia del microstato (metto public così posso stamparlo);
	int S;				//spin totale del microstato("");
	int **StatoSpin;	//matrice dello stato di spin

	clock_t start,end;	//variabili di controllo tempo di esecuzione
	double tempo;

public:
microstato(int Nin)		//N= numero di spin in una linea
	{
		d=2;	 
		N=Nin;
		N_nodi=PowInt(N, d);

		cout<<"#---------------------------------------------------------------------------------------------------------#"<<  endl;
		printf("#---- Inizializzazione casuale microstato %dD composto da %d spin ----------------#\n",d,N_nodi);
		start=clock();	
		cout<<"#---------------------------------------------------------------------------------------------------------#"<<  endl;

			//allocazione dinamica della memoria per la mATRICE http://www.hwupgrade.it/forum/showthread.php?t=1332311
			/* allocazione vettore righe (ogni elemento del vettore è un puntatore) */
				StatoSpin = (int**)malloc( (N) * sizeof(int) ); 
			/* Per ogni riga si allocano le colonne */
				for(int i=0; i<N; i++) StatoSpin[i] = (int*)calloc( (N),sizeof(int) );


		srand((unsigned)time(0));
		for(int i=0; i<N; i++){for(int j=0; j<N; j++){ 
			StatoSpin[i][j]=	Spinrand();	
		}}
			
		E_init(); //salvo energia del microstato
		S_init();

		end=clock();tempo=((double)(end-start))/CLOCKS_PER_SEC;
/*		cout<<"#---- Fine Inizializzazione del sistema  \t \t -------------- \t t_esec = "<<tempo<<" secondi"<<" ---------#"<<endl;
		cout<<"#---------------------------------------------------------------------------------------------------------	#"<<endl<<"#-"<<endl;*/
	}

//	METODI Privati
private:
int E_nodo(int i, int j);			//restituisce Energia del sito i,j
void E_init();						//inizializza variabile E della classe
void S_init();						//inizializza variabile S della classe


public:
//	METODI DELLA CLASSE 
void flip(int i, int j);			//flippa sito i,j aggiorna E e S
void congela();						//set di tutti gli spin a +1 e aggiorna E e S
void sciogli();						//set degli spin a scacchiera e aggiorna E e S
void rinizializza(int Nin);			//rinizializza il sistema cambiando Numero di spin (attenzione: passare sempre A N più piccoli)

//	METODI DI STATO
double M(); 						//restituisce densità M= spin totale diviso numero di nodi
double H();							//restituisce densità H

//	METODI DI CONTROLLO
void stampa_stato();				
void stampa_stato(string riga);
void animazione_SwenWang(string riga, int istanti, double beta); 	//stampano output adatto per essere animato
void animazione_Metro(string riga, int istanti, double beta); 

//	METODI DI "EVOLUZIONE" DEL SISTEMA
void step_metropolis(int i, int j, double beta);					//esegue uno step di metropolis al nodo (i,j)
void step_montecarlo(int N_step,double beta);						//esegue N_step di metropolis con scelta random del nodo da flip
void step_montecarlo(double beta);									//esegue in sequenza 1 step metropolis per ogni nodo
void evol_montecarlo(double beta, int N_step); 						//esegue N_step di metropolis per nodo 

int testbond_up(int i, int j,double beta);									// testa se il bond tra nodo (i,j) e (i+1,j) è attivato
int testbond_dx(int i, int j,double beta);									// testa se il bond tra nodo (i,j) e (i,j+1) è attivato
void step_SwenWang(double beta);											//esegue 1 step a multicluster
double step_SwenWang_M(double beta);										//esegue 1 step e restituisce M improved
void step_SwenWang_M_Quad(double beta, double *M_imp, double *M_quad_imp);	//esegue 1 step e riempi input con M impro e M^2 impro
double step_SwenWang_Size(double beta);										//esegue 1 step e restituisce size medio dei cluster
void evol_SwenWang(double beta, int N_step); 								//esegue N step di multicluster


//	METODI DI RACCOLTA
void Raccolta_M_Metropolis(double beta, double *O, int Nmarkov);			//Raccolta di valori M (Metro.)
void Raccolta_M_abs_Metropolis(double beta, double *O, int Nmarkov);		//riempe il vettore O con Nmarkov valori di |M| (Metro.)
void Raccolta_H_Metropolis(double beta, double *O, int Nmarkov);			//riempe il vettore O con Nmarkov valori di |H| (Metro.)
double Raccolta_St_Metropolis(double beta, matrice O, int Nmarkov);			//riempe la riga t della matrice O con valori di StS0
void Raccolta_Tutto_Metro(double beta, double *M, double *M_quad, double *H, int Nmarkov);//riempe 3 vettori con le osservabili M, M^2, H

void Raccolta_M_Cluster(double beta, double *O, int Nmarkov);
void Raccolta_M_Cluster_Improved(double beta, double *O, int Nmarkov);
void Raccolta_M_Cluster_Improved_Quad(double beta, double *O, double *U, int Nmarkov);
void Raccolta_H_Cluster(double beta, double *O, int Nmarkov);
double Raccolta_St_Cluster(double beta, matrice O, int Nmarkov);
void Raccolta_Size_Cluster(double beta, double *O, int Nmarkov);
void Raccolta_Tutto_Cluster(double beta, double *M, double *M_quad, double *H, int Nmarkov);

//metodi di "evoluzione" del sistema versione 2 ( senza calcolare l'esponenziale, hint di newman-barkema)
int testbond_up_V2(int i, int j,double beta);
int testbond_dx_V2(int i, int j,double beta);
void step_SwenWang_V2(double beta);											//esegue 1 step a multicluster
double step_SwenWang_M_V2(double beta);										//esegue 1 step e restituisce M improved
void step_SwenWang_M_Quad_V2(double beta, double *M_imp, double *M_quad_imp);	//esegue 1 step e riempi input con M impro e M^2 impro
void evol_SwenWang_V2(double beta, int N_step); 								//esegue N step di multicluster

//metodi di raccolta del sistema versione 2
void Raccolta_M_Cluster_V2(double beta, double *O, int Nmarkov);
void Raccolta_M_Cluster_Improved_V2(double beta, double *O, int Nmarkov);
void Raccolta_M_Cluster_Improved_Quad_V2(double beta, double *O, double *U, int Nmarkov);
void Raccolta_H_Cluster_V2(double beta, double *O, int Nmarkov);
void Raccolta_St_Cluster_V2(double beta, matrice O, int Nmarkov);

};

int microstato::E_nodo(int i, int j){	//calcola Energia di interazione del nodo (i,j) considerando il bordo periodico
	double E_nodo=0;
	if (i==0)			E_nodo-=StatoSpin[i][j]*(StatoSpin[i+1][j]+StatoSpin[N-1][j]);
	else if(i== N-1)	E_nodo-=StatoSpin[i][j]*(StatoSpin[0][j]+StatoSpin[i-1][j]);
	else				E_nodo-=StatoSpin[i][j]*(StatoSpin[i+1][j]+StatoSpin[i-1][j]);

	if (j==0)			E_nodo-=StatoSpin[i][j]*(StatoSpin[i][j+1]+StatoSpin[i][N-1]);
	else if(j== N-1)	E_nodo-=StatoSpin[i][j]*(StatoSpin[i][0]+StatoSpin[i][j-1]);
	else				E_nodo-=StatoSpin[i][j]*(StatoSpin[i][j+1]+StatoSpin[i][j-1]);

	return(E_nodo);
}

void microstato::E_init(){ //energia totale inizializza la variabile E della classe
	E=0;
	for(int i=0; i<N; i++){for(int j=0; j<N; j++){
		E+=E_nodo(i,j);
	}}
	E=E/2;
}

void microstato::S_init(){ //spin totale inizializza la variabile S della classe
	S=0;
	for(int i=0; i<N; i++){for(int j=0; j<N; j++){
		S+=StatoSpin[i][j];
	}}
}


void microstato::flip(int i, int j){
	StatoSpin[i][j]=-StatoSpin[i][j];
	E=E+2*E_nodo(i,j);
	S=S+2*StatoSpin[i][j];
}

void microstato::congela(){
	for(int i=0; i<N; i++){for(int j=0; j<N; j++){
		StatoSpin[i][j]=1;
	}}
	E= -2*N_nodi;
	S=N_nodi;
}

void microstato::sciogli(){			//funziona solo con N pari!
	for(int i=0; i<N; i++){for(int j=0; j<N; j++){
		StatoSpin[i][j]=PowInt(-1,i+j);
	}}
	E= 2*N_nodi;
	S=0;
}

void microstato::rinizializza(int Nin){ //rinizializza  utile per confrontare comportamenti ad N diversi
	N=Nin;
	N_nodi=PowInt(N, d);
	cout<<"#---------------------------------------------------------------------------------------------------------#"<<  endl;
	printf("#---- RInizializzazione casuale microstato %dD composto da %d spin ----------------#\n",d,N_nodi);
	start=clock();	
	cout<<"#---------------------------------------------------------------------------------------------------------#"<<  endl;
		//allocazione dinamica della memoria per la mATRICE http://www.hwupgrade.it/forum/showthread.php?t=1332311
			/* allocazione vettore righe (ogni elemento del vettore è un puntatore) */
			StatoSpin = (int**)realloc(StatoSpin, (N) * sizeof(int) ); //http://www.cplusplus.com/reference/clibrary/cstdlib/realloc/
			/* Per ogni riga si allocano le colonne */
			for(int i=0; i<N; i++) StatoSpin[i] = (int*)realloc(StatoSpin[i], (N)*sizeof(int) );

	for(int i=0; i<N; i++){for(int j=0; j<N; j++){
		StatoSpin[i][j]=	Spinrand();		//StatoSpin[i][j]=1;
	}}
	E_init(); //salvo energia del microstato
	S_init();
}



// METODI DI STATO /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/-
double microstato::M(){ 
	return( (double)S/N_nodi);
}

double microstato::H(){ 
	return( (double)E/N_nodi);
}


//METODI DI CONTROLLO /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/-
#include "Controllo.h"

//METODI DI EVOLUZIONE/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/-
#include "Metropolis.h"
//#include "MultiCluster.h"				//algoritmo swen wang cpu impegnativo
#include "MultiClusterClass.h"			//algoritmo swen wang ram impegnativo
#include "MultiClusterClass_V2.h"		//versione velocizzata, non calcola l'esponenziale ogni volta che viene chiamato il test

//METODI DI RACCOLTA (PRODUZIONE)/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/-
#include "Raccolta.h"
#include "Raccolta_V2.h"				//versione da usare con l'algoritmo velocizzato



