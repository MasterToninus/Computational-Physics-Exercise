/*
STUDIO DIPENDENZA DELLA SUSCETTIVITÀ <Chi> DA BETA CON L'ALGORITMO A MULTICLUSTER
	produce un grafico Chi vs B con errore

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

#include "funzioni_statistica.h"
#include "funzioni_utili.h"
#include "Matrici.h"
#include "microstati_struttura.h"

#define beta_crit log( 1.+ sqrt(2.))/2.

double jackknife_Chi( double *O,double *O_quad, int N){ //newman pag 88
	double m=media(O,N);
	double m_quad= media(O_quad,N);
	double Chi= m_quad -m*m;
	double Chi_j;
	double J=0; 
	for(int j=0;j<N;j++){
		double m_j=0;
		double m_j_quad=0;
		for(int i=0;i<N;i++){
			if(i != j){
				m_j += O[i];
				m_j_quad += O_quad[i]; 
			}
		}		
		m_j	=	(m_j/(N-1)) ;
		m_j_quad = (m_j_quad/(N-1)) ;
		Chi_j= m_j_quad - m_j * m_j;
		J += (Chi_j - Chi)*(Chi_j - Chi);
	}
	return(sqrt(J*(N-1)/N));
}

void quadratura( double *O,double *O_quad, int N){
	for(int j=0;j<N;j++){
	O_quad[j]= O[j] * O[j];
	}
}



int main()
{
	int N=100;							//numero di nodi in una linea
	microstato sistema(N);				//inizializzo la classe microstato

	int n_dots_1=30, n_dots_2 = 3 * n_dots_1, n_dots_3 = n_dots_1; 		//# punti per sezione 
	int n_dots_tot=n_dots_1 +n_dots_2 + n_dots_3; 						// # punti totali
	double X[n_dots_tot] , Y[n_dots_tot], Z[n_dots_tot];				//array ascissa ordinata del grafico

	int Nmarkov=1500;						//numero di elementi della catana di markov su cui produco la statistica
	double O[Nmarkov];					//array dei valori assunti dall Osservabile istantaneo sulla catena
	double O_quad[Nmarkov];

	double beta_min=0.025, beta_max= beta_crit -0.085;			//Primo pezzo_ prima della zona critica
	double step= (beta_max-beta_min)/n_dots_1;
	int k = 0;

	while (k < n_dots_1){															
		double beta= beta_min + k*step;
		cout<<"\n>>>>> "<<k<<"-sima Raccolta di M su "<<n_dots_tot<<" (beta = "<<beta<<" )"<<endl;
		X[k] = beta;
		sistema.evol_SwenWang(beta, 30);
		sistema.Raccolta_M_Cluster_Improved_Quad(beta, O, O_quad, Nmarkov);
		double dummy = media(O,Nmarkov);
		Y[k]=beta*(N*N)*(media(O_quad,Nmarkov) - dummy*dummy);
		Z[k] = beta*(N*N)*jackknife_Chi( O,O_quad, Nmarkov);
		k++;
	}
	int k_end= k;

	beta_min = beta_max, beta_max= beta_crit +0.085;			//secondo pezzo_ intorno alla temperatura critica
	step= (beta_max-beta_min)/(n_dots_2);
	while (k < k_end + n_dots_2){													
		double beta= beta_min + (k - (k_end))*step;
		cout<<"\n>>>>> "<<k<<"-sima Raccolta di M su "<<n_dots_tot<<" (beta = "<<beta<<" )"<<endl;
		X[k] = beta;
		sistema.evol_SwenWang(beta, 30);
		sistema.Raccolta_M_Cluster_Improved_Quad(beta, O, O_quad, Nmarkov);
		double dummy = media(O,Nmarkov);
		Y[k]=beta*(N*N)*(media(O_quad,Nmarkov) - dummy*dummy);
		Z[k] = beta*(N*N)*jackknife_Chi( O,O_quad, Nmarkov);
		k++;
	}
	k_end = k;

	beta_min = beta_max, beta_max= 0.90;						//terzo pezzo_ dopo la temperatura critica
	step= (beta_max-beta_min)/n_dots_3;
	while (k < n_dots_tot){															
		double beta= beta_min + (k - (k_end))*step;
		cout<<"\n>>>>> "<<k<<"-sima Raccolta di M su "<<n_dots_tot<<" (beta = "<<beta<<" )"<<endl;
		X[k] = beta;
		sistema.evol_SwenWang(beta, 30);
		sistema.Raccolta_M_abs_Metropolis(beta, O, Nmarkov);
		quadratura( O,O_quad, Nmarkov);
		double dummy = media(O,Nmarkov);
		Y[k]=beta*(N*N)*(media(O_quad,Nmarkov) - dummy*dummy);
		Z[k] = beta*(N*N)*jackknife_Chi( O,O_quad, Nmarkov);
		k++;
	}


		stringstream sstm;
		sstm << "Output/ParteA/"<<"ChivsBeta_N"<< N <<".dat";
		string nomeFile = sstm.str();
		cout<<"\n>>>>> Costruzione grafico "<<nomeFile<<endl;
		grafico(n_dots_tot, X, Y, Z, nomeFile);


return(0);
}
