//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
/*			CONTROLLO CONSERVAZIONE (al centro della scatola)						*/
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

void sistema_soffice::evoluzione_Check(int Npassi) 	//Evoluzione per Npassi urti mostrando per ogni urto le variabili dinamiche di momento totale, energia totale e temperatura, dovrebbero essere conservate!
{
	cout<<"#-@ Inizio evoluzione Controllata pei "<<Npassi<<" step( "<<Npassi*t_step <<" [t]) \t\t\t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	for(int i=0; i<Npassi;i++){ 
		vettore MomentoTotale = Ptot();
		double EnergiaTotale = Utot() + Ktot();
		vettore ForzaTotale = Ftot();
		//printf("#-@ step = %6d \t Px =  %1.3f \t Fx =  %1.3f \t Etot = %1.3f \t kT = %1.3f \t t_esec : %1.3f sec", i, MomentoTotale.x(), ForzaTotale.x(), EnergiaTotale,kT_stato(), tempo_esec());
		if(d==2)printf("#-@ step = %6d \t Ptot = ( %1.1f , %1.1f ) Ftot = ( %1.1f , %1.1f ) \t Etot = %1.2f   kT = %1.2f  t_esec : %1.2f sec", i, MomentoTotale.x(), MomentoTotale.y(), ForzaTotale.x(), ForzaTotale.y(),  EnergiaTotale,kT_stato(), tempo_esec());
		else if(d==3)printf("#-@ step = %6d \t Ptot = ( %1.1f , %1.1f , %1.1f ) Ftot = ( %1.1f , %1.1f , %1.1f ) \t Etot = %1.2f   kT = %1.2f  t_esec : %1.2f sec", i, MomentoTotale.x(), MomentoTotale.y(), MomentoTotale.z(), ForzaTotale.x(), ForzaTotale.y(), ForzaTotale.z(), EnergiaTotale,kT_stato(), tempo_esec());
		cout << string(600,'\b');

		double FT=mod(Ftot());
		if(FT!=FT){cout<<"errore! c'è un nan"<<endl;	
			stampa_stato_completo("Output/LogErrori/statoerrore.dat");	
			stampa_vicini("Output/LogErrori/vicinierrore.dat");
			break;break;break;
		}
		if((i+1)%10==0)	CostruzioneListaVicini();
		evoluzione();
	}
	CostruzioneListaVicini();
	cout<<endl<<"#"<<endl;
}




//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
/*			TRAIETTORIE DELLA PARTICELLA DI TEST (al centro della scatola)						*/
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

//   (ALGORITMI DI EVOLUZIONE A NPASSI FISSATO)
void sistema_soffice::evoluzione_conmoto(int Npassi,string riga){
	int i_studio ;
	for( int i=0; i< M ; i++){
		if(d == 2 && P0[i].x()<L*0.6 && P0[i].x()>L*0.4 && P0[i].y()<L*0.6 && P0[i].x()>L*0.4)i_studio=i;
		if(d == 3 && P0[i].x()<L*0.6 && P0[i].x()>L*0.4 && P0[i].y()<L*0.6 && P0[i].x()>L*0.4&& P0[i].z()<L*0.6 && P0[i].z()>L*0.4)i_studio=i;
	}

	string nomeFile= "Output/"+riga;	
	ofstream myfile(nomeFile.c_str());
	cout<<"#-@ Inizio Calcolo traiettoria della particella P[" <<i_studio<<"] per "<<Npassi<<" step \t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	myfile<<"# Dimensione lato L = "<<L<<endl;
	if(d==2)myfile<<P0[i_studio].x()<< "\t " <<P0[i_studio].y()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<  endl;
	if(d==3)myfile<<P0[i_studio].x()<< "\t " <<P0[i_studio].y()<<"\t "<<P0[i_studio].z()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<"\t " <<v0[i_studio].z()<<  endl;

	for(int i=0;i< Npassi; i++){
		if((i+1)%10==0){
			printf("#-@ \t step %3d / %3d \t\t (t= %1.1f [t]) \t\t\t\t t_esec : %1.3f sec",i,Npassi,t_step*i,tempo_esec());
			cout << string(300,'\b');
			CostruzioneListaVicini();//cout<<"dopo dieci passo aggiorno la lista vicini"<<endl;
		}
		evoluzione();
		if(d==2)myfile<<P0[i_studio].x()<< "\t " <<P0[i_studio].y()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<  endl;
		if(d==3)myfile<<P0[i_studio].x()<< "\t " <<P0[i_studio].y()<<"\t "<<P0[i_studio].z()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<"\t " <<v0[i_studio].z()<<  endl;
	}
	myfile.close();
	cout<<endl<<"#"<<endl;
	CostruzioneListaVicini();
}

