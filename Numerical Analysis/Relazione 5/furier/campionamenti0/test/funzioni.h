double gradino(double t) 
{
	double r, T= 8;
	double k = floor(t/T); //(parte intera)
	t= t-k*T;
	if(t>0 && t<T/2) r=1;
	else r=0;


  return (r);
}

double gaussiana(double x) 
{
	double r,a=2;
	r= (exp (-(x*x/a)/2))/(a*sqrt(2*M_PI)); 


  return (r);
}

double esponenziale(double x) 
{
	double r,a=2;
	r= exp (-(x/a)); 


  return (r);
}
