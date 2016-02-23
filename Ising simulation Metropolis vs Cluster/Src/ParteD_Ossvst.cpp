/*
	STUDIO DIPENDENZA DELLA OSSERVABILI <m>, <Chi>, <C> DA t

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

double jackknife_c( double *O, int N){
	double m = media(O,N);
	double m_quad = media_quadratica(O,N);
	double c = m_quad -m*m;
	double c_j;
	double J = 0; 
	for(int j=0;j<N;j++){
		double m_j=0;
		double m_j_quad=0;
		for(int i=0;i<N;i++){
			if(i != j){
				m_j += O[i];
				m_j_quad += O[i]*O[i]; 
			}
		}		
		m_j	=	(m_j/(N-1)) ;
		m_j_quad = (m_j_quad/(N-1)) ;
		c_j= m_j_quad - m_j * m_j;
		J += (c_j - c)*(c_j - c);
	}
	return(sqrt(J*(N-1)/N));
}

int main()
{
	int N_i=120;							//numero di nodi in una linea
	microstato sistema(N_i);				//inizializzo la classe microstato

	int n_dots_1 = 20, n_dots_2 = 5 * n_dots_1, n_dots_3 = n_dots_1; 		//# punti per sezione 
	int n_dots_tot = n_dots_1 +n_dots_2 + n_dots_3; 						// # punti totali
	double X, Y_1 , Z_1 ;			//array ascissa ordinata del grafico M
	double Y_2, Z_2;			//array ascissa ordinata del grafico Chi
	double Y_3, Z_3;			//array ascissa ordinata del grafico c


	int Nmarkov=1500;						//numero di elementi della catana di markov su cui produco la statistica
	double M[Nmarkov];					//array dei valori assunti dall Osservabile istantaneo sulla catena
	double M_quad[Nmarkov];
	double H[Nmarkov];

	for(int n=0;n<4;n++){ //stampo 4 grafici con diversi N
		int N= N_i-30*n;
		sistema.rinizializza(N);

		stringstream sstm1;
		sstm1 << "Output/ParteD/"<<"M/Mvst_N"<< N <<".dat";
		string nomeFile1 = sstm1.str();
		stringstream sstm2;
		sstm2 << "Output/ParteD/"<<"Chi/Chivst_N"<< N <<".dat";
		string nomeFile2 = sstm2.str();
		stringstream sstm3;
		sstm3 << "Output/ParteD/"<<"c/cvst_N"<< N <<".dat";
		string nomeFile3 = sstm3.str();


		double beta_min=beta_crit-0.15, beta_max= beta_crit -0.085;			//Primo pezzo_ prima della zona critica
		double step= (beta_max-beta_min)/n_dots_1;
		int k = 12;	
		while (k < n_dots_1){															
			double beta= beta_min + k*step; 
			cout<<"\n>>>>> Raccolta del punto "<<k<<" / "<<n_dots_tot<<" (beta = "<<beta<<" )"<<endl;
			X = beta_crit/beta - 1;
			sistema.evol_SwenWang(beta, 30);
			sistema.Raccolta_Tutto_Cluster(beta, M, M_quad,H, Nmarkov);

			Y_1 = media(M,Nmarkov);
			Z_1 = jackknife(M,Nmarkov);

			double M_med = media(M,Nmarkov);
			Y_2 = beta*(N*N)*(media(M_quad,Nmarkov) - M_med*M_med);
			Z_2 = beta*(N*N)*jackknife_Chi( M,M_quad, Nmarkov);

			double H_med = media(H,Nmarkov);
			double H_med_quad= media_quadratica(H,Nmarkov);
			Y_3 = (beta*beta)*(N*N)*(H_med_quad - H_med*H_med);
			Z_3 = (beta*beta)*(N*N)*jackknife_c( H, Nmarkov);

			grafico_add(X,Y_1,Z_1,nomeFile1);
			grafico_add(X,Y_2,Z_2,nomeFile2);
			grafico_add(X,Y_3,Z_3,nomeFile3);
			k++;
		}
		int k_end= k;

		beta_min = beta_max, beta_max= beta_crit +0.085;			//secondo pezzo_ intorno alla temperatura critica
		step= (beta_max-beta_min)/(n_dots_2);
		while (k < k_end + n_dots_2){													
			double beta= beta_min + (k - (k_end))*step;
			cout<<"\n>>>>> Raccolta del punto "<<k<<" / "<<n_dots_tot<<" (beta = "<<beta<<" )"<<endl;
			X = beta_crit/beta - 1;
			sistema.evol_SwenWang(beta, 30);
			sistema.Raccolta_Tutto_Cluster(beta, M, M_quad,H, Nmarkov);
	
			Y_1 = media(M,Nmarkov);
			Z_1 = jackknife(M,Nmarkov);

			double M_med = media(M,Nmarkov);
			Y_2 = beta*(N*N)*(media(M_quad,Nmarkov) - M_med*M_med);
			Z_2 = beta*(N*N)*jackknife_Chi( M,M_quad, Nmarkov);

			double H_med = media(H,Nmarkov);
			double H_med_quad= media_quadratica(H,Nmarkov);
			Y_3 = (beta*beta)*(N*N)*(H_med_quad - H_med*H_med);
			Z_3 = (beta*beta)*(N*N)*jackknife_c( H, Nmarkov);

			grafico_add(X,Y_1,Z_1,nomeFile1);
			grafico_add(X,Y_2,Z_2,nomeFile2);
			grafico_add(X,Y_3,Z_3,nomeFile3);
			k++;
		}
		k_end = k;

		beta_min = beta_max, beta_max = beta_crit + 0.15;						//terzo pezzo_ dopo la temperatura critica
		step = (beta_max-beta_min)/n_dots_3;
		while (k < n_dots_tot){															
			double beta= beta_min + (k - (k_end))*step;
			cout<<"\n>>>>> Raccolta del punto "<<k<<" / "<<n_dots_tot<<" (beta = "<<beta<<" )"<<endl;
			X = beta_crit/beta - 1;
			sistema.evol_SwenWang(beta, 30);
			sistema.Raccolta_Tutto_Cluster(beta, M, M_quad,H, Nmarkov);
	
			Y_1 = media(M,Nmarkov);
			Z_1 = jackknife(M,Nmarkov);

			double M_med = media(M,Nmarkov);
			Y_2 = beta*(N*N)*(media(M_quad,Nmarkov) - M_med*M_med);
			Z_2 = beta*(N*N)*jackknife_Chi( M,M_quad, Nmarkov);

			double H_med = media(H,Nmarkov);
			double H_med_quad= media_quadratica(H,Nmarkov);
			Y_3 = (beta*beta)*(N*N)*(H_med_quad - H_med*H_med);
			Z_3 = (beta*beta)*(N*N)*jackknife_c( H, Nmarkov);

			grafico_add(X,Y_1,Z_1,nomeFile1);
			grafico_add(X,Y_2,Z_2,nomeFile2);
			grafico_add(X,Y_3,Z_3,nomeFile3);
			k++;
		}
	}

return(0);
}