void sistema_soffice::evoluzione_condiffusione(int Npassi,string riga) 	//Evoluzione per Npassi urti ,stampa la diffusione compiuta da una particella nel mezzo della scatola (il suo moto senza applicare il bordo periodico)
{
	int i_studio ;
	for( int i=0; i< M ; i++){
		if(d == 2 && P0[i].x()<L*0.6 && P0[i].x()>L*0.4 && P0[i].y()<L*0.6 && P0[i].x()>L*0.4)i_studio=i;
		if(d == 3 && P0[i].x()<L*0.6 && P0[i].x()>L*0.4 && P0[i].y()<L*0.6 && P0[i].x()>L*0.4&& P0[i].z()<L*0.6 && P0[i].z()>L*0.4)i_studio=i;
	}
	CollassaDiffusione(); //riporta tutte le immagini diffuse all'interno della scatola

	string nomeFile= "Output/"+riga;	
	ofstream myfile(nomeFile.c_str());
	cout<<"#-@ Inizio Calcolo traiettoria di Diffusione della particella P[" <<i_studio<<"] per "<<Npassi<<" step \t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	myfile<<"# Dimensione lato L = "<<L<<endl;
	if(d==2)myfile<<P0[i_studio].x()<< "\t " <<P0[i_studio].y()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<  endl;
	if(d==3)myfile<<P0[i_studio].x()<< "\t " <<P0[i_studio].y()<<"\t "<<P0[i_studio].z()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<"\t " <<v0[i_studio].z()<<  endl;

	for(int i=0;i< Npassi; i++){
		if((i+1)%10==0){
			printf("#-@ \t step %3d / %3d \t\t (t= %1.1f [t]) \t\t\t\t t_esec : %1.3f sec",i,Npassi,t_step*i,tempo_esec());
			cout << string(300,'\b');
			CostruzioneListaVicini();//cout<<"dopo dieci passo aggiorno la lista vicini"<<endl;
		}
		evoluzione();
		if(d==2)myfile<<Pdiffusa[i_studio].x()<< "\t " <<Pdiffusa[i_studio].y()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<  endl;
		if(d==3)myfile<<Pdiffusa[i_studio].x()<< "\t " <<Pdiffusa[i_studio].y()<<"\t "<<Pdiffusa[i_studio].z()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<"\t " <<v0[i_studio].z()<<  endl;
	}
	myfile.close();
	cout<<endl<<"#"<<endl;
	CostruzioneListaVicini();

}

//	(ALGORITMI DI EVOLUZIONE AD INTERVALLO DI TEMPO FISSATO)

void sistema_soffice::evoluzione_conmoto(double Dt,string riga){
	int i_studio ;
	for( int i=0; i< M ; i++){
		if(d == 2 && P0[i].x()<L*0.6 && P0[i].x()>L*0.4 && P0[i].y()<L*0.6 && P0[i].x()>L*0.4)i_studio=i;
		if(d == 3 && P0[i].x()<L*0.6 && P0[i].x()>L*0.4 && P0[i].y()<L*0.6 && P0[i].x()>L*0.4&& P0[i].z()<L*0.6 && P0[i].z()>L*0.4)i_studio=i;
	}

	string nomeFile= "Output/"+riga;	
	ofstream myfile(nomeFile.c_str());
	cout<<"#-@ Inizio Calcolo traiettoria della particella P[" <<i_studio<<"] per "<<Dt<<" [t] \t\t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	myfile<<"# Dimensione lato L = "<<L<<endl;
	if(d==2)myfile<<P0[i_studio].x()<< "\t " <<P0[i_studio].y()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<  endl;
	if(d==3)myfile<<P0[i_studio].x()<< "\t " <<P0[i_studio].y()<<"\t "<<P0[i_studio].z()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<"\t " <<v0[i_studio].z()<<  endl;

	int Npassi=0;	
	while (Npassi*t_step < Dt)
	{
		if((Npassi+1)% 10 ==0){
		printf("#-@ \t tempo %1.1f [t] su %1.1f [t] \t (step= %d) \t \t\t\t t_esec : %1.3f sec",Npassi*t_step,Dt,Npassi,tempo_esec());
		cout << string(300,'\b');
		CostruzioneListaVicini();			//AGGIORNAMENTO DELLA LISTA VICINI OGNI 10 PASSI
		}
		evoluzione();	
		if(d==2)myfile<<P0[i_studio].x()<< "\t " <<P0[i_studio].y()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<  endl;
		if(d==3)myfile<<P0[i_studio].x()<< "\t " <<P0[i_studio].y()<<"\t "<<P0[i_studio].z()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<"\t " <<v0[i_studio].z()<<  endl;
		Npassi++;
	}
	myfile.close();
	CostruzioneListaVicini();
	cout<<endl<<"#"<<endl;
}

