#include <iostream>
#include <math.h>
#include <limits>
using namespace std;
//Calcolo teorico della precisione macchina nei principali tipi di variabili
//la rappresentazione in binario implica un'inevitabile approssimazione della cifra a seconda del numero di bit che utilizza per immagazzinarla


int main()
{
cout <<"\n******** SULLA PRECISIONE DELLE VARIABILI *************\n\n\n";
cout <<"\n usando le funzioni *numeric_limits* è possibile sapere quanti bit vengono utilizzati dalla mantissa delle variabili floating points"<<endl; 

cout<<"\n_____________Float_____________________"<<endl;
	cout << "bit mantissa float " << numeric_limits<float>::digits << endl;	
	cout << "cifre float " << numeric_limits<float>::digits10 << endl; //Number of digits (in decimal base) that can be represented without change.


cout<<"\n_____________Double_____________________"<<endl;
	cout << "bit mantissa double " << numeric_limits<double>::digits << endl; 
	cout << "cifre double " << numeric_limits<double>::digits10 << endl; 


cout<<"\n_____________Long Double_____________________"<<endl;
  cout << "bit mantissa long double " << numeric_limits<long double>::digits << endl; 
  cout << "cifre long double " << numeric_limits<long double>::digits10 << endl; 


float alfa = 1;
double beta = 1;
long double gamma = 1;

cout<<"\nErrore intrinseco nella rappresentazione in virgola mobile:\n"<<endl;
cout<<"           |      !  |         |         |         |         |         |         |"<<endl;
printf(" float=   %56.70f \n double=  %56.70f \n longDo=  %56.70Lf \n vero=1\n",alfa,beta,gamma);
cout<<"           |         |     !  !|         |         |         |         |         |\n ottengo la precisione predetta!!"<<endl;










cout << "\n\n\n";



return(0);}
