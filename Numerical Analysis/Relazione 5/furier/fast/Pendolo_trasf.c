#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>

#include "FFT.h"

using namespace std;
int main()
{
	unsigned long int nn=0 ;
	double x;
	
	ifstream inFile;	//conta numero di punti valutati
	inFile.open("F0_caos");
		if (!inFile)
			{cout << "Unable to open file";
			exit(1);}	 // terminate with error
	while (inFile >> x >> x)	nn++	;
	cout<<"\n numero di punti\t\t\t"<<nn<<endl;
	inFile.close();


	unsigned long int N = (nn << 1) +1 , i = 1;



	double t[N] , h[N] ;
	ifstream inFile1;
	inFile1.open("F0_caos");if (!inFile1) {cout << "Unable to open file";	exit(1);}
	while (inFile1 >> t[i] >> h[i]){h[i+1] = 0 /*parte immaginaria nulla*/;	i= i + 2	;}
	inFile1.close();
	
	double dt = t[3] - t[1];
	
	FFT( h , nn , 1);
	
	unsigned long int hn = nn >> 1;	
	double  H[nn];
	for(unsigned long i=0, j=1 ; i<nn ; i++ , j=j+2)	H[i]= sqrt( h[j]*h[j] + h[j+1]*h[j+1])*dt;
	
	ofstream file1("spettro_F0_caos",ios::trunc);
//frequenza positive 
	for(unsigned long int i=0 ; i<=hn ; i++)
		{double fn =((double) i )/((double)nn*dt) ;	
		file1<< fn <<"\t\t\t"<<H[i]<<endl;}
	for(unsigned long int i= 1 ; i<hn ; i++)
		{double fn = -(nn/2 -i)/((double)nn*dt) ;	
		file1<< fn <<"\t\t\t"<<H[i]<<endl;}
	file1.close();
	


return(0);}

