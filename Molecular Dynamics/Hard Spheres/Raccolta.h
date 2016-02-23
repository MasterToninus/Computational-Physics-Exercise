/*
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/

	RACCOLTA DI OSSERVABILI di COLLISIONE, 1 dato per ogni collisione----> Nc = Ndatitotali

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
*/

double sistema_rigido::Raccolta_DeltaV(int Nc, double *O){
	cout<<"##--@ Inizio Raccolta di "<< Nc <<" campioni di modulo Delta V ( 1 per collisione) \t\t t_esec : "<<tempo_esec()<<" sec"<<endl;
	//EVOLUZIONE
	int i_urto, j_urto; //labelli delle 2 particelle urtanti
	double t_urto;	double t=0.; 
	for(int k=0; k<Nc; k++){
		if(k% 50 ==0){
		printf("##--@ \t %d° Collisione  \t\t\t (t =  %1.3f [t]) \t\t\t t_esec : %1.3f sec",k,t,tempo_esec());	
		cout<< string(300,'\b');}
	//1) scorro tutti gli elementi della tavola e trovo gli elementi che collidono per primi
		t_urto= CalcoloTempoCollisione(&i_urto,&j_urto);
		t+=t_urto;
	//2) evolvo le posizioni e applico condizione di bordo	
		EvoluzionePosizioniParticelle( t_urto);
	//2.5) evolvo la velocità delle particelle che hanno urtato
		O[k] = EvoluzioneVelocitaParticelle(i_urto,j_urto);
	//3) Aggiorno tavola di collisione
		AggiornamentoTavolaCollisione(t_urto,i_urto,j_urto);
	}
	printf("##--@ \t Fine Raccolta  %d urti \t\t (t =  %1.3f [t]) \t\t\t t_esec : %1.3f sec\n#\n",Nc,t,tempo_esec());

	return(t);
}
void sistema_rigido::Raccolta_DeltaV(int Nc, double *DeltaV, double *TempiC){
	cout<<"##--@ Inizio Raccolta di "<< Nc <<" campioni di modulo Delta V ( 1 per collisione) \t\t t_esec : "<<tempo_esec()<<" sec"<<endl;
	//EVOLUZIONE
	int i_urto, j_urto; //labelli delle 2 particelle urtanti
	double t_urto;	double t=0.; 
	for(int k=0; k<Nc; k++){
		if(k% 50 ==0){
		printf("##--@ \t %d° Collisione  \t\t\t (t =  %1.3f [t]) \t\t\t t_esec : %1.3f sec",k,t,tempo_esec());	
		cout<< string(300,'\b');}
	//1) scorro tutti gli elementi della tavola e trovo gli elementi che collidono per primi
		t_urto= CalcoloTempoCollisione(&i_urto,&j_urto);
		TempiC[k]=t_urto;
	//2) evolvo le posizioni e applico condizione di bordo	
		EvoluzionePosizioniParticelle( t_urto);
	//2.5) evolvo la velocità delle particelle che hanno urtato
		DeltaV[k] = EvoluzioneVelocitaParticelle(i_urto,j_urto);
	//3) Aggiorno tavola di collisione
		AggiornamentoTavolaCollisione(t_urto,i_urto,j_urto);
	}
	printf("##--@ \t Fine Raccolta  %d urti \t\t (t =  %1.3f [t]) \t\t\t t_esec : %1.3f sec\n#\n",Nc,t,tempo_esec());

}
//______________________________________________________________________________________________________________________________


double sistema_rigido::Raccolta_TempiCollisione(int Nc, double *O){
	cout<<"##--@ Inizio Raccolta di "<< Nc <<" campioni di Tempo collisione ( 1 per collisione) \t\t t_esec : "<<tempo_esec()<<" sec"<<endl;
 	double t=0.; 
	for(int k=0; k<Nc; k++){
		if(k% 50 ==0){
		end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
		printf("##--@ \t %d° Collisione  \t\t\t (t =  %1.3f [t]) \t\t\t t_esec : %1.3f sec",k,t,tempo);	
		cout<< string(300,'\b');}
		O[k]=evoluzione();
		t+= O[k];
	}
	printf("##--@ \t Fine Raccolta  %d urti \t\t (t =  %1.3f [t]) \t\t\t t_esec : %1.3f sec\n#\n",Nc,t,tempo_esec());
}
//______________________________________________________________________________________________________________________________


