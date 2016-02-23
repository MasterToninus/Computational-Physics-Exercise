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
double a0=0.000001; //punto iniziale non posso mettere esattamente zero perchè è singolare in 0!
double a1=2000; //punto finale dovrebbe essere l'infinito!
double I_atteso= M_PI;
double I; //integrale


double min=0;
double max=2;

cout<<"\nArea funzA da\t"<<a0<<"\t"<<a1<<"\n"<<endl;
//ciclo sulle diviosioni dell intervallo

ofstream myfile1("funzA/Rettangoli Inferiore",ios::trunc);
for( int N=5 ; N<2000 ;N++){
	I = IntRetInf(funzA,a0,a1,N);	myfile1<<N<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile1.close();

ofstream myfile2("funzA/Rettangoli Superiore",ios::trunc);
for( int N=5 ; N<2000 ;N++){
	I = IntRetSup(funzA,a0,a1,N);	myfile2<<N<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile2.close();

ofstream myfile3("funzA/Rettangoli Medio",ios::trunc);
for( int N=5 ; N<2000 ;N++){
	I = IntRetMed(funzA,a0,a1,N);	myfile3<<N<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile3.close();

ofstream myfile4("funzA/Trapezi",ios::trunc);
for( int N=5 ; N<1000 ;N++){
	I = IntTrap(funzA,a0,a1,N);	myfile4<<N*2<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile4.close();

ofstream myfile5("funzA/Simpson",ios::trunc);
for( int N=5 ; N<700 ;N++){
	I = IntSimp(funzA,a0,a1,N);	myfile5<<N*3<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile5.close();

ofstream myfile6("funzA/Montecarlo",ios::trunc);
for( int N=100 ; N<2400 ;N++){
	I = MonteCarlo(funzA,a0,a1,min,max,N);	myfile6<<N<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile6.close();

ofstream myfile7("funzA/MultiGaussordine5",ios::trunc);
for( int N=1 ; N<400 ;N++){
	int n=5;
	I = MultiGauss(funzA,n,a0,a1,N);	myfile7<<N*5<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile7.close();

ofstream myfile8("funzA/MultiGaussordine10",ios::trunc);
for( int N=1 ; N<200 ;N++){
	int n=10;
	I = MultiGauss(funzA,n,a0,a1,N);	myfile8<<N*10<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile8.close();

ofstream myfile9("funzA/MultiGaussordine20",ios::trunc);
for( int N=1 ; N<100 ;N++){
	int n=20;
	I = MultiGauss(funzA,n,a0,a1,N);	myfile9<<N*20<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile9.close();


return(0);}