void sistema_soffice::evoluzione_condiffusione(double Dt,string riga){
	int i_studio ;
	for( int i=0; i< M ; i++){
		if(d == 2 && P0[i].x()<L*0.6 && P0[i].x()>L*0.4 && P0[i].y()<L*0.6 && P0[i].x()>L*0.4)i_studio=i;
		if(d == 3 && P0[i].x()<L*0.6 && P0[i].x()>L*0.4 && P0[i].y()<L*0.6 && P0[i].x()>L*0.4&& P0[i].z()<L*0.6 && P0[i].z()>L*0.4)i_studio=i;
	}
	CollassaDiffusione(); //riporta tutte le immagini diffuse all'interno della scatola

	string nomeFile= "Output/"+riga;	
	ofstream myfile(nomeFile.c_str());
	cout<<"#-@ Inizio Calcolo traiettoria della particella P[" <<i_studio<<"] per "<<Dt<<" [t] \t\t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	myfile<<"# Dimensione lato L = "<<L<<endl;
	if(d==2)myfile<<P0[i_studio].x()<< "\t " <<P0[i_studio].y()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<  endl;
	if(d==3)myfile<<P0[i_studio].x()<< "\t " <<P0[i_studio].y()<<"\t "<<P0[i_studio].z()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<"\t " <<v0[i_studio].z()<<  endl;

	int Npassi=0;	
	while (Npassi*t_step < Dt)
	{
		if((Npassi+1)% 10 ==0){
		printf("#-@ \t tempo %1.1f [t] su %1.1f [t] \t (step= %d) \t \t\t\t t_esec : %1.3f sec",Npassi*t_step,Dt,Npassi,tempo_esec());
		cout << string(300,'\b');
		CostruzioneListaVicini();			//AGGIORNAMENTO DELLA LISTA VICINI OGNI 10 PASSI
		}
		evoluzione();	
		if(d==2)myfile<<Pdiffusa[i_studio].x()<< "\t " <<Pdiffusa[i_studio].y()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<  endl;
		if(d==3)myfile<<Pdiffusa[i_studio].x()<< "\t " <<Pdiffusa[i_studio].y()<<"\t "<<Pdiffusa[i_studio].z()<<"\t " <<v0[i_studio].x()<<"\t " <<v0[i_studio].y()<<"\t " <<v0[i_studio].z()<<  endl;
		Npassi++;
	}
	myfile.close();
	CostruzioneListaVicini();
	cout<<endl<<"#"<<endl;
}




