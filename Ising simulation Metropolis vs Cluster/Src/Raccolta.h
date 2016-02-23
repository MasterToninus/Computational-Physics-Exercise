//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
//RACCOLTA TRAMITE ALGORITMO DI SWENDENWANG

void microstato::Raccolta_M_Cluster(double beta, double *O, int Nmarkov){//beta, lunghezza vettore, vettore di osservabili da riempire

	end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
	cout<<"##--- inizio Raccolta di "<<Nmarkov<<" campioni di M \t \t t_esec: "<<tempo<<" sec"<<endl;

	for(int k=0;k<Nmarkov;k++){
		end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
		cout<<"##--# "<<k+1<<"-sima evoluzione \t \t t_esec: "<<tempo<<" sec" << string(300,'\b');
		step_SwenWang(beta);
		O[k]=M();
	}
	cout<<endl;
}

void microstato::Raccolta_M_Cluster_Improved(double beta, double *O, int Nmarkov){//beta, lunghezza vettore, vettore di osservabili da riempire

	end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
	cout<<"##--- inizio Raccolta di "<<Nmarkov<<" campioni di M \t \t t_esec: "<<tempo<<" sec"<<endl;

	for(int k=0;k<Nmarkov;k++){
		end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
		cout<<"##--# "<<k+1<<"-sima evoluzione \t \t t_esec: "<<tempo<<" sec" << string(300,'\b');
		O[k]=step_SwenWang_M(beta);
	}
	cout<<endl;
}

void microstato::Raccolta_M_Cluster_Improved_Quad(double beta, double *O,double *U, int Nmarkov){//beta, lunghezza vettore, vettore di osservabili da riempire( x 2) e lunghezza del vettore

	end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
	cout<<"##--- inizio Raccolta di "<<Nmarkov<<"campioni di M \t \t t_esec: "<<tempo<<" sec"<<endl;

	for(int k=0;k<Nmarkov;k++){
		end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
		cout<<"##--# "<<k+1<<"-sima evoluzione \t \t t_esec: "<<tempo<<" sec" << string(300,'\b');
		step_SwenWang_M_Quad(beta,	&O[k], &U[k]);
	}
	cout<<endl;
}

void microstato::Raccolta_H_Cluster(double beta, double *O, int Nmarkov){//beta, lunghezza vettore, vettore di osservabili da riempire

	end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
	cout<<"##--- inizio Raccolta di "<<Nmarkov<<" campioni di H \t \t t_esec: "<<tempo<<" sec"<<endl;

	for(int k=0;k<Nmarkov;k++){
		end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
		cout<<"##--# "<<k+1<<"-sima evoluzione \t \t t_esec: "<<tempo<<" sec" << string(300,'\b');
		step_SwenWang(beta);
		O[k]=H();
	}
	cout<<endl;
}

double microstato::Raccolta_St_Cluster(double beta, matrice O, int Nmarkov){//beta, lunghezza vettore, vettore di osservabili da riempire
//	http://www.cplusplus.com/forum/articles/7459/

	end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
	cout<<"##--- inizio Raccolta di 2N (sfruttando simmetrie) campioni di S (spin totale per ogni linea)  per ogni step di Swen. - Wang  \t \t t_esec: "<<tempo<<" sec"<<endl;

	double S_riga[N], S_colonna[N];
	int t_max=(N-N%2)/2;
	double m = 0; 	

	for(int k=0;k<Nmarkov;k++){
		end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
		cout<<"##--# "<<k+1<<"-sima evoluzione \t \t t_esec: "<<tempo<<" sec" << string(300,'\b');

		m += step_SwenWang_M( beta);

		for(int i=0; i<N; i++){						//Calcolo lo spin medio su ogni riga e colonna
			S_riga[i]=0;
			S_colonna[i]=0;
			for(int j=0; j<N; j++){ 
			S_riga[i]+=StatoSpin[i][j];
			S_colonna[i]+=StatoSpin[j][i];		
			}
			S_riga[i] = S_riga[i]/N;				//spin totale sulla riga i-sima
			S_colonna[i] = S_colonna[i]/N;			//spin totale sulla colonna i-sima
		}

		for(int t=0; t<=t_max; t++){			//Inserisco nella matrice i valori di correlazione ( alla riga t la correlazione a tstep)
			for(int i=0; i<N; i++){
				int t_up=i+t;
				if(t_up>=N)t_up-=N;					//condizione di bordo periodico
				O.put(t, 2*N*k + i, S_riga[i]*S_riga[t_up]);//O[t][2*N*k + i] = S_riga[i]*S_riga[i+t];
				O.put( t, 2*N*k + N + i, S_colonna[i]*S_colonna[t_up]);
			}
		}

	}
	cout<<endl;
	return(m/Nmarkov);								//restituisce la magnetizzazione media
}



void microstato::Raccolta_Size_Cluster(double beta, double *O, int Nmarkov){//beta, lunghezza vettore, vettore di osservabili da riempire

	end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
	cout<<"##--- inizio Raccolta di "<<Nmarkov<<" campioni di Cluster Size \t \t t_esec: "<<tempo<<" sec"<<endl;

	for(int k=0;k<Nmarkov;k++){
		end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
		cout<<"##--# "<<k+1<<"-sima evoluzione \t \t t_esec: "<<tempo<<" sec" << string(300,'\b');
		O[k]=step_SwenWang_Size(beta);
	}
	cout<<endl;
}

