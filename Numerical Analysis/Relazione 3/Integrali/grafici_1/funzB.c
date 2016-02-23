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
double a1=5-0.00000001; //punto finale non posso mettere esattamente 5 perchè è singolare in 5!
double I_atteso= M_PI/2;
double I; //integrale

//per montecarlo serve sapere il max e minimo, sarebbe scomodo e proceduralmente lungo mettere nel algoritmo di montecarlo uno per la ricerca degli estremanti!
double min=0;
double max=funzB(a1);

cout<<"\nArea funzB da\t"<<a0<<"\t"<<a1<<"\n"<<endl;
//ciclo sulle diviosioni dell intervallo

ofstream myfile1("funzB/Rettangoli Inferiore",ios::trunc);
for( int N=5 ; N<2000 ;N++){
	I = IntRetInf(funzB,a0,a1,N);	myfile1<<N<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile1.close();

ofstream myfile2("funzB/Rettangoli Superiore",ios::trunc);
for( int N=5 ; N<2000 ;N++){
	I = IntRetSup(funzB,a0,a1,N);	myfile2<<N<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile2.close();

ofstream myfile3("funzB/Rettangoli Medio",ios::trunc);
for( int N=5 ; N<2000 ;N++){
	I = IntRetMed(funzB,a0,a1,N);	myfile3<<N<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile3.close();

ofstream myfile4("funzB/Trapezi",ios::trunc);
for( int N=4 ; N<1000 ;N++){
	I = IntTrap(funzB,a0,a1,N);	myfile4<<N+1<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile4.close();

ofstream myfile5("funzB/Simpson",ios::trunc);
for( int N=2 ; N<700 ;N++){
	I = IntSimp(funzB,a0,a1,N);	myfile5<<2*N+1<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile5.close();

ofstream myfile6("funzB/Montecarlo",ios::trunc);
for( int N=100 ; N<2400 ;N++){
	I = MonteCarlo(funzB,a0,a1,min,max,N);	myfile6<<N<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile6.close();

ofstream myfile7("funzB/MultiGaussordine5",ios::trunc);
for( int N=1 ; N<400 ;N++){
	int n=5;
	I = MultiGauss(funzB,n,a0,a1,N);	myfile7<<N*5<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile7.close();

ofstream myfile8("funzB/MultiGaussordine10",ios::trunc);
for( int N=1 ; N<200 ;N++){
	int n=10;
	I = MultiGauss(funzB,n,a0,a1,N);	myfile8<<N*10<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile8.close();

ofstream myfile9("funzB/MultiGaussordine20",ios::trunc);
for( int N=1 ; N<100 ;N++){
	int n=20;
	I = MultiGauss(funzB,n,a0,a1,N);	myfile9<<N*20<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile9.close();


return(0);}
