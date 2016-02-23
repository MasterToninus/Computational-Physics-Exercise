//METODI DI CONTROLLO/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/-
double sistema_rigido::tempo_esec(){
return(((double)(clock()-start))/CLOCKS_PER_SEC);
}

bool sistema_rigido::CheckSovrapposizione(){
	bool check=true;

	stringstream sstm;
	sstm << "Output/LogErrori/ParticelleSovrapposte"<<d<<"D.dat";
	string nomeFile = sstm.str()	;
	grafico_start(nomeFile);

	for(int i=0;i<M;i++)for(int j=i+1;j<M;j++){
		double distanza = distanza_immagini(i,j);
		if(distanza - sigma< -0.000000000001){
			check=false;
			if(d==2){
				grafico_add(nomeFile,5, P0[i].x(),P0[i].y(),sigma/2,v0[i].x(),v0[i].y());
				grafico_add(nomeFile,5, P0[j].x(),P0[j].y(),sigma/2,v0[j].x(),v0[j].y());
			}
			if(d==3){
				grafico_add(nomeFile,7, P0[i].x(),P0[i].y(),P0[i].z(),sigma/2,v0[i].x(),v0[i].y(),v0[i].z());
				grafico_add(nomeFile,7, P0[j].x(),P0[j].y(),P0[j].z(),sigma/2,v0[j].x(),v0[j].y(),v0[j].z());
			}	
			cout<<"errore! particelle compenetrate D= "<<distanza/sigma * 100 <<" \% sigma (guardare log errori)\n \t!!!!!\t TERMINARE ctrl + z \t!!!!! "<<endl;
			}		
	}
	if(check == false)stampa_stato("LogErrori/prova.dat");
return(check);
}


//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
/*			STAMPA POSIZIONI DEL SISTEMA						*/
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
void sistema_rigido::stampa_stato(string riga) // in ingresso una stringa per modificare nome file ingresso
{
	string nomeFile= "Output/"+riga;	
	ofstream myfile(nomeFile.c_str());
	cout<<"#-|| Stampo Stato Completo sistema: "<<nomeFile<<" \t\t\t t_esec : "<<tempo_esec()<<" sec"<<endl<<"#"<<endl;

	if(d==2){
		//plot 'sistemarigido_prova.dat' using 1:2:3 with circles
		//plot 'sistemarigido_prova.dat' using 1:2:4:5 with vectors head filled lt 1
		myfile<<"#X\t\t#Y\t\tR\t" << "\t#Vx\t\t#Vy\t" <<endl; 
		for(int i=0;i<M;i++){ //cout<<"stampo";
			myfile<<P0[i].x()<< "\t " <<P0[i].y()<<"\t " <<sigma/2<<"\t ";
			myfile<<v0[i].x()<<"\t " <<v0[i].y()<<  endl;
		}
	}
	if(d==3){
		//splot 'sistemarigido_prova.dat' using 1:2:3:4:5:6 with vectors head filled lt 2
		myfile<<"#X\t\t#Y\t\t#Z\t" << "\t#Vx\t\t#Vy\t\t#Vz\t" <<endl; 
		for(int i=0;i<M;i++){
			myfile <<P0[i].x()<< "\t " <<P0[i].y()<<"\t " <<P0[i].z()<<"\t ";
			myfile <<v0[i].x()<<"\t " <<v0[i].y()<<"\t "<<v0[i].z()<<"\t " <<  endl;
			}
	}
	myfile.close();
}

void sistema_rigido::stampa_stato_diffusione(string riga) // in ingresso una stringa per modificare nome file ingresso
{
	string nomeFile= "Output/"+riga;	
	ofstream myfile(nomeFile.c_str());
	cout<<"#-|| Stampo Stato Completo sistema: "<<nomeFile<<" \t\t\t t_esec : "<<tempo_esec()<<" sec"<<endl<<"#"<<endl;

	if(d==2){
		//plot 'sistemarigido_prova.dat' using 1:2:3 with circles
		//plot 'sistemarigido_prova.dat' using 1:2:4:5 with vectors head filled lt 1
		myfile<<"#X\t\t#Y\t\tR\t" << "\t#Vx\t\t#Vy\t" <<endl; 
		for(int i=0;i<M;i++){ //cout<<"stampo";
			myfile<<Pdiffusa[i].x()<< "\t " <<Pdiffusa[i].y()<<"\t " <<sigma/2<<"\t ";
			myfile<<v0[i].x()<<"\t " <<v0[i].y()<<  endl;
		}
	}
	if(d==3){
		//splot 'sistemarigido_prova.dat' using 1:2:3:4:5:6 with vectors head filled lt 2
		myfile<<"#X\t\t#Y\t\t#Z\t" << "\t#Vx\t\t#Vy\t\t#Vz\t" <<endl; 
		for(int i=0;i<M;i++){
			myfile <<Pdiffusa[i].x()<< "\t " <<Pdiffusa[i].y()<<"\t " <<Pdiffusa[i].z()<<"\t ";
			myfile <<v0[i].x()<<"\t " <<v0[i].y()<<"\t "<<v0[i].z()<<"\t " <<  endl;
			}
	}
	myfile.close();
}



//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
/*			TAVOLA DI COLLISIONE						*/
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
void sistema_rigido::stampa_tavolacollisioni() // stampa nel terminale
{
	double t_urto= tmax;
	int i_urto, j_urto;

	for(int i=0;i<M;i++){for(int j=0;j<M;j++){
		double t = Tc[i][j];
		if(t<t_urto){t_urto=t; i_urto=i; j_urto=j;}
		if(j<i){printf("      \t");}
		else{if (t> tmax-1)	printf("  x   \t");
			else printf("%2.3f \t",Tc[i][j]);
			}
		}
		cout<<endl;}
	cout<<" t_urto = "<<t_urto<<"\t particelle urtanti i = "<<i_urto<<" j = "<<j_urto<<endl;
}

void sistema_rigido::stampa_tavolacollisioni(string riga) // in ingresso una stringa per modificare nome file ingresso
{
	string nomeFile= "Output/"+riga;
	ofstream myfile(nomeFile.c_str());
	for(int i=0;i<M;i++){for(int j=0;j<M;j++){
		myfile<<Tc[i][j]<<"\t";}
		myfile<<endl;}
	myfile.close();
}

