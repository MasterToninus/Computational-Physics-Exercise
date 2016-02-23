
#include <iostream>
#include <iomanip>

using namespace std;


//costruzione istogramma


void histodouble(double *P,int K,double centro,double range, int n_col ){ 

//creo vettore dei conti e lo azzero
int N=n_col+2;
int v[N];
for(int j=0; j<N; j++)v[j]=0;			


double min= centro-range/2;
double h= range/n_col;

//conteggio
for(int i=0 ; i<K ; i++)
		{ 
		for(int j=0; j<N-1; j++)
			{
			if(P[i]<= min+j*h){v[j]=v[j]+1;break;}
			}
		if(P[i]>= min+n_col*h){ v[N-1]=v[N-1]+1;}
		}

//output di prova
cout << "\t\t  # <  "<< min<<"\t\t\t:\t"<<v[0]<<endl;
for( int j=0; j<N-1; j++)cout << min +j*h << " \t< # <  "<< min +(j+1)*h <<"\t\t\t:\t"<< v[j]<<endl;
cout << "\t\t  # >  "<< min+n_col*h<< "\t\t\t:\t"<<v[N-1]<<endl;



int tot=0;
for( int j=0; j<N; j++)tot= tot+v[j];
cout<<" tot conteggi è ="<<tot<<endl;


//scrittura file istogramma
ofstream myfile("myHistogramData.txt",ios::trunc);	
for( int j=1; j<N-1; j++)myfile<< min +h*((double)j-0.5)<<"\t"<<v[j]<<endl;
myfile.close();

return;}
