#include <iostream>
#include <math.h>
#include <fstream>

#include "pendoli.h"
#include "problemicauchy.h"
using namespace std;

int main(){
        
	int N=10000;	// numero di punti
	double dt=0.01;	// passo di campionatura	

	double t[N]; 	//vettori delle variabili x,y,y'
	double Th[N];
	double w[N];    

	
	
	t[0]=0;		//valore iniziale
    	Th[0]=(M_PI)*0.25+0.013;
	w[0] =0;
     
 
Runge_Kutta_secondo(F,t,Th,w,dt,N);


    	ofstream myfile("1_theta_t",ios::trunc);
	for(int i=0;i<N;i++){myfile<<t[i]<<"\t\t\t"<<Th[i]<<endl;}
	myfile.close();
/*
	ofstream myfile1("grafici/1_vel_t.txt",ios::trunc);
	for(int i=0;i<N;i++){myfile1<<t[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile1.close();

	ofstream myfile2("grafici/1_spaziofasi.txt",ios::trunc);
	for(int i=0;i<N;i++){myfile2<<Th[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile2.close();
*/

//normalizzazione a pigreco
	for(int i=0;i<N;i++){
	double k=(Th[i])/(M_PI);
	int num= (int)k;
	if(num%2==0) Th[i]=Th[i]-num*M_PI;
	else {	if(num>0) Th[i]=Th[i]-(num+1)*M_PI;
	else Th[i]=Th[i]-(num-1)*M_PI;}
	}
ofstream myfile1("spaziofasi",ios::trunc);
	for(int i=0;i<N;i++){myfile1<<Th[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile1.close();




	Th[0]=(M_PI)*0.25+0.017;
	Runge_Kutta_secondo(F1,t,Th,w,dt,N);

	ofstream myfile3("2_theta_t",ios::trunc);
	for(int i=0;i<N;i++){myfile3<<t[i]<<"\t\t\t"<<Th[i]<<endl;}
	myfile3.close();
/*
	ofstream myfile4("grafici/2_vel_t.txt",ios::trunc);
	for(int i=0;i<N;i++){myfile4<<t[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile4.close();

	ofstream myfile5("grafici/2_spaziofasi.txt",ios::trunc);
	for(int i=0;i<N;i++){myfile5<<Th[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile5.close();	
*/

	Th[0]=(M_PI)*0.25+0.015;
	Runge_Kutta_secondo(F2,t,Th,w,dt,N);

	ofstream myfile6("3_theta_t",ios::trunc);
	for(int i=0;i<N;i++){myfile6<<t[i]<<"\t\t\t"<<Th[i]<<endl;}
	myfile6.close();
/*
	ofstream myfile7("grafici/3_vel_t.txt",ios::trunc);
	for(int i=0;i<N;i++){myfile7<<t[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile7.close();

	ofstream myfile8("grafici/3_spaziofasi.txt",ios::trunc);
	for(int i=0;i<N;i++){myfile8<<Th[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile8.close();
*/



return(0);
	}
