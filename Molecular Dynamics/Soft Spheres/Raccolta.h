/*
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
//RACCOLTA DI OSSERVABILI DI STATO, 1 dato per ogni singola particella----> Nconfigurazioni * Nparticelle = Ndatitotali
//(i valori d'aspettazioni saranno medie temporali, quindi medie su questi valori)

>>>>>>>>>>>>>>>] VERSIONI A intervallo di tempo fissato [<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	Si campionano configurazioni ogni  Dt [t]

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
*/

void sistema_soffice::Raccolta_P(int Nconfigurazioni,double Dt, double *O){ //raccolta termine di pressione P*
//Nconfigurazioni, intervalli di un passo, vettore di osservabili da riempire
	int Ndati = Nconfigurazioni;
	cout<<"##--@ Inizio Raccolta di "<< Ndati <<" campioni di P (uno per ogni "<<Dt<<" [t] ) \t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	for(int k=0;k<Nconfigurazioni;k++){
		if(k% 50 ==0){
			cout<<"##--@ \t configurazione "<<k+1<<" / "<<Nconfigurazioni<<" \t (t= "<<k*Dt<<" [t]) \t\t\t\t t_esec : "<<tempo_esec()<<" sec" << string(300,'\b');}
		O[ k ] = termP_stato();
		evoluzione_muto(Dt);			//evolvo il sistema per 100*Dt [t]			
	}
	cout<<"##--@ \t configurazione "<<Nconfigurazioni<<" / "<<Nconfigurazioni<<" \t (t= "<<Nconfigurazioni*Dt<<" [t]) \t\t\t\t t_esec : "<<tempo_esec()<<" sec" <<endl<<"#"<<endl;
}

void sistema_soffice::Raccolta_T(int Nconfigurazioni,double Dt, double *O){ //raccolta termine di pressione T*
//Nconfigurazioni, intervalli di un passo, vettore di osservabili da riempire
	int Ndati = Nconfigurazioni;
	cout<<"##--@ Inizio Raccolta di "<< Ndati <<" campioni di T (uno per ogni "<<Dt<<" [t] ) \t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	for(int k=0;k<Nconfigurazioni;k++){
		if(k% 50 ==0){
			cout<<"##--@ \t configurazione "<<k+1<<" / "<<Nconfigurazioni<<" \t (t= "<<k*Dt<<" [t]) \t\t\t\t t_esec : "<<tempo_esec()<<" sec" << string(300,'\b');}
		O[ k ] = kT_stato();		
		evoluzione_muto(Dt);			//evolvo il sistema per 100*Dt [t]	
	}
	cout<<"##--@ \t configurazione "<<Nconfigurazioni<<" / "<<Nconfigurazioni<<" \t (t= "<<Nconfigurazioni*Dt<<" [t]) \t\t\t\t t_esec : "<<tempo_esec()<<" sec" <<endl<<"#"<<endl;
}

void sistema_soffice::Raccolta_U(int Nconfigurazioni,double Dt, double *O){ //raccolta termine di pressione T*
//Nconfigurazioni, intervalli di un passo, vettore di osservabili da riempire
	int Ndati = Nconfigurazioni;
	cout<<"##--@ Inizio Raccolta di "<< Ndati <<" campioni di U*/N (uno per ogni "<<Dt<<" [t] ) \t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	for(int k=0;k<Nconfigurazioni;k++){
		if(k% 50 ==0){
			cout<<"##--@ \t configurazione "<<k+1<<" / "<<Nconfigurazioni<<" \t (t= "<<k*Dt<<" [t]) \t\t\t\t t_esec : "<<tempo_esec()<<" sec" << string(300,'\b');}
		O[ k ] = Utot()/M;			
		evoluzione_muto(Dt);			//evolvo il sistema
	}
	cout<<"##--@ \t configurazione "<<Nconfigurazioni<<" / "<<Nconfigurazioni<<" \t (t= "<<Nconfigurazioni*Dt<<" [t]) \t\t\t\t t_esec : "<<tempo_esec()<<" sec" <<endl<<"#"<<endl;
}

