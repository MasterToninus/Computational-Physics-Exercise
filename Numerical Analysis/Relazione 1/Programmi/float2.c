#include <iostream>
#include <math.h>
#include <limits>
using namespace std;
//Calcolo teorico della precisione macchina nei principali tipi di variabili
//la rappresentazione in binario implica un'inevitabile approssimazione della cifra a seconda del numero di bit che utilizza per immagazzinarla


int main()
{

cout<<"\nErrore nella rappresentazione in base 2:\n"<<endl;
float alfa = 0.1f/10 ;
double beta =0.1/10 ;
long double gamma = 0.1L/10 ;
cout<<"           |      !  |         |         |         |         |         |         |"<<endl;
printf(" float=   %56.70f \n double=  %56.70f \n longDo=  %56.70Lf \n vero=    0.1000000000000000000000000000000000000000000000000000000000000000000000\n",alfa,beta,gamma);
cout<<"           |         |         |         |         |         |         |         |\n anche un semplice numero razionale viene allocato con un errore!"<<endl;


return(0);}
