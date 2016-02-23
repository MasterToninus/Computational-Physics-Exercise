#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
/*stampo la coppia (termine della serie , somma parziale) */

int main()
{

unsigned int N = 10000; //massimo intero per cui calcolo la somma


cout<<".......calcolo......"<<endl;

fstream myfile;
  myfile.open ("dati1.txt");



float tot=0 , c=0,y,tote;
for(unsigned int i=1 ; i<=N ;i=i+1)
{
float a= 1./((float)i*i);
y=a-c;
tote= tot + y;
c=(tote-tot)-a;
tot=tote;
if (i%10==0) // ogni 10
   {
      myfile<<i<<"\t"<<tot<<endl;
   }
}



myfile.close();




/*
const double Pi=3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
 float result=(Pi*Pi)/6;
float sum=0;
for(unsigned int i=1 ; i<=N ;i=i+1)
{
float a= 1./((float)i*i);
sum=sum+a;

if (sum==result)
   {
      cout<<"dopo il termine :" << i<< " il valore non varia piu'\n";
      cout<<"i termini della successione successivi a: "<<i<<" sono minori di:" <<scientific<< 1/((double)i*i)<< " e il valore totale non varia piu'\n";
      
break;
   
   }
}*/
return(0);}
