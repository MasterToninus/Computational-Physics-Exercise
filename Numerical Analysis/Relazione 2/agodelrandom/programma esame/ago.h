#include <ctime> 
using namespace std;


/*calcola una singola probabilita'di successo con N lanci per un esperimento di buffon con un ago lungo R [cm] su un pavimento con fessure distanti T [cm]*/
double exp_buffon(int N, double T, double R)  
{
  	double probabilita;
  	int cont=0; //contatore delle volte che l'ago tocca una fessura
	for(int i=0; i<N; i++)
		{ 
        	double x = ((double)rand()/RAND_MAX)*T/2;
		double s = ((double)rand()/RAND_MAX)*(M_PI/2);
		if(x<=(R/2)*sin(s))cont++ ; // condizione di successo
 		}
	return probabilita=((double)cont/N);
  
} 


/*versione che raggruppa k= R/T*/
double buffon(int N, double k)  
{
  	int cont=0; //contatore delle volte che l'ago tocca una fessura
	for(int i=0; i<N; i++)
		{ 
        	double x = ((double)rand()/RAND_MAX);
		double s = ((double)rand()/RAND_MAX)*(M_PI/2);
		if(x<=k*sin(s))cont++ ; // condizione di successo
 		}
	return ((double)cont/N);
  
} 
