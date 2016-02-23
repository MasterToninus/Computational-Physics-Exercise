//ordinatore
void ordinatore( double &x0, double &x1)
		{
		double dummy;
		dummy=x1;
		x1=x0;
		x0=dummy;
		}


//rettangoli inferiore
double IntRetInf(double (*F)(double), double x0,double x1,int N)
	{
	int sign=0;
	if(x1<x0){ordinatore(x0,x1); sign=1;}
	double D= (x1-x0)/N;
	double somma=0;
	for(int i=0 ; i<N ;i=i+1)
		{somma+=F(x0+i*D)*D;}
	if(sign==1)somma=-somma;
	return (somma);
	}

double IntRetInf_I(double (*F)(double), double x0,double h,int N)
	{
	double somma=0;
	for(int i=0 ; i<N ;i=i+1)
		{somma+=F(x0+i*h)*h;}
	return (somma);
	}


//rettangoli superiore
double IntRetSup(double (*F)(double), double x0,double x1,int N)
	{
	int sign=0;
	if(x1<x0){ordinatore(x0,x1); sign=1;}
	double D= (x1-x0)/N;
	double somma=0;
	for(int i=1 ; i<=N ;i=i+1)
		{somma+=F(x0+i*D)*D;}
	if(sign==1)somma=-somma;
	return (somma);
	}

double IntRetSup_I(double (*F)(double), double x0,double h,int N)
	{
	double somma=0;    
	for(int i=1 ; i<=N ;i=i+1)
		{somma+=F(x0+i*h)*h;}
	return (somma);
	}


//rettangoli nel punto di mezzo
double IntRetMed(double (*F)(double), double x0,double x1,int N)
	{
	int sign=0;
	if(x1<x0){ordinatore(x0,x1); sign=1;}
	double D= (x1-x0)/N;
	double somma=0;
	for(int i=0 ; i<N ;i=i+1)
	{somma+=F(x0+D*((double)i+0.5))*D;}
	if(sign==1)somma=-somma;
	return (somma);
	}

double IntRetMed_I(double (*F)(double), double x0,double h,int N)
	{
	double somma=0;    
	for(int i=0 ; i<N ;i=i+1)
	{somma+=F(x0+h*((double)i+0.5))*h;}
	return (somma);
	}


//trapezi
double IntTrap(double (*F)(double), double x0,double x1,int N)
	{
	int sign=0;
	if(x1<x0){ordinatore(x0,x1); sign=1;}
	double D= (x1-x0)/N;
	double somma=0;
	for(int i=0 ; i<N ;i=i+1)
		{
		double area = (F(x0+(double)i*D)+F(x0+D+(double)i*D))*D/2;
		somma+=area;
		}
	if(sign==1)somma=-somma;
	return (somma);
	}

double IntTrap_I(double (*F)(double), double x0,double h,int N)
	{
	double somma=0;    
	for(int i=0 ; i<N ;i=i+1)
		{
		double area = (F(x0+(double)i*h)+F(x0+((double)i+1.)*h))*h/2;
		somma+=area;
		}
	return (somma);
	}
	

//simpson
double IntSimp(double (*F)(double), double x0,double x1,int N)
	{
	int sign=0;
	if(x1<x0){ordinatore(x0,x1); sign=1;}
	double D= (x1-x0)/(2*N);
	double somma=0;
	for(int i=0 ; i<N ;i=i+1)
		{
		double area = (F(x0+2*i*D)+4*F(x0+((double)2*i+1.)*D)+F(x0+2*((double)i+1.)*D))*(D/3);
		somma+=area;
		}
	if(sign==1)somma=-somma;
	return (somma);
	}

double IntSimp_I(double (*F)(double), double x0,double h,int N)
	{
	double somma=0;    
	for(int i=0 ; i<N ;i=i+1)
		{
		double area = (F(x0+2*i*h)+4*F(x0+((double)2*i+1.)*h)+F(x0+2*((double)i+1.)*h))*(h/3);
		somma+=area;
		}
	return (somma);
	}
	


//integrazione montecarlo
#include <ctime> 
double MonteCarlo(double (*F)(double), double x0,double x1, double min, double max, int N)
	{
	int sign=0;
	if(x1<x0){ordinatore(x0,x1); sign=1;}	
	srand((unsigned)time(0));
	double A=(max-min)*(x1-x0);
	int successiposit=0;
	int successinegat=0;
	
	for(int i=0 ; i<N ;i=i+1)
			{
			double x= x0 + ((double)rand()/RAND_MAX)*(x1-x0);
			double y= min + ((double)rand()/RAND_MAX)*(max-min);
			if(y<=F(x)&& y>=0)successiposit=successiposit+1;
			else if(y>=F(x) && y<0)successinegat+=1;
			}
	if(N > RAND_MAX/6)srand((unsigned)time(0)-1); 
	double integrale= A*(double)successiposit/N-A*(double)successinegat/N;
	if(sign==1)integrale=-integrale;
	return (integrale);
	}

double MonteCarlo(double (*F)(double,double), double x0,double y0,double x1,double y1,double min, double max,int N)
	{ 
	double A=(max-min)*(x1-x0)*(y1-y0);
	int successiposit=0;
	int successinegat=0;
	
	for(int i=0 ; i<N ;i=i+1)
			{
			double x= x0 + ((double)rand()/RAND_MAX)*(x1-x0);
			double y= y0 + ((double)rand()/RAND_MAX)*(y1-y0);
			double z= min + ((double)rand()/RAND_MAX)*(max-min);
			if(z<=F(x,y) && z>=0)successiposit+=1;
			else if(z>=F(x,y) && z<0)successinegat+=1;
			}
	if(N > RAND_MAX/6)srand((unsigned)time(0)-1); 
	double integrale= A*successiposit/N-A*successinegat/N;
	return (integrale);
	}
