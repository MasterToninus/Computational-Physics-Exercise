/*
PROBLEMA 8
Studiare il limite termodinamico di PV/(Nkt)
PRODUCE GRAFICO termP vs N

*/


#include <iostream>
#include <string>
#include <sstream> //per giocare con la classe string

#include <math.h>
#include <cstdlib> 
#include <ctime> 
#include <fstream>
#include <vector>


using namespace std;

#include "funzioni_utili.h"
#include "vettori_fisici.h"
#include "tempi_collisione.h"
#include "STRUTTURONA_sfere_rigide.h"

double rho_star(double eta,int d){return(eta*d*2/M_PI);}

int main()
{

	int d= 3;
	double eta=0.3;

	string nomeFile ="Output/Problema8/termPvsN_3D.dat";
	grafico_start(nomeFile,"\t#N\t\t#termP\t\t#sigmatermP\t");

	int Nc = 500000; //500*sistema.M
	double Y,Z;

	int n_dots = 6;
 	int N_min=2, N_step = 1;

	for(int i=0;i<=n_dots;i++){
		int	N=N_min +i*N_step; // numero di particellle lungo un lato
		sistema_rigido sistema(d, N, eta);
		sistema.CheckSovrapposizione();
		sistema.Termalizzazione(Nc);	//termalizzo: 50 urti per ogni particella
		if(sistema.CheckSovrapposizione()==0){ cout<<"\t a eta= "<<eta<<" le particelle sono sovrapposte"<<endl;break;}

		sistema.P_Osservabile( Nc, &Y, 25, &Z);
		Y = Y - 1;
		cout<<Y<<endl;
		grafico_add(nomeFile, 3, (double)sistema.M, (double)Y, (double)Z);
		sistema.stampa_stato("Test/prova3D.dat");
	}



return(0);
}
