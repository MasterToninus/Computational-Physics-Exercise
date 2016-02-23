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
double I_atteso= 0;
for(int i=0; i<5000; i++){
double j= (double)5000-(double)i;
double coso=pow((double)1/j,j);
I_atteso=I_atteso+ coso;
}
double I; //integrale


cout<<"\nArea funzG da\t"<<a0<<"\t"<<a1<<"\n"<<endl;
//ciclo sulle diviosioni dell intervallo

ofstream myfile1("funzG/Rettangoli Inferiore",ios::trunc);
for( int N=5 ; N<500 ;N++){
	I = IntRetInf(funzG,a0,a1,N);	myfile1<<N<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile1.close();

ofstream myfile2("funzG/Rettangoli Superiore",ios::trunc);
for( int N=5 ; N<500 ;N++){
	I = IntRetSup(funzG,a0,a1,N);	myfile2<<N<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile2.close();

ofstream myfile3("funzG/Rettangoli Medio",ios::trunc);
for( int N=5 ; N<500 ;N++){
	I = IntRetMed(funzG,a0,a1,N);	myfile3<<N<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile3.close();

ofstream myfile4("funzG/Trapezi",ios::trunc);
for( int N=5 ; N<500 ;N++){
	I = IntTrap(funzG,a0,a1,N);	myfile4<<N*2<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile4.close();

ofstream myfile5("funzG/Simpson",ios::trunc);
for( int N=2 ; N<500 ;N++){
	I = IntSimp(funzG,a0,a1,N);	myfile5<<N*3<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile5.close();

ofstream myfile7("funzG/MultiGaussordine5",ios::trunc);
for( int N=1 ; N<500 ;N++){
	int n=5;
	I = MultiGauss(funzG,n,a0,a1,N);	myfile7<<N*5<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile7.close();

ofstream myfile8("funzG/MultiGaussordine10",ios::trunc);
for( int N=1 ; N<500 ;N++){
	int n=10;
	I = MultiGauss(funzG,n,a0,a1,N);	myfile8<<N*10<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile8.close();

ofstream myfile9("funzG/MultiGaussordine20",ios::trunc);
for( int N=1 ; N<500 ;N++){
	int n=20;
	I = MultiGauss(funzG,n,a0,a1,N);	myfile9<<N*20<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile9.close();


return(0);}
