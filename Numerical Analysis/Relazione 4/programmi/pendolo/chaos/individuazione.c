#include <iostream>
#include <math.h>
#include <fstream>

#include "problemicauchy.h"
using namespace std;


double Fcaos(double t, double x, double v) 
{double R, A=0.5, B=1, F0=1.148555, W=0.66;
	
R= -(A)*v-(B)*(sin(x))+F0*cos(W*t);
return(R);
}



double Falta(double t, double x, double v) 
{double R, A=0.5, B=1, F0=2.150, W=0.66;
	
R= -(A)*v-(B)*(sin(x))+F0*cos(W*t);
return(R);
}

double Falta_1(double t, double x, double v) 
{double R, A=0.5, B=1, F0=2.155, W=0.66;
	
R= -(A)*v-(B)*(sin(x))+F0*cos(W*t);
return(R);
}

double Falta_2(double t, double x, double v) 
{double R, A=0.5, B=1, F0=2.145, W=0.66;
	
R= -(A)*v-(B)*(sin(x))+F0*cos(W*t);
return(R);
}

double Fbassa(double t, double x, double v) 
{double R, A=0.5, B=1, F0=0.150, W=0.66;
	
R= -(A)*v-(B)*(sin(x))+F0*cos(W*t);
return(R);
}


double Fbassa_1(double t, double x, double v) 
{double R, A=0.5, B=1, F0=0.155, W=0.66;
	
R= -(A)*v-(B)*(sin(x))+F0*cos(W*t);
return(R);
}

double Fbassa_2(double t, double x, double v) 
{double R, A=0.5, B=1, F0=0.145, W=0.66;
	
R= -(A)*v-(B)*(sin(x))+F0*cos(W*t);
return(R);
}

