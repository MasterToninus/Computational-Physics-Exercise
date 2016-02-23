double microstato::Raccolta_St_Cluster_v2(double beta, matrice O, int Nmarkov){//beta, lunghezza vettore, vettore di osservabili da riempire
//	http://www.cplusplus.com/forum/articles/7459/

	end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
	cout<<"##--- inizio Raccolta di 2N (sfruttando simmetrie) campioni di S (spin totale per ogni linea)  per ogni step di Swen. - Wang  \t \t t_esec: "<<tempo<<" sec"<<endl;

	double S_riga[N], S_colonna[N];
	int t_max=(N-N%2)/2;
	double m = 0; 	

	for(int k=0;k<Nmarkov;k++){
		end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
		cout<<"##--# "<<k+1<<"-sima evoluzione \t \t t_esec: "<<tempo<<" sec" << string(300,'\b');

		m = step_SwenWang_M( beta);

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
				double S0St=0;	
				int t_up=i+t;
				if(t_up>=N)t_up-=N;					//condizione di bordo periodico
				S0St+= S_riga[i]*S_riga[t_up] +  S_colonna[i]*S_colonna[t_up];
			}
				S0St = S0St/(2*N) - m*m;
				O.put(t, k, S0St);
		}

	}
	cout<<endl;
	return(m/Nmarkov);								//restituisce la magnetizzazione media
}

