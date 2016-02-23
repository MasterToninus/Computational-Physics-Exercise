#include <cstdlib> 
#include <iostream>
#include <ctime> 
#include <fstream>
#include <math.h>
#include "integrazioneMonteCarlo.h"
#include "funzione1.h"
using namespace std;
//test per l'invertitore

int main()
{
double x0,x1;
x0=-2;x1=-5;
cout<<"\tx0 :"<<x0<<"\tx1 :"<<x1<<"\n"<<endl;
ordinatore(x0,x1);
cout<<"invertitore...\n\tx0 :"<<x0<<"\tx1 :"<<x1<<"\n"<<endl;


return(0);}
