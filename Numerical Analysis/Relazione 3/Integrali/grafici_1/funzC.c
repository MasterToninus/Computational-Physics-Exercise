#include <iostream>
#include <math.h>
#include <fstream>
#include "funzioni.h"
#include "integrazione.h"
#include "gauss.h"
using namespace std;

/* calcolare integrale numeric di una funzione */

int main()
{
double a0=0; //punto iniziale
double a1=M_PI;  //mettere 2 pigreco è inutile perchè avrei solo cifre molto piccole ed entrerei nel domionio del incertezza da troncamento!!!!!!!!!
double I_atteso= 2;
double I; //integrale


double min=-1;
double max=1;

cout<<"\nArea funzC da\t"<<a0<<"\t"<<a1<<"\n"<<endl;
//ciclo sulle diviosioni dell intervallo

FILE * myfile1;
	myfile1 = fopen ("funzC/Rettangoli Inferiore","w");

for( int N=5 ; N<2000 ;N++){
	I = IntRetInf(funzC,a0,a1,N);	fprintf (myfile1, "%d \t %21.20f \n",N,fabs(I_atteso-I));
	}
fclose (myfile1);


FILE * myfile2;
	myfile2 = fopen ("funzC/Rettangoli Superiore","w");
	
for( int N=5 ; N<2000 ;N++){
	I = IntRetSup(funzC,a0,a1,N);fprintf (myfile2, "%d \t %21.20f \n",N,fabs(I_atteso-I));
	}
fclose (myfile2);

FILE * myfile3;
	myfile3 = fopen ("funzC/Rettangoli Medio","w");

for( int N=5 ; N<2000 ;N++){
	I = IntRetMed(funzC,a0,a1,N);fprintf (myfile3, "%d \t %21.20f \n",N,fabs(I_atteso-I));
	}
fclose (myfile3);

FILE * myfile4;
	myfile4 = fopen ("funzC/Trapezi","w");

for( int N=4 ; N<1000 ;N++){
	I = IntTrap(funzC,a0,a1,N);fprintf (myfile4, "%d \t %21.20f \n",N+1,fabs(I_atteso-I));
	}
fclose (myfile4);

FILE * myfile5;
	myfile5 = fopen ("funzC/Simpson","w");

for( int N=1 ; N<700 ;N++){
	I = IntSimp(funzC,a0,a1,N);	fprintf (myfile5, "%d \t %21.20f \n",2*N+1,fabs(I_atteso-I));
	}
fclose (myfile5);

ofstream myfile6("funzC/Montecarlo",ios::trunc);
for( int N=100 ; N<2400 ;N++){
	I = MonteCarlo(funzC,a0,a1,min,max,N);	myfile6<<N<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile6.close();

FILE * myfile7;
	myfile7 = fopen ("funzC/MultiGaussordine5","w");

for( int N=1 ; N<400 ;N++){
	int n=5;
	I = MultiGauss(funzC,n,a0,a1,N);	fprintf (myfile7, "%d \t %21.20f \n",5*N,fabs(I_atteso-I));
	}
fclose (myfile7);

FILE * myfile8;
	myfile8 = fopen ("funzC/MultiGaussordine10","w");

for( int N=1 ; N<200 ;N++){
	int n=10;
	I = MultiGauss(funzC,n,a0,a1,N)/MultiGauss(funzC,5,a0,a1,2*N);fprintf (myfile8, "%d \t %21.20f \n",10*N,fabs(I_atteso-I));
	}
fclose (myfile8);

FILE * myfile9;
	myfile9 = fopen ("funzC/MultiGaussordine20","w");

for( int N=1 ; N<100 ;N++){
	int n=20;
	I = MultiGauss(funzC,n,a0,a1,N)/MultiGauss(funzC,10,a0,a1,2*N);		fprintf (myfile9, "%d \t %21.20f \n",20*N,fabs(I_atteso-I));
	}
fclose (myfile9);


return(0);}
