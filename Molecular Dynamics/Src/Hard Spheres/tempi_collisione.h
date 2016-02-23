//           Funzioni che danno il tempo di collisione tra 2 particelle (coppia vettore P vettore V
			// è poco efficiente passare tipo personalizzato ma il codice è più leggibile
#define tmax 99999999.
//funzione che dato vettore posizione e vett velocità di coppia di parti da il tc
double tempo_collisione(vettore R1, vettore R2, vettore V1, vettore V2, double sigma){
	vettore dR = R1 - R2;//vettore separazione tra 2 particelle ij
	vettore dV= V1 - V2;//vettore velocità relativa tra 2 particelle ij	

	double Tc;//variabile tempo di collisione
	double dRdV = dR*dV;//cout<<dRdV<<" ";
	double delta = dRdV*dRdV - Mod(dV) *(Mod(dR) - sigma*sigma);
	if(delta>=0 && dRdV<0) Tc = -(dRdV + sqrt(delta)) /Mod(dV); 
	else if(Mod(dV)==0) Tc=tmax;
	else Tc=tmax;

	return(Tc);
}

double tempo_collisione_COMMENTATO(vettore R1, vettore R2, vettore V1, vettore V2, double sigma){
	vettore dR = R1 - R2;//vettore separazione tra 2 particelle ij
	vettore dV= V1 - V2;//vettore velocità relativa tra 2 particelle ij	

	double Tc;//variabile tempo di collisione
	double dRdV = dR*dV;//cout<<dRdV<<" ";
	double delta = dRdV*dRdV - Mod(dV) *(Mod(dR) - sigma*sigma);
	if(delta>=0 && dRdV<0) Tc = -(dRdV + sqrt(delta)) /Mod(dV); 
	else if(Mod(dV)==0) Tc=tmax;
	else Tc=tmax;

/*///*///	stringstream sstm;
/*///*///	sstm << "Output/LogErrori/ParticelleSovrapposte"<<R1.size()<<"D.dat";
/*///*///	string nomeFile = sstm.str();
/*///*///		if(Tc<=0){
/*///*///			cout<<"\n ERRORE TC <=0. A cosa è dovuto?"<<endl;
/*///*///			cout<<"(R1-R2)x(V1-V2) = "<<dRdV<<"\t (se le particelle sono adiacenti questo non può essere maggiore di 0!)"<<endl;
/*///*///			cout<<"|R1-R2|^2 - sigma^2 = "<<Mod(dR) - sigma*sigma<<"\t ( le particelle sono sovrapposte ?)"<<endl;
/*///*///			cout<<"L'errore lo sta dando una particella immagine? R2 = ";
/*///*///				if(R1.size()==2){
/*///*///					cout<<"( "<<R2.x()<<" , "<<R2.y()<<" );"<<endl;
/*///*///					grafico_add(nomeFile,5, R1.x(),R1.y(),sigma/2,V1.x(),V1.y());
/*///*///					grafico_add(nomeFile,5, R2.x(),R2.y(),sigma/2,V2.x(),V2.y());
/*///*///				}
/*///*///				if(R1.size()==3){
/*///*///					cout<<"( "<<R2.x()<<" , "<<R2.y()<<" , "<<R2.z()<<" );"<<endl;
/*///*///					grafico_add(nomeFile,7, R1.x(),R1.y(),R1.z(),sigma/2,V1.x(),V1.y(),V1.z());
/*///*///					grafico_add(nomeFile,7, R2.x(),R2.y(),R2.z(),sigma/2,V2.x(),V2.y(),V2.z());
/*///*///				}	
/*///*///			} 
/*///*///	if(mod(dR)!=0 && mod(dR)-sigma<-0.00000000000001){
/*///*///		cout<<"c'è un probleblema le due particelle sono a distanza minore di sigma (D - sigma )= "<<mod(dR)-sigma<<endl;
/*///*///			stringstream sstm;
/*///*///			sstm << "Output/Test/ParticelleSovrapposte.dat";
/*///*///			string nomeFile = sstm.str()	;
/*///*///			if(R1.size()==2){
/*///*///				grafico_add(nomeFile,5, R1.x(),R1.y(),sigma/2,V1.x(),V1.y());
/*///*///				grafico_add(nomeFile,5, R2.x(),R2.y(),sigma/2,V2.x(),V2.y());
/*///*///			}
/*///*///			if(R1.size()==3){
/*///*///				grafico_add(nomeFile,7, R1.x(),R1.y(),R1.z(),sigma/2,V1.x(),V1.y(),V1.z());
/*///*///				grafico_add(nomeFile,7, R2.x(),R2.y(),R2.z(),sigma/2,V2.x(),V2.y(),V2.z());
/*///*///			}	
/*///*///	}

	return(Tc);
}

