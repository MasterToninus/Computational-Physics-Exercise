double sistema_rigido::P_Osservabile(int Nc){
	cout<<"##--@ MISURA OSSERVABILE P (media temporale in "<<Nc<<" urti)"<<endl;
	double O[Nc];
	double t = Raccolta_DeltaV( Nc, O);
	double P= sommatoria(O, Nc);	
	P = 1 + P*sigma/(3*t*M); //Sarebbe in realtà Z
	//kT e V = 1 per inizializzazione
	return (P);
}
/*
void sistema_rigido::P_Osservabile(int Nc,double *P,int m, double *sigmaP){
	cout<<"##--@ MISURA OSSERVABILE P (media temporale in "<<Nc<<" urti) con errore (binning di "<<m<<" valori)"<<endl;
	double O[Nc];
	double t = Raccolta_DeltaV( Nc, O);
	double termP= sommatoria(O, Nc);	
	*P = 1 + termP*sigma/(3*t*M);
	//Calcolo Errore con Binning
	double sigmatermP= binning( O, Nc,m);
	*sigmaP = sigmatermP*sigma/(3*t*M);
}*/

double Z_binning( double *DeltaV, double *TempiC, int N, int m){
//vettore dei dati, Numero di elementi del vettori, numero di elementi del bin
	int N_new= (N-N%m)/m; // numero dei nuovi sottoinsiemi di valori
	double tot=0, totquad=0;
	double termP; double t;
	for(int j=0;j<N_new;j++){//		per ogni sotto insieme
		termP=0; t = 0;
		for(int i=0;i<m;i++){//		calcolo la somma dei valori
			termP+= DeltaV[j*m+i];
			t+=TempiC[j*m+i];
		}		
		termP=termP/t;				//		quindi la media come nuova stima dell'osservabile
		tot+=termP;				//		sommo tutte le medie
		totquad+=termP*termP;		//		e sommo il loro quadrato
	}
	tot=tot/N_new;			//		da cui ottengo una nuova stima per la media totale
	totquad=totquad/N_new;  //		e per la media quadrata
	return(sqrt((totquad - tot*tot)/N_new));//		utilizzo i valori ottenuti per calcolare la deviazione standard
}

void sistema_rigido::P_Osservabile(int Nc,double *P,int m, double *sigmaP){
	cout<<"##--@ MISURA OSSERVABILE P (media temporale in "<<Nc<<" urti) con errore (binning di "<<m<<" valori)"<<endl;
	double DeltaV[Nc];
	double TempiC[Nc];
	Raccolta_DeltaV( Nc, DeltaV, TempiC);
	double t = sommatoria(TempiC, Nc);
	double termP= sommatoria(DeltaV, Nc);	
	*P = 1 + termP*sigma/(3*t*M);
	//Calcolo Errore con Binning
	double sigmatermP= Z_binning( DeltaV, TempiC, Nc,m);
	*sigmaP = sigmatermP*sigma/(3*M);
}

//______________________________________________________________________________________________________________________________


double sistema_rigido::TempoCollisione_medio(int Nc){
	cout<<"##--@ MISURA TEMPO DI COLLISIONE MEDIO (media su "<<Nc<<" urti)"<<endl;
	double t = evoluzione( Nc); 
	return (t/(Nc/M));
}
//______________________________________________________________________________________________________________________________



