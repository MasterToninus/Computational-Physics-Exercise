using namespace std;

void step_eulero(double (*F)(double,double), double *p0,double h) //ingresso: funzione, valori iniziali, incremento
{
	double x0=p0[0];
	double y0=p0[1];
	p0[0]= x0+h;
	p0[1]= y0 + F(x0,y0)*h;
}

void step_eulero(double (*F)(double,double,double), double *p0,double dt) //ingresso: funzione, valori iniziali, incremento
{
	double t0=p0[0];
	double x0=p0[1];
	double v0=p0[2];
	p0[2] = v0 + F(t0,x0,v0)*dt;
	p0[1] = x0 + v0*dt;
	p0[0] = t0 + dt;
}

void step_correttore(double (*F)(double,double), double *p0,double h) //ingresso: funzione, valori iniziali, incremento
{
	double K[2];
	double x0=p0[0];
	double y0=p0[1];
	K[0]= h*F( x0 , y0 );
	K[1]= h*F( x0 + h/2 , y0 + K[0]/2 );
	p0[0]= x0 + h;
	p0[1]= y0 + ( K[1]);
return;
}


//funzione che dato punto (x0,y0) restituisce punto (x0+h,y1)
void RK4(double (*F)(double,double), double *p0,double h) //ingresso: funzione, valori iniziali, incremento
{
	double K[4];
	double x0=p0[0];
	double y0=p0[1];
	K[0]= h*F( x0 , y0 );
	K[1]= h*F( x0 + h/2 , y0 + K[0]/2 );
	K[2]= h*F( x0 + h/2 , y0 + K[1]/2 );
	K[3]= h*F( x0 + h, y0 + K[2] );
	p0[0]= x0 + h;
	p0[1]= y0 + ( K[0] + 2*K[1] + 2*K[2] + K[3] )/6;
}

//funzione che dato punto p0=(x0,y0,u0) restituisce punto p1=(x1,y1,u1), trasforma il vettore p0 nel vettore p1
void RK4(double (*G)(double,double,double), double *p0,double h) //ingresso: funzione, valori iniziali, incremento
{
	double x=p0[0];
	double y=p0[1];
	double u=p0[2];
	double k[4],m[4];

	k[0] = h * u;
	m[0] = h * G(x,y,u) ;
	k[1] = h * (u+ m[0]/2);
	m[1] = h * G(x + h/2 , y +k[0]/2 , u +m[0]/2);
	k[2] = h * (u+ m[1]/2);
	m[2] = h * G(x + h/2, y + k[1]/2 , u + m[1]/2);
	k[3] = h * (u + m[2]);
	m[3] = h * G(x+h,y + k[2], u + m[2]);
	
	p0[0] = x +h;
	p0[1] = y + (k[0]+2*k[1]+2*k[2]+k[3])/6;
	p0[2] = u + ( m[0] + 2*m[1] + 2*m[2] +m[3])/6;
}


//algoritmi di calcolo per funzioni di primo grado
void eulero(double (*F)(double,double), double x0,double y0,double h,double *Y,int N){ 
	double p0[2];
	p0[0]=x0;
	p0[1]=y0;
	Y[0]= y0;
	
	for(int i=0;i<N-1;  i++){
	 step_eulero(F,p0,h);
	 Y[i+1] = p0[1];
      }
return;
}	

void correttore(double (*F)(double,double), double x0,double y0,double h,double *Y,int N){ 
	double p0[2];
	p0[0]=x0;
	p0[1]=y0;
	Y[0]= y0;
	
	for(int i=0;i<N-1;  i++){
	 step_correttore(F,p0,h);
	 Y[i+1] = p0[1];
      }
return;
}	


void Runge4(double (*F)(double,double), double x0,double y0,double h,double *Y,int N) 
{//costruire errore nel caso dim X diversa da N!
	double p0[2];
	p0[0]=x0;
	p0[1]=y0;
	Y[0]= y0;
	for(int i=0;i<N-1;i++)
	{
	RK4(F,p0,h);
	Y[i+1]=p0[1];
	}
return;
}









//algoritmi di calcolo per funzioni di secondo grado
void Runge4(double (*F)(double,double,double),double t0,double x0,double v0,double dt, double *X,int N) 
{//costruire errore nel caso dim X diversa da N!
	double p0[3];
	p0[0]=t0;
	p0[1]=x0;
	p0[2]=v0;
	X[0]= x0;
	
	for(int i=0;i<N-1;  i++){
	RK4(F,p0,dt);
	X[i+1] = p0[1];
      }
return;
}

void Runge_Kutta_secondo(double (*F)(double,double,double),double *t,double *x,double *v,double dt,int N) 
{//costruire errore nel caso dim X diversa da N!
	double p0[3];
	p0[0]=t[0];
	p0[1]=x[0];
	p0[2]=v[0];
	
	for(int i=0;i<N-1;  i++){
	 RK4(F,p0,dt);
	 t[i+1] = t[i] +dt;
	 x[i+1] = p0[1];
	 v[i+1] = p0[2];
      }
return;
}



void eulero(double (*F)(double,double,double),double *t,double *x,double *v,double dt,int N)
{

	double p0[3];
	p0[0]=t[0];
	p0[1]=x[0];
	p0[2]=v[0];
	
	for(int i=0;i<N-1;  i++){
	step_eulero(F,p0,dt);
	t[i+1] = t[i] +dt;
	x[i+1] = p0[1];
	v[i+1] = p0[2];
	}
return;
}	




