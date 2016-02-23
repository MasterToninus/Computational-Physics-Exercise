//METODI DI CONTROLLO/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/-



void microstato::stampa_stato(string riga) // in ingresso una stringa per modificare nome file ingresso
{
	string nomeFile= "Output/"+riga;
	ofstream myfile(nomeFile.c_str());
	end=clock(); 	tempo=((double)(end-start))/CLOCKS_PER_SEC;
	cout<<"#- Stampo stato: "<<nomeFile<<" \t t_esecuzione: "<<tempo<<" secondi"<<endl<<"#-"<<endl;

	//load 'StampaIsing.p'
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){ //cout<<"stampo";
			myfile<<i<< "\t" <<j<< "\t" <<StatoSpin[i][j] <<  endl;
			myfile<<i<< "\t" <<j+1 <<"\t" <<StatoSpin[i][j] <<  endl;
		}
		myfile<<  endl;
		for(int j=0;j<N;j++){ //cout<<"stampo";
			myfile<<i+1<< "\t" <<j <<"\t" <<StatoSpin[i][j] <<  endl;
			myfile<<i+1<< "\t" <<j+1 <<"\t" <<StatoSpin[i][j] <<  endl;
		}
		myfile<<  endl;
	} 
	myfile.close();
}

void microstato::stampa_stato() 
{
	for(int i=N-1;i>=0;i--){for(int j=0;j<N;j++){
			cout<<"\t"<<StatoSpin[i][j];}cout<<  endl;}
}

void microstato::animazione_SwenWang(string riga, int istanti, double beta) // in ingresso una stringa per modificare nome file ingresso
{
	string nomeFile= "Output/"+riga;
	ofstream myfile(nomeFile.c_str());
	end=clock(); 	tempo=((double)(end-start))/CLOCKS_PER_SEC;
	cout<<"#- Stampo Animazione SwenWang: "<<nomeFile<<" a beta = "<<beta <<" \t t_esecuzione: "<<tempo<<" sec"<<endl<<"#-"<<endl;

	for(int k=0;k<istanti;k++){
		end=clock(); 	tempo=((double)(end-start))/CLOCKS_PER_SEC;
		cout<<"#--# Istante "<<k+1<<" ... \t \t \t t_esec: "<<tempo<<" sec" << string(300,'\b');
		//myfile<<"# index " <<k<<  endl;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){ //cout<<"stampo";
				myfile<<i<< "\t" <<j<< "\t" <<StatoSpin[i][j] <<  endl;
				myfile<<i<< "\t" <<j+1 <<"\t" <<StatoSpin[i][j] <<  endl;
			}
			myfile<<  endl;
			for(int j=0;j<N;j++){ //cout<<"stampo";
				myfile<<i+1<< "\t" <<j <<"\t" <<StatoSpin[i][j] <<  endl;
				myfile<<i+1<< "\t" <<j+1 <<"\t" <<StatoSpin[i][j] <<  endl;
			}
			myfile<<  endl;
		} 
		step_SwenWang(beta);
		myfile<<   endl;

	}
	myfile.close();
	cout<<endl;
}

void microstato::animazione_Metro(string riga, int istanti, double beta) // in ingresso una stringa per modificare nome file ingresso
{
	string nomeFile= "Output/"+riga;
	ofstream myfile(nomeFile.c_str());
	end=clock(); 	tempo=((double)(end-start))/CLOCKS_PER_SEC;
	cout<<"#- Stampo Animazione Metro : "<<nomeFile<<" a beta = "<<beta <<" \t t_esecuzione: "<<tempo<<" sec"<<endl<<"#-"<<endl;

	for(int k=0;k<istanti;k++){
		end=clock(); 	tempo=((double)(end-start))/CLOCKS_PER_SEC;
		cout<<"#--# Istante "<<k+1<<" ... \t \t \t t_esec: "<<tempo<<" sec" << string(300,'\b');
		//myfile<<"# index " <<k<<  endl;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){ //cout<<"stampo";
				myfile<<i<< "\t" <<j<< "\t" <<StatoSpin[i][j] <<  endl;
				myfile<<i<< "\t" <<j+1 <<"\t" <<StatoSpin[i][j] <<  endl;
			}
			myfile<<  endl;
			for(int j=0;j<N;j++){ //cout<<"stampo";
				myfile<<i+1<< "\t" <<j <<"\t" <<StatoSpin[i][j] <<  endl;
				myfile<<i+1<< "\t" <<j+1 <<"\t" <<StatoSpin[i][j] <<  endl;
			}
			myfile<<  endl;
		} 
		step_montecarlo( N*N, beta);
		myfile<<   endl;

	}
	myfile.close();
	cout<<endl;
}