double sistema_rigido::Stampa_HBoltzman_Vx(int Ncolonne,int Nconfigurazioni, int Ncollisioni, string nomeFile){ 
/*Restituisce la funzione di boltzman sulle vx raccolte in Nconfigurazioni successive e stampa l'istogramma di nomeFile
Quindi NON é la media di tanti valori della funzione H calcolata su varie configurazioni ma è la funzione H calcolata su una distribuzione media costituita dai valori presi su tante configurazioni*/
// # colonne distribuzione, # configurazioni campionate, # collisioni tra le configurazioni
	int Ndati= Nconfigurazioni*M;
	double Vx[Ndati];
	cout<<"#>>>@ Check di Termalizzazione  "<< Ndati <<" campioni di Vx  ( "<<M<<" ogni "<<Ncollisioni<<" collisioni) \t\t\t t_esec : "<<tempo<<" sec"<<endl;
	Raccolta_Vx(Nconfigurazioni, Ncollisioni, Vx); 
	istogramma(Ncolonne, Vx,Ndati,nomeFile);
	double H_Vx =	Boltzman( Ncolonne, Vx, Ndati );
	double H_exp = - sqrt(M_PI*kT()/2);
	cout<<H_Vx<<" \t " << H_exp<<endl;
	cout<<"#>>>@ (H(vx)_calcolato - H(vx)_exp )/ H(vx)_exp \% ="<< (H_Vx - H_exp)/H_exp*100 <<" \t\t\t t_esec : "<<tempo<<" sec"<<endl;
return(H_Vx);
}
//______________________________________________________________________________________________________________________________





void sistema_rigido::Stampa_dS_conBordoVsStep(int Ncampionature, int Nstep_Dt_Max, double t_step, string nomeFile){ 
/* Produce un grafico degli spostamenti (con bordo) medi dopo (Nstep_Dt*t_step) [t] vs Nstep_Dt */
// Ncampionature = # di coppie stato inizio - fine che si campionano su cui si media per ottenere una stima di dsQuad( t_step*N_Dt)
// t_step = unità di tempo in cui si discretizza l'evoluzione del sistema
// Nstep_Dt_Max =  distanza temporale massima(# di t_step) che si considera per produrre un punto del grafico
// ( N_Delta_campionatura = distanza temporale (# di t_step) tra 2 configurazioni inizio consecutive in questo caso sarà = 1 t_step)

	int Nconfigurazioni = Nstep_Dt_Max + Ncampionature;

	//costruisco matrice delle Posizioni, per ogni riga ho nell'elemento i la posizione della particella i nello step temporale k; quindi Nconfigurazioni simulate = numero di righe, M=Nparticelle= N colonne
    vector< vector<vettore> > MatP(Nconfigurazioni,vector<vettore>(M,0)); 

	cout<<"##--@ Inizio Raccolta di "<< Nconfigurazioni <<" Configurazioni (posizione di ogni particella) \t\t\t t_esec : "<<tempo_esec()<<" sec"<<endl;
	for(int k=0;k<Nconfigurazioni;k++){
		if(k% 50 ==0){
		cout<<"##--@ \t configurazione "<<k+1<<" / "<<Nconfigurazioni<<" \t (t= "<<k*t_step<<" [t]) \t\t\t\t t_esec : "<<tempo_esec()<<" sec" << string(300,'\b');}
		for(int i=0; i<M; i++)MatP[k][i] = P0[i];		//salvo la posizione di ogni particella dopo k passi
		evoluzione(); //evolvo il sistema di uno step
	}
	cout<<endl;

	cout<<"##--@\n##--@ Costruzione Grafico andamento di <dS> (con bordo) in funzione di [t] di evoluzione : "<<nomeFile<<endl;
	for(int Nstep_Dt=1; Nstep_Dt < Nstep_Dt_Max; Nstep_Dt++){	
		int Nrighedati = Ncampionature;
		int Ndati = Nrighedati*M;						 //ogni riga valida porta a M stime
		double dS_quad[Ndati];							 //lista dei valori di spotamento quadratico

		cout<<"##--@ Punto "<<Nstep_Dt<<" / "<<Nstep_Dt_Max<<" : < dS( "<<Nstep_Dt*t_step<<" [t]) > (con bordo) \t\t t_esec : "<<tempo_esec()<<" sec"<< string(300,'\b');

		for(int k=0; k< Nrighedati; k++){			//scorro tutte le righe che hanno almeno altre (Nstep) righe dopo di loro
			for(int i=0; i<	M; i++){				//scorro tutti gli elementi sulla riga (spostamenti della particella)
				dS_quad[k*M+i] = distanza_immagini(MatP[k+Nstep_Dt][i] , MatP[k][i]);
			}
		}	
		double X=	Nstep_Dt*t_step;
		double Y=	media(dS_quad,Ndati);
		double Z=	deviazione_standard(dS_quad,Ndati);
		grafico_add(nomeFile, 3, (double)X, (double)Y,(double)Z);
	}
	cout<<endl;
}
//______________________________________________________________________________________________________________________________


