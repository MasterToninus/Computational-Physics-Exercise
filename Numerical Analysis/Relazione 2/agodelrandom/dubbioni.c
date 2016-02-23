#include <iostream>
#include <math.h>
#include <cstdlib> 
#include <iostream>
#include <ctime> 
#include <fstream>
#include "ago.h"
using namespace std;

//dubbioni: qual'è il periodo del generatore rand?????????

int main()
{
cout << "The value of RAND_MAX is " <<  RAND_MAX << endl;
srand((unsigned)time(0));

unsigned int x=rand();

unsigned int cont=0;
for(unsigned int i=1; i>0; i++){
	unsigned int y=rand();
	cont=cont+1;
	if(x==y)break;}
cout<<"\n il periodo del generatore è : "<< cont << endl<< " questo implica che la bontà del generatore è buona fino al ordine del miliardo di lanci"<<endl;
return(0);}
