using namespace std;

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


void Runge_Kutta_secondo(double (*F)(double,double,double),double *t,double *x,double *v,double dt,unsigned long int N) 
{//costruire errore nel caso dim X diversa da N!
	double p0[3];
	p0[0]=t[0];
	p0[1]=x[0];
	p0[2]=v[0];
	
	for(unsigned long int i=0; i < N-1;  i++){
	 RK4(F,p0,dt);
	 t[i+1] = t[i] +dt;
	 x[i+1] = p0[1];
	 v[i+1] = p0[2];
      }
return;
}





