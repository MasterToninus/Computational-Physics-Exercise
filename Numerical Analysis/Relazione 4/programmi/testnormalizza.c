
void normalizza(double *Th, int N) 
{	//normalizzazione a pigreco
	for(int i=0;i<N;i++){
	double f= floor((Th[i])/(2*M_PI)+0.5);// parte intera di angolo + pi diviso 2 pi
	Th[i]=Th[i]-f*2*M_PI;};
}
http://forum.html.it/forum/showthread/t-404120.html
