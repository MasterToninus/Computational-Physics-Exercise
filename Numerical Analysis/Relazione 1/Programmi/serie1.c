#include <iostream>
#include <math.h>
using namespace std;

int main()
{
cout <<" come avvengono le somme tra float? \n";
unsigned long int N = 10000; //massimo intero per cui calcolo la somma
const float Pi=3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
float result=(Pi*Pi)/6;//valore atteso

cout << " verifico i troncamenti!!!\n";

float sum1=0;
for(unsigned int i=1 ; i<=N ;i=i+1)
{
float a= 1/((double)i*i);
sum1= sum1+a;
}


float sum2=0;
for(unsigned int j=0 ; j<=N-1 ;j=j+1)
{
float i= (float)(N-j);

float a= 1/((float)i*i);
sum2= sum2+a;


}

printf("somma a partire da 1 =\t %21.20f\nsomma a rovescio =\t %21.20f\n risultato atteso =\t %21.20f",sum1,sum2,result);


return(0);}
