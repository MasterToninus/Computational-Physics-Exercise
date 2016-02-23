//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
/*			CONTROLLO CONSERVAZIONE (al centro della scatola)						*/
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

void sistema_rigido::evoluzione_Check(int Npassi) 	//Evoluzione per Npassi urti mostrando per ogni urto le variabili dinamiche di momento totale, energia totale e temperatura, dovrebbero essere conservate!
{
	cout<<"#-@ Inizio evoluzione Controllata di "<<Npassi<<" step( urti) \t\t\t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	double t=0.;
	for(int i=0; i<Npassi;i++){
		bool test= CheckSovrapposizione(); 
		printf("#-@ n_urti = %6d \t Ptot = ( %1.2f , %1.2f , %1.2f ) \t Etot = %1.2f \t kT = %1.2f \t\t t_esec : %1.3f sec",i,MomentoTotale().x(),MomentoTotale().y(),MomentoTotale().z(),EnergiaTotale(),kT(),tempo_esec());
		cout << string(500,'\b');

		if(test==true)evoluzione();
		else if(test==false){cout<<endl;break;}
	}
	cout<<endl<<"#"<<endl;
}

void sistema_rigido::evoluzione_Check(int Npassi,double t_step) 	//Evoluzione per Npassi urti mostrando per ogni urto le variabili dinamiche di momento totale, energia totale e temperatura, dovrebbero essere conservate!
{
	cout<<"#-@ Inizio evoluzione Controllata di "<<Npassi<<" step( urti) \t\t\t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	int Nc=0.;
	for(int i=0; i<Npassi;i++){
		bool test= CheckSovrapposizione(); 
		printf("#-@ n_step = %6d (Nc= %6d )\t Px = %1.2f \t Etot = %1.2f \t kT = %1.2f \t\t t_esec : %1.3f sec",i,Nc,MomentoTotale().x(),EnergiaTotale(),kT(),tempo_esec());
		cout << string(500,'\b');
		Nc+=evoluzione_muto(t_step);
		if(test == true)evoluzione();
		if(test == false)break;
	}
	cout<<endl<<"#"<<endl;
}


//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
/*			TRAIETTORIE DELLA PARTICELLA DI TEST (al centro della scatola)						*/
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

//   (ALGORITMI DI EVOLUZIONE A NPASSI FISSATO)
void sistema_rigido::evoluzione_conmoto(int Npassi,string riga) 	//Evoluzione per Npassi urti ,stampa la traiettoria compiuta da una particella nel mezzo della scatola con bordo
{
	int i_studio ;
	if(i_studio>=M)cout<<"errore! non esiste nessuna particella di indice "<<i_studio<<endl;
	for( int i=0; i< M ; i++){
		if(d == 2 && P0[i].x()<0.6 && P0[i].x()>0.4 && P0[i].y()<0.6 && P0[i].x()>0.4)i_studio=i;
		if(d == 3 && P0[i].x()<0.6 && P0[i].x()>0.4 && P0[i].y()<0.6 && P0[i].x()>0.4&& P0[i].z()<0.6 && P0[i].z()>0.4)i_studio=i;
	}

	string nomeFile= "Output/"+riga;	
	ofstream myfile(nomeFile.c_str());
	cout<<"#-@ Inizio Calcolo traiettoria della particella " <<i_studio<<" per "<<Npassi<<" step \t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	myfile<<"# Diametro = "<<sigma<<endl;
	if(d==2)myfile<<P0[i_studio].x()<< "\t " <<P0[i_studio].y()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<  endl;
	if(d==3)myfile<<P0[i_studio].x()<< "\t " <<P0[i_studio].y()<<"\t "<<P0[i_studio].z()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<"\t " <<v0[i_studio].z()<<  endl;

	double t=0.;
	for(int k=0; k<Npassi; k++){
		if(k% 10 ==0){
			printf("#-@ \t urto %3d / %3d \t\t (t= %1.1f [t]) \t\t\t\t t_esec : %1.3f sec",k+1,Npassi,t,tempo_esec());
			cout << string(500,'\b');
		}
		t+=evoluzione();
		if(d==2)myfile<<P0[i_studio].x()<< "\t " <<P0[i_studio].y()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<  endl;
		if(d==3)myfile<<P0[i_studio].x()<< "\t " <<P0[i_studio].y()<<"\t "<<P0[i_studio].z()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<"\t " <<v0[i_studio].z()<<  endl;

	}
	myfile.close();
	cout<<endl<<"#"<<endl;
}
void sistema_rigido::evoluzione_condiffusione(int Npassi,string riga) 	//Evoluzione per Npassi urti ,stampa la diffusione compiuta da una particella nel mezzo della scatola (il suo moto senza applicare il bordo periodico)
{
	int i_studio ;
	for( int i=0; i< M ; i++){
		if(d == 2 && P0[i].x()<0.6 && P0[i].x()>0.4 && P0[i].y()<0.6 && P0[i].x()>0.4)i_studio=i;
		if(d == 3 && P0[i].x()<0.6 && P0[i].x()>0.4 && P0[i].y()<0.6 && P0[i].x()>0.4&& P0[i].z()<0.6 && P0[i].z()>0.4)i_studio=i;
	}
	CollassaDiffusione(); //riporta tutte le immagini diffuse all'interno della scatola

	string nomeFile= "Output/"+riga;	
	ofstream myfile(nomeFile.c_str());
	cout<<"#-@ Inizio Calcolo traiettoria di Diffusione della particella " <<i_studio<<" per "<<Npassi<<" step \t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	myfile<<"# Diametro = "<<sigma<<endl;
	if(d==2)myfile<<P0[i_studio].x()<< "\t " <<P0[i_studio].y()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<  endl;
	if(d==3)myfile<<P0[i_studio].x()<< "\t " <<P0[i_studio].y()<<"\t "<<P0[i_studio].z()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<"\t " <<v0[i_studio].z()<<  endl;

	double t=0.;
	for(int k=0; k<Npassi; k++){
		if(k% 10 ==0){
			printf("#-@ \t urto %3d / %3d \t\t (t= %1.1f [t]) \t\t\t\t t_esec : %1.3f sec",k+1,Npassi,t,tempo_esec());
			cout << string(500,'\b');
		}
		t+=evoluzione();
		if(d==2)myfile<<Pdiffusa[i_studio].x()<< "\t " <<Pdiffusa[i_studio].y()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<  endl;
		if(d==3)myfile<<Pdiffusa[i_studio].x()<< "\t " <<Pdiffusa[i_studio].y()<<"\t "<<Pdiffusa[i_studio].z()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<"\t " <<v0[i_studio].z()<<  endl;

	}
	myfile.close();
	cout<<endl<<"#"<<endl;
}