void sistema_soffice::Raccolta_Stato_Completo(int Nconfigurazioni,double Dt, double *P, double *T, double *U){ //raccolta termine di pressione T*
//Nconfigurazioni, intervalli di un passo, vettore di osservabili da riempire
	int Ndati = Nconfigurazioni;
	cout<<"##--@ Inizio Raccolta di "<< Ndati <<" campioni di P*,T*,U* (uno per ogni "<<Dt<<" [t] ) \t t_esec : "<<tempo_esec()<<" sec"<<endl;

	for(int k=0;k<Nconfigurazioni;k++){
		if(k% 50 ==0){
			cout<<"##--@ \t configurazione "<<k+1<<" / "<<Nconfigurazioni<<" \t (t= "<<k*Dt<<" [t]) \t\t\t\t t_esec : "<<tempo_esec()<<" sec" << string(300,'\b');}
		U[ k ] = Utot()/M;	
		T[ k ] = kT_stato();
		P[ k ] = termP_stato();			
		evoluzione_muto(Dt);			//evolvo il sistema per 100*Dt [t]
	}
	cout<<"##--@ \t configurazione "<<Nconfigurazioni<<" / "<<Nconfigurazioni<<" \t (t= "<<Nconfigurazioni*Dt<<" [t]) \t\t\t\t t_esec : "<<tempo_esec()<<" sec" <<endl<<"#"<<endl;
}



/*
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
//RACCOLTA DI OSSERVABILI PARTICELLA, 1 dato per ogni singola particella----> Nconfigurazioni * Nparticelle = Ndatitotali

>>>>>>>>>>>>>>>] VERSIONI A intervallo di tempo fissato [<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	Si campionano configurazioni ogni  Dt_campionature [t]

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
*/

void sistema_soffice::Raccolta_Vx(int Nconfigurazioni, double Dt_campionature, double *O){
/* Raccolta delle componenti x delle velocità delle particelle in Nconfigurazioni distanti Dt [t] tra loro */
//Nconfigurazioni = # di configurazioni che si vogliono campionare
//Dt_campionature = intervallo di tempo totale che intercorre tra due campionature successive di una configurazione
//O				  =	Array dei valori di vx che vengono campionati
	int Ndati = Nconfigurazioni*M;
	cout<<"##--@ Inizio Raccolta di "<< Ndati <<" campioni di Vx ("<<M<<" ogni "<<Dt_campionature<<"[t]) \t\t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	for(int k=0;k<Nconfigurazioni;k++){
		if(k% 50 ==0){
			cout<<"##--@ \t configurazione "<<k+1<<" / "<<Nconfigurazioni<<" \t (t= "<<k*Dt_campionature<<" [t]) \t\t\t\t t_esec : "<<tempo_esec()<<" sec" << string(300,'\b');}
		evoluzione_muto(Dt_campionature);			//evolvo il sistema per Dt [t]
		for(int i=0; i< M; i++){
			O[i +M*k] = v0[i].x();
		}			
	}
	cout<<"##--@ \t configurazione "<<Nconfigurazioni<<" / "<<Nconfigurazioni<<" \t (t= "<<Nconfigurazioni*Dt_campionature<<" [t]) \t\t\t\t t_esec : "<<tempo_esec()<<" sec" <<endl<<"#"<<endl;
}
//___________________________________________________________________________________________________________________-_-_-_-


void sistema_soffice::Raccolta_Vquad(int Nconfigurazioni,double Dt_campionature, double *O){ //raccolta modulo quadro della velocità
/* Raccolta del |V|^2 delle velocità delle particelle in Nconfigurazioni distanti Dt [t] tra loro */
//Nconfigurazioni = # di configurazioni che si vogliono campionare
//Dt_campionature = intervallo di tempo totale che intercorre tra due campionature successive di una configurazione
//O				  =	Array dei valori di vx che vengono campionati	int Ndati = Nconfigurazioni*M;
	int Ndati = M*Nconfigurazioni;
	cout<<"##--@ Inizio Raccolta di "<< Ndati <<" campioni di |V|^2 ("<<M<<" ogni "<<Dt_campionature<<"[t]) \t\t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	for(int k=0;k<Nconfigurazioni;k++){
		if(k% 50 ==0){
			cout<<"##--@ \t configurazione "<<k+1<<" / "<<Nconfigurazioni<<" \t (t= "<<k*Dt_campionature<<" [t]) \t\t\t\t t_esec : "<<tempo_esec()<<" sec" << string(300,'\b');}
		evoluzione_muto(Dt_campionature);			//evolvo il sistema per 100*Dt [t]
		for(int i=0; i< M; i++)	O[i +M*k] = Mod(v0[i]);			
	}
	cout<<"##--@ \t configurazione "<<Nconfigurazioni<<" / "<<Nconfigurazioni<<" \t (t= "<<Nconfigurazioni*Dt_campionature<<" [t]) \t\t\t\t t_esec : "<<tempo_esec()<<" sec" <<endl<<"#"<<endl;
}
//___________________________________________________________________________________________________________________-_-_-_-


