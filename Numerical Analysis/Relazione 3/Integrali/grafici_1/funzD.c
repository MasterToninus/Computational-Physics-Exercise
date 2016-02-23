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
double a1=350; //punto finale
double I_atteso= a1*funzD(a1)-a1+1;
double I; //integrale

//per montecarlo serve sapere il max e minimo, sarebbe scomodo e proceduralmente lungo mettere nel algoritmo di montecarlo uno per la ricerca degli estremanti!
double min=0;
double max=funzD(a1);

cout<<"\nArea funzD da\t"<<a0<<"\t"<<a1<<"\n"<<endl;
//ciclo sulle diviosioni dell intervallo

ofstream myfile1("funzD/Rettangoli Inferiore",ios::trunc);
for( int N=5 ; N<2000 ;N++){
	I = IntRetInf(funzD,a0,a1,N);	myfile1<<N<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile1.close();

ofstream myfile2("funzD/Rettangoli Superiore",ios::trunc);
for( int N=5 ; N<2000 ;N++){
	I = IntRetSup(funzD,a0,a1,N);	myfile2<<N<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile2.close();

ofstream myfile3("funzD/Rettangoli Medio",ios::trunc);
for( int N=5 ; N<2000 ;N++){
	I = IntRetMed(funzD,a0,a1,N);	myfile3<<N<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile3.close();

ofstream myfile4("funzD/Trapezi",ios::trunc);
for( int N=3 ; N<1000 ;N++){
	I = IntTrap(funzD,a0,a1,N);	myfile4<<N*2<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile4.close();

ofstream myfile5("funzD/Simpson",ios::trunc);
for( int N=2 ; N<660 ;N++){
	I = IntSimp(funzD,a0,a1,N);	myfile5<<N*3<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile5.close();

ofstream myfile6("funzD/Montecarlo",ios::trunc);
for( int N=100 ; N<2400 ;N++){
	I = MonteCarlo(funzD,a0,a1,min,max,N);	myfile6<<N<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile6.close();

ofstream myfile7("funzD/MultiGaussordine5",ios::trunc);
for( int N=1 ; N<400 ;N++){
	int n=5;
	I = MultiGauss(funzD,n,a0,a1,N);	myfile7<<N*5<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile7.close();

ofstream myfile8("funzD/MultiGaussordine10",ios::trunc);
for( int N=1 ; N<200 ;N++){
	int n=10;
	I = MultiGauss(funzD,n,a0,a1,N);	myfile8<<N*10<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile8.close();

ofstream myfile9("funzD/MultiGaussordine20",ios::trunc);
for( int N=1 ; N<100 ;N++){
	int n=20;
	I = MultiGauss(funzD,n,a0,a1,N);	myfile9<<N*20<<"\t"<<fabs(I_atteso-I)<<endl;
	}
myfile9.close();


/*ofstream myfile7("Stima/Gauss",ios::trunc);
for( int n=1 ; n<21 ;n++){
	I = IntGauss(funzD,n,a0,a1);	myfile7<<n<<" "<<fabs(I_atteso-I)<<endl;
	}
myfile7.close();*/

return(0);}
