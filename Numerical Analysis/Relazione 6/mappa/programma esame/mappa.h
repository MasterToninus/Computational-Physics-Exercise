//semplice mappa da R a R
double mappalogistica(double r, double x0) 
	{
	double x1=r*x0*((double)1-x0);
	return(x1);
	}

 //mappa logistica N volte consecutive al valore x0
double mappalogistica(double r, double x0, int N)
	{
	for(int i=0;i<=N; i++)x0=r*x0*((double)1-x0);
	return(x0);
	}
//mappa logistica N volte consecutive al valore x0, e restituisce n punti seguenti	
void mappalogistica(double r, double x0, int N, int n, double *X)//parametro,punto iniziale, numero di mappe,elementi vettore, vettore
	{
	X[0]=mappalogistica(r,x0,N);
	for(int j=1;j<n;j++)X[j]=mappalogistica(r,X[j-1]);
	}





//lo stesso di prima ma con i long double	
long double mappalogistica(long double r,long double x0)
	{
	long double x1=r*x0*((long double)1-x0);
	return(x1);
	}
	
long double mappalogistica(long double r, long double x0, int N)
	{
	for(int i=0;i<=N; i++)x0=r*(x0-x0*x0);
	return(x0);
	}
	
void mappalogistica(long double r, long double x0, int N, int n, long double *X)//parametro,punto iniziale, numero di mappe,elementi vettore, vettore
	{
	X[0]=mappalogistica(r,x0,N);
	for(int j=1;j<n;j++)X[j]=mappalogistica(r,X[j-1]);
	}