void sistema_soffice::Raccolta_FxR(int Nconfigurazioni,double Dt_campionature, double *O){ //raccolta momento angolare F x R
/* Raccolta di FxR delle particelle in Nconfigurazioni distanti Dt [t] tra loro */
//Nconfigurazioni = # di configurazioni che si vogliono campionare
//Dt_campionature = intervallo di tempo totale che intercorre tra due campionature successive di una configurazione
//O				  =	Array dei valori di vx che vengono campionati	int Ndati = Nconfigurazioni*M;
	int Ndati = Nconfigurazioni*M;
	cout<<"##--@ Inizio Raccolta di "<< Ndati <<" campioni di F x R ("<<M<<" ogni "<<Dt_campionature<<"[t]) \t\t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	for(int k=0;k<Nconfigurazioni;k++){
		if(k% 50 ==0){
			cout<<"##--@ \t configurazione "<<k+1<<" / "<<Nconfigurazioni<<" \t (t= "<<k*Dt_campionature<<" [t]) \t\t\t\t t_esec : "<<tempo_esec()<<" sec" << string(300,'\b');}
		evoluzione_muto(Dt_campionature);			//evolvo il sistema per 100*Dt [t]
		for(int i=0; i< M; i++)	O[i +M*k] = (P0[i])*(a0[i]);			
	}
	cout<<"##--@ \t configurazione "<<Nconfigurazioni<<" / "<<Nconfigurazioni<<" \t (t= "<<Nconfigurazioni*Dt_campionature<<" [t]) \t\t\t\t t_esec : "<<tempo_esec()<<" sec" <<endl<<"#"<<endl;
}
//___________________________________________________________________________________________________________________-_-_-_-


void sistema_soffice::Raccolta_Nvicini(int Nconfigurazioni,double Dt_campionature, double *O){ //raccolta # particelle vicine
/* Raccolta del numero di particelle vicine vicine  in Nconfigurazioni distanti Dt [t] tra loro */
//Nconfigurazioni = # di configurazioni che si vogliono campionare
//Dt_campionature = intervallo di tempo totale che intercorre tra due campionature successive di una configurazione
//O				  =	Array dei valori di Nvicini che vengono campionati	int Ndati = Nconfigurazioni*M;
	int Ndati = Nconfigurazioni*M;
	cout<<"##--@ Inizio Raccolta di "<< Ndati <<" campioni del Numero di Particelle vicine ("<<M<<" ogni "<<Dt_campionature<<"[t]) \t\t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	int Nvicini[M];for(int i=0; i< M; i++)Nvicini[i]=0;

	for(int k=0;k<Nconfigurazioni;k++){
		if(k% 50 ==0){cout<<"##--@ \t configurazione "<<k+1<<" / "<<Nconfigurazioni<<" \t (t= "<<k*Dt_campionature<<" [t]) \t\t\t\t t_esec : "<<tempo_esec()<<" sec" << string(300,'\b');}
		
		for(int i=0;i<M-1;i++)for(int j=NPOINT[i];j<NPOINT[i+1];j++){ //Conteggio dei vicini
			Nvicini[i]++;
			Nvicini[LIST[j]]++;
		}
		for(int i=0; i< M; i++)	O[i +M*k] = (double)Nvicini[i];			
		evoluzione_muto(Dt_campionature);			//evolvo il sistema per 100*Dt [t]
	}
	cout<<"##--@ \t configurazione "<<Nconfigurazioni<<" / "<<Nconfigurazioni<<" \t (t= "<<Nconfigurazioni*Dt_campionature<<" [t]) \t\t\t\t t_esec : "<<tempo_esec()<<" sec" <<endl<<"#"<<endl;
}
//___________________________________________________________________________________________________________________-_-_-_-