double sistema_rigido::Raccolta_LiberoCammino(int Nc, double *O){
	cout<<"##--@ Inizio Raccolta di "<< Nc <<" campioni del libero cammino ( 1 ogni collisione) \t\t t_esec : "<<tempo_esec()<<"sec"<<endl;
	//EVOLUZIONE
	int i_urto, j_urto; //labelli delle 2 particelle urtanti
	double t_urto;	double t=0.;  	double X=0;//memorizzo il cammino libero totale

	double spost[M];//vettore che immagazzina tutta la lunghezza percorsa liberamente dalla particella i-sima fin ora (azzerato dopo urto
	bool test[M]; 	//vettore di test! segna se una particella ha già urtato una volta
	for(int i=0;i<M;i++){test[i]=false;spost[i]=0;}		//inizializzazione vettor
	int Nc_veri=0;//Ncollisioni valide per misurare il libero cammino medio	(bisogna misurare 2 collisioni per conoscere il cammino libero
	int k=0;		//contatore di collisioni totali evvenute	

	while(Nc_veri<Nc){
		if(k% 10 ==0){
		printf("##--@ \t %d° Collisione  \t\t\t (t =  %1.3f [t]) \t\t\t t_esec : %1.3f sec",k,t,tempo_esec());	
		cout<< string(300,'\b');}
	//1) scorro tutti gli elementi della tavola e trovo gli elementi che collidono per primi
		t_urto= CalcoloTempoCollisione(&i_urto,&j_urto);
		t+=t_urto; //sommatoria dei tempi di collisione
	//@) aggiorno vettore dei cammini
		for(int i=0;i<M;i++)spost[i]+=t_urto*mod(v0[i]); 
	//@) salvo libero cammino della prima particella urtante
		if(test[i_urto]==true){ //se i ha già urtato prima ho un valore di libero cammino medio utilizzabile (test=1)
			O[Nc_veri] = spost[i_urto];
			Nc_veri++;
		}
		else test[i_urto]=true;	//se non ha già urtato il prossimo urto sarà un valore valido
	//@) salvo libero cammino della seconda particella urtante
		if(test[j_urto]==true){ //se j ha già urtato prima ho un valore di libero cammino medio utilizzabile (test=1)
			O[Nc_veri] = spost[j_urto];
			Nc_veri++;
		}
		else test[j_urto]=true; //se non ha già urtato il prossimo urto sarà un valore valido	
	//@) azzero il contatore del cammino delle particelle urtanti
		spost[i_urto]=0;spost[j_urto]=0;
	//2) evolvo le posizioni e applico condizione di bordo	
		EvoluzionePosizioniParticelle( t_urto);
	//2.5) evolvo la velocità delle particelle che hanno urtato
		double dummy = EvoluzioneVelocitaParticelle(i_urto,j_urto);
	//3) Aggiorno tavola di collisione
		AggiornamentoTavolaCollisione(t_urto,i_urto,j_urto);
		k++;
		double X = O[Nc_veri-1];
//		cout<<X<<endl;
		if(X!=X){cout<<" ho uno spostamento nan!\n\n\n ctrl+z!!!!";break;} // se x è nan allora break
	}
	printf("##--@ \t Fine Raccolta  %d urti \t\t (t =  %1.3f [t]) \t\t\t t_esec : %1.3f sec\n#\n",Nc,t,tempo_esec());
	return(t);
}
//______________________________________________________________________________________________________________________________








