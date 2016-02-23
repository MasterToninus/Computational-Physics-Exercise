
int Spinrand()			// restitusce {+1,-1} random
{
	int s=rand();
	if(s<=RAND_MAX/2)s=-1;
	else s=1;
return(s);
}

int Intrand(int N)		// restitusce un numero random intero da 0 A N-1
{
	double s=(double)rand()/RAND_MAX;
	int l=0;
	while(s >= (1+l) * (1./(N)))l++;
	return (l);
}

int PowInt(int x, int n)// restituisce l'elevamente a potenza di un numero intero
{  
int dummy=1;
for(int i=0;i<n;i++){ dummy = dummy*x;}
return(dummy);
}


int massimo(int *V,int n)//restituisce il valore massimo tra le componenti del vettore V
{  
	int dummy = V[0];
	for(int i=1;i<n;i++){if(V[i]>=dummy){dummy=V[i];}}
	return(dummy);
}

// FUNZIONI DI COSTRUZIONE GRAFICO, CREANO IL FILE NELLA CARTELLA DESIDERATA E SOVRASCRIVONO

void grafico(int n_dot, double *X,double *Y,string nomeFile){
	ofstream myfile(nomeFile.c_str());
	for(int i=0;i<n_dot;i++){
		myfile<< X[i] << "\t" << Y[i]<<  endl;}
	myfile.close();
}
void grafico(int n_dot, double *X,double *Y,double *Z,string nomeFile){
	ofstream myfile(nomeFile.c_str());
	for(int i=0;i<n_dot;i++){
		myfile<< X[i] << "\t" << Y[i]<< "\t" << Z[i]<<  endl;}
	myfile.close();
}
void grafico(int n_dot, double X_0, double step, double *Y,string nomeFile){
	ofstream myfile(nomeFile.c_str());
	for(int i=0;i<n_dot;i++){
		myfile<< X_0 + i * step << "\t" << Y[i]<<  endl;}
	myfile.close();
}

// FUNZIONI DI COSTRUZIONE GRAFICO, APPENDONO I NUOVI PUNTI SUL FILE ESISTENTE

void grafico_append(int n_dot, double *X,double *Y,string nomeFile){
	ofstream myfile(nomeFile.c_str(),ios::app);
	for(int i=0;i<n_dot;i++){
		myfile<< X[i] << "\t" << Y[i]<<  endl;}
	myfile.close();
}
void grafico_append(int n_dot, double *X,double *Y,double *Z,string nomeFile){
	ofstream myfile(nomeFile.c_str(),ios::app);
	for(int i=0;i<n_dot;i++){
		myfile<< X[i] << "\t" << Y[i]<< "\t" << Z[i]<<  endl;}
	myfile.close();
}
void grafico_append(int n_dot, double X_0, double step, double *Y,string nomeFile){
	ofstream myfile(nomeFile.c_str(),ios::app);
	for(int i=0;i<n_dot;i++){
		myfile<< X_0 + i * step << "\t" << Y[i]<<  endl;}
	myfile.close();
}

// FUNZIONI DI COSTRUZIONE GRAFICO, APPENDONO un singolo punto  SUL FILE ESISTENTE

void grafico_add(double X,double Y,string nomeFile){
	ofstream myfile(nomeFile.c_str(),ios::app);
	myfile<< X << "\t" << Y<<  endl;
	myfile.close();
}
void grafico_add(double X,double Y,double Z,string nomeFile){
	ofstream myfile(nomeFile.c_str(),ios::app);
	myfile<< X << "\t" << Y<< "\t"<<Z<<  endl;
	myfile.close();
}


// FUNZIONI DI COSTRUZIONE ISTOGRAMMA

void istogramma_v1(int n_int, double *V,double Vmin,double Vmax,int M,string nomeFile){
// numero di intervalli fatto , array di valori da istogrammare, numero di elementi da istogrammare
	int N[n_int]; // vettore del numero di oggetti nella casella 
	for(int i=0;i<n_int;i++){N[i]=0;}
	
	//int M =sizeof(V)/sizeof(double); //numero totale elementi

	double a= Vmin,b= Vmax; 
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

void istogramma_v2(int n_int, double *V,double Vmax,int M,string nomeFile){
// numero di intervalli fatto , array di valori da istogrammare, numero di elementi da istogrammare
	int N[n_int]; // vettore del numero di oggetti nella casella 
	for(int i=0;i<n_int;i++){N[i]=0;}
	
	//int M =sizeof(V)/sizeof(double); //numero totale elementi

	double a= -Vmax,b= Vmax; 
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

