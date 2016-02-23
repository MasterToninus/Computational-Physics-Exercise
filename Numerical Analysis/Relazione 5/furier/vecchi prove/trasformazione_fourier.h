//mi restituisce la trasformata di fourier della funzione samplata nella singola frequenza fn
double H_fn_Re (double *t,double * h, double fn, int N ){
	double delta= t[1]-t[0];
	double somma=0;
	for(int k=0; k<N; k++)somma+= h[k] * cos(2*M_PI*fn*t[k])*delta;
	return(somma);}
	
double H_fn_Im (double *t,double * h, double fn, int N ){
	double delta= t[1]-t[0];
	double somma=0;
	for(int k=0; k<N; k++)somma+= h[k] * sin(2*M_PI*fn*t[k])*delta;
	return(somma);}


//versione per funzioni samplate a valori complessi
double H_fn_Re (double *t,double * reh,double * Imh, double fn, int N ){
	double delta= t[1]-t[0];
	double somma=0;
	for(int k=0; k<N; k++)somma+= (reh[k] * cos(2*M_PI*fn*t[k]) - Imh[k]* sin(2*M_PI*fn*t[k]))*delta;
	return(somma);}

double H_fn_Im (double *t,double * reh,double * Imh, double fn, int N ){
	double delta= t[1]-t[0];
	double somma=0;
	for(int k=0; k<N; k++)somma+= (reh[k] * sin(2*M_PI*fn*t[k]) + Imh[k]* cos(2*M_PI*fn*t[k]))*delta;
	return(somma);}	 

double Anti_H_fn_Re (double *f,double * ReH,double * ImH, double tn, int N ){
	double delta= f[1]-f[0];
	double somma=0;
	for(int k=0; k<N; k++)somma+= (ReH[k] * cos(2*M_PI*tn*f[k]) + ImH[k]* sin(2*M_PI*tn*f[k]))*delta;
	return(somma);}

double Anti_H_fn_Im (double *f,double * ReH,double * ImH, double tn, int N ){
	double delta= f[1]-f[0];
	double somma=0;
	for(int k=0; k<N; k++)somma+= (-ReH[k] * sin(2*M_PI*tn*f[k]) + ImH[k]* cos(2*M_PI*tn*f[k]))*delta;
	return(somma);}	 


//questi algoritmi vanno bene solo per sampling per t che comincia da 0!
double H_fn_Re (int N, double delta, double fn, double *h ){
	double somma=0;
	for(int k=0; k<N; k++)somma+= h[k] * cos(2*M_PI*fn*k*delta)*delta;
	return(somma);}

double H_fn_Im (int N, double delta, double fn, double *h ){
	double somma=0;
	for(int k=0; k<N; k++)somma+= h[k] * sin(2*M_PI*fn*k*delta)*delta;
	return(somma);}

	
//algoritmi pensati esplicitamente per il pendolo quindi comincia da 0
void H_fn_Re (int N, double deltat, double *theta_t,double *f, double *theta_f )
	{
	for(int i=0; i<N; i++)
		{
		int n= N/2+i;
		f[i]=n/(N*deltat);
		double somma=0;
		for(int k=0; k<N; k++)somma+= theta_t[k] * cos(2*M_PI*n*k/N)*deltat;
		theta_f[i]=somma;
		}
	}	

void H_fn_Im (int N, double deltat, double *theta_t,double *f, double *theta_f )
	{
	for(int i=0; i<N; i++)
		{
		int n= N/2+i;
		f[i]=n/(N*deltat);
	
		double somma=0;
		for(int k=0; k<N; k++)somma+= theta_t[k] * sin(2*M_PI*n*k/N)*deltat;
		theta_f[i]=somma;
		}	
	}	
void H_fn_mod (int N, double deltat, double *theta_t,double *f, double *mod )
	{
	double re[N],Im[N];
	H_fn_Re(N,deltat, theta_t,f,re);
	H_fn_Im(N,deltat, theta_t,f,Im);
	for(int i=0; i<N; i++)		mod[i]=sqrt(re[i]*re[i]+Im[i]*Im[i]);
	}