int main(){
        
	int N=20000;	// numero di punti
	double dt=0.005;	// passo di campionatura	

	double t[N]; 	//vettori delle variabili x,y,y'
	double Th[N];
	double w[N];    

	
	
	t[0]=0;		//valore iniziale
    	Th[0]=0;
	w[0] =0;
     
 
Runge_Kutta_secondo(Falta,t,Th,w,dt,N);

    	ofstream myfile("individuazione/F0_alta",ios::trunc);
	for(int i=0;i<N;i++){myfile<<t[i]<<"\t\t\t"<<Th[i]<<endl;}
	myfile.close();
//normalizzazione a pigreco
	for(int i=0;i<N;i++){
	double k=(Th[i])/(M_PI);
	int num= (int)k;
	if(num%2==0) Th[i]=Th[i]-num*M_PI;
	else {	if(num>0) Th[i]=Th[i]-(num+1)*M_PI;
	else Th[i]=Th[i]-(num-1)*M_PI;}
	}
ofstream myfile1("individuazione/F0_alta_fasi",ios::trunc);
	for(int i=5000;i<N;i++){myfile1<<Th[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile1.close();

Runge_Kutta_secondo(Falta_1,t,Th,w,dt,N);

    	ofstream myfile7("individuazione/F0_alta_+",ios::trunc);
	for(int i=0;i<N;i++){myfile7<<t[i]<<"\t\t\t"<<Th[i]<<endl;}
	myfile7.close();
//normalizzazione a pigreco
	for(int i=0;i<N;i++){
	double k=(Th[i])/(M_PI);
	int num= (int)k;
	if(num%2==0) Th[i]=Th[i]-num*M_PI;
	else {	if(num>0) Th[i]=Th[i]-(num+1)*M_PI;
	else Th[i]=Th[i]-(num-1)*M_PI;}
	}
ofstream myfile8("individuazione/F0_alta_+_fasi",ios::trunc);
	for(int i=5000;i<N;i++){myfile8<<Th[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile8.close();
	
Runge_Kutta_secondo(Falta_2,t,Th,w,dt,N);

    	ofstream myfile9("individuazione/F0_alta_-",ios::trunc);
	for(int i=0;i<N;i++){myfile9<<t[i]<<"\t\t\t"<<Th[i]<<endl;}
	myfile9.close();
//normalizzazione a pigreco
	for(int i=0;i<N;i++){
	double k=(Th[i])/(M_PI);
	int num= (int)k;
	if(num%2==0) Th[i]=Th[i]-num*M_PI;
	else {	if(num>0) Th[i]=Th[i]-(num+1)*M_PI;
	else Th[i]=Th[i]-(num-1)*M_PI;}
	}
ofstream myfile10("individuazione/F0_alta_-_fasi",ios::trunc);
	for(int i=5000;i<N;i++){myfile10<<Th[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile10.close();
	


	Runge_Kutta_secondo(Fcaos,t,Th,w,dt,N);

	ofstream myfile3("individuazione/F0_caos",ios::trunc);
	for(int i=0;i<N;i++){myfile3<<t[i]<<"\t\t\t"<<Th[i]<<endl;}
	myfile3.close();
	
//normalizzazione a pigreco
	for(int i=0;i<N;i++){
	double k=(Th[i])/(M_PI);
	int num= (int)k;
	if(num%2==0) Th[i]=Th[i]-num*M_PI;
	else {	if(num>0) Th[i]=Th[i]-(num+1)*M_PI;
	else Th[i]=Th[i]-(num-1)*M_PI;}
	}
ofstream myfile4("individuazione/F0_caos_fasi",ios::trunc);
	for(int i=5000;i<N;i++){myfile4<<Th[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile4.close();
	
	
	



	Runge_Kutta_secondo(Fbassa,t,Th,w,dt,N);

	ofstream myfile5("individuazione/F0_bassa",ios::trunc);
	for(int i=0;i<N;i++){myfile5<<t[i]<<"\t\t\t"<<Th[i]<<endl;}
	myfile5.close();

//normalizzazione a pigreco
	for(int i=0;i<N;i++){
	double k=(Th[i])/(M_PI);
	int num= (int)k;
	if(num%2==0) Th[i]=Th[i]-num*M_PI;
	else {	if(num>0) Th[i]=Th[i]-(num+1)*M_PI;
	else Th[i]=Th[i]-(num-1)*M_PI;}
	}
ofstream myfile6("individuazione/F0_bassa_fasi",ios::trunc);
	for(int i=5000;i<N;i++){myfile6<<Th[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile6.close();

Runge_Kutta_secondo(Fbassa_1,t,Th,w,dt,N);

    	ofstream myfile11("individuazione/F0_bassa_+",ios::trunc);
	for(int i=0;i<N;i++){myfile11<<t[i]<<"\t\t\t"<<Th[i]<<endl;}
	myfile11.close();
//normalizzazione a pigreco
	for(int i=0;i<N;i++){
	double k=(Th[i])/(M_PI);
	int num= (int)k;
	if(num%2==0) Th[i]=Th[i]-num*M_PI;
	else {	if(num>0) Th[i]=Th[i]-(num+1)*M_PI;
	else Th[i]=Th[i]-(num-1)*M_PI;}
	}
ofstream myfile12("individuazione/F0_bassa_+_fasi",ios::trunc);
	for(int i=5000;i<N;i++){myfile12<<Th[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile12.close();
	
Runge_Kutta_secondo(Fbassa_2,t,Th,w,dt,N);

    	ofstream myfile13("individuazione/F0_bassa_-",ios::trunc);
	for(int i=0;i<N;i++){myfile13<<t[i]<<"\t\t\t"<<Th[i]<<endl;}
	myfile13.close();
//normalizzazione a pigreco
	for(int i=0;i<N;i++){
	double k=(Th[i])/(M_PI);
	int num= (int)k;
	if(num%2==0) Th[i]=Th[i]-num*M_PI;
	else {	if(num>0) Th[i]=Th[i]-(num+1)*M_PI;
	else Th[i]=Th[i]-(num-1)*M_PI;}
	}
ofstream myfile14("individuazione/F0_bassa_-_fasi",ios::trunc);
	for(int i=5000;i<N;i++){myfile14<<Th[i]<<"\t\t\t"<<w[i]<<endl;}
	myfile14.close();

return(0);
	}