/*
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
//RACCOLTA DI OSSERVABILI PARTICELLA, 1 dato per ogni singola particella----> Nconfigurazioni * Nparticelle = Ndatitotali

>>>>>>>>>>>>>>>VERSIONI A NUMERO DI COLLISIONI FISSATO<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	Si campionano configurazioni ogni Nc_campionature urti
	(per le osservabili relative alla differenze tra due configurazioni ad un certo intervallo di tempo di distanza bisogna indicare anche Nc_Dt = il numero di collisioni che avvengono tra le due configurazioni della coppia)

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
*/

double sistema_rigido::Raccolta_Vx(int Nconfigurazioni, int Nc_campionature, double *O){
/* Raccolta delle componenti x delle velocità delle particelle in Nconfigurazioni distanti Nc_campionature tra loro */
//Nconfigurazioni = # di configurazioni che si vogliono campionare
//Nc_campionature = # di urti che intercorrono tra due campionature successive di una configurazione
//O				  =	Array dei valori di vx che vengono campionati
	cout<<"##--@ Inizio Raccolta di "<< Nconfigurazioni*M <<" campioni di Vx  \t\t\t\t\t\t t_esec : "<<tempo_esec()<<" sec \n";
	cout<<"##--@ ("<< Nconfigurazioni <<" configurazioni raccolte ogni "<<Nc_campionature<<" urti, "<<M<<" campioni di vxogni configurazione)\n";
		
	double t=0.;
	for(int k=0;k<Nconfigurazioni;k++){
		if(k% 10 ==0){
			printf("##--@ \t  Configurazione %d / %d ( %d° collisione) \t\t\t\t t_esec : %1.3f sec",k+1,Nconfigurazioni,Nc_campionature*k,tempo_esec());	
		cout<< string(300,'\b');
		}
		t+=evoluzione_muto(Nc_campionature);
		for(int i=0;i<M;i++){O[M*k+i]=v0[i].x();}
	}

	printf("##--@ \t  Configurazione %d / %d ( %d° collisione) \t\t\t\t t_esec : %1.3f sec\n#\n", Nconfigurazioni, Nconfigurazioni, Nc_campionature*Nconfigurazioni,tempo_esec());	
return(t);
}
//______________________________________________________________________________________________________________________________

double sistema_rigido::Raccolta_dS(int Ncampionature, int Nc_campionature, int Nc_Dt, double *O){
/* Raccolta  di spostamentamenti (con bordo) tra coppie di configurazioni che distano Nc_Dt collisioni tra loro. 
Misura dello spostamento radiale in funzione del numero di urti di diffusione, questo numero si trasforma in una stima del tempo di diffusione moltiplicando per il tempo di collisione medio (ritornato dalla funzione)*/
// Ncampionature = # di coppie di configurazioni inizio - fine campionate
// Nc_campionature = # di urti che intercorrono tra la configurazione inizio di una coppia e l'inizio della coppia successiva
// Nc_Dt =  distanza temporale (# di collisioni) tra la configurazioni iniziale e quella finale della stessa coppia
//O = array che viene riempito dalle stime di ds quad, una per ogni particella per ogni coppia di configurazioni
	cout<<"##--@ Inizio Raccolta di "<< Ncampionature*M <<" campioni di dS^2( "<<Nc_Dt<<" urti)\t\t\t t_esec : "<<tempo_esec()<<" sec"<<endl;
	cout<<"##--@ ("<< Ncampionature <<" coppie di configurazioni (distanti "<<Nc_Dt<<" tra di loro) raccolte ogni "<<Nc_campionature<<" urti, "<<M<<" campioni ogni coppia di configurazione)"<<endl;

	vector< vector<vettore> > P0_iniziali( Ncampionature , vector<vettore>(M,0) );	//vector che contiene le configurazioni (posizione di ogni particella) di inizio di ogni coppia di configurazioni

	int Nevoluzioni= (Ncampionature-1)*Nc_campionature + Nc_Dt; // devo evolvere il sistema un numero di volte sufficienti in modo che l'ultima configurazione iniziale abbia la sua configurazione finale dopo un giusto intervallo temporale

	double t= 0. ;	//tempo di evoluzione del sistema	
	int ContIni=0;	//contatori di quante campionature sono iniziate e finite
	int ContFin=0;

	for(int n=0; n<=Nevoluzioni;n++){		//n= al numero di evoluzioni compiute
		printf("##--@ step : %5d / %5d \t                        \t\t t_esec : %.2f sec ",n,Nevoluzioni,tempo_esec());
		cout<< string(300,'\b');

		if(n%Nc_campionature==0 && ContIni< Ncampionature){			   //ho un nuovo inizio ogni Nstep_campionature
			for(int j=0; j<	M; j++)	P0_iniziali[ContIni][j]  = P0[j];  //salvo la configurazione di inizio della coppia ContIni
			printf("##--@ step : %5d / %5d \t Inizio serie :   %d    \t\t t_esec : %.2f sec ",n,Nevoluzioni,ContIni,tempo_esec());
			cout<< string(300,'\b');
			ContIni++;												   //la prossima volta comincierà la campionatura ContIni+1
		}

		if( n >= Nc_Dt && (n - Nc_Dt)%Nc_campionature==0){	//ho un nuovo Fine ogni Nstep_campionature dopo la Nstep_Dt -sima
			for(int j=0; j<	M; j++)	O[M*ContFin + j]= distanza_immagini(P0[j], P0_iniziali[ContFin][j]); //Salvo i valori di spostamento
			printf("##--@ step : %5d  / %5d \t Fine serie :   %d    \t\t t_esec : %.2f sec ",n,Nevoluzioni,ContFin,tempo_esec());
			cout<< string(300,'\b');
			ContFin++;												// la prossima volta terminera la campionatura ContFin+1
		}
		t +=evoluzione(); //evolvo il sistema di uno step (una collisione)
	}
	cout<<"\n#"<< endl;
return(t);
}
//______________________________________________________________________________________________________________________________

