//METROPOLIS

void microstato::step_metropolis(int i, int j,double beta){	//http://cs.adelaide.edu.au/~paulc/teaching/montecarlo/node29.html
	double Enod=E_nodo(i,j);
	if (Enod>=0) flip(i,j);//in questo caso l'energia dello stato flippato e minore di quello old
	else{
		double random=(double)rand()/RAND_MAX;
		if(random<= exp(2*Enod*beta))flip(i,j);
	}
}

void microstato::step_montecarlo(int Num,double beta){	
	for(int n=0; n<Num; n++){ //faccio test di proposta tante volte quanti sono i nodi
			step_metropolis( Intrand(N), Intrand(N), beta); //scelgo random nodo da flippare
	}
}

void microstato::step_montecarlo(double beta){
	for(int i=0; i<N; i++){for(int j=0; j<N; j++){//faccio un test di proposta per ogni nodo del reticolo
		step_metropolis( i, j, beta);
	}}	
}

void microstato::evol_montecarlo(double beta, int M){
	printf("##--- Ciclo di %d evoluzioni con Metropolis con beta = %f \n",M,beta);
	for( int i=0; i<M; i++){
		step_montecarlo(beta);
		end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
		cout<<"##--# "<<i+1<<"-sima evoluzione \t \t t_esec: "<<tempo<<" sec" << string(300,'\b');
	}
	cout<<endl;
}

