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


float alfa = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679f;
double beta = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
long double gamma = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679L;


cout<<"\nErrore intrinseco nella rappresentazione in virgola mobile:\n"<<endl;
cout<<"           |      !  |         |         |         |         |         |         |"<<endl;
printf(" float=   %56.70f \n double=  %56.70f \n longDo=  %56.70Lf \n vero=    3.1415926535897932384626433832795028841971693993751058209749445923078164\n",alfa,beta,gamma);
cout<<"           |         |     !  !|         |         |         |         |         |\n ottengo la precisione predetta!!"<<endl;


cout<<"\nErrore nella rappresentazione in base 2:\n"<<endl;
alfa = 0.1f;
beta =0.1;
gamma = 0.1L;
cout<<"           |      !  |         |         |         |         |         |         |"<<endl;
printf(" float=   %56.70f \n double=  %56.70f \n longDo=  %56.70Lf \n vero=    0.1000000000000000000000000000000000000000000000000000000000000000000000\n",alfa,beta,gamma);
cout<<"           |         |         |         |         |         |         |         |\n anche un semplice numero razionale viene allocato con un errore!"<<endl;

cout<<"\n concludo che una variabile floating point è in ogni caso uguale al numero che abbiamo allocato solo fino ad una certa cifra significativa."<<endl;

cout<<"\n\n\nsi può notare che l'errore sulla variabile non è sempre sulla stessa cifra... la cosa dipende dal massimo e minimo numero che la variabile può allocare\n"<<endl;
  
  cout << "minimo float " << numeric_limits<float>::min() << endl;
  cout << "massimo float " << numeric_limits<float>::max() << endl;
  cout << "minimo double " << numeric_limits<double>::min() << endl;
  cout << "massimo double " << numeric_limits<double>::max() << endl;
  cout << "minimo long double " << numeric_limits<long double>::min() << endl;
  cout << "massimo long double " << numeric_limits<long double>::max() << endl;
cout << "ad esempio vedo la differenza tra certe cifre:\n";
alfa =31.415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679f;
beta =31.415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
gamma =31.415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679L;
cout<<"           |         |         |         |         |         |         |         |"<<endl;
printf(" float=   %56.70f \n double=  %56.70f \n longDo=  %56.70Lf \n vero=    31.415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679\n",alfa,beta,gamma);
cout<<"           |         |         |         |         |         |         |         |\n "<<endl;

alfa =0.00314159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706791f;
beta =0.0031415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
gamma =0.0031415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679L;
cout<<"           |         |         |         |         |         |         |         |"<<endl;
printf(" float=   %56.70f \n double=  %56.70f \n longDo=  %56.70Lf \n vero=    0.0031415926535897932384626433832795028841971693993751058209\n",alfa,beta,gamma);
cout<<"           |         |         |         |         |         |         |         |\n "<<endl;

return(0);}