double sistema_rigido::Raccolta_dS_quad(int Ncampionature, int Nc_campionature, int Nc_Dt, double *O){
/* Raccolta  di diffusione (spostamento quadratico senza  bordo) tra coppie di configurazioni che distano Nc_Dt collisioni tra loro. 
Misura dello spostamento quadratico in funzione del numero di urti di diffusione, questo numero si trasforma in una stima del tempo di diffusione moltiplicando per il tempo di collisione medio (ritornato dalla funzione)*/
// Ncampionature = # di coppie di configurazioni inizio - fine campionate
// Nc_campionature = # di urti che intercorrono tra la configurazione inizio di una coppia e l'inizio della coppia successiva
// Nc_Dt =  distanza temporale (# di collisioni) tra la configurazioni iniziale e quella finale della stessa coppia
//O = array che viene riempito dalle stime di ds quad, una per ogni particella per ogni coppia di configurazioni
	cout<<"##--@ Inizio Raccolta di "<< Ncampionature*M <<" campioni di dS^2( "<<Nc_Dt<<" urti)\t\t\t t_esec : "<<tempo_esec()<<" sec"<<endl;
	cout<<"##--@ ("<< Ncampionature <<" coppie di configurazioni (distanti "<<Nc_Dt<<" tra di loro) raccolte ogni "<<Nc_campionature<<" urti, "<<M<<" campioni ogni coppia di configurazione)"<<endl;

	CollassaDiffusione();
	vector< vector<vettore> > Pdiffusa_iniziali( Ncampionature , vector<vettore>(M,0) );	//vector che contiene le configurazioni (posizione di ogni particella) di inizio di ogni coppia di configurazioni

	int Nevoluzioni= (Ncampionature-1)*Nc_campionature + Nc_Dt; // devo evolvere il sistema un numero di volte sufficienti in modo che l'ultima configurazione iniziale abbia la sua configurazione finale dopo un giusto intervallo temporale

	double t= 0. ;	//tempo di evoluzione del sistema	
	int ContIni=0;	//contatori di quante campionature sono iniziate e finite
	int ContFin=0;

	for(int n=0; n<=Nevoluzioni;n++){		//n= al numero di evoluzioni compiute
		printf("##--@ step : %5d / %5d \t                        \t\t t_esec : %.2f sec ",n,Nevoluzioni,tempo_esec());
		cout<< string(300,'\b');

		if(n%Nc_campionature==0 && ContIni< Ncampionature){							//ho un nuovo inizio ogni Nstep_campionature
			for(int j=0; j<	M; j++)	Pdiffusa_iniziali[ContIni][j]  = Pdiffusa[j];	//salvo la configurazione di inizio della coppia ContIni
			printf("##--@ step : %5d / %5d \t Inizio serie :   %d    \t\t t_esec : %.2f sec ",n,Nevoluzioni,ContIni,tempo_esec());
			cout<< string(300,'\b');
			ContIni++;													//la prossima volta comincierà la campionatura ContIni+1
		}

		if( n >= Nc_Dt && (n - Nc_Dt)%Nc_campionature==0){	//ho un nuovo Fine ogni Nstep_campionature dopo la Nstep_Dt -sima
			for(int j=0; j<	M; j++)	O[M*ContFin + j]= Mod(Pdiffusa[j] - Pdiffusa_iniziali[ContFin][j]); //Salvo i valori di spostamento
			printf("##--@ step : %5d  / %5d \t Fine serie :   %d    \t\t t_esec : %.2f sec ",n,Nevoluzioni,ContFin,tempo_esec());
			cout<< string(300,'\b');
			ContFin++;												// la prossima volta terminera la campionatura ContFin+1
		}
		t +=evoluzione(); //evolvo il sistema di uno step (una collisione)
	}
	cout<<"\n#"<< endl;
return(t);
}







