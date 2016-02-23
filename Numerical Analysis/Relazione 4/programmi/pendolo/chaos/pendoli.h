
double F(double t, double x, double v) 
{double R, A=0.5, B=1, F0=1.1495, W=0.66;
	
R= -(A)*v-(B)*(sin(x))+F0*cos(W*t);
return(R);
}

double F1(double t, double x, double v) 
{double R, A=0.5, B=1, F0=1.150, W=0.66;
	
R= -(A)*v-(B)*(sin(x))+F0*cos(W*t);
return(R);
}

double F2(double t, double x, double v) 
{double R, A=0.5, B=1, F0=1.1505, W=0.66;
	
R= -(A)*v-(B)*(sin(x))+F0*cos(W*t);
return(R);
}

double F11(double t, double x, double v) 
{double R, A=0.5, B=1, F0=1.150, W=0.665;
	
R= -(A)*v-(B)*(sin(x))+F0*cos(W*t);
return(R);
}

double F12(double t, double x, double v) 
{double R, A=0.5, B=1, F0=1.150, W=0.655;
	
R= -(A)*v-(B)*(sin(x))+F0*cos(W*t);
return(R);
}

