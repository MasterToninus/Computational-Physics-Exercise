void H_Re ( double delta, int N ,double * h,  double * H ) //dando la delta, il numero N di punti campionati e la funzione campionata da 0 a Ndelta mi restituisce la parte reale della trasformata da  (-fc a fc) campionata ogni ..
{
for(int i=0; i<N; i++)
		{
		double n= -N/2. + (double)i;
		double Hn=0;
		for(int k=0; k<N; k++)Hn+= h[k] * cos(2*M_PI*n*k/N);
		H[i]=Hn*delta;
		}
}

void H_Im ( double delta, int N ,double * h,  double * H ) //punti campionati da 0 a t intervallati da delta , delta, numero punti campionati
{
for(int i=0; i<N; i++)
		{
		double n= -N/2. + (double)i;
		double Hn=0;
		for(int k=0; k<N; k++)Hn+= h[k] * sin(2*M_PI*n*k/N);
		H[i]=Hn*delta;
		}
}

void trasf_antitrasf( double delta, int N ,double * h1,  double * h2 )
{
double H1_re[N];
H_Re(delta , N , h1 , H1_re);

double H1_im[N];
H_Im(delta , N , h1 , H1_im);

for(int k=0; k<N; k++)
		{

		double somma=0;
		for(int i=0; i<N; i++){
			double n= -N/2. + (double)i;
			somma+= H1_re[i] *cos(2*M_PI*n*k/N) + H1_im[i]* sin(2*M_PI*n*k/N);
					}
		h2[k]=somma/(N*delta);
		}
}

void modH( double delta, int N ,double * h,  double * modH )
{
double H_re[N];
H_Re(delta , N , h , H_re);

double H_im[N];
H_Im(delta , N , h , H_im);

for(int k=0; k<N; k++)modH[k] = sqrt(H_re[k]*H_re[k]+H_im[k]*H_im[k]);

}