//	(ALGORITMI DI EVOLUZIONE AD INTERVALLO DI TEMPO FISSATO)
void sistema_rigido::evoluzione_conmoto(double Dt,string riga) //Evoluzione per Dt [t] ,stampa la traiettoria compiuta da una particella nel mezzo della scatola con bordo
{
	int i_studio ; //Cerco particella nel centro della scatola
	for( int i=0; i< M ; i++){
		if(d == 2 && P0[i].x()<0.6 && P0[i].x()>0.4 && P0[i].y()<0.6 && P0[i].x()>0.4)i_studio=i;
		if(d == 3 && P0[i].x()<0.6 && P0[i].x()>0.4 && P0[i].y()<0.6 && P0[i].x()>0.4&& P0[i].z()<0.6 && P0[i].z()>0.4)i_studio=i;
	}

	string nomeFile= "Output/"+riga;	
	ofstream myfile(nomeFile.c_str());
	cout<<"#-@ Inizio Calcolo traiettoria della particella " <<i_studio<<" per "<<Dt<<" [t] \t\t t_esec : "<<tempo_esec()<<" sec"<<endl;
	myfile<<"# Diametro = "<<sigma<<endl;
	if(d==2)myfile<<P0[i_studio].x()<< "\t " <<P0[i_studio].y()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<  endl;
	if(d==3)myfile<<P0[i_studio].x()<< "\t " <<P0[i_studio].y()<<"\t "<<P0[i_studio].z()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<"\t " <<v0[i_studio].z()<<  endl;

	double t=0.;int k=0;//contatore urto
	while (t<Dt){
		int i_urto, j_urto; //labelli delle 2 particelle urtanti
		double t_urto= CalcoloTempoCollisione(&i_urto,&j_urto); // tempo al prossimo urto
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
		if(d==2)myfile<<P0[i_studio].x()<< "\t " <<P0[i_studio].y()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<  endl;
		if(d==3)myfile<<P0[i_studio].x()<< "\t " <<P0[i_studio].y()<<"\t "<<P0[i_studio].z()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<"\t " <<v0[i_studio].z()<<  endl;
		if(k% 10 ==0){
			printf("#-@ \t urto %3d  \t\t (t = %1.5f [t]) \t\t\t t_esec : %1.3f sec",k+1,t,tempo_esec());
			cout << string(500,'\b');
		}
	}
	myfile.close();
	cout<<endl<<"#"<<endl;
}

