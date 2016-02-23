//METODI DI EVOLUZIONE/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/-

double sistema_rigido::evoluzione() //considero che non avvengano urti simultanei! Tc ha un solo minimo
{
	int i_urto, j_urto; //labelli delle 2 particelle urtanti
	double t_urto;
// EVOLUZIONE 
//1) scorro tutti gli elementi della tavola e trovo gli elementi che collidono per primi
	t_urto= CalcoloTempoCollisione(&i_urto,&j_urto);
//2) evolvo le posizioni e applico condizione di bordo
	EvoluzionePosizioniParticelle( t_urto);
//2.5) evolvo la velocità delle particelle che hanno urtato
	double delta_v = EvoluzioneVelocitaParticelle(i_urto,j_urto);
//3) Aggiorno tavola di collisione
	AggiornamentoTavolaCollisione(t_urto,i_urto,j_urto);
return(t_urto);
}

/*
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
ALGORITMI DI EVOLUZIONE A NPASSI FISSATO

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
*/

double sistema_rigido::evoluzione(int Npassi)	//Evoluzione per Npassi urti con contatore a video, ritorna il tempo di evoluzione
{
	cout<<"#-@ Inizio evoluzione temporale di "<<Npassi<<" step( urti) \t\t\t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	double t=0.;
	for(int i=0; i<Npassi;i++){
		if((i+1)%10==0){
		printf("#-@ \t step %3d / %3d \t\t (t= %1.1f [t]) \t\t\t\t t_esec : %1.3f sec",i,Npassi,t,tempo_esec());
		cout << string(500,'\b');}
		t+=evoluzione();
	}
	cout<<endl<<"#"<<endl;
	return(t);
}

double sistema_rigido::evoluzione_muto(int Npassi) 	//Evoluzione per Npassi urti senza contatore a video, ritorna il tempo di evoluzione
{
	double t=0.;
	for(int i=0; i<Npassi;i++) 	t+=evoluzione();
	return(t);
}


/*
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
ALGORITMI DI EVOLUZIONE AD INTERVALLO DI TEMPO FISSATO

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
*/

int sistema_rigido::evoluzione(double Dt) //evolve per Dt[t] con contatore a video e ritorna il numero di urti
{
	int i_urto, j_urto; //labelli delle 2 particelle urtanti
	double t_urto;
	double t=0.;
	int k=0;//contatore urto
	cout<<"#-@ Inizio evoluzione temporale di "<<Dt<<" [t] \t\t\t\t t_esec : "<<tempo_esec()<<" sec"<<endl;
	while (t<Dt){
		t_urto= CalcoloTempoCollisione(&i_urto,&j_urto); // tempo al prossimo urto
		if(t + t_urto> Dt){		//se intervallo di tempo mancante è minore del tempo per avare un urto
			double t_quasi_urto= Dt-t;
			//2) evolvo le posizioni e applico condizione di bordo
			EvoluzionePosizioniParticelle(t_quasi_urto);
			//2.5) non aggiorno la velocità! evolvo per meno del t di collisione quindi non ho urto
			//3) Aggiorno tavola di collisione
			AggiornamentoTavolaCollisione(t_quasi_urto,i_urto,j_urto);
		}
		else{				// se intervallo di tempo mancante è maggiore o uguale al tempo necessario per portare all'urto
			//2) evolvo le posizioni fino all'urtoe applico condizione di bordo
			EvoluzionePosizioniParticelle( t_urto);
			//2.5) evolvo la velocità delle particelle che hanno urtato
			double delta_v = EvoluzioneVelocitaParticelle(i_urto,j_urto);
			//3) Aggiorno tavola di collisione
			AggiornamentoTavolaCollisione(t_urto,i_urto,j_urto);
			k++;				
		}
		t += t_urto;
		if(k% 10 ==0){
			printf("#-@ \t urto %3d  \t\t (t = %1.5f [t]) \t\t\t t_esec : %1.3f sec",k+1,t,tempo_esec());
			cout << string(500,'\b');
		}
	}
	cout<<endl<<"#"<<endl;
return(k);
}	

