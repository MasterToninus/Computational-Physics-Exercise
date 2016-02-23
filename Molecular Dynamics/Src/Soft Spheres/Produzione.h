double sistema_soffice::kT_Osservabile(int Nconfigurazioni, double Dt){
//# di configurazioni campionate, intervallo temporale tra due campioni
	int Ndati = Nconfigurazioni ;
	double O[Ndati];
	Raccolta_T( Nconfigurazioni, Dt,  O);
	double Tmedia = media(O,Ndati);
return(Tmedia*2/(d*M));
}
//______________________________________________________________________________________________________________________________
double sistema_soffice::P_Osservabile(int Nconfigurazioni, double Dt){
//# di configurazioni campionate, intervallo temporale tra due campioni
	int Ndati = Nconfigurazioni ;
	double O[Ndati];
	Raccolta_P( Nconfigurazioni, Dt,  O);
	double Tmedia = media(O,Ndati);
return(Tmedia*2/(d*M));
}
//______________________________________________________________________________________________________________________________


double sistema_soffice::Stampa_HBoltzman_Vx(int Ncolonne,int Nconfigurazioni, double Dt, string nomeFile){ 
/*Restituisce la funzione di boltzman sulle vx raccolte in Nconfigurazioni successive e stampa l'istogramma di nomeFile
Quindi NON é la media di tanti valori della funzione H calcolata su varie configurazioni ma è la funzione H calcolata su una distribuzione media costituita dai valori presi su tante configurazioni*/
// # colonne distribuzione, # configurazioni campionate, intervallo di tempo tra le configurazioni campionate
	int Ndati= Nconfigurazioni*M;
	double Vx[Ndati];
	cout<<"#>>>@ Check di Termalizzazione  "<< Ndati <<" campioni di Vx  ( "<<M<<" ogni "<<Dt<<" [t]) \t\t\t t_esec : "<<tempo<<" sec"<<endl;
	Raccolta_Vx(Nconfigurazioni,Dt, Vx);
	istogramma(Ncolonne, Vx,Ndati,nomeFile);
	double H_Vx =	Boltzman( Ncolonne, Vx, Ndati );

	double kT = kT_Osservabile( Nconfigurazioni,  Dt);
	double H_exp = - sqrt(M_PI*kT/2);
	cout<<H_Vx<<" \t " << H_exp<<endl;
	cout<<"#>>>@ (H(vx)_calcolato - H(vx)_exp )/ H(vx)_exp \% ="<< (H_Vx - H_exp)/H_exp*100 <<" \t\t\t t_esec : "<<tempo<<" sec"<<endl;
return(H_Vx);
}
//______________________________________________________________________________________________________________________________


void sistema_soffice::Stampa_dS_conBordoVsStep(int Ncampionature, int Nstep_Dt_Max,double step_Dt, string nomeFile){ 
/* Produce un grafico degli spostamenti (con bordo) medi dopo (Nstep_Dt*step_Dt) [t] vs Nstep_Dt */
// Ncampionature = # di coppie stato inizio - fine che si campionano su cui si media per ottenere una stima di dsQuad( Dt*N_Dt)
// step_Dt = intervallo di tempo in cui si discretizza l'evoluzione del sistema (maggire di t_step!)
// Nstep_Dt_Max =  distanza temporale massima(# di step_Dt) che si considera per produrre un punto del grafico
// ( N_Delta_campionatura = distanza temporale (# di step_Dt) tra 2 configurazioni inizio consecutive in questo caso sarà = 1 step_Dt)

	int Nconfigurazioni = Nstep_Dt_Max + Ncampionature;

	//costruisco matrice delle Posizioni, per ogni riga ho nell'elemento i la posizione della particella i nello step temporale k; quindi Nconfigurazioni simulate = numero di righe, M=Nparticelle= N colonne
    vector< vector<vettore> > MatP(Nconfigurazioni,vector<vettore>(M,0)); 

	cout<<"##--@ Inizio Raccolta di "<< Nconfigurazioni <<" Configurazioni (posizione di ogni particella) ogni "<<step_Dt<<" [t] \t\t t_esec : "<<tempo_esec()<<" sec"<<endl;
	for(int k=0;k<Nconfigurazioni;k++){
		if(k% 50 ==0){
		cout<<"##--@ \t configurazione "<<k+1<<" / "<<Nconfigurazioni<<" \t (t= "<<k*step_Dt<<" [t]) \t\t\t\t t_esec : "<<tempo_esec()<<" sec" << string(300,'\b');}
		for(int i=0; i<M; i++)MatP[k][i] = P0[i];		//salvo la posizione di ogni particella dopo k passi
		evoluzione_muto(step_Dt); //evolvo il sistema di uno step
	}
	cout<<endl;

	cout<<"##--@\n##--@ Costruzione Grafico andamento di <dS> (con bordo) in funzione di [t] di evoluzione : "<<nomeFile<<endl;
	for(int Nstep_Dt=1; Nstep_Dt < Nstep_Dt_Max; Nstep_Dt++){	
		int Nrighedati = Ncampionature;
		int Ndati = Nrighedati*M;						 //ogni riga valida porta a M stime
		double dS_quad[Ndati];							 //lista dei valori di spotamento quadratico

		cout<<"##--@ Punto "<<Nstep_Dt<<" / "<<Nstep_Dt_Max<<" : < dS( "<<Nstep_Dt*step_Dt<<" [t]) > (con bordo) \t\t t_esec : "<<tempo_esec()<<" sec"<< string(300,'\b');

		for(int k=0; k< Nrighedati; k++){			//scorro tutte le righe che hanno almeno altre (Nstep) righe dopo di loro
			for(int i=0; i<	M; i++){				//scorro tutti gli elementi sulla riga (spostamenti della particella)
				dS_quad[k*M+i] = distanza_immagini(MatP[k+Nstep_Dt][i] , MatP[k][i]);
			}
		}	
		double X=	Nstep_Dt*step_Dt;
		double Y=	media(dS_quad,Ndati);
		double Z=	deviazione_standard(dS_quad,Ndati);
		grafico_add(nomeFile, 3, (double)X, (double)Y,(double)Z);
	}
	cout<<endl;
}
//______________________________________________________________________________________________________________________________


