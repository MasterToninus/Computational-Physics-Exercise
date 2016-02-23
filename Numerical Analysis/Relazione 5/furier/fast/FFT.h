
#define swap(a,b) tempr = (a); (a) = (b) ; (b) = tempr
/*
x << y                    // x shifted y bits to left (x * pow(2, y))
x >> y                    // x shifted y bits to right (x / pow(2, y))

x += y                    // x = x + y, also -= *= /= <<= >>= &= |= ^=

*/

	
void bitreverse (double *data, unsigned long nn) // vettore dei dati, nn numeri complessi quindi nn*2 double
{
double tempr;
unsigned long n,m,j,i;
n = nn <<1;
j = 1;
	for(i=1 ; i < n ; i += 2){
		if (j > i ) {
			swap(data[j] , data[i]); 
			swap(data[j+1] , data[i+1]); 
			}
		m = n >> 1;
		while ( m >= 2 && j > m){
			j -= m;
			m >>= 1;
			}
		j += m ;
	}
}

void FFT (double *data, unsigned long nn, int isign) 
{
double tempr, tempi;
double wtemp, wr, wpr, wpi, wi, theta;
unsigned long mmax, istep, i, j, n , m;

n = nn <<1;
j = 1; //bit reversing
	for(i=1 ; i < n ; i += 2){
		if (j > i ) {
			swap(data[j] , data[i]); 
			swap(data[j+1] , data[i+1]); 
			}
		m = n >> 1;
		while ( m >= 2 && j > m){
			j -= m;
			m >>= 1;
			}
		j += m ;
	}

mmax = 2; // inizia l'algoritmo
while (n > mmax){
	istep = mmax << 1 ;
	theta = isign*(6.28318530717959/mmax);
	wtemp = sin(0.5 * theta);
	wpr = -2.0 * wtemp * wtemp;
	wpi = sin(theta);
	wr = 1.0;
	wi = 0.0;
	for ( m = 1 ; m < mmax ; m += 2) {
		for ( i = m ; i <= n ; i +=istep){
			j = i +mmax;
			tempr = wr*data[j] - wi*data[j+1];
			tempi = wr*data[j+1] + wi*data[j];
			data[j] = data[i] - tempr;
			data[j+1] = data[i+1] - tempi;	
			data[i] += tempr;
			data[i+1] += tempi;
		}
		wr = ( wtemp = wr )*wpr - wi*wpi + wr;
		wi = wi*wpr + wtemp*wpi +wi;
	}	
	mmax = istep;
	}
}
