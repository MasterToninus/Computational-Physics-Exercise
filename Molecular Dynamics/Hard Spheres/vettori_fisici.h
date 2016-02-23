/*	 Classe CALCOLO VETTORIALE per vettori "fisici" senza controllo delle dimensioni compatibili quando faccio calcoli
*/

class vettore {
private:
	static const int n=3;
	int d;
	double V[n];
	
public:
	vettore( double v0) {V[0]=v0; d=1;}
	vettore( double v0,double v1) {V[0]=v0;V[1]=v1; d=2;}
	vettore( double v0,double v1, double v2) {V[0]=v0;V[1]=v1;V[2]=v2; d=3;}

vettore& operator+=(vettore a){
	//if(d != a.d)cout<<"errore!"<<endl;
	for(int i=0;i<d;i++){V[i]+=a.V[i];}
	return *this;}
	
vettore& operator-=(vettore a){
	//if(d != a.d)cout<<"errore!"<<endl;	
	for(int i=0;i<d;i++){V[i]-=a.V[i];}
	return *this;}

vettore& operator*=(double a){
	for(int i=0;i<d;i++){V[i]*=a;}
	return *this;}

vettore& operator/=(double a){
	for(int i=0;i<d;i++){V[i]/=a;}
	return *this;}

	//funzioni che restituiscono la componente
	double x() const { return V[0]; }
	double y() const { return V[1]; }
	double z() const { return V[2]; }
	//pseudo size of
	int size() const { return(d); }

	//utili per la simulazione si può semplificare ponendo L=1 e togliendo la parte intera! 
	void riscalamento(double L){
		for(int i=0;i<d;i++){
			while(V[i]<0.){V[i]+=L;}
			while(V[i]>=L){V[i]-=L;}}
		}
/*	void arrotondamento(int A){
		for(int i=0;i<d;i++){V[i] = arrotonda(V[i],A);}
		}*/

//calcolo vettoriale composizioni lineari
friend vettore operator+(vettore, vettore);
friend vettore operator-(vettore, vettore);
friend vettore operator*(double, vettore);
friend vettore operator/(double, vettore);
//prodotto interno
friend double operator*(vettore, vettore);
friend double Mod(vettore);
friend double mod(vettore);

};

vettore operator+(vettore a, vettore b)
{
	vettore r=a;
   	return r+=b;
}
vettore operator-(vettore a, vettore b)
{
	vettore r=a;
   	return r-=b;
}
vettore operator*(double x, vettore a)
{
	vettore r=a;
   	return r*=x;
}
vettore operator/(vettore a,double x)
{
	vettore r=a;
   	return r/=x;
}

double operator*(vettore a1, vettore a2)
{
	if(a1.d != a2.d)cout<<"errore prodotto interno di vettori di dim diversa!"<<endl;
	double r=0;
	for(int i=0;i<a1.d;i++){r+=a1.V[i]*a2.V[i];}
	return r;
}
double Mod(vettore a)
{
	double r= a*a; return r;
}
double mod(vettore a)
{
	double r= sqrt(a*a); return r;
}


