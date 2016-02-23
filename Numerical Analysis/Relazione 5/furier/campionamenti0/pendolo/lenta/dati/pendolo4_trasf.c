#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>

#include "trasformazione_fourier_2.h"

using namespace std;
int main()
{
	int N=0 , i=0;
	double x;
	
	ifstream inFile;
	inFile.open("pendolo4");
		if (!inFile)
			{cout << "Unable to open file";
			exit(1);}	 // terminate with error
	while (inFile >> x >> x)	N++	;
	cout<<"\t\t\t"<<N<<endl;
	inFile.close();


	double t[N] , h[N] , H[N];
	ifstream inFile1;
	inFile1.open("pendolo4");
		if (!inFile1) 
			{cout << "Unable to open file";
			exit(1);}	// terminate with error
	while (inFile1 >> t[i] >> h[i])	i++	;
	inFile.close();
	
	//for(i=0 ; i < N ; i++ )    cout<< t[i] << "\t\t\t" << h[i] << endl;
	double dt = t[2] - t[1];
	modH (dt ,N ,h, H );
	
	ofstream file("spettro_pendolo4",ios::trunc);
	for(int i=0 ; i<N ; i++)
		{double fn =(-0.5 + (double)i/N)/dt ;	
		file<< fn <<"\t\t\t"<<H[i]<<endl;}
	file.close();

	return(0);}
