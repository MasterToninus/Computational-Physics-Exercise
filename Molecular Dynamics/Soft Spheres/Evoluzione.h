//http://www2.ph.ed.ac.uk/~graeme/compmeth/verlet.html

void sistema_soffice::evoluzione(){ //step di un unico intervallo elementare t_step=n 0.001 (definito costante)
//evolvo posizioni
	for(int i=0; i<M; i++){
		vettore dS = t_step*v0[i] + t_step*t_step*0.5*a0[i];
		P0[i] += dS;
		P0[i].riscalamento(L);	
		Pdiffusa[i]+=dS;
	}
//calcolo velocità a metà passo
	vector<vettore> v_mezzopasso;
	for(int i=0; i<M; i++)	v_mezzopasso.push_back(v0[i] + 0.5*t_step*a0[i]);
//aggiorno accelerazioni con le nuove posizioni evolute
	CalcoloAccelerazioni();
//aggiorno velocità con posizioni e accele evolute
	for(int i=0; i<M; i++)		v0[i] = v_mezzopasso[i] + 0.5*t_step*a0[i]; 
}

/*
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
ALGORITMI DI EVOLUZIONE A NPASSI FISSATO

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
*/

void sistema_soffice::evoluzione(int Npassi){	//evoluzione di Npassi fondamentali
	cout<<"#-@ Inizio evoluzione temporale di "<<Npassi<<" step \t\t\t\t\t\t t_esec : "<<tempo_esec()<<" sec"<<endl;
	
	for(int i=0;i< Npassi; i++){
		if((i+1)%10==0){
		printf("#-@ \t step %3d / %3d \t\t (t= %1.1f [t]) \t\t\t\t\t t_esec : %1.3f sec",i,Npassi,t_step*i,tempo_esec());
		cout << string(500,'\b');
		CostruzioneListaVicini();			//AGGIORNAMENTO DELLA LISTA VICINI OGNI 10 PASSI
		}
		evoluzione();	
	}
	cout<<endl<<"#"<<endl;
	CostruzioneListaVicini();
}

void sistema_soffice::evoluzione_muto(int Npassi){
	for(int i=0;i< Npassi; i++){
		if((i+1)%10==0)	CostruzioneListaVicini();			//AGGIORNAMENTO DELLA LISTA VICINI OGNI 10 PASSI
		evoluzione();	
	}
	CostruzioneListaVicini();
}

void sistema_soffice::termalizzazione_kTfissa(int Npassi, double T_D){
// Numero di passi , Temperatura desiderata (applicata una volta per ogni passo)
	cout<<"#-@ Inizio Termalizzazione a T_D= "<<T_D<<" per "<<Npassi<<" passi \t\t\t\t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	double T_A; //temperatura assegnata
	vettore vtot(0);	// momento totale iniziale

	//evolvo Npassi riscalando ogni volta la velocità in modo opportuno
	for(int i=0;i< Npassi; i++){
		if((i+1 )%10 ==0){
		printf("#-@ \t step %3d / %3d \t\t (t= %1.1f [t]) \t\t\t\t\t t_esec : %1.3f sec",i,Npassi,t_step*i,tempo_esec());
		cout << string(300,'\b');
		CostruzioneListaVicini();	//AGGIORNAMENTO DELLA LISTA VICINI OGNI 10 ASSI											
		}
		T_A= kT_stato();			

		for(int i=0; i<M; i++)	v0[i] = sqrt(T_D/T_A)*v0[i];		//scalare velocità per avere T desiderata T_D	
//		vettore vtot=Ptot();									// momento totale iniziale
//		for(int j=0; j<M; j++){v0[j] -= vtot/M;}				//scalare le velocità per avere momento nullo
		evoluzione();	
	}
	CostruzioneListaVicini();
	T_A = kT_stato(); //temperatura aggiustata
	printf("\n#-@ Fine Termalizzazione\t(Px: %1.1e \t T_i : %1.3f ) \t\t\t\t t_esec : %1.3f sec\n#\n", Ptot().x(),T_A,tempo_esec());
}


void sistema_soffice::termalizzazione_Efissa(int Npassi, double E_D){
// Numero di passi , Energia desiderata (applicata una volta per ogni passo)
	cout<<"#-@ Inizio Termalizzazione a E_D= "<<E_D*M<<" per "<<Npassi<<" passi \t\t\t\t\t t_esec : "<<tempo_esec()<<" sec"<<endl;
	if(Utot()>E_D*M)cout<<"#-@ IMPOSSIBILE TERMALIZZARE E_D< U_A ="<<Utot()<<endl;
	else{
		double Ek_A= Ktot()/M;
		double U_A = Utot()/M;			
		for(int i=0; i<M; i++)	v0[i] *=sqrt((E_D-U_A)/Ek_A);
		evoluzione_muto( Npassi);
		Ek_A= Ktot()/M;
		U_A = Utot()/M;
		for(int i=0; i<M; i++)	v0[i] *=sqrt((E_D-U_A)/Ek_A);
		printf("#-@ Fine Termalizzazione\t(Px: %1.1e \t E_tot: %.1f ) \t\t\t t_esec : %1.3f sec\n#\n", Ptot().x(),(Ktot()+Utot()),tempo_esec());
	}
}






