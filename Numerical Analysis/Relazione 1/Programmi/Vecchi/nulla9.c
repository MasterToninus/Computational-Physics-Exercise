#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;


int main()
{

cout<<".......studio del resto della serie......"<<endl;
unsigned int N = 10000000; //massimo intero per cui calcolo la somma

const double Pi=3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679L;
 double result=(Pi*Pi)/6;//valore atteso

cout<<".......calcolo......"<<endl;

fstream myfile;
  myfile.open ("dati2.txt");




double resto=result , c=0;
for(unsigned int i=1 ; i<N ;i=i++)
{
double a= 1./((double)i*i);

double y=a-c;
double tote= resto - y;
c=(tote-resto)+a;
resto=tote;
if (i>300000 and i%100==0) //non stampo sul file i primi resti, non sono utili. stampo uno ogni 10
   {
      myfile<<i<<"\t"<<resto<<endl;
   }
}
myfile.close();




return(0);}