void microstato::Raccolta_Tutto_Cluster(double beta, double *m, double *m_quad, double *h, int Nmarkov){//beta, lunghezza vettore, vettore di osservabili da riempire( x 2) e lunghezza del vettore

	end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
	cout<<"##--- inizio Raccolta di "<<Nmarkov<<"campioni di M, M^2, H \t \t t_esec: "<<tempo<<" sec"<<endl;

	for(int k=0;k<Nmarkov;k++){
		end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
		cout<<"##--# "<<k+1<<"-sima evoluzione \t \t t_esec: "<<tempo<<" sec" << string(300,'\b');
		step_SwenWang_M_Quad(beta,	&m[k], &m_quad[k]);
		h[k]=H();
	}
	cout<<endl;
}






//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
// RACCOLTA TRAMITE ALGORITMO DI METROPOLIS

void microstato::Raccolta_M_Metropolis(double beta, double *O, int Nmarkov){//beta, lunghezza vettore, vettore di osservabili da riempire

	end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
	cout<<"##--- inizio Raccolta di "<<Nmarkov<<" campioni di M \t \t t_esec: "<<tempo<<" sec"<<endl;

	for(int k=0;k<Nmarkov;k++){
		end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
		cout<<"##--# "<<k+1<<"-sima evoluzione \t \t t_esec: "<<tempo<<" sec" << string(300,'\b');
		step_montecarlo(beta);
		O[k]=M();
	}
	cout<<endl;
}

void microstato::Raccolta_M_abs_Metropolis(double beta, double *O, int Nmarkov){//beta, lunghezza vettore, vettore di osservabili da riempire

	end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
	cout<<"##--- inizio Raccolta di "<<Nmarkov<<" campioni di M \t \t t_esec: "<<tempo<<" sec"<<endl;

	for(int k=0;k<Nmarkov;k++){
		end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
		cout<<"##--# "<<k+1<<"-sima evoluzione \t \t t_esec: "<<tempo<<" sec" << string(300,'\b');
		step_montecarlo(beta);
		O[k]=fabs(M());
	}
	cout<<endl;
}


double microstato::Raccolta_St_Metropolis(double beta, matrice O, int Nmarkov){//beta, lunghezza vettore, vettore di osservabili da riempire

	end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
	cout<<"##--- inizio Raccolta di 2N (sfruttando simmetrie) campioni di S (spin totale per ogni linea)  per ogni step di montecarlo  \t \t t_esec: "<<tempo<<" sec"<<endl;

	double S_riga[N], S_colonna[N];
	int t_max=(N-N%2)/2;
	double m = 0;

	for(int k=0;k<Nmarkov;k++){
		end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
		cout<<"##--# "<<k+1<<"-sima evoluzione \t \t t_esec: "<<tempo<<" sec" << string(300,'\b');
		step_montecarlo(beta);
		m += M();
		for(int i=0; i<N; i++){
			S_riga[i]=0;
			S_colonna[i]=0;
			for(int j=0; j<N; j++){ 
			S_riga[i]+=StatoSpin[i][j];
			S_colonna[i]+=StatoSpin[j][i];		
			}
			S_riga[i] = S_riga[i]/N;				//spin totale sulla riga i-sima
			S_colonna[i] = S_colonna[i]/N;			//spin totale sulla colonna i-sima
		}

		for(int t=0; t<=t_max; t++){
			for(int i=0; i<N; i++){
				int t_up=i+t;
				if(t_up>=N)t_up-=N;					//condizione di bordo periodico
				O.put(t, 2*N*k + i, S_riga[i]*S_riga[t_up]);//O[t][2*N*k + i] = S_riga[i]*S_riga[i+t];
				O.put( t, 2*N*k + N + i, S_colonna[i]*S_colonna[t_up]);
			}
		}
	}
	cout<<endl;
	return(m/Nmarkov);								//restituisce la magnetizzazione media
}

void microstato::Raccolta_H_Metropolis(double beta, double *O, int Nmarkov){//beta, lunghezza vettore, vettore di osservabili da riempire

	end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
	cout<<"##--- inizio Raccolta di "<<Nmarkov<<" campioni di H \t \t t_esec: "<<tempo<<" sec"<<endl;

	for(int k=0;k<Nmarkov;k++){
		end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
		cout<<"##--# "<<k+1<<"-sima evoluzione \t \t t_esec: "<<tempo<<" sec" << string(300,'\b');
		step_montecarlo(beta);
		O[k]=H();
	}
	cout<<endl;
}

void microstato::Raccolta_Tutto_Metro(double beta, double *m, double *m_quad, double *h, int Nmarkov){//beta, lunghezza vettore, vettore di osservabili da riempire( x 2) e lunghezza del vettore

	end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
	cout<<"##--- inizio Raccolta di "<<Nmarkov<<"campioni di M, M^2, H \t \t t_esec: "<<tempo<<" sec"<<endl;

	for(int k=0;k<Nmarkov;k++){
		end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
		cout<<"##--# "<<k+1<<"-sima evoluzione \t \t t_esec: "<<tempo<<" sec" << string(300,'\b');
		step_montecarlo(beta);
		m[k] = fabs(M());
		m_quad[k] = m[k]*m[k];
		h[k] = H();	
	}
	cout<<endl;
}
