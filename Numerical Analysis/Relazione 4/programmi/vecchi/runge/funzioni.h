


double funz(double x, double y) 
{double R;
	R= cos(x);
return(R);
}



/*
eq lineare-> riconducibile a sistema. caso II grado         
		y''+A(x)y'+B(x)y= C(x)

diventa:	Z1'= Z2
		Z2'= -A(x)Z2 -B(x)Z1 +C(x)		

caso pendolo
		y''+ay'+bsin(y)=0 = y''+ A(x,y')+B(x,y)=0 


caso generale	
		y''=F(t,y,y')
diventa	
		Z1'= Z2
		Z2'= F(t,Z1,Z2)




*/


double pendolo(double t, double Z1, double Z2) 
{double R, g=9.8 ,m=1 ,r=1 , n=0;
	R= -(n/(m*r))*Z2-(m*g)*sin(Z1);
return(R);
}

double F(double t, double x, double v) 
{
double R, A=0.12, B=0.5, F0=0.6, W=0.66;	
R= -(A)*v-(B)*(sin(x))+F0*cos(W*t);
return(R);
}

double F1(double t, double x, double v) 
{
double R, A=0.12, B=0.5, F0=0.5, W=0.66;	
R= -(A)*v-(B)*(sin(x))+F0*cos(W*t);
return(R);
}

double F2(double t, double x, double v) 
{
double R, A=0.12, B=0.5, F0=0.4, W=0.66;
R= -(A)*v-(B)*(sin(x))+F0*cos(W*t);
return(R);
}

