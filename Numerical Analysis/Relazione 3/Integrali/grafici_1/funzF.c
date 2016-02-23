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
double a0=0.00000001; //punto iniziale non posso mettere esattamente 0 perchè il logaritmo è singolare in 1!
double a1=1; //punto finale 
double I_atteso= -pow(M_PI,2)/12;
double I; //integrale


cout<<"\nArea funzF da\t"<<a0<<"\t"<<a1<<"\n"<<endl;
//ciclo sulle diviosioni dell intervallo

ofstream myfile1("funzF/Rettangoli Inferiore",ios::trunc);
for( int N=5 ; N<500 ;N++){
	I = IntRetInf(funzF,a0,a1,N);	myfile1<<N<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile1.close();

ofstream myfile2("funzF/Rettangoli Superiore",ios::trunc);
for( int N=5 ; N<500 ;N++){
	I = IntRetSup(funzF,a0,a1,N);	myfile2<<N<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile2.close();

ofstream myfile3("funzF/Rettangoli Medio",ios::trunc);
for( int N=5 ; N<500 ;N++){
	I = IntRetMed(funzF,a0,a1,N);	myfile3<<N<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile3.close();

ofstream myfile4("funzF/Trapezi",ios::trunc);
for( int N=5 ; N<500 ;N++){
	I = IntTrap(funzF,a0,a1,N);	myfile4<<N+1<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile4.close();

ofstream myfile5("funzF/Simpson",ios::trunc);
for( int N=5 ; N<500 ;N++){
	I = IntSimp(funzF,a0,a1,N);	myfile5<<2*N+1<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile5.close();

ofstream myfile7("funzF/MultiGaussordine5",ios::trunc);
for( int N=1 ; N<500 ;N++){
	int n=5;
	I = MultiGauss(funzF,n,a0,a1,N);	myfile7<<N*5<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile7.close();

ofstream myfile8("funzF/MultiGaussordine10",ios::trunc);
for( int N=1 ; N<500 ;N++){
	int n=10;
	I = MultiGauss(funzF,n,a0,a1,N);	myfile8<<N*10<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile8.close();

ofstream myfile9("funzF/MultiGaussordine20",ios::trunc);
for( int N=1 ; N<500 ;N++){
	int n=20;
	I = MultiGauss(funzF,n,a0,a1,N);	myfile9<<N*20<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile9.close();


return(0);}
