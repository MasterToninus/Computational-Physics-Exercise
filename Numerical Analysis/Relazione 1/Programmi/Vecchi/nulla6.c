#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

/* 
http://it.wikipedia.org/wiki/IEEE_754 
http://it.wikipedia.org/wiki/Virgola_mobile
http://www.mat.uniroma3.it/users/liverani/IN1/gnuplot.shtml
con implementato Kahan sommation algorithm
*/
int main()
{

cout<<".......studio del resto della serie......"<<endl;
unsigned int N = 1000000000; //massimo intero per cui calcolo la somma
const double Pi=3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679L;
 double result=(Pi*Pi)/6;//valore atteso



double tot=result , c=0;
for(unsigned int i=1 ; i<N ;i=i++)
{
double a= 1./((double)i*i);

double y=a-c;
double tote= tot - y;
c=(tote-tot)+a;
tot=tote;

if (tot<0.000001 )//float è preciso fino alla quinta cifra
   {
      cout<<"dopo il termine :" << i<< " il valore non varia piu'\n";
      cout<<"lo somma dei termini della successione successivi a: "<<i<<" sono minori di:" <<scientific<< tot<< " e il valore totale non varia piu'\n\n\n";
      
break;
      /* esce dal ciclo */
   }
}


return(0);}
