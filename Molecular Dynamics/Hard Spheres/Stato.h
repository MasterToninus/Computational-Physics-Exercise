//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
/*			VARIABILI DI STATO - OSSERVABILI ISTANTANEE						*/
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

vettore sistema_rigido::MomentoTotale(){	//m=1 quindi velocità totale = momento totale
	vettore vtot(0);
	if(d==2) vtot = vettore(0,0);else if(d==3) vtot = vettore(0,0,0);
	for(int j=0; j<M; j++){ vtot +=v0[j];	}
	return(vtot);
}

double sistema_rigido::EnergiaTotale(){ // la sola energia è quella cinetica
	double Etot=0;	
	for(int j=0; j<M; j++){ Etot +=Mod(v0[j])/2;}
	return(Etot);
}

double sistema_rigido::kT(){ // Temperatura= energia media/ ecc
	return((EnergiaTotale()/M)*2/d);
}

double sistema_rigido::H_Boltzman(){			//funzione di boltzman sulle velocità dello stato
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

double sistema_rigido::H_Boltzman(int Ncolonne){			//funzione di boltzman sulle velocità dello stato
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




