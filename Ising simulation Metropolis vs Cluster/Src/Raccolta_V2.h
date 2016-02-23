//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
//RACCOLTA TRAMITE ALGORITMO DI SWENDENWANG

void microstato::Raccolta_M_Cluster_V2(double Pbond, double *O, int Nmarkov){//beta, lunghezza vettore, vettore di osservabili da riempire

	end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
	cout<<"##--- inizio Raccolta di "<<Nmarkov<<" campioni di M \t \t t_esec: "<<tempo<<" sec"<<endl;

	for(int k=0;k<Nmarkov;k++){
		end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
		cout<<"##--# "<<k+1<<"-sima evoluzione \t \t t_esec: "<<tempo<<" sec" << string(300,'\b');
		step_SwenWang(Pbond);
		O[k]=M();
	}
	cout<<endl;
}

void microstato::Raccolta_M_Cluster_Improved_V2(double Pbond, double *O, int Nmarkov){//beta, lunghezza vettore, vettore di osservabili da riempire

	end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
	cout<<"##--- inizio Raccolta di "<<Nmarkov<<" campioni di M \t \t t_esec: "<<tempo<<" sec"<<endl;

	for(int k=0;k<Nmarkov;k++){
		end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
		cout<<"##--# "<<k+1<<"-sima evoluzione \t \t t_esec: "<<tempo<<" sec" << string(300,'\b');
		O[k]=step_SwenWang_M(Pbond);
	}
	cout<<endl;
}

void microstato::Raccolta_M_Cluster_Improved_Quad_V2(double Pbond, double *O,double *U, int Nmarkov){//beta, lunghezza vettore, vettore di osservabili da riempire( x 2) e lunghezza del vettore

	end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
	cout<<"##--- inizio Raccolta di "<<Nmarkov<<"campioni di M \t \t t_esec: "<<tempo<<" sec"<<endl;

	for(int k=0;k<Nmarkov;k++){
		end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
		cout<<"##--# "<<k+1<<"-sima evoluzione \t \t t_esec: "<<tempo<<" sec" << string(300,'\b');
		step_SwenWang_M_Quad(Pbond,	&O[k], &U[k]);
	}
	cout<<endl;
}

void microstato::Raccolta_H_Cluster_V2(double Pbond, double *O, int Nmarkov){//Pbond, lunghezza vettore, vettore di osservabili da riempire

	end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
	cout<<"##--- inizio Raccolta di "<<Nmarkov<<" campioni di H \t \t t_esec: "<<tempo<<" sec"<<endl;

	for(int k=0;k<Nmarkov;k++){
		end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
		cout<<"##--# "<<k+1<<"-sima evoluzione \t \t t_esec: "<<tempo<<" sec" << string(300,'\b');
		step_SwenWang(Pbond);
		O[k]=H();
	}
	cout<<endl;
}

void microstato::Raccolta_St_Cluster_V2(double Pbond, matrice O, int Nmarkov){//Pbond, lunghezza vettore, vettore di osservabili da riempire
//	http://www.cplusplus.com/forum/articles/7459/

	end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
	cout<<"##--- inizio Raccolta di 2N (sfruttando simmetrie) campioni di S (spin totale per ogni linea)  per ogni step di montecarlo  \t \t t_esec: "<<tempo<<" sec"<<endl;

	double S_riga[N], S_colonna[N];
	int t_max=(N-N%2)/2;

	for(int k=0;k<Nmarkov;k++){
		end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
		cout<<"##--# "<<k+1<<"-sima evoluzione \t \t t_esec: "<<tempo<<" sec" << string(300,'\b');
		step_SwenWang(Pbond);

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

		for(int t=1; t<=t_max; t++){
			for(int i=0; i<N; i++){
				int t_up=i+t;
				if(t_up>=N)t_up-=N;					//condizione di bordo periodico
				O.put(t, 2*N*k + i, S_riga[i]*S_riga[t_up]);//O[t][2*N*k + i] = S_riga[i]*S_riga[i+t];
				O.put( t, 2*N*k + N + i, S_colonna[i]*S_colonna[t_up]);
			}
		}
		for(int i=0; i<N; i++){
			O.put(0, 2*N*k + i, S_riga[i]);
			O.put( 0, 2*N*k + N + i, S_colonna[i]);
		}
	}
	cout<<endl;
}