//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
/*			SNAPSHOT DIFFUSIONE						*/
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
//   (ALGORITMI DI EVOLUZIONE A NPASSI FISSAT
void sistema_soffice::stampa_Diffusione(int Npassi,string riga){
	cout<<"#-|| Stampo Istantanea di Diffusione del sistema: "<<riga<<" \t\t t_esec : "<<tempo_esec()<<" sec"<<endl;

	CollassaDiffusione(); //riporta tutte le immagini diffuse all'interno della scatola
	vector<vettore> P0_iniziali(M,0); 	 //vector delle posizioni delle particelle		 (considerando le condizioni al bordo
	for(int j=0; j<	M; j++)		P0_iniziali[j]  = Pdiffusa[j];

	stringstream sstm0;
	sstm0 <<riga<<"_Inizio.dat";
	string nomeFile = sstm0.str()	;

	stampa_stato_diffusione(nomeFile);
	evoluzione( Npassi);

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
void sistema_soffice::stampa_Diffusione(double Dt,string riga){
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
void sistema_soffice::animazione_completo(int N_snap, string riga) // in ingresso una stringa per modificare nome file ingresso
{
	string nomeFile= "Output/"+riga;	
	ofstream myfile(nomeFile.c_str());
	cout<<"#-|| Stampo Animazione del sistema: "<<nomeFile<<" \t\t t_esec : "<<tempo_esec()<<" sec"<<endl<<"#"<<endl;

	if(d==3){
		myfile<<"#L = "<<L<<endl;
		for(int j=0; j<N_snap; j++){
			cout<<"#--# Istante "<<j+1<<" ... \t \t \t t_esec: "<<tempo_esec()<<" sec" << string(300,'\b');
			myfile<<"#X\t\t#Y\t\t#Z\tR" << "\t#Vx\t\t#Vy\t\t#Vz\t" << "\t#Ax\t\t#Ay\t#Az\t"<<endl; 
			for(int i=0;i<M;i++){ //cout<<"stampo";
				double R= 1.1235 / 2; //distanza in cui la forza tagliata si annulla diviso 2!
				myfile <<P0[i].x()<< "\t " <<P0[i].y()<<"\t " <<P0[i].z()<<"\t "<<R<<"\t ";
				myfile <<v0[i].x()<< "\t " <<v0[i].y()<<"\t " <<v0[i].z()<<"\t ";
				myfile <<a0[i].x()<< "\t " <<a0[i].y()<<"\t " <<a0[i].z()<<  endl;		
			}
		if((j + 1 )%10 ==0)	CostruzioneListaVicini();			//AGGIORNAMENTO DELLA LISTA VICINI OGNI 10 PASSI
		evoluzione();
		myfile <<endl<<endl;
		CostruzioneListaVicini();
		}	
	}

	if(d==2){
		myfile<<"#L = "<<L<<endl;
		for(int j=0; j<N_snap; j++){
			cout<<"#--# Istante "<<j+1<<" ... \t \t \t t_esec: "<<tempo_esec()<<" sec" << string(300,'\b');
			myfile<<"#X\t\t#Y\t\tR" << "\t#Vx\t\t#Vy\t" << "\t#Ax\t\t#Ay"<<endl; 
			for(int i=0;i<M;i++){ //cout<<"stampo";
				double R= 1.1235 / 2; //distanza in cui la forza tagliata si annulla diviso 2!	
				myfile << P0[i].x()<< "\t " <<P0[i].y()<<"\t "<<R<<"\t ";
				myfile << v0[i].x()<< "\t " <<v0[i].y()<<"\t ";
				myfile << a0[i].x()<< "\t " <<a0[i].y()<<  endl;			
			}
		if((j + 1 )%10 ==0)	CostruzioneListaVicini();			//AGGIORNAMENTO DELLA LISTA VICINI OGNI 10 PASSI
		evoluzione();
		myfile <<endl<<endl;
		CostruzioneListaVicini();
		}
	}
	myfile.close();
}

void sistema_soffice::animazione_diffusione(int N_snap, string riga) // in ingresso una stringa per modificare nome file ingresso
{
	string nomeFile= "Output/"+riga;	
	ofstream myfile(nomeFile.c_str());
	cout<<"#-|| Stampo Animazione del sistema: "<<nomeFile<<" \t\t t_esec : "<<tempo_esec()<<" sec"<<endl<<"#"<<endl;

	if(d==3){
		myfile<<"#L = "<<L<<endl;
		for(int j=0; j<N_snap; j++){
			cout<<"#--# Istante "<<j+1<<" ... \t \t \t t_esec: "<<tempo_esec()<<" sec" << string(300,'\b');
			myfile<<"#X\t\t#Y\t\t#Z\tR" << "\t#Vx\t\t#Vy\t\t#Vz\t" << "\t#Ax\t\t#Ay\t#Az\t"<<endl; 
			for(int i=0;i<M;i++){ //cout<<"stampo";
				double R= 1.1235 / 2; //distanza in cui la forza tagliata si annulla diviso 2!
				myfile <<Pdiffusa[i].x()<< "\t " <<Pdiffusa[i].y()<<"\t " <<Pdiffusa[i].z()<<"\t "<<R<<"\t ";
				myfile <<v0[i].x()<< "\t " <<v0[i].y()<<"\t " <<v0[i].z()<<"\t ";
				myfile <<a0[i].x()<< "\t " <<a0[i].y()<<"\t " <<a0[i].z()<<  endl;		
			}
		if((j + 1 )%10 ==0)	CostruzioneListaVicini();			//AGGIORNAMENTO DELLA LISTA VICINI OGNI 10 PASSI
		evoluzione();
		myfile <<endl<<endl;
		CostruzioneListaVicini();
		}	
	}


	if(d==2){
		myfile<<"#L = "<<L<<endl;
		for(int j=0; j<N_snap; j++){
			cout<<"#--# Istante "<<j+1<<" ... \t \t \t t_esec: "<<tempo_esec()<<" sec" << string(300,'\b');
			myfile<<"#X\t\t#Y\t\tR" << "\t#Vx\t\t#Vy\t" << "\t#Ax\t\t#Ay"<<endl; 
			for(int i=0;i<M;i++){ //cout<<"stampo";
				double R= 1.1235 / 2; //distanza in cui la forza tagliata si annulla diviso 2!		
				myfile << Pdiffusa[i].x()<< "\t " <<Pdiffusa[i].y()<<"\t "<<R<<"\t ";
				myfile << v0[i].x()<< "\t " <<v0[i].y()<<"\t ";
				myfile << a0[i].x()<< "\t " <<a0[i].y()<<  endl;			
			}
		if((j + 1 )%10 ==0)	CostruzioneListaVicini();			//AGGIORNAMENTO DELLA LISTA VICINI OGNI 10 PASSI
		evoluzione();
		myfile <<endl<<endl;
		CostruzioneListaVicini();
		}
	}
	myfile.close();
}