void sistema_soffice::Stampa_dS_quadVsStep(int Ncampionature, int Nstep_Dt_Max, double step_Dt, string nomeFile){ 
/* Produce un grafico degli spostamenti quadratici medi dopo (Nstep_Dt*Dt) [t] vs Nstep_Dt */
// Ncampionature = # di coppie stato inizio - fine che si campionano su cui si media per ottenere una stima di dsQuad( Dt*N_Dt)
// step_Dt = intervallo di tempo in cui si discretizza l'evoluzione del sistema (maggire di t_step!)
// Nstep_Dt_Max =  distanza temporale massima(# di step_Dt) che si considera per produrre un punto del grafico
// ( N_Delta_campionatura = distanza temporale (# di Dt) tra 2 configurazioni inizio consecutive in questo caso sarà = 1 step_Dt)

	int Nconfigurazioni = Nstep_Dt_Max + Ncampionature;
		grafico_start(nomeFile);

	//costruisco matrice delle Posizioni diffusi, per ogni riga ho nell'elemento i la posizione della particella i nello step temporale k; quindi Nconfigurazioni simulate = numero di righe, M=Nparticelle= N colonne
    vector< vector<vettore> > MatPdiffusa(Nconfigurazioni,vector<vettore>(M,0)); 
	CollassaDiffusione();

	cout<<"##--@ Inizio Raccolta di "<< Nconfigurazioni <<" Configurazioni (posizione di ogni particella) ogni "<<step_Dt<<" [t] \t\t t_esec : "<<tempo_esec()<<" sec"<<endl;
	for(int k=0;k<Nconfigurazioni;k++){
		if(k% 50 ==0){
		cout<<"##--@ \t configurazione "<<k+1<<" / "<<Nconfigurazioni<<" \t (t= "<<k*step_Dt<<" [t]) \t\t\t\t t_esec : "<<tempo_esec()<<" sec" << string(300,'\b');}
		for(int i=0; i<M; i++)MatPdiffusa[k][i] = Pdiffusa[i];		//salvo la posizione di ogni particella dopo k passi
		evoluzione_muto(step_Dt); //evolvo il sistema di uno step
	}
	cout<<endl;

	cout<<"##--@\n##--@ Costruzione Grafico andamento di <dS^2> (senza bordo) in funzione di [t] di evoluzione : "<<nomeFile<<endl;
	for(int Nstep_Dt=1; Nstep_Dt < Nstep_Dt_Max; Nstep_Dt++){	
		int Nrighedati = Ncampionature;
		int Ndati = Nrighedati*M;						 //ogni riga valida porta a M stime
		double dS_quad[Ndati];							 //lista dei valori di spotamento quadratico

		cout<<"##--@ Punto "<<Nstep_Dt<<" / "<<Nstep_Dt_Max<<" : < dS( "<<Nstep_Dt*step_Dt<<" [t]) > (con bordo) \t\t t_esec : "<<tempo_esec()<<" sec"<< string(300,'\b');

		for(int k=0; k< Nrighedati; k++){			//scorro tutte le righe che hanno almeno altre (Nstep) righe dopo di loro
			for(int i=0; i<	M; i++){				//scorro tutti gli elementi sulla riga (spostamenti della particella)
				dS_quad[k*M+i] = Mod(MatPdiffusa[k+Nstep_Dt][i] - MatPdiffusa[k][i]);
			}
		}	
		double X=	Nstep_Dt*step_Dt;
		double Y=	media(dS_quad,Ndati);
		double Z=	deviazione_standard(dS_quad,Ndati);
		grafico_add(nomeFile, 3, (double)X, (double)Y,(double)Z);
	}
	cout<<endl;
}