/*
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
//RACCOLTA DI OSSERVABILI PARTICELLA INIZIO-FINE, 1 dato per ogni singola particella ogni coppia di configurazioni----> Nconfigurazioni * Nparticelle = Ndatitotali

>>>>>>>>>>>>>>>] VERSIONI A Numero di step Dt Fissato [<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	Si campionano configurazioni ogni (Nstep_campionature) passi (evoluzioni di  step_Dt (maggiore di un singolo t_step))
	(per le osservabili relative alla differenze tra due configurazioni ad un certo intervallo di tempo di distanza bisogna indicare anche (Nstep_Dt) = il numero di passi che avvengono tra le due configurazioni della coppia)

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
*/

void sistema_soffice::Raccolta_dS_conBordo(int Ncampionature, int Nstep_campionature, int Nstep_Dt, double step_Dt, double *O){ 
/* Raccolta  di spostamentamenti (con bordo) tra coppie di configurazioni che distano (Nstep_Dt) * (Dt) [t] di evoluzione */
// Ncampionature = # di coppie di configurazioni inizio - fine campionate
// step_Dt = unità di tempo in cui si discretizza l'evoluzione del sistema (più grande del t_step di base dell'algoritmo)
// Nstep_Dt =  distanza temporale (# di Dt) tra la configurazioni inizio e quella fine della stessa coppia
// Nstep_campionature = distanza temporale (# di Dt) tra 2 configurazioni inizio consecutive

	cout<<"##--@ Inizio Raccolta di "<< Ncampionature *M <<" campioni di dS( "<<Nstep_Dt*step_Dt<<" [t] ) (con bordo) \t\t t_esec : "<<tempo_esec()<<" sec"<<endl;
	cout<<"##--@ ("<< Ncampionature <<" coppie di configurazioni (distanti "<<Nstep_Dt*step_Dt<<" step_Dt tra di loro) raccolte ogni "<< Nstep_campionature<<" step_Dt )";
	cout<<"##--@ ("<<M<<" campioni ogni coppia di configurazione, step_Dt = "<<step_Dt<<" [t])"<<endl;

	vector< vector<vettore> > P0_iniziali( Ncampionature , vector<vettore>(M,0) );	//vector che contiene le configurazioni (posizione di ogni particella) di inizio di ogni coppia di configurazioni

	int Nevoluzioni= (Ncampionature-1)*Nstep_campionature + Nstep_Dt; // devo evolvere il sistema un numero di volte sufficienti in modo che l'ultima configurazione iniziale abbia la sua configurazione finale dopo un giusto intervallo temporale

	int ContIni=0;	//contatori di quante campionature sono iniziate e finite
	int ContFin=0;

	for(int n=0; n<=Nevoluzioni;n++){		//n= al numero di evoluzioni compiute
		printf("##--@ step : %5d / %5d \t                        \t\t t_esec : %.2f sec ",n,Nevoluzioni,tempo_esec());
		cout<< string(300,'\b');

		if(n%Nstep_campionature==0 && ContIni< Ncampionature){			//ho un nuovo inizio ogni Nstep_campionature
			for(int j=0; j<	M; j++)	P0_iniziali[ContIni][j]  = P0[j] ;	//salvo la configurazione di inizio della coppia ContIni
			printf("##--@ step : %5d / %5d \t Inizio serie :   %d    \t\t t_esec : %.2f sec ",n,Nevoluzioni,ContIni,tempo_esec());
			cout<< string(300,'\b');
			ContIni++;													//la prossima volta comincierà la campionatura ContIni+1
		}

		if( n >= Nstep_Dt && (n - Nstep_Dt)%Nstep_campionature==0){	//ho un nuovo Fine ogni Nstep_campionature dopo la Nstep_Dt -sima
			for(int j=0; j<	M; j++)	O[M*ContFin + j]= distanza_immagini(P0[j], P0_iniziali[ContFin][j]); //Salvo i valori di spostamento
			printf("##--@ step : %5d  / %5d \t Fine serie :   %d    \t\t t_esec : %.2f sec ",n,Nevoluzioni,ContFin,tempo_esec());
			cout<< string(300,'\b');
			ContFin++;											// la prossima volta terminera la campionatura ContFin+1
		}	
		evoluzione_muto(step_Dt); //evolvo il sistema di uno step
	}
	cout<<"\n#"<< endl;
}
//___________________________________________________________________________________________________________________-_-_-_-