void sistema_rigido::evoluzione_condiffusione(double Dt,string riga)//Evoluzione per Dt [t],stampa la diffusione compiuta da una particella nel mezzo della scatola (il suo moto senza applicare il bordo periodico) 
{
	int i_studio ; //Cerco particella nel centro della scatola
	for( int i=0; i< M ; i++){
		if(d == 2 && P0[i].x()<0.6 && P0[i].x()>0.4 && P0[i].y()<0.6 && P0[i].x()>0.4)i_studio=i;
		if(d == 3 && P0[i].x()<0.6 && P0[i].x()>0.4 && P0[i].y()<0.6 && P0[i].x()>0.4&& P0[i].z()<0.6 && P0[i].z()>0.4)i_studio=i;
	}
	CollassaDiffusione(); //riporta tutte le immagini diffuse all'interno della scatola

	string nomeFile= "Output/"+riga;	
	ofstream myfile(nomeFile.c_str());
	cout<<"#-@ Inizio Calcolo traiettoria di Diffusione della particella " <<i_studio<<" per "<<Dt<<" [t] \t\t t_esec : "<<tempo_esec()<<" sec"<<endl;
	myfile<<"# Diametro = "<<sigma<<endl;
	if(d==2)myfile<<P0[i_studio].x()<< "\t " <<P0[i_studio].y()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<  endl;
	if(d==3)myfile<<P0[i_studio].x()<< "\t " <<P0[i_studio].y()<<"\t "<<P0[i_studio].z()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<"\t " <<v0[i_studio].z()<<  endl;

	double t=0.;int k=0;//contatore urto
	while (t<Dt){
		int i_urto, j_urto; //labelli delle 2 particelle urtanti
		double t_urto= CalcoloTempoCollisione(&i_urto,&j_urto); // tempo al prossimo urto
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
		if(d==2)myfile<<Pdiffusa[i_studio].x()<< "\t " <<Pdiffusa[i_studio].y()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<  endl;
		if(d==3)myfile<<Pdiffusa[i_studio].x()<< "\t " <<Pdiffusa[i_studio].y()<<"\t "<<Pdiffusa[i_studio].z()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<"\t " <<v0[i_studio].z()<<  endl;
		if(k% 10 ==0){
			printf("#-@ \t urto %3d  \t\t (t = %1.5f [t]) \t\t\t t_esec : %1.3f sec",k+1,t,tempo_esec());
			cout << string(500,'\b');
		}
	}
	myfile.close();
	cout<<endl<<"#"<<endl;
}







