//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
/*			VARIABILI DI STATO - OSSERVABILI ISTANTANEE						*/
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

vettore sistema_soffice::Ptot(){	//m=1 quindi velocità totale = momento totale
	vettore vtot(0);
	if(d==2) vtot = vettore(0,0);else if(d==3) vtot = vettore(0,0,0);
	for(int j=0; j<M; j++){ vtot +=v0[j];	}
	return(vtot);
}

double sistema_soffice::Ktot(){ // energia cinetica (per avere la media divido per M)
	double Etot=0;	
	for(int j=0; j<M; j++){ Etot +=Mod(v0[j])*0.5;}
	return(Etot);
}

double sistema_soffice::Utot(){ 
	double Utot=0; 
	for(int i=0;i<(M-1);i++){
		for(int j=NPOINT[i];j<NPOINT[i+1];j++){
			Utot+=u_s( i , LIST[j]);
		}
	}
	return(Utot);
}

vettore sistema_soffice::Ftot(){ 
	vettore Ftot(0);
	if(d==2) Ftot = vettore(0,0);else if(d==3) Ftot = vettore(0,0,0);	
	for(int j=0; j<M; j++){ Ftot +=a0[j];}
	return(Ftot);
}


//T e P intesi come quantita del sistema di particelle associate ad un preciso tempo e stato!
//le quantità T e P "osservabili" sono medie temporali!
double sistema_soffice::kT_stato(){
return(Ktot()*2/(d*M));
}

double sistema_soffice::termP_stato(){	//sarebbe Z-1
	double rF_media=0;
	for(int j=0; j<M; j++){
		rF_media+=a0[j]*P0[j];
		}
	rF_media=rF_media/M;
return(rF_media/(d*kT_stato()));
}



/*
//___________________________________________________________________________________________________________________________
//controllo stato di termalizzazione

*/

double sistema_soffice::H_Boltzman(){			//funzione di boltzman sulle velocità dello stato
	int Ncolonne = M/2; // # numero di colonne con cui costruisco l'istogramma di distribuzione

	double Vx[M];		// vettore dei valori di cui devo costruire la distribuzione
	for(int i = 0; i<M; i++) Vx[i]=v0[i].x();
	double Hx = Boltzman( Ncolonne, Vx, M);

	double Vy[M];		// vettore dei valori di cui devo costruire la distribuzione
	for(int i = 0; i<M; i++) Vy[i]=v0[i].y();
	double Hy = Boltzman( Ncolonne, Vy, M);

	double Hz=0;
	if(d==3){
		double Vz[M];		// vettore dei valori di cui devo costruire la distribuzione
		for(int i = 0; i<M; i++) Vz[i]=v0[i].z();
		Hz = Boltzman( Ncolonne, Vz, M);
	}

//	double H_exp = - sqrt(M_PI*kT()/2);
return((Hx+Hy+Hz)/d);
}

double sistema_soffice::H_Boltzman(int Ncolonne){			//funzione di boltzman sulle velocità dello stato
	double Vx[M];		// vettore dei valori di cui devo costruire la distribuzione
	for(int i = 0; i<M; i++) Vx[i]=v0[i].x();
	double Hx = Boltzman( Ncolonne, Vx, M);

	double Vy[M];		// vettore dei valori di cui devo costruire la distribuzione
	for(int i = 0; i<M; i++) Vy[i]=v0[i].y();
	double Hy = Boltzman( Ncolonne, Vy, M);

	double Hz=0;
	if(d==3){
		double Vz[M];		// vettore dei valori di cui devo costruire la distribuzione
		for(int i = 0; i<M; i++) Vz[i]=v0[i].z();
		Hz = Boltzman( Ncolonne, Vz, M);
	}

//	double H_exp = - sqrt(M_PI*kT()/2);
return((Hx+Hy+Hz)/d);
}