void sistema_soffice::Raccolta_dS_quad(int Ncampionature, int Nstep_campionature, int Nstep_Dt, double step_Dt, double *O){ 
/* Raccolta  della diffusione ( spostamentamenti quadratico senza bordo) tra coppie di configurazioni che distano (Nstep_Dt) * (Dt) [t] di evoluzione */
// Ncampionature = # di coppie di configurazioni inizio - fine campionate
// step_Dt = unità di tempo in cui si discretizza l'evoluzione del sistema (più grande del t_step di base dell'algoritmo)
// Nstep_Dt =  distanza temporale (# di step_Dt) tra la configurazioni inizio e quella fine della stessa coppia
// Nstep_campionature = distanza temporale (# di step_Dt) tra 2 configurazioni inizio consecutive

	cout<<"##--@ Inizio Raccolta di "<< Ncampionature *M <<" dS^2( "<<Nstep_Dt*step_Dt<<" [t] ) (spostamento assoluto senza bordo) \t t_esec : "<<tempo_esec()<<" sec"<<endl;
	cout<<"##--@ ("<< Ncampionature <<" coppie di configurazioni (distanti "<<Nstep_Dt<<" step_Dt tra di loro) raccolte ogni "<< Nstep_campionature<<" step_Dt )";
	cout<<"##--@ ("<<M<<" campioni ogni coppia di configurazioni, step_Dt = "<<step_Dt<<" [t])"<<endl;

	CollassaDiffusione();
	vector< vector<vettore> > Pdiffusa_iniziali( Ncampionature , vector<vettore>(M,0) );	//vector che contiene le configurazioni (posizione di ogni particella diffusa) di inizio di ogni coppia di configurazioni

	int Nevoluzioni= (Ncampionature-1)*Nstep_campionature + Nstep_Dt; // devo evolvere il sistema un numero di volte sufficienti in modo che l'ultima configurazione iniziale abbia la sua configurazione finale dopo un giusto intervallo temporale
	
	int ContIni=0;	//contatori di quante campionature sono iniziate e finite
	int ContFin=0;

	for(int n=0; n<=Nevoluzioni;n++){		//n= al numero di evoluzioni compiute
		printf("##--@ step : %5d / %5d \t                        \t\t t_esec : %.2f sec ",n,Nevoluzioni,tempo_esec());
		cout<< string(300,'\b');

		if(n%Nstep_campionature==0 && ContIni< Ncampionature){			//ho un nuovo inizio ogni Nstep_campionature
			for(int j=0; j<	M; j++)	Pdiffusa_iniziali[ContIni][j]  = Pdiffusa[j] ;	//salvo la configurazione di inizio della coppia ContIni
			printf("##--@ step : %5d / %5d \t Inizio serie :   %d    \t\t t_esec : %.2f sec ",n,Nevoluzioni,ContIni,tempo_esec());
			cout<< string(300,'\b');
			ContIni++;													//la prossima volta comincierà la campionatura ContIni+1
		}

		if( n >= Nstep_Dt && (n - Nstep_Dt)%Nstep_campionature==0){	//ho un nuovo Fine ogni Nstep_campionature dopo la Nstep_Dt -sima
			for(int j=0; j<	M; j++)	O[M*ContFin + j]= Mod(Pdiffusa[j] - Pdiffusa_iniziali[ContFin][j]); //Salvo i valori di spostamento quadratico (modulo quadro della differenza tra le due posizioni diffuse
			printf("##--@ step : %5d  / %5d \t Fine serie :   %d    \t\t t_esec : %.2f sec ",n,Nevoluzioni,ContFin,tempo_esec());
			cout<< string(300,'\b');
			ContFin++;												// la prossima volta terminera la campionatura ContFin+1
		}
		if((n+1)%10==0)	CostruzioneListaVicini();	
		evoluzione(step_Dt); //evolvo il sistema di uno step
	}
	cout<<"\n#"<< endl;
}









//___________________________________________________________________________________________________________________-_-_-_-
//___________________________________________________________________________________________________________________-_-_-_-
//___________________________________________________________________________________________________________________-_-_-_-
//___________________________________________________________________________________________________________________-_-_-_-

