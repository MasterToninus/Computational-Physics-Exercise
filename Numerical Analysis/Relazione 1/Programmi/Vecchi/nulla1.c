#include <iostream>
#include <math.h>
#include <limits>
using namespace std;
//Calcolo teorico della precisione macchina nei principali tipi di variabili

/*http://ennebi.solira.org/cpp/pag21.html
http://en.wikipedia.org/wiki/IEEE_754
http://en.wikipedia.org/wiki/IEEE_754-1985
*/


int main()
{
cout <<"\n******** SULLA PRECISIONE DELLE VARIABILI *************\n\n\n";



cout<<"_____________INTERI_____________________"<<endl;
cout << "bit intero " << numeric_limits<int>::digits << endl;
  cout << "cifre intero " << numeric_limits<int>::digits10 << endl;
  cout << "minimo intero " << numeric_limits<int>::min() << endl;
  cout << "massimo intero " << numeric_limits<int>::max() << endl;

cout << "\nbit unsigned intero " << numeric_limits<unsigned int>::digits << endl;
  cout << "cifre unsigned intero " << numeric_limits<unsigned int>::digits10 << endl;
  cout << "minimo unsigned intero " << numeric_limits<unsigned int>::min() << endl;
  cout << "massimo unsigned intero " << numeric_limits<unsigned int>::max() << endl;

cout<<"\n_____________VIRGOLA MOBILE_____________________"<<endl;

cout<<"FLOAT: \n 1     8               23               lunghezza in bit\n+-+--------+-----------------------+\n|S|  Esp.  |  Mantissa             |\n+-+--------+-----------------------+\n31 30      22                      0    indice dei bit\n";  
cout << "\nbit float " << numeric_limits<float>::digits << endl;
  cout << "cifre float " << numeric_limits<float>::digits10 << endl;
  cout << "minimo float " << numeric_limits<float>::min() << endl;
  cout << "massimo float " << numeric_limits<float>::max() << endl;

cout << "\n ultima cifra rappresentata 2^-23 ="<< pow(0.5,23)<<endl << endl;

cout<<"\nDOUBLE : \n  1     11                                52\n+-+-----------+----------------------------------------------------+\n|S|  Exp      |  Fraction                                          |\n+-+-----------+----------------------------------------------------+\n64 63        52                                                    0\n";



  cout << "\nbit double " << numeric_limits<double>::digits << endl; 
  cout << "cifre double " << numeric_limits<double>::digits10 << endl; 
  cout << "minimo double " << numeric_limits<double>::min() << endl;
  cout << "massimo double " << numeric_limits<double>::max() << endl;

cout << "\n ultima cifra rappresentata 2^-53 ="<< pow(0.5,53)<<endl << endl;

  cout << "\nbit long double " << numeric_limits<long double>::digits << endl; 
  cout << "cifre long double " << numeric_limits<long double>::digits10 << endl; 
  cout << "minimo long double " << numeric_limits<long double>::min() << endl;
  cout << "massimo long double " << numeric_limits<long double>::max() << endl;


cout << "\n ultima cifra rappresentata 2^-64 ="<< pow(0.5,65) <<endl << endl;



float alfa = 0.0031415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679f;
double beta = 0.0031415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
long double gamma = 0.0031415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679L;


cout<<"\nErrore intrinseco nella rappresentazione in virgola mobile:\n"<<endl;
cout<<"           |      !  |         |         |         |         |         |"<<endl;
printf(" float=   %56.55f \n double=  %56.55f \n longDo=  %56.55Lf \n vero=    0.0031415926535897932384626433832795028841971693993751058209\n",alfa,beta,gamma);
cout<<"           |         |     !  !|         |         |         |         |\n ottengo la precisione predetta!!"<<endl;










cout << "\n\n\n";



return(0);}
