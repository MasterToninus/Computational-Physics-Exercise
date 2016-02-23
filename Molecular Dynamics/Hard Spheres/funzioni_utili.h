int PowInt(int x, int n)
{  
int dummy=1;
for(int i=0;i<n;i++){ dummy = dummy*x;}
return(dummy);
}

double sommatoria(double *V,int  V_size){
	double tot=0;
	for(int i=0;i<V_size;i++)	tot+=V[i];
	return(tot);
}



//------------------------------------------------------------------------------------------------------------------------------
//		FUNZIONI STATISTICHE SU ARRAY DI VALORI
//------------------------------------------------------------------------------------------------------------------------------

double media(double *V,int  V_size){
	double tot=0;
	for(int i=0;i<V_size;i++)	tot+=V[i];
	return(tot/(double)V_size);
}
double media_quadratica(double *V,int  V_size){
	double tot=0;
	for(int i=0;i<V_size;i++)	tot+=V[i]*V[i];
	return(tot/(double)V_size);
}

double deviazione_standard(double *V,int  V_size){
	double tot=0, totquad=0;
	for(int i=0;i<V_size;i++){	tot+=V[i]; totquad+=V[i]*V[i];}
	totquad= totquad/V_size;
	tot=tot/(double)V_size;
	return(sqrt((totquad - tot*tot)));
}

double binning( double *O, int N, int m){
//vettore dei dati, Numero di elementi del vettori, numero di elementi del bin
	int N_new= (N-N%m)/m; // numero dei nuovi sottoinsiemi di valori
	double tot=0, totquad=0;
	double U;
	for(int j=0;j<N_new;j++){//		per ogni sotto insieme
		U=0;
		for(int i=0;i<m;i++){//		calcolo la somma dei valori
			U+= O[j*m+i];
		}		
		U=U/m;				//		quindi la media come nuova stima dell'osservabile
		tot+=U;				//		sommo tutte le medie
		totquad+=U*U;		//		e sommo il loro quadrato
	}
	tot=tot/N_new;			//		da cui ottengo una nuova stima per la media totale
	totquad=totquad/N_new;  //		e per la media quadrata
	return(sqrt((totquad - tot*tot)/N_new));//		utilizzo i valori ottenuti per calcolare la deviazione standard
}



//------------------------------------------------------------------------------------------------------------------------------
//		CREAZIONI GRAFICI, METODI CHE SCRIVONO UNA SINGOLA RIGA SU FILE
//------------------------------------------------------------------------------------------------------------------------------

#include <stdarg.h>
void grafico_start(string nomeFile){ 
	ofstream myfile(nomeFile.c_str());
	myfile<< endl;
	myfile.close();
}
void grafico_start(string nomeFile,string testo){ 
	ofstream myfile(nomeFile.c_str());
	myfile<<testo<<endl;
	myfile.close();
}


void grafico_add(string nomeFile,int N,...){
	ofstream myfile(nomeFile.c_str(),ios::app);		//appende o crea file

    va_list ListaDati;
    va_start(ListaDati, N); 			//lista dati inizia da N e contiene N quantità

    for(int i = 0; i < N; ++i )      myfile<< va_arg(ListaDati, double)<<"\t";
    va_end(ListaDati);
	myfile<< endl;
	myfile.close();
}



//------------------------------------------------------------------------------------------------------------------------------
//		CREAZIONI ISTOGRAMMA DA ARRAY DI DATI
//------------------------------------------------------------------------------------------------------------------------------

double IntegraleRettangoli(double *f_x, double dx, int N_x){
//valori assunti della funzione ad intervalli regolari di ampiezza dx, Numero di intervalli
	double somma=0;
	for(int i=0;i<N_x;i++) somma+=f_x[i]*dx;
return(somma);
}

void CreaDistribuzione(int M, double *V,int n_int, double *X, double *Y){
// numero di intervalli fatto , array di valori da istogrammare, numero di elementi da istogrammare, nome file
	int N[n_int]; 									// vettore del numero di oggetti nella casella 
	for(int i=0;i<n_int;i++){Y[i]=0;}				//azzero

	double a= V[0],b= V[0]; //cerco ultime colonne dell'istogramma ( a minimo b massimo)
	for(int i=1;i<M;i++){		//scorro M elementi di V
		if(V[i]<=a)a= V[i];
		else if(V[i]>=b)b= V[i];}

	double delta = (b-a)/n_int; // ampiezza colonne istogramma	
	for(int i=0;i<n_int;i++) X[i] = a+ (0.5+(double)i)* delta;

	int l;//contatore
	for(int i=0;i<M;i++){ // scorro M elementi di V (ciclo costruisce array con info istogramma)
			l=0;
			while(V[i]>= a + l * delta)l++;
			N[l-1]++;}

	for(int i=0;i<n_int;i++) Y[i] = (double)N[i]/(M*delta);//normalizzo! M*delta= superficie dell'isto
}

double Boltzman(int n_int, double *V, int M){
	int N[n_int]; 									// vettore del numero di oggetti nella casella 
	for(int i=0;i<n_int;i++){N[i]=0;}				//azzero

	double a= V[0],b= V[0]; //cerco ultime colonne dell'istogramma
	for(int i=1;i<M;i++){
		if(V[i]<=a)a= V[i];
		else if(V[i]>=b)b= V[i];}
	//cout<<" numero di elementi "<<M<< "\t\t val minimo " << a<< "\t val massimo " << b<<  endl;

	double delta = (b-a)/n_int; // ampiezza colonne istogramma	
	int l;//contatore
	for(int i=0;i<M;i++){ //ciclo costruisce array con info istogramma
			l=0;
			while(V[i]>= a + l * delta)l++;
			N[l-1]++;}

	double integrale = 0;
	for(int i=0;i<n_int;i++) if(N[i] != 0){
		double y = (double)N[i]/(M*delta); 
		integrale += delta * y * log(y) ;
	}
	return(integrale);
}

void istogramma(int n_int, double *V,int M,string nomeFile){
// numero di intervalli fatto , array di valori da istogrammare, numero di elementi da istogrammare, nome file
	int N[n_int]; 									// vettore del numero di oggetti nella casella 
	for(int i=0;i<n_int;i++){N[i]=0;}				//azzero

	double a= V[0],b= V[0]; //cerco ultime colonne dell'istogramma
	for(int i=1;i<M;i++){
		if(V[i]<=a)a= V[i];
		else if(V[i]>=b)b= V[i];}
	//cout<<" numero di elementi "<<M<< "\t\t val minimo " << a<< "\t val massimo " << b<<  endl;

	double delta = (b-a)/n_int; // ampiezza colonne istogramma	
	int l;//contatore
	for(int i=0;i<M;i++){ //ciclo costruisce array con info istogramma
			l=0;
			while(V[i]>= a + l * delta)l++;
			N[l-1]++;}
	ofstream myfile(nomeFile.c_str());
	for(int i=0;i<n_int;i++){ //ciclo costruisce file con istogramma
		myfile<<a+ (0.5+(double)i)* delta << "\t" << (double)N[i]/(M*delta)<<  endl;}//normalizzo! M*delta= superficie dell'isto
	myfile.close();
}