//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
/*			SNAPSHOT DIFFUSIONE						*/
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
//   (ALGORITMI DI EVOLUZIONE A NPASSI FISSAT
void sistema_rigido::stampa_Diffusione(int Ncollisioni,string riga){
	cout<<"#-|| Stampo Istantanea di Diffusione del sistema: "<<riga<<" \t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	CollassaDiffusione(); //riporta tutte le immagini diffuse all'interno della scatola
	vector<vettore> P0_iniziali(M,0); 	 //vector delle posizioni delle particelle		 (considerando le condizioni al bordo
	for(int j=0; j<	M; j++)		P0_iniziali[j]  = Pdiffusa[j];

	stringstream sstm0;
	sstm0 <<riga<<"_Inizio.dat";
	string nomeFile = sstm0.str()	;

	stampa_stato_diffusione(nomeFile);
	evoluzione(Ncollisioni);

	stringstream sstm;
	sstm <<riga<<"_Fine.dat";
	nomeFile = sstm.str()	;
	stampa_stato_diffusione(nomeFile);

	stringstream sstm2;
	sstm2 << "Output/"<<riga<<"_Spostamento.dat";
	nomeFile = sstm2.str();
	ofstream myfile2(nomeFile.c_str());
	if(d==2){
		myfile2<<"#X\t\t#Y\t\t#R\t\tdX\t\tdY\t" <<endl; 
		for(int i=0;i<M;i++){ //cout<<"stampo";
			double R= sigma / 2;		//la forza tagliata si annulla a distanza R= 1.12315
			myfile2 << P0_iniziali[i].x()<< "\t " <<P0_iniziali[i].y()<<"\t "<<R<<"\t ";
			myfile2 << (Pdiffusa[i]-P0_iniziali[i]).x()<< "\t " <<(Pdiffusa[i]-P0_iniziali[i]).y()<<endl	;
		}
	}
	if(d==3){
		myfile2<<"#X\t\t#Y\t\t#Z\t\tR\t\t#dX\t\t#dY\t\t#dZ\t" <<endl; 
		for(int i=0;i<M;i++){
			double R= sigma / 2;		
			myfile2 <<P0_iniziali[i].x()<< "\t " <<P0_iniziali[i].y()<<"\t " <<P0_iniziali[i].z()<<"\t "<<R<<"\t ";
			myfile2 <<(Pdiffusa[i]-P0_iniziali[i]).x()<< "\t " <<(Pdiffusa[i]-P0_iniziali[i]).y()<<"\t " <<(Pdiffusa[i]-P0_iniziali[i]).z()<<"\t "<<endl	;
		}
	}
	myfile2.close();
	cout<<"#"<<endl;
}
//	(ALGORITMI DI EVOLUZIONE AD INTERVALLO DI TEMPO FISSATO)
void sistema_rigido::stampa_Diffusione(double Dt,string riga){
	cout<<"#-|| Stampo Istantanea di Diffusione del sistema: "<<riga<<" \t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	CollassaDiffusione(); //riporta tutte le immagini diffuse all'interno della scatola
	vector<vettore> P0_iniziali(M,0); 	 //vector delle posizioni delle particelle		 (considerando le condizioni al bordo
	for(int j=0; j<	M; j++)		P0_iniziali[j]  = Pdiffusa[j];

	stringstream sstm0;
	sstm0 <<riga<<"_Inizio.dat";
	string nomeFile = sstm0.str()	;

	stampa_stato_diffusione(nomeFile);
	evoluzione(Dt);

	stringstream sstm;
	sstm <<riga<<"_Fine.dat";
	nomeFile = sstm.str()	;
	stampa_stato_diffusione(nomeFile);

	stringstream sstm2;
	sstm2 << "Output/"<<riga<<"_Spostamento.dat";
	nomeFile = sstm2.str();
	ofstream myfile2(nomeFile.c_str());
	if(d==2){
		myfile2<<"#X\t\t#Y\t\t#R\t\tdX\t\tdY\t" <<endl; 
		for(int i=0;i<M;i++){ //cout<<"stampo";
			double R= sigma / 2;		//la forza tagliata si annulla a distanza R= 1.12315
			myfile2 << P0_iniziali[i].x()<< "\t " <<P0_iniziali[i].y()<<"\t "<<R<<"\t ";
			myfile2 << (Pdiffusa[i]-P0_iniziali[i]).x()<< "\t " <<(Pdiffusa[i]-P0_iniziali[i]).y()<<endl	;
		}
	}
	if(d==3){
		myfile2<<"#X\t\t#Y\t\t#Z\t\tR\t\t#dX\t\t#dY\t\t#dZ\t" <<endl; 
		for(int i=0;i<M;i++){
			double R= sigma / 2;		
			myfile2 <<P0_iniziali[i].x()<< "\t " <<P0_iniziali[i].y()<<"\t " <<P0_iniziali[i].z()<<"\t "<<R<<"\t ";
			myfile2 <<(Pdiffusa[i]-P0_iniziali[i]).x()<< "\t " <<(Pdiffusa[i]-P0_iniziali[i]).y()<<"\t " <<(Pdiffusa[i]-P0_iniziali[i]).z()<<"\t "<<endl	;
		}
	}
	myfile2.close();
	cout<<"#"<<endl;
}