int sistema_rigido::evoluzione_muto(double Dt) //evolve per Dt[t] senza contatore a video e ritorna il numero di urti
{
	int i_urto, j_urto; //labelli delle 2 particelle urtanti
	double t_urto;
	double t=0.;
	int k=0;//contatore urto

	while (t<Dt){
		t_urto= CalcoloTempoCollisione(&i_urto,&j_urto); // tempo al prossimo urto
		if(t + t_urto> Dt){		//se intervallo di tempo mancante è minore del tempo per avare un urto
			double t_quasi_urto= Dt-t;
			//2) evolvo le posizioni e applico condizione di bordo
			EvoluzionePosizioniParticelle(t_quasi_urto);
			//2.5) non aggiorno la velocità! evolvo per meno del t di collisione quindi non ho urto
			//3) Aggiorno tavola di collisione
			AggiornamentoTavolaCollisione(t_quasi_urto,i_urto,j_urto);
		}
		else{				// se intervallo di tempo mancante è maggiore o uguale al tempo necessario per portare all'urto
			//2) evolvo le posizioni fino all'urtoe applico condizione di bordo
			EvoluzionePosizioniParticelle( t_urto);
			//2.5) evolvo la velocità delle particelle che hanno urtato
			double delta_v = EvoluzioneVelocitaParticelle(i_urto,j_urto);
			//3) Aggiorno tavola di collisione
			AggiornamentoTavolaCollisione(t_urto,i_urto,j_urto);
			k++;				
		}
		t += t_urto;
	}
return(k);
}	

/*VERSIONE AUTORICORSIVA senza contatore degli urti
void sistema_rigido::evoluzione_muto(double Dt) 
{
	int i_urto, j_urto; //labelli delle 2 particelle urtanti
	double t_urto= CalcoloTempoCollisione(&i_urto,&j_urto); // tempo al prossimo urto
	if(Dt < t_urto){		//se intervallo Dt di evoluzione non porta al tempo di urto
		//2) evolvo le posizioni e applico condizione di bordo
		EvoluzionePosizioniParticelle(Dt);
		//2.5) non aggiorno la velocità! evolvo per meno del t di collisione quindi non ho urto
		//3) Aggiorno tavola di collisione
		AggiornamentoTavolaCollisione(Dt,i_urto,j_urto);
	}
	else{				// se intervallo di Dt è maggiore o uguale al tempo necessario per portare all'urto
		//2) evolvo le posizioni fino all'urtoe applico condizione di bordo
		EvoluzionePosizioniParticelle( t_urto);
		//2.5) evolvo la velocità delle particelle che hanno urtato
		double delta_v = EvoluzioneVelocitaParticelle(i_urto,j_urto);
		//3) Aggiorno tavola di collisione
		AggiornamentoTavolaCollisione(t_urto,i_urto,j_urto);
		Dt -= t_urto;				
		evoluzione_muto(Dt); 		//richiamo la funzione per un intervallo di tempo minore
	}
}	
*/

/*
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
ALGORITMI DI TERMALIZZAZIONE
	(sono semplici algoritmi di evoluzione dove semplicemente non si perde tempo ad evolvere le posizioni di diffusione)
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
*/

void sistema_rigido::Termalizzazione(int Nc) //considero che non avvengano urti simultanei! Tc ha un solo minimo
{
	cout<<"#-@ Inizio Termalizzazione per "<<Nc<<" urti \t\t\t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	int i_urto, j_urto; //labelli delle 2 particelle urtanti
	double t_urto;
	double t=0.;

	for(int i=0; i<Nc;i++){			//evoluzione
		if((i+1)%50==0){
			printf("#-@ \t urto %3d / %3d \t\t (t= %1.1f [t]) \t\t\t\t t_esec : %1.3f sec",i,Nc,t,tempo);
			cout << string(500,'\b');
			CheckSovrapposizione();
		}
		//1) scorro tutti gli elementi della tavola e trovo gli elementi che collidono per primi
		t_urto= CalcoloTempoCollisione(&i_urto,&j_urto);
		t += t_urto;
		//2) evolvo solo le posizioni del sistema con condizioni al bordo
		for(int i=0;i<M;i++){
			P0[i]=P0[i]+t_urto*v0[i];
			P0[i].riscalamento(L);	
		}
		//2.5) evolvo la velocità delle particelle che hanno urtato
		double delta_v = EvoluzioneVelocitaParticelle(i_urto,j_urto);
		//3) Aggiorno tavola di collisione
		AggiornamentoTavolaCollisione(t_urto,i_urto,j_urto);
	}
	cout<<endl<<"#"<<endl;
}
