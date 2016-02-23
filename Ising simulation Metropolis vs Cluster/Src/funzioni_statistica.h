//------------------------------------------------------------------------------------------------------------------------------
//		FUNZIONI STATISTICHE SU ARRAY DI VALORI
//------------------------------------------------------------------------------------------------------------------------------

double media(double *V,int  V_size){
	double tot=0;
	for(int i=0;i<V_size;i++)	tot+=V[i];
	return(tot/(double)V_size);
}
double media_quadratica(double *V,int  V_size){
	double tot=0;
	for(int i=0;i<V_size;i++)	tot+=V[i]*V[i];
	return(tot/(double)V_size);
}

double deviazione_standard(double *V,int  V_size){
	double tot=0, totquad=0;
	for(int i=0;i<V_size;i++){	tot+=V[i]; totquad+=V[i]*V[i];}
	totquad= totquad/V_size;
	tot=tot/(double)V_size;
	return(sqrt((totquad - tot*tot)));
}



//------------------------------------------------------------------------------------------------------------------------------
//		STUDIO DELLA CORRELAZIONE PER ARRAY DI MISURE
//------------------------------------------------------------------------------------------------------------------------------

double correlazione(double *O, int dim_O, int t){ //pagina 63 newman barkema
	double tot_corr=0,tot_t1=0,tot_t2=0;
	int n_campioni = (dim_O-t);
	for(int i=0;i<n_campioni;i++){
		tot_corr+=O[i]*O[i+t];
		tot_t1+=O[i];
		tot_t2+=O[i+t];		
	}
	tot_corr = tot_corr / (double)n_campioni;
	tot_t1 = tot_t1 / (double)n_campioni;
	tot_t2 = tot_t2 / (double)n_campioni;		

	return(tot_corr -tot_t1*tot_t2);
}

void stampa_CAvst(double *O, int dim_O, int t_max, string riga){
	string nomeFile= riga;
	ofstream myfile(nomeFile.c_str());
	cout<<"#- Stampo correlaz vs (t): "<<nomeFile<<endl;

	double CA[t_max];
	for(int t=0;t<t_max;t++){	
		CA[t]=correlazione(O,dim_O,t);
	}

	for(int t=0;t<t_max;t++){	myfile<<t<< "\t" << CA[t]/CA[0] <<  endl;} 
	myfile.close();
}

double Tau(double *O, int dim_O, int t_max){
	double T=1;
 	double CA_0=correlazione(O,dim_O,0);
	for(int t=1;t<t_max;t++){	
		T += correlazione(O,dim_O,t)/CA_0;
	}
	return(T);
}



//------------------------------------------------------------------------------------------------------------------------------
//		STIMA degli ERRORi PER SET CORRELATI
//------------------------------------------------------------------------------------------------------------------------------

double binning( double *O, int N, int m){
	int N_new= (N-N%m)/m; // numero dei nuovi sottoinsiemi di valori
	double tot=0, totquad=0;
	double U;
	for(int j=0;j<N_new;j++){//		per ogni sotto insieme
		U=0;
		for(int i=0;i<m;i++){//		calcolo la somma dei valori
			U+= O[j*m+i];
		}		
		U=U/m;				//		quindi la media come nuova stima dell'osservabile
		tot+=U;				//		sommo tutte le medie
		totquad+=U*U;		//		e sommo il loro quadrato
	}
	tot=tot/N_new;			//		da cui ottengo una nuova stima per la media totale
	totquad=totquad/N_new;  //		e per la media quadrata
	return(sqrt((totquad - tot*tot)/N_new));//		utilizzo i valori ottenuti per calcolare la deviazione standard
}

void stampa_binning( double *O, int N, int m_max,string riga){
	string nomeFile= "Output/"+riga;
	ofstream myfile(nomeFile.c_str());
	cout<<"#- Stampo binning vs m (# del campione barrato): "<<nomeFile<<endl;

	double V[m_max];
	for(int m=1;m<m_max;m++){	
		V[m]=binning(O,N,m);
	}
	for(int m=1;m<m_max;m++){	myfile<<m<< "\t" << V[m] <<  endl;} 
	myfile.close();
}

double jackknife( double *O, int N){
	double m=media(O,N);
	double J=0; 
	for(int j=0;j<N;j++){
		double m_j=0;
		for(int i=0;i<N;i++){
			if(i != j)m_j += O[i];
		}		
		m_j	=	(m_j/(N-1)) - m;
		J += (m_j)*(m_j);
	}
	return(sqrt(J*(N-1)/N));
}