void sistema_soffice::Raccolta_Ordine(int Ncampionature, int Nstep_campionature, int Nstep_Dt, double step_Dt, double *dS_quad,double *Nvici, double *Z){ 
/* Raccolta  dei parametri d'ordine. il metodo è incasinato perchè raccoglie 3 osservabili molto diverse, una associata a coppie di stati, una alle particelle e una allo stato */
// Ncampionature = # di coppie di configurazioni inizio - fine campionate
// step_Dt = unità di tempo in cui si discretizza l'evoluzione del sistema (più grande del t_step di base dell'algoritmo)
// Nstep_Dt =  distanza temporale (# di step_Dt) tra la configurazioni inizio e quella fine della stessa coppia
// Nstep_campionature = distanza temporale (# di step_Dt) tra 2 configurazioni inizio consecutive

	cout<<"##--@ Inizio Raccolta di "<< Ncampionature *M <<" dS^2( "<<Nstep_Dt*step_Dt<<" [t] ) (spostamento assoluto senza bordo) \t t_esec : "<<tempo_esec()<<" sec"<<endl;
	cout<<"##--@ ("<< Ncampionature <<" coppie di configurazioni (distanti "<<Nstep_Dt<<" step_Dt tra di loro) raccolte ogni "<< Nstep_campionature<<" step_Dt )"<<endl;
	cout<<"##--@ ("<<M<<" campioni ogni coppia di configurazioni, step_Dt = "<<step_Dt<<" [t])"<<endl;

	CollassaDiffusione();
	vector< vector<vettore> > Pdiffusa_iniziali( Ncampionature , vector<vettore>(M,0) );	//vector che contiene le configurazioni (posizione di ogni particella diffusa) di inizio di ogni coppia di configurazioni

	int Nevoluzioni= (Ncampionature-1)*Nstep_campionature + Nstep_Dt; // devo evolvere il sistema un numero di volte sufficienti in modo che l'ultima configurazione iniziale abbia la sua configurazione finale dopo un giusto intervallo temporale
	
	int ContIni=0;	//contatori di quante campionature sono iniziate e finite
	int ContFin=0;

	for(int n=0; n<=Nevoluzioni;n++){		//n= al numero di evoluzioni compiute
		printf("##--@ step : %5d / %5d \t                        \t\t t_esec : %.2f sec ",n,Nevoluzioni,tempo_esec());
		cout<< string(300,'\b');

		if(n%Nstep_campionature==0 && ContIni< Ncampionature){			//ho un nuovo inizio ogni Nstep_campionature
			for(int j=0; j<	M; j++)	Pdiffusa_iniziali[ContIni][j]  = Pdiffusa[j] ;	//salvo la configurazione di inizio della coppia ContIni
			printf("##--@ step : %5d / %5d \t Inizio serie :   %d    \t\t t_esec : %.2f sec ",n,Nevoluzioni,ContIni,tempo_esec());
			cout<< string(300,'\b');
			ContIni++;													//la prossima volta comincierà la campionatura ContIni+1
		}

		if( n >= Nstep_Dt && (n - Nstep_Dt)%Nstep_campionature==0){	//ho un nuovo Fine ogni Nstep_campionature dopo la Nstep_Dt -sima
			printf("##--@ step : %5d  / %5d \t Fine serie :   %d    \t\t t_esec : %.2f sec ",n,Nevoluzioni,ContFin,tempo_esec());
			cout<< string(300,'\b');
	//PARAMETRO D'ORDINE 1 
			for(int j=0; j<	M; j++)	dS_quad[M*ContFin + j]= Mod(Pdiffusa[j] - Pdiffusa_iniziali[ContFin][j]); //Salvo i valori di spostamento quadratico (modulo quadro della differenza tra le due posizioni diffuse
	//PARAMETRO D'ORDINE 2 
			int Nvicini[M];for(int i=0; i< M; i++)Nvicini[i]=0;
			//stampa_vicini();
				for(int i=0;i<M-1;i++)for(int j=NPOINT[i];j<NPOINT[i+1];j++){ //Conteggio dei vicini
				Nvicini[i]++;
				Nvicini[LIST[j]]++;
			}
		for(int j=0; j< M; j++)	Nvici[j +M*ContFin] = (double)Nvicini[j];		  //salvo i vicini	
	//PARAMETRO D'ORDINE 3 
			Z[ ContFin ] = termP_stato();										//salvo Z
			ContFin++;												// la prossima volta terminera la campionatura ContFin+1
		}
		if((n+1)%10==0)	CostruzioneListaVicini();	
		evoluzione_muto(step_Dt); //evolvo il sistema di uno step
	}
	cout<<"\n#"<< endl;
}