/*
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
ALGORITMI DI EVOLUZIONE AD INTERVALLO DI TEMPO FISSATO

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
*/

void sistema_soffice::evoluzione(double Dt){	//evoluzione di Dt unità di tempo
	cout<<"#-@ Inizio evoluzione temporale per "<<Dt<<" [t] \t\t\t\t\t\t t_esec : "<<tempo_esec()<<" sec"<<endl;
	int Npassi=0;	
	while (Npassi*t_step < Dt)
	{
		if((Npassi+1)% 10 ==0){
			printf("#-@ \t tempo %1.1f [t] su %1.1f [t] \t (step= %d) \t\t\t\t\t t_esec : %1.3f sec",Npassi*t_step,Dt,Npassi,tempo_esec());
			cout << string(300,'\b');
			CostruzioneListaVicini();			//AGGIORNAMENTO DELLA LISTA VICINI OGNI 10 PASSI
		}
		evoluzione();	
		Npassi++;
	}
	cout<<endl<<"#"<<endl;
	CostruzioneListaVicini();
}
void sistema_soffice::evoluzione_muto(double Dt){
	int Npassi=0;	
	while (Npassi*t_step < Dt)
	{
		if((Npassi + 1 )%10 ==0)	CostruzioneListaVicini();			//AGGIORNAMENTO DELLA LISTA VICINI OGNI 10 PASSI
		evoluzione();	
		Npassi++;
	}
	CostruzioneListaVicini();
}

void sistema_soffice::termalizzazione_kTfissa(double Dt, double T_D){
	cout<<"#-@ Inizio Termalizzazione a T_D= "<<T_D<<" per "<<Dt<<" [t] \t\t\t\t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	double T_A; //temperatura assegnata
	vettore vtot(0);	// momento totale iniziale

	//evolvo per Dt [t] riscalando ogni volta la velocità in modo opportuno
	int Npassi=0;	
	while (Npassi*t_step < Dt)
	{
		if((Npassi+1)% 10 ==0){
			printf("#-@ \t tempo %1.1f [t] su %1.1f [t] \t (step= %d) \t\t\t\t\t t_esec : %1.3f sec",Npassi*t_step,Dt,Npassi,tempo_esec());
			cout << string(300,'\b');
			CostruzioneListaVicini();			//AGGIORNAMENTO DELLA LISTA VICINI OGNI 10 PASSI
		}
		T_A= kT_stato();				
		for(int i=0; i<M; i++)	v0[i] *= sqrt(T_D/T_A);		//scalare velocità per avere T desiderata T_D	
		vettore vtot=Ptot();									// momento totale iniziale
		for(int j=0; j<M; j++){v0[j] -= vtot/M;}				//scalare le velocità per avere momento nullo

		evoluzione();	
		Npassi++;

	}
	CostruzioneListaVicini();

	T_A = kT_stato(); //temperatura aggiustata
	printf("\n#-@ Fine Termalizzazione\t(Px: %1.1e \t T_i : %1.3f ) \t\t\t\t t_esec : %1.3f sec\n#\n", Ptot().x(),T_A,tempo_esec());
}

void sistema_soffice::termalizzazione_Efissa(double Dt, double E_D){
	cout<<"#-@ Inizio Termalizzazione a E_D= "<<E_D*M<<" per "<<Dt<<" [t] \t\t\t\t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	if(Utot()>E_D*M)cout<<"#-@ IMPOSSIBILE TERMALIZZARE E_D< U_A"<<endl;
	else{
		double Ek_A= Ktot()/M;
		double U_A = Utot()/M;			
		for(int i=0; i<M; i++)	v0[i] *=sqrt((E_D-U_A)/Ek_A);
		evoluzione_muto(Dt);
		Ek_A= Ktot()/M;
		U_A = Utot()/M;
		for(int i=0; i<M; i++)	v0[i] *=sqrt((E_D-U_A)/Ek_A);
		printf("#-@ Fine Termalizzazione\t(Px: %1.1e \t E_tot: %.1f ) \t\t\t t_esec : %1.3f sec\n#\n", Ptot().x(),(Ktot()+Utot()),tempo_esec());

	}
}

