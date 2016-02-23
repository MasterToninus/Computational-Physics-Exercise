/*	 
	Classe MATRICI per poter passare matrici come argomenti di funzioni facilmente
*/

class matrice {
	public:
	double **M; //matrice di double
	int n_righe;		//altezza
	int n_colonne;		//larghezza
	

	matrice( int N_i, int N_j) {
		n_righe	=	N_i;
		n_colonne	=	N_j;
		//allocazione dinamica della memoria per la mATRICE http://www.hwupgrade.it/forum/showthread.php?t=1332311
			/* allocazione vettore righe (ogni elemento del vettore è un puntatore) */
				M = (double**)malloc( (n_righe) * sizeof(int) ); 
			/* Per ogni riga si allocano le colonne */
				for(int i=0; i<n_righe; i++) M[i] = (double*)calloc( (n_colonne),sizeof(double) );
	}

	double get(int i, int j);
	void put(int i, int j, double x);
	void stampa();
	double media_riga(int i);
	double media_quadratica_riga(int i);
	double jackknife_riga( int i);

};

double matrice::get(int i, int j){
	return(M[i][j]);
}

void matrice::put(int i, int j, double x){
	M[i][j]= x;
}

void matrice::stampa(){
	for(int i=0; i<n_righe; i++){for(int j=0; j<n_colonne; j++){
		printf ("%4.2f\t", M[i][j]);
	}	cout<<endl;}
}

double matrice::media_riga(int i){
	return(media(M[i],n_colonne));
}

double matrice::media_quadratica_riga(int i){
	return(media_quadratica(M[i],n_colonne));
}

double matrice::jackknife_riga( int i){
	return(jackknife(M[i],n_colonne));
}
