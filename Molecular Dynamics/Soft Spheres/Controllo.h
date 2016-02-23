//METODI DI CONTROLLO/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/-
double sistema_soffice::tempo_esec(){
return(((double)(clock()-start))/CLOCKS_PER_SEC);
}


//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
/*			STAMPA POSIZIONI DEL SISTEMA						*/
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
void sistema_soffice::stampa_stato_completo(string riga) // in ingresso una stringa per modificare nome file ingresso
{
	string nomeFile= "Output/"+riga;	
	ofstream myfile(nomeFile.c_str());
	cout<<"#-|| Stampo Stato Completo sistema: "<<nomeFile<<" \t\t t_esec : "<<tempo_esec()<<" sec"<<endl<<"#"<<endl;
	myfile<<"#L = "<<L<<endl;

	if(d==2){
		myfile<<"#X\t\t#Y\t\tR\t" << "\t#Vx\t\t#Vy\t" << "\t#Ax\t\t#Ay"<<endl; 
		for(int i=0;i<M;i++){ //cout<<"stampo";
			double R= 1.12315 / 2;		//la forza tagliata si annulla a distanza R= 1.12315
			myfile << P0[i].x()<< "\t " <<P0[i].y()<<"\t "<<R<<"\t ";
			myfile << v0[i].x()<< "\t " <<v0[i].y()<<"\t ";
			myfile << a0[i].x()<< "\t " <<a0[i].y()<<  endl;			
		}
	}

	if(d==3){
		myfile<<"#X\t\t#Y\t\t#Z\t\tR\t" << "\t#Vx\t\t#Vy\t\t#Vz\t" << "\t#Ax\t\t#Ay\t#Az"<<endl; 
		for(int i=0;i<M;i++){
			double R= 1.12315 / 2;		
			myfile <<P0[i].x()<< "\t " <<P0[i].y()<<"\t " <<P0[i].z()<<"\t "<<R<<"\t ";
			myfile <<v0[i].x()<< "\t " <<v0[i].y()<<"\t " <<v0[i].z()<<"\t ";
			myfile <<a0[i].x()<< "\t " <<a0[i].y()<<"\t " <<a0[i].z()<<  endl;
		}
	}
	myfile.close();
}

void sistema_soffice::stampa_stato_diffusione(string riga) // in ingresso una stringa per modificare nome file ingresso
{
	string nomeFile= "Output/"+riga;	
	ofstream myfile(nomeFile.c_str());
	cout<<"#-|| Stampo Stato Diffusione del sistema: "<<nomeFile<<" \t\t t_esec : "<<tempo_esec()<<" sec"<<endl<<"#"<<endl;
	myfile<<"#L = "<<L<<endl;

	if(d==2){
		myfile<<"#X\t\t#Y\t\tR\t" << "\t#Vx\t\t#Vy\t" << "\t#Ax\t\t#Ay"<<endl; 
		for(int i=0;i<M;i++){ //cout<<"stampo";
			double R= 1.12315 / 2;		//la forza tagliata si annulla a distanza R= 1.12315
			myfile << Pdiffusa[i].x()<< "\t " <<Pdiffusa[i].y()<<"\t "<<R<<"\t ";
			myfile << v0[i].x()<< "\t " <<v0[i].y()<<"\t ";
			myfile << a0[i].x()<< "\t " <<a0[i].y()<<  endl;			
		}
	}

	if(d==3){
		myfile<<"#X\t\t#Y\t\t#Z\t" << "\t#Vx\t\t#Vy\t\t#Vz\t" << "\t#Ax\t\t#Ay\t#Az"<<endl; 
		for(int i=0;i<M;i++){
			double R= 1.12315 / 2;		
			myfile <<Pdiffusa[i].x()<< "\t " <<Pdiffusa[i].y()<<"\t " <<Pdiffusa[i].z()<<"\t "<<R<<"\t ";
			myfile <<v0[i].x()<< "\t " <<v0[i].y()<<"\t " <<v0[i].z()<<"\t ";
			myfile <<a0[i].x()<< "\t " <<a0[i].y()<<"\t " <<a0[i].z()<<  endl;
		}
	}
	myfile.close();
}



//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
/*			LISTA DEi VICINI						*/
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
void sistema_soffice::stampa_vicini() // stampa nel terminale
{
	cout<<"#-|| Stampo lista vicini \t t_esecuzione : "<<tempo_esec()<<" sec"<<endl<<"#"<<endl;

	for(int i=0;i<M-1;i++){
		cout<<"particella "<<i<<" ha "<<NPOINT[i+1]-NPOINT[i]<<" vicini i cui indici sono:"<<endl;
		for(int j=NPOINT[i];j<NPOINT[i+1];j++){
			cout<<LIST[j]<<"\t";
		}
		cout<<endl<<endl;}
}

void sistema_soffice::stampa_vicini(string riga) // in ingresso una stringa per modificare nome file ingresso
{
	string nomeFile= "Output/"+riga;
	ofstream myfile(nomeFile.c_str());
	cout<<"#-|| Stampo ListaVicini: "<<nomeFile<<" \t\t t_esec : "<<tempo_esec()<<" sec"<<endl<<"#"<<endl;

	for(int i=0;i<M-1;i++){
		myfile<<"Particella "<<i<<" ha "<<NPOINT[i+1]-NPOINT[i]<<" vicini i cui indici sono:"<<endl;
		for(int j=NPOINT[i];j<NPOINT[i+1];j++){
			myfile<<LIST[j]<<"\t";
		}
		myfile<<endl<<endl;}
	myfile.close();
}

void sistema_soffice::stampa_potenziali(string riga) // in ingresso una stringa per modificare nome file ingresso
{
	string nomeFile= "Output/"+riga;
	ofstream myfile(nomeFile.c_str());

	for(int i=0;i<M-1;i++)		for(int j=NPOINT[i] ;j<NPOINT[i+j];j++){
			double Pot=u_s( i, LIST[j]);
			myfile<<"u( "<<i<<" , "<<j<<" ) = "<<Pot<<endl;
	}
	myfile.close();
}