void sistema_rigido::Stampa_dS_quadVsStep(int Ncampionature, int Nstep_Dt_Max, double t_step, string nomeFile){ 
/* Produce un grafico degli spostamenti quadratici medi dopo (Nstep_Dt*t_step) [t] vs Nstep_Dt */
// Ncampionature = # di coppie stato inizio - fine che si campionano su cui si media per ottenere una stima di dsQuad( t_step*N_Dt)
// t_step = unità di tempo in cui si discretizza l'evoluzione del sistema
// Nstep_Dt_Max =  distanza temporale massima(# di t_step) che si considera per produrre un punto del grafico
// ( N_Delta_campionatura = distanza temporale (# di t_step) tra 2 configurazioni inizio consecutive in questo caso sarà = 1 t_step)

	int Nconfigurazioni = Nstep_Dt_Max + Ncampionature;

	//costruisco matrice delle Posizioni diffusi, per ogni riga ho nell'elemento i la posizione della particella i nello step temporale k; quindi Nconfigurazioni simulate = numero di righe, M=Nparticelle= N colonne
    vector< vector<vettore> > MatPdiffusa(Nconfigurazioni,vector<vettore>(M,0)); 
	CollassaDiffusione();

	cout<<"##--@ Inizio Raccolta di "<< Nconfigurazioni <<" Configurazioni (posizione diffuse di ogni particella) \t\t\t t_esec : "<<tempo_esec()<<" sec"<<endl;
	for(int k=0;k<Nconfigurazioni;k++){
		if(k% 50 ==0){
		cout<<"##--@ \t configurazione "<<k+1<<" / "<<Nconfigurazioni<<" \t (t= "<<k*t_step<<" [t]) \t\t\t\t t_esec : "<<tempo_esec()<<" sec" << string(300,'\b');}
		for(int i=0; i<M; i++)MatPdiffusa[k][i] = Pdiffusa[i];		//salvo la posizione di ogni particella dopo k passi
		evoluzione(); //evolvo il sistema di uno step
	}
	cout<<endl;

	cout<<"##--@\n##--@ Costruzione Grafico andamento di <dS^2> (senza bordo) in funzione di [t] di evoluzione : "<<nomeFile<<endl;
	grafico_start(nomeFile,"#t\t\t#<dS^2>\t\t#sigmadS^2");
	for(int Nstep_Dt=1; Nstep_Dt < Nstep_Dt_Max; Nstep_Dt++){	
		int Nrighedati = Ncampionature;
		int Ndati = Nrighedati*M;						 //ogni riga valida porta a M stime
		double dS_quad[Ndati];							 //lista dei valori di spotamento quadratico

		cout<<"##--@ Punto "<<Nstep_Dt<<" / "<<Nstep_Dt_Max<<" : < dS( "<<Nstep_Dt*t_step<<" [t]) > (senza bordo) \t\t t_esec : "<<tempo_esec()<<" sec"<< string(300,'\b');

		for(int k=0; k< Nrighedati; k++){			//scorro tutte le righe che hanno almeno altre (Nstep) righe dopo di loro
			for(int i=0; i<	M; i++){				//scorro tutti gli elementi sulla riga (spostamenti della particella)
				dS_quad[k*M+i] = Mod(MatPdiffusa[k+Nstep_Dt][i] - MatPdiffusa[k][i]);
			}
		}	
		double X=	Nstep_Dt*t_step;
		double Y=	media(dS_quad,Ndati);
		double Z=	deviazione_standard(dS_quad,Ndati);
		grafico_add(nomeFile, 3, (double)X, (double)Y,(double)Z);
	}
	cout<<endl;
}

