#include <iostream>
#include <math.h>
using namespace std;
/*programma per valutare la somma parziale dei termini della successione 1/n^2 dello stesso ordine di grandezza*/

int main()
{
cout << " Quanto valgono le somme parziali della serie: \n";
cout <<"sum^ = " << scientific<< 1. <<"\t termini ~ 1\t\t\t\t\te+00"<< endl;

long double sum0=0 ;
for(unsigned int i=3 ; i>1 ;i=i-1)
{
long double a= 1.0/(i*i);
sum0= sum0 +a;
}
cout <<"sum0 = " << scientific<< sum0 <<"\t termini ~ 0.1\t\t\t\t\te-01"<< endl;


long double sum1=0 ;
for(unsigned int i=10 ; i>3 ;i=i-1)
{
long double a= 1.0/(i*i);
sum1= sum1 +a;
}

cout <<"sum1 = " << scientific<< sum1<<"\t termini ~ 0.01\t\t\t\t\te-02"<< endl;

long double sum2=0 ;
for(unsigned int i=31 ; i>10 ;i=i-1)
{
long double a= 1./(i*i);
sum2= sum2 +a;
}

cout <<"sum2 = " << scientific<< sum2<<"\t termini ~ 0.001\t\t\t\te-03"<< endl;

long double sum3=0 ;
for(unsigned int i=100 ; i>31 ;i=i-1)
{
long double a= 1./(i*i);
sum3= sum3 +a;
}

cout <<"sum3 = " << scientific<< sum3<<"\t termini ~ 0.0001\t\t\t\te-04"<< endl;

long double sum4=0 ;
for(unsigned int i=316 ; i>100 ;i=i-1)
{
long double a= 1./(i*i);
sum4= sum4 +a;
}

cout <<"sum4 = " << scientific<< sum4<<"\t termini ~ 0.00001\t\t\t\te-05"<< endl;

long double sum5=0 ;
for(unsigned int i=1000 ; i>316 ;i=i-1)
{
long double a= 1./(i*i);
sum5= sum5+a;
}

cout <<"sum5 = " << scientific<< sum5<<"\t termini ~ 0.000001\t\t\t\te-06"<< endl;

long double sum6=0 ;
for(unsigned int i=3162 ; i>1000 ;i=i-1)
{
long double a= 1./(i*i);
sum6= sum6+a;
}

cout <<"sum6 = " << scientific<< sum6<<"\t termini ~ 0.0000001\t\t\t\te-07"<< endl;

long double sum7=0 ;
for(unsigned int i=10000 ; i>3162 ;i=i-1)
{
long double a= 1./(i*i);
sum7= sum7+a;
}

cout <<"sum7 = " << scientific<< sum7<<"\t termini ~ 0.00000001\t\t\t\te-08"<< endl;

long double sum8=0 ;
for(unsigned int i=31622 ; i>10000 ;i=i-1)
{
long double a= 1./(i*i);
sum8= sum8+a;
}

cout <<"sum8 = " << scientific<< sum8<<"\t termini ~ 0.000000001\t\t\t\te-09"<< endl;

long double sum9=0 ;
for(unsigned int i=100000 ; i>31622 ;i=i-1)
{
long double a= 1./((long double)i*i); //cast!!
sum9= sum9+a;
}

cout <<"sum9 = " << scientific<< sum9<<"\t termini ~ 0.0000000001\t\t\t\te-10"<< endl;

long double sum10=0 ;
for(unsigned int i=316227 ; i>100000 ;i=i-1)
{
long double a= 1./((long double)i*i); //cast!!
sum10= sum10+a;
}

cout <<"sum10 = " << scientific<< sum10 <<"\t termini ~ 0.00000000001\t\t\te-11"<< endl;

long double sum11=0 ;
for(unsigned int i=1000000 ; i>316227 ;i=i-1)
{
long double a= 1./((long double)i*i); //cast!!
sum11= sum11+a;
}

cout <<"sum11 = " << scientific<< sum11 <<"\t termini ~ 0.000000000001\t\t\te-12"<< endl;


long double sum12=0 ;
for(unsigned int i=3162277 ; i>1000000 ;i=i-1)
{
long double a= 1./((long double)i*i); //cast!!
sum12= sum12+a;
}
cout <<"sum12 = " << scientific<< sum12 <<"\t termini ~ 0.0000000000001\t\t\te-13"<< endl;

long double sum13=0;
for(unsigned int i=10000000; i>3162277; i=i-1)
{
long double a= 1./((long double)i*i); //cast!!
sum13= sum13+a;
}
cout <<"sum13 = " << scientific<< sum13 <<"\t termini ~ 0.00000000000001\t\t\te-14"<< endl;

long double sum14=0 ;
for(unsigned int i=31622776 ; i>10000000 ;i=i-1)
{
long double a= 1./((long double)i*i); //cast!!
sum14= sum14+a;
}
cout <<"sum14 = " << scientific<< sum14 <<"\t termini ~ 0.000000000000001\t\t\te-15"<< endl;

long double sum15=0;
for(unsigned int i=100000000; i>31622776; i=i-1)
{
long double a= 1./((long double)i*i); //cast!!
sum15= sum15+a;
}
cout <<"sum15 = " << scientific<< sum15 <<"\t termini ~ 0.0000000000000001\t\t\te-16"<< endl;

long double sum16=0;
for(unsigned int i=316227766; i>100000000; i=i-1)
{
long double a= 1./((long double)i*i); //cast!!
sum16= sum16+a;
}
cout <<"sum16 = " << scientific<< sum16 <<"\t termini ~ 0.00000000000000001\t\t\te-17"<< endl;

long double sum17=0;
for(unsigned int i=1000000000; i>316227766; i=i-1)
{
long double a= 1./((long double)i*i); //cast!!
sum17= sum17+a;
}
cout <<"sum17 = " << scientific<< sum17 <<"\t termini ~ 0.000000000000000001\t\t\te-18"<< endl;

/*anche da qui ci sono probleblemic' un warning!*/

long double sum18=0;
for(unsigned int i=3162277660; i>1000000000; i=i-1)
{
long double a= 1./((long double)i*i); //cast!!
sum18= sum18+a;
}
cout <<"sum18 = " << scientific<< sum18 <<"\t termini ~ 0.0000000000000000001\t\te-19"<< endl;






//da qui iniziano i problemi il massimo unsigned int consentito è 4294967295!

long double sum19=0;
long double a=10^(10), b=sqrt(10^(2*9+1));
for(long double i=a; i>b; i=i-1)
{
long double a= 1./((long double)i*i); //cast!!
sum19= sum19+a;
}
cout <<"sum19 = " << scientific<< sum19 <<"\t termini ~ 0.00000000000000000001\t\te-20  ciclo con indice double non ha senso"<< endl;

a=sqrt(10^(2*10+1));b = 10^10;
long double sum20=0;
for(long double i=a; i>b; i=i-1)
{
long double a= 1./((long double)i*i); //cast!!
sum20= sum20+a;
}
cout <<"sum20 = " << scientific<< sum20 <<"\t termini ~ 0.000000000000000000001\t\te-21"<< endl;

a= sqrt(10^(11)); b = 10^(2*10+1);
long double sum21=0;
for(long double i=a; i>b; i=i-1)
{
long double a= 1./((long double)i*i); //cast!!
sum21= sum21+a;
}
cout <<"sum21 = " << scientific<< sum21 <<"\t termini ~ 0.0000000000000000000001\t\te-22"<< endl;

a= sqrt(10^(2*11+1)); b = 10^(11);
long double sum22=0;
for(long double i=a; i>b; i=i-1)
{
long double a= 1./((long double)i*i); //cast!!
sum21= sum21+a;
}
cout <<"sum22 = " << scientific<< sum22 <<"\t termini ~ 0.00000000000000000000001\t\te-23"<< endl;






long double sum=sqrt(6.*(1.+sum0+ sum1 +sum2+sum3+sum4+sum5+sum6+sum7+sum8+sum9+sum10+sum11+sum12+sum13+sum14+sum15+sum16+sum17+sum18+sum19+sum20+sum21+sum22));

cout<<"         |        |        |        |        |        |        |"<<endl;
printf(" pi=   %56.55Lf \n vero= 3.1415926535897932384626433832795028841971693993751058209\n",sum);
cout<<"         |     !  |        |        |        |        |        | "<<endl;



/*cout<<" ho un errore alla 7^ cifra decimale (bisogna ricordarsi di far scorrere la virgola finchè non ha davanti un zero è un 1)\nil float di base è preciso fino alla sesta ultimo bit: 2^-23 = 0.0000001 \nho ottenuto un valore preciso fino al float? \n per quanto visto prima il valore a cui arresto il calcolo della serie ha un resto che è < di 10^-6 che quindi non potrei nemmeno percepire quando immagazzino la variabile come float"<< endl;
*/



return(0);}