//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
/*			ANIMAZIONI						*/
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
void sistema_rigido::animazione_completo(int N_snap,double Dt, string riga) // in ingresso una stringa per modificare nome file ingresso
{
	string nomeFile= "Output/"+riga;	
	ofstream myfile(nomeFile.c_str());

	cout<<"#-|| Stampo Animazione del sistema: "<<nomeFile<<" \t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	if(d==2){
		myfile<<"#X\t\t#Y\t\tR" << "\t#Vx\t\t#Vy\t"<<endl; 
		for(int i=0;i<M;i++){ //cout<<"stampo";
			myfile << P0[i].x()<< "\t " <<P0[i].y()<<"\t "<<sigma/2<<"\t ";
			myfile << v0[i].x()<< "\t " <<v0[i].y()<<  endl;			
		}
		for(int k= 0; k<=N_snap; k++){
			evoluzione_muto( Dt);
			cout<<"#--# snap : "<< k <<" / "<<N_snap<<" ... \t \t \t t_esec: "<<tempo_esec()<<" sec" << string(300,'\b');			
			myfile <<endl<<endl;
			for(int i=0;i<M;i++){ //cout<<"stampo";
				myfile << P0[i].x()<< "\t " <<P0[i].y()<<"\t "<<sigma/2<<"\t ";
				myfile << v0[i].x()<< "\t " <<v0[i].y()<<  endl;			
			}
		}
	}

	if(d==3){
		myfile<<"#X\t\t#Y\t\t#Z\t\tR" << "\t#Vx\t\t#Vy\t\t#Vz\t"<<endl; 
		for(int i=0;i<M;i++){ //cout<<"stampo";
			myfile << P0[i].x()<< "\t " <<P0[i].y()<<"\t "<<P0[i].z()<<"\t "<<sigma/2<<"\t ";
			myfile << v0[i].x()<< "\t " <<v0[i].y()<< "\t " <<v0[i].z()<<  endl;			
		}
		for(int k= 0; k<=N_snap; k++){
			evoluzione_muto( Dt);
			cout<<"#--# snap : "<< k <<" / "<<N_snap<<" ... \t \t \t t_esec: "<<tempo_esec()<<" sec" << string(300,'\b');			
			myfile <<endl<<endl;
			for(int i=0;i<M;i++){ //cout<<"stampo";
				myfile << P0[i].x()<< "\t " <<P0[i].y()<<"\t "<<P0[i].z()<<"\t "<<sigma/2<<"\t ";
				myfile << v0[i].x()<< "\t " <<v0[i].y()<< "\t " <<v0[i].z()<<  endl;			
			}
		}
	}
	cout<<"#"<<endl;
	myfile.close();
}

void sistema_rigido::animazione_diffusione(int N_snap,double Dt, string riga) // in ingresso una stringa per modificare nome file ingresso
{
	string nomeFile= "Output/"+riga;	
	ofstream myfile(nomeFile.c_str());
	cout<<"#-|| Stampo Animazione diffusione del sistema: "<<nomeFile<<" \t\t t_esec : "<<tempo_esec()<<" sec"<<endl;
	CollassaDiffusione(); //riporta tutte le immagini diffuse all'interno della scatola

	if(d==2){
		myfile<<"#X\t\t#Y\t\tR" << "\t#Vx\t\t#Vy\t"<<endl; 
		for(int i=0;i<M;i++){ //cout<<"stampo";
			myfile << P0[i].x()<< "\t " <<P0[i].y()<<"\t "<<sigma/2<<"\t ";
			myfile << v0[i].x()<< "\t " <<v0[i].y()<<  endl;			
		}
		for(int k= 0; k<=N_snap; k++){
			evoluzione_muto( Dt);
			cout<<"#--# snap : "<< k <<" / "<<N_snap<<" ... \t \t \t t_esec: "<<tempo_esec()<<" sec" << string(300,'\b');			
			myfile <<endl<<endl;
			for(int i=0;i<M;i++){ //cout<<"stampo";
				myfile << Pdiffusa[i].x()<< "\t " <<Pdiffusa[i].y()<<"\t "<<sigma/2<<"\t ";
				myfile << v0[i].x()<< "\t " <<v0[i].y()<<  endl;			
			}
		}
	}

	if(d==3){
		myfile<<"#X\t\t#Y\t\t#Z\t\tR" << "\t#Vx\t\t#Vy\t\t#Vz\t"<<endl; 
		for(int i=0;i<M;i++){ //cout<<"stampo";
			myfile << P0[i].x()<< "\t " <<P0[i].y()<<"\t "<<P0[i].z()<<"\t "<<sigma/2<<"\t ";
			myfile << v0[i].x()<< "\t " <<v0[i].y()<< "\t " <<v0[i].z()<<  endl;			
		}
		for(int k= 0; k<=N_snap; k++){
			evoluzione_muto( Dt);
			cout<<"#--# snap : "<< k <<" / "<<N_snap<<" ... \t \t \t t_esec: "<<tempo_esec()<<" sec" << string(300,'\b');			
			myfile <<endl<<endl;
			for(int i=0;i<M;i++){ //cout<<"stampo";
				myfile << Pdiffusa[i].x()<< "\t " <<Pdiffusa[i].y()<<"\t "<<Pdiffusa[i].z()<<"\t "<<sigma/2<<"\t ";
				myfile << v0[i].x()<< "\t " <<v0[i].y()<< "\t " <<v0[i].z()<<  endl;			
			}
		}
	}
	cout<<"#"<<endl;
	myfile.close();
}

