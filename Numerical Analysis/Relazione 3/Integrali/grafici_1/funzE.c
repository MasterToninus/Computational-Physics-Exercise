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
double a1=10; //punto finale non posso mettere esattamente 5 perchè è singolare in 5!
double I_atteso= exp(-2)*sqrt(M_PI)/2;
double I; //integrale


cout<<"\nArea funzE da\t"<<a0<<"\t"<<a1<<"\n"<<endl;
//ciclo sulle diviosioni dell intervallo

ofstream myfile1("funzE/Rettangoli Inferiore",ios::trunc);
for( int N=5 ; N<10000 ;N++){
	I = IntRetInf(funzE,a0,a1,N);	myfile1<<N<<"\t"<<fabs(I_atteso-I)/I_atteso*100<<endl;
	}
myfile1.close();

ofstream myfile2("funzE/Rettangoli Superiore",ios::trunc);
for( int N=5 ; N<10000 ;N++){
	I = IntRetSup(funzE,a0,a1,N);	myfile2<<N<<"\t"<<fabs(I_atteso-I)/I_atteso*100<<endl;
	}
myfile2.close();

ofstream myfile3("funzE/Rettangoli Medio",ios::trunc);
for( int N=5 ; N<10000 ;N++){
	I = IntRetMed(funzE,a0,a1,N);	myfile3<<N<<"\t"<<fabs(I_atteso-I)/I_atteso*100<<endl;
	}
myfile3.close();

ofstream myfile4("funzE/Trapezi",ios::trunc);
for( int N=5 ; N<10000 ;N++){
	I = IntTrap(funzE,a0,a1,N);	myfile4<<N+1<<"\t"<<fabs(I_atteso-I)/I_atteso*100<<endl;
	}
myfile4.close();

ofstream myfile5("funzE/Simpson",ios::trunc);
for( int N=2 ; N<5000 ;N++){
	I = IntSimp(funzE,a0,a1,N);	myfile5<<2*N+1<<"\t"<<fabs(I_atteso-I)/I_atteso*100<<endl;
	}
myfile5.close();

ofstream myfile7("funzE/MultiGaussordine5",ios::trunc);
for( int N=1 ; N<2000 ;N++){
	int n=5;
	I = MultiGauss(funzE,n,a0,a1,N);	myfile7<<N*5<<"\t"<<fabs(I_atteso-I)/I_atteso*100<<endl;
	}
myfile7.close();

ofstream myfile8("funzE/MultiGaussordine10",ios::trunc);
for( int N=1 ; N<1000 ;N++){
	int n=10;
	I = MultiGauss(funzE,n,a0,a1,N);	myfile8<<N*10<<"\t"<<fabs(I_atteso-I)/I_atteso*100<<endl;
	}
myfile8.close();

ofstream myfile9("funzE/MultiGaussordine20",ios::trunc);
for( int N=1 ; N<500 ;N++){
	int n=20;
	I = MultiGauss(funzE,n,a0,a1,N);	myfile9<<N*20<<"\t"<<fabs(I_atteso-I)/I_atteso*100<<endl;
	}
myfile9.close();


return(0);}