/*
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
//RACCOLTA DI OSSERVABILI PARTICELLA, 1 dato per ogni singola particella----> Nconfigurazioni * Nparticelle = Ndatitotali

>>>>>>>>>>>>>>>VERSIONI A intervallo di tempo fissato<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	per prima cosa si fissa un intervallo temporale t_step che funge da unità di tempo
	Si campionano configurazioni ogni Nstep_campionature step unità tempo
	(per le osservabili relative alla differenze tra due configurazioni ad un certo intervallo di tempo di distanza bisogna indicare anche Nstep_Dt = il numero di step unità tempo che avvengono tra le due configurazioni della coppia)

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
*/

int sistema_rigido::Raccolta_Vx(int Nconfigurazioni, double Dt, double *O){
/* Raccolta delle componenti x delle velocità delle particelle in Nconfigurazioni distanti Nc_campionature tra loro */
//Nconfigurazioni = # di configurazioni che si vogliono campionare
//Dt = intervallo di tempo totale che intercorre tra due campionature successive di una configurazione
//O				  =	Array dei valori di vx che vengono campionati
	cout<<"##--@ Inizio Raccolta di "<< Nconfigurazioni*M <<" campioni di Vx  \t\t\t\t\t\t t_esec : "<<tempo_esec()<<" sec \n";
	cout<<"##--@ ("<< Nconfigurazioni <<" configurazioni raccolte ogni "<<Dt<<" [t], "<<M<<" campioni di vxogni configurazione)\n";
	
	int ContUrti =0;
	for(int k=0;k<Nconfigurazioni;k++){
		if(k% 10 ==0){
			printf("##--@ \t  Configurazione %d / %d ( %2.3f [t]) \t\t\t\t t_esec : %1.3f sec",k+1,Nconfigurazioni,Dt*k,tempo_esec());	
		cout<< string(300,'\b');
		}
		ContUrti+=evoluzione_muto(Dt);
		for(int i=0;i<M;i++){O[M*k+i]=v0[i].x();}
	}

	printf("##--@ \t  Configurazione %d / %d  ( %2.3f [t]) \t\t\t\t t_esec : %1.3f sec\n#\n" , Nconfigurazioni, Nconfigurazioni, Dt*Nconfigurazioni, tempo_esec());	
return(ContUrti);
}
//___________________________________________________________________________________________________________________-_-_-_-

