#include <iostream>
#include <math.h>
#include <fstream>
#include "funzioni.h"
#include "integrazione.h"
#include "gauss.h"
using namespace std;

/* Prototipo del programma usato per stampare i grafici */

int main()
{
double a0=1; //punto iniziale
double a1=2; //punto finale
double I_atteso= a1*funzD(a1)-a1+1;
double I; //integrale

//per montecarlo serve sapere il max e minimo, sarebbe scomodo e proceduralmente lungo mettere nel algoritmo di montecarlo uno per la ricerca degli estremanti!
double min=0;
double max=funzD(a1);

cout<<"\nArea funzD da\t"<<a0<<"\t"<<a1<<"\n"<<endl;
//ciclo sulle diviosioni dell intervallo

ofstream myfile1("Stima/Rettangoli_Inferiore",ios::trunc);
for( int N=3 ; N<300 ;N++){
	I = IntRetInf(funzD,a0,a1,N);	myfile1<<N<<" "<<fabs(I_atteso-I)<<endl;
	}
myfile1.close();

ofstream myfile2("Stima/Rettangoli_Superiore",ios::trunc);
for( int N=3 ; N<300 ;N++){
	I = IntRetSup(funzD,a0,a1,N);	myfile2<<N<<" "<<fabs(I_atteso-I)<<endl;
	}
myfile2.close();

ofstream myfile3("Stima/Rettangoli_Medio",ios::trunc);
for( int N=3 ; N<300 ;N++){
	I = IntRetMed(funzD,a0,a1,N);	myfile3<<N<<" "<<fabs(I_atteso-I)<<endl;
	}
myfile3.close();

ofstream myfile4("Stima/Trapezi",ios::trunc);
for( int N=3 ; N<300 ;N++){
	I = IntTrap(funzD,a0,a1,N);	myfile4<<N<<" "<<fabs(I_atteso-I)<<endl;
	}
myfile4.close();

ofstream myfile5("Stima/Simpson",ios::trunc);
for( int N=3 ; N<300 ;N++){
	I = IntSimp(funzD,a0,a1,N);	myfile5<<N<<" "<<fabs(I_atteso-I)<<endl;
	}
myfile5.close();

ofstream myfile6("Stima/Montecarlo",ios::trunc);
for( int N=1000 ; N<4000 ;N++){
	I = MonteCarlo(funzD,a0,a1,min,max,N);	myfile6<<N<<" "<<fabs(I_atteso-I)<<endl;
	}
myfile6.close();

ofstream myfile7("Stima/Gauss",ios::trunc);
for( int n=1 ; n<21 ;n++){
	I = IntGauss(funzD,n,a0,a1);	myfile7<<n<<" "<<fabs(I_atteso-I)<<endl;
	}
myfile7.close();

return(0);}
