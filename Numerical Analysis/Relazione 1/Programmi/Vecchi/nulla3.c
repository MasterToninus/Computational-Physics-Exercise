#include <iostream>
#include <math.h>
using namespace std;

/* 
http://it.wikipedia.org/wiki/IEEE_754 
http://it.wikipedia.org/wiki/Virgola_mobile


*/
int main()
{
cout <<" come avvengono le somme tra float? \n";
cout<<".......calcolo con l'algoritmo di kahan (riduzione del troncamento dato dalla somma)......"<<endl;
unsigned int N = 1000000000; //massimo intero per cui calcolo la somma
const double Pi=3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679L;
 double result=(Pi*Pi)/6;//valore atteso


//somma inversa
 double tot1=0 , c=0;
for(unsigned int i=N ; i>0 ;i=i-1)
{
double a= 1./((double)i*i);
double y=a-c;
double tote= tot1 + y;
c=(tote-tot1)-a;
tot1=tote;
}


double tot2=0 , c2=0;
for(unsigned int i=1 ; i<(N-1) ;i=i++)
{
double a= 1./((double)i*i);
double y=a-c2;
double tote= tot2 + y;
c2=(tote-tot2)-a;
tot2=tote;
}




cout <<"somma a partire da 1 = \t"<<scientific<< tot2 << "\nsomma a rovescio = \t" <<scientific<< tot1 << "\nrisultato atteso = \t" <<scientific<< result<<endl;
//cout<<"differiscono di \t : "<<K<<endl;

return(0);}