int sistema_rigido::Raccolta_dS_conBordo(int Ncampionature, int Nstep_campionature, int Nstep_Dt, double t_step, double *O){ 
/* Raccolta  di spostamentamenti (con bordo) tra coppie di configurazioni che distano (Nstep_Dt) * (t_step) [t] di evoluzione */
// Ncampionature = # di coppie di configurazioni inizio - fine campionate
// t_step = unità di tempo in cui si discretizza l'evoluzione del sistema
// Nstep_Dt =  distanza temporale (# di t_step) tra la configurazioni inizio e quella fine della stessa coppia
// Nstep_campionature = distanza temporale (# di t_step) tra 2 configurazioni inizio consecutive

	cout<<"##--@ Inizio Raccolta di "<< Ncampionature *M <<" dS( "<<Nstep_Dt*t_step<<" [t] ) (con bordo) per ogni particella \t\t t_esec : "<<tempo_esec()<<" sec"<<endl;
	cout<<"##--@ ("<< Ncampionature <<" coppie di configurazioni (distanti "<<Nstep_Dt<<" t_step = "<<t_step<<" [t] tra di loro) raccolte ogni "<< Nstep_campionature<<" t_step, "<<M<<" campioni ogni coppia di configurazione)"<<endl;

	vector< vector<vettore> > P0_iniziali( Ncampionature , vector<vettore>(M,0) );	//vector che contiene le configurazioni (posizione di ogni particella) di inizio di ogni coppia di configurazioni

	int Nevoluzioni= (Ncampionature-1)*Nstep_campionature + Nstep_Dt; // devo evolvere il sistema un numero di volte sufficienti in modo che l'ultima configurazione iniziale abbia la sua configurazione finale dopo un giusto intervallo temporale

	int ContUrti=0;	
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
		ContUrti+=evoluzione_muto(t_step); //evolvo il sistema di uno step
	}
	cout<<"\n#"<< endl;
return(ContUrti);
}
//___________________________________________________________________________________________________________________-_-_-_-

int sistema_rigido::Raccolta_dS_quad(int Ncampionature, int Nstep_campionature, int Nstep_Dt, double t_step, double *O){ 
/* Raccolta  della diffusione ( spostamentamenti quadratico senza bordo) tra coppie di configurazioni che distano (Nstep_Dt) * (t_step) [t] di evoluzione */
// Ncampionature = # di coppie di configurazioni inizio - fine campionate
// t_step = unità di tempo in cui si discretizza l'evoluzione del sistema
// Nstep_Dt =  distanza temporale (# di t_step) tra la configurazioni inizio e quella fine della stessa coppia
// Nstep_campionature = distanza temporale (# di t_step) tra 2 configurazioni inizio consecutive

	cout<<"##--@ Inizio Raccolta di "<< Ncampionature *M <<" dS^2( "<<Nstep_Dt*t_step<<" [t] ) (spostamento assoluto senza bordo) per ogni particella \t t_esec : "<<tempo_esec()<<" sec"<<endl;
	cout<<"##--@ ("<< Ncampionature <<" coppie di configurazioni (distanti "<<Nstep_Dt<<" t_step = "<<t_step<<" [t] tra di loro) raccolte ogni "<< Nstep_campionature<<" t_step, "<<M<<" campioni ogni coppia di configurazione)"<<endl;

	CollassaDiffusione();
	vector< vector<vettore> > Pdiffusa_iniziali( Ncampionature , vector<vettore>(M,0) );	//vector che contiene le configurazioni (posizione di ogni particella diffusa) di inizio di ogni coppia di configurazioni

	int Nevoluzioni= (Ncampionature-1)*Nstep_campionature + Nstep_Dt; // devo evolvere il sistema un numero di volte sufficienti in modo che l'ultima configurazione iniziale abbia la sua configurazione finale dopo un giusto intervallo temporale
	
	int ContUrti=0;
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
		ContUrti+=evoluzione_muto(t_step); //evolvo il sistema di uno step
	}
	cout<<"\n#"<< endl;
return(ContUrti);
}

