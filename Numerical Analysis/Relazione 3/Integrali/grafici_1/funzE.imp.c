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
double a1=5; //punto finale non posso mettere esattamente 5 perchè è singolare in 5!
double I_atteso= exp(-2)*sqrt(M_PI)/2;
double I; //integrale


cout<<"\nArea funzE da\t"<<a0<<"\t"<<a1<<"\n"<<endl;
//ciclo sulle diviosioni dell intervallo

ofstream myfile1("funzE/Rettangoli Inferiore",ios::trunc);
for( int N=5 ; N<10000 ;N++){
	double h=1/N;
	double K= 5*N ;//numero di incrementini per ottenere l'intervallo desiderati K =|a1-a0|/h
	I = IntRetInf_I(funzE,a0,h,K);	myfile1<<h<<"\t"<<fabs(I_atteso-I)/I_atteso*100<<endl;
	}
myfile1.close();

ofstream myfile2("funzE/Rettangoli Superiore",ios::trunc);
for( int N=5 ; N<10000 ;N++){
	double h=1/N;
	double K= 5*N ;	
	I = IntRetSup_I(funzE,a0,h,K);	myfile2<<h<<"\t"<<fabs(I_atteso-I)/I_atteso*100<<endl;
	}
myfile2.close();

ofstream myfile3("funzE/Rettangoli Medio",ios::trunc);
for( int N=5 ; N<10000 ;N++){
	double h=1/N;
	double K= 5*N ;
	I = IntRetMed_I(funzE,a0,h,K);	myfile3<<h<<"\t"<<fabs(I_atteso-I)/I_atteso*100<<endl;
	}
myfile3.close();

ofstream myfile4("funzE/Trapezi",ios::trunc);
for( int N=5 ; N<10000 ;N++){
	double h=1/N;
	double K= 5*N ;
	I = IntTrap_I(funzE,a0,h,K);	myfile4<<h<<"\t"<<fabs(I_atteso-I)/I_atteso*100<<endl;
	}
myfile4.close();

ofstream myfile5("funzE/Simpson",ios::trunc);
for( int N=2 ; N<5000 ;N++){
	double h=1/N;
	double K= 5*N ;
	I = IntSimp_I(funzE,a0,h,K);	myfile5<<h<<"\t"<<fabs(I_atteso-I)/I_atteso*100<<endl;
	}
myfile5.close();

ofstream myfile7("funzE/MultiGaussordine5",ios::trunc);
for( int N=1 ; N<2000 ;N++){
	double h=1/N;
	double K= 5*N ;	int n=5;
	I = MultiGauss_I(funzE,n,a0,h,K);	myfile7<<h<<"\t"<<fabs(I_atteso-I)/I_atteso*100<<endl;
	}
myfile7.close();

ofstream myfile8("funzE/MultiGaussordine10",ios::trunc);
for( int N=1 ; N<1000 ;N++){
	double h=1/N;
	double K= 5*N ;	
	int n=10;
	I = MultiGauss(funzE,n,a0,h,K);	myfile8<<h<<"\t"<<fabs(I_atteso-I)/I_atteso*100<<endl;
	}
myfile8.close();

ofstream myfile9("funzE/MultiGaussordine20",ios::trunc);
for( int N=1 ; N<500 ;N++){
	double h=1/N;
	double K= 5*N ;
	int n=20;
	I = MultiGauss(funzE,n,a0,h,K);	myfile9<<h<<"\t"<<fabs(I_atteso-I)/I_atteso*100<<endl;
	}
myfile9.close();


return(0);}
