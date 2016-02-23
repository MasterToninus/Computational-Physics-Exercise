//SWENDSEN-WANG  http://www.hpjava.org/theses/shko/thesis_paper/node69.html

// ricordare i= indice di riga, j= di colonna  quindi se testo a destra i=fisso e j++1

int microstato::testbond_up(int i, int j,double beta){ // queste funzioni test potrei farle con bool invece di int e ritorna true o false
	int test=0;
	int i_up=i+1;
	if(i_up==N)i_up=0;//condizione di bordo periodico
	
	if(StatoSpin[i][j]==StatoSpin[i_up][j]){
	double random=(double)rand()/RAND_MAX;
		if(random< 1-exp(-2*beta))test=1;
	//test=1; //collego tutti quelli con stesso spin per prova (beta=inf T=0)
	}
	return(test);
}
int microstato::testbond_dx(int i, int j,double beta){
	int test=0;
	int j_dx=j+1;
	if(j_dx == N)j_dx=0;//condizione di bordo periodico	

	if(StatoSpin[i][j]==StatoSpin[i][j_dx]){
	double random=(double)rand()/RAND_MAX;
		if(random< 1-exp(-2*beta))test=1;
	//test=1; //collego tutti quelli con stesso spin per prova (beta=inf T=0)
	}
	return(test);
}


void microstato::step_SwenWang(double beta){	
	int *Mat[N][N];
	int label[N_nodi];
	for(int i=0; i<N; i++){for(int j=0; j<N; j++){ 
		label[N*i+j]=N*i+j;
		Mat[i][j]=&label[N*i+j];
	}}
	vector<int> labeleff;				
	for(int i=0; i<N_nodi; i++)labeleff.push_back(i); 

//comincio il ciclo dei bond attivati orizzontali
	for(int k=0; k<N; k++){for(int l=0; l<N; l++){
		int l_dx=l+1;
		if(l_dx==N)l_dx=0; 
		if(testbond_dx( k, l, beta)==1){	
			int* labellosalvato= Mat[k][l_dx]; 
			Mat[k][l_dx]=Mat[k][l];	

			if(Mat[k][l]!=labellosalvato){ 
				for(int m=0; m<N; m++){for(int n=0; n<N; n++){ //questo doppio ciclo rende il programma brutto!
					if(Mat[m][n]==labellosalvato){
						Mat[m][n]=Mat[k][l];
					}
				}}
				for(int i=0; i<labeleff.size(); i++){ 		//anche questo ciclo è brutto, deve controllare sequenziamente tutto
					if(labeleff[i]== *labellosalvato){	
						labeleff.erase (labeleff.begin()+i);
						break;								
					}
				}
			}
		}
	}}

//comincio il ciclo dei bond attivati verticale
	for(int k=0; k<N; k++){for(int l=0; l<N; l++){
		int k_up=k+1;
		if(k_up==N)k_up=0; 
		if(testbond_up( k, l, beta)==1){	
			int *labellosalvato= Mat[k_up][l]; 
			Mat[k_up][l]=Mat[k][l];		

			if(Mat[k][l]!=labellosalvato){ 
				for(int m=0; m<N; m++){for(int n=0; n<N; n++){
					if(Mat[m][n]==labellosalvato){
						Mat[m][n]=Mat[k][l];
					}
				}}
				for(int i=0; i<labeleff.size(); i++){ 		
					if(labeleff[i]==*labellosalvato){		
						labeleff.erase (labeleff.begin()+i);
						break;								
					}
				}
			}
		}
	}}

//adesso cambio il valore con -1 se il cluster +1 se il cluster non flippa
	for(int i=0; i<labeleff.size(); i++){
		label[labeleff[i]]=Spinrand();	
	}

//aggiorno il microstato flippando tutti i nodi appartenti allo stesso cluster
	for(int i=0; i<N; i++){for(int j=0; j<N; j++){
		if( *Mat[i][j]==-1)flip(i,j);
	}}
}



void microstato::evol_SwenWang(double beta, int M){
	printf("#----# Ciclo di %d evoluzioni con Swen.-Wang con beta = %f \n",M,beta);
	clock_t startS=clock();	
	for( int i=0; i<M; i++){
		step_SwenWang(beta);
		end=clock();	tempo=((double)(end-startS))/CLOCKS_PER_SEC;
		cout<<"#--# "<<i+1<<"-sima evoluzione \t \t t_esec: "<<tempo<<" sec" << string(300,'\b');
	}
	end=clock();tempo=((double)(end-startS))/CLOCKS_PER_SEC;
	cout<<"\n#----# Fine Inizializzazione del sistema  \t \t -------------- \t t_esec tot = "<<tempo<<" sec"<<endl;
}




//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

double microstato::step_SwenWang_M(double beta){	//versione con magnetizzazione
	int *Mat[N][N];
	int label[N_nodi];
	for(int i=0; i<N; i++){for(int j=0; j<N; j++){ 
		label[N*i+j]=N*i+j;
		Mat[i][j]=&label[N*i+j];
	}}
	vector<int> labeleff;				
	for(int i=0; i<N_nodi; i++)labeleff.push_back(i); 

	//comincio il ciclo dei bond attivati orizzontali
	for(int k=0; k<N; k++){for(int l=0; l<N; l++){
		int l_dx=l+1;
		if(l_dx==N)l_dx=0; 
		if(testbond_dx( k, l, beta)==1){	
			int* labellosalvato= Mat[k][l_dx]; 
			Mat[k][l_dx]=Mat[k][l];	

			if(Mat[k][l]!=labellosalvato){ 
				for(int m=0; m<N; m++){for(int n=0; n<N; n++){ //questo doppio ciclo rende il programma brutto!
					if(Mat[m][n]==labellosalvato){
						Mat[m][n]=Mat[k][l];
					}
				}}
				for(int i=0; i<labeleff.size(); i++){ 		//anche questo ciclo è brutto, deve controllare sequenziamente tutto
					if(labeleff[i]== *labellosalvato){	
						labeleff.erase (labeleff.begin()+i);
						break;								
					}
				}
			}
		}
	}}

	//comincio il ciclo dei bond attivati verticale
	for(int k=0; k<N; k++){for(int l=0; l<N; l++){
		int k_up=k+1;
		if(k_up==N)k_up=0; 
		if(testbond_up( k, l, beta)==1){	
			int *labellosalvato= Mat[k_up][l]; 
			Mat[k_up][l]=Mat[k][l];		

			if(Mat[k][l]!=labellosalvato){ 
				for(int m=0; m<N; m++){for(int n=0; n<N; n++){
					if(Mat[m][n]==labellosalvato){
						Mat[m][n]=Mat[k][l];
					}
				}}
				for(int i=0; i<labeleff.size(); i++){ 		
					if(labeleff[i]==*labellosalvato){		
						labeleff.erase (labeleff.begin()+i);
						break;								
					}
				}
			}
		}
	}}

/*
//-------------------controllo output------------------------------------------
cout<<"\n test dei cluster per vedere se funziona"<<endl;
	for(int m=N-1; m>=0; m--){for(int n=0; n<N; n++){
		printf("\t %d",*Mat[m][n]);
	}	cout<<endl;}
//-------------------------------------------------------------
*/

//adesso cambio il valore di label[k] con -1 se il cluster +1 se il cluster non flippa
	for(int i=0; i<labeleff.size(); i++){
		label[labeleff[i]]=Spinrand();	
	}

//aggiorno il microstato flippando tutti i nodi appartenti allo stesso cluster
	for(int i=0; i<N; i++){for(int j=0; j<N; j++){
		if( *Mat[i][j]==-1)flip(i,j);
	}}

//adesso cambio il valore di label[k] (con k appartenente a labeleff) in modo che contenga il numero di elementi del cluster
	for(int i=0; i<N; i++){for(int j=0; j<N; j++){	label[N*i+j]=0;	}} //azzero
	for(int i=0; i<N; i++){for(int j=0; j<N; j++){	
			*Mat[i][j]+=1;	
	}}

/*
//-------------controllo output------------------------------------------------
cout<<"\n test del contatore elementi del cluster per vedere se funziona"<<endl;
	for(int i=0; i<labeleff.size(); i++){
		cout<<" cluster : "<<labeleff[i]<<" \t #° elementi= "<<label[labeleff[i]]<<endl;	
	}
//-------------------------------------------------------------
*/

int sizemax=massimo(label,N_nodi);


//-------------controllo output------------------------------------------------
cout<<" numero di cluster : \t"<<labeleff.size()<<endl;
cout<<" taglia massima di cluster : \t"<<sizemax<<endl;
cout<<" magnetizza improved : \t"<<(double)sizemax/(N_nodi)<<endl;
//-------------------------------------------------------------


return((double)sizemax/(N_nodi));
}

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

void microstato::step_SwenWang_M_Quad(double beta, double *M_imp, double *M_quad_imp);{	//versione con magnetizzazione
	int *Mat[N][N];
	int label[N_nodi];
	for(int i=0; i<N; i++){for(int j=0; j<N; j++){ 
		label[N*i+j]=N*i+j;
		Mat[i][j]=&label[N*i+j];
	}}
	vector<int> labeleff;				
	for(int i=0; i<N_nodi; i++)labeleff.push_back(i); 

	//comincio il ciclo dei bond attivati orizzontali
	for(int k=0; k<N; k++){for(int l=0; l<N; l++){
		int l_dx=l+1;
		if(l_dx==N)l_dx=0; 
		if(testbond_dx( k, l, beta)==1){	
			int* labellosalvato= Mat[k][l_dx]; 
			Mat[k][l_dx]=Mat[k][l];	

			if(Mat[k][l]!=labellosalvato){ 
				for(int m=0; m<N; m++){for(int n=0; n<N; n++){ //questo doppio ciclo rende il programma brutto!
					if(Mat[m][n]==labellosalvato){
						Mat[m][n]=Mat[k][l];
					}
				}}
				for(int i=0; i<labeleff.size(); i++){ 		//anche questo ciclo è brutto, deve controllare sequenziamente tutto
					if(labeleff[i]== *labellosalvato){	
						labeleff.erase (labeleff.begin()+i);
						break;								
					}
				}
			}
		}
	}}

	//comincio il ciclo dei bond attivati verticale
	for(int k=0; k<N; k++){for(int l=0; l<N; l++){
		int k_up=k+1;
		if(k_up==N)k_up=0; 
		if(testbond_up( k, l, beta)==1){	
			int *labellosalvato= Mat[k_up][l]; 
			Mat[k_up][l]=Mat[k][l];		

			if(Mat[k][l]!=labellosalvato){ 
				for(int m=0; m<N; m++){for(int n=0; n<N; n++){
					if(Mat[m][n]==labellosalvato){
						Mat[m][n]=Mat[k][l];
					}
				}}
				for(int i=0; i<labeleff.size(); i++){ 		
					if(labeleff[i]==*labellosalvato){		
						labeleff.erase (labeleff.begin()+i);
						break;								
					}
				}
			}
		}
	}}

/*
//-------------------controllo output------------------------------------------
cout<<"\n test dei cluster per vedere se funziona"<<endl;
	for(int m=N-1; m>=0; m--){for(int n=0; n<N; n++){
		printf("\t %d",*Mat[m][n]);
	}	cout<<endl;}
//-------------------------------------------------------------
*/

//adesso cambio il valore di label[k] con -1 se il cluster +1 se il cluster non flippa
	for(int i=0; i<labeleff.size(); i++){
		label[labeleff[i]]=Spinrand();	
	}

//aggiorno il microstato flippando tutti i nodi appartenti allo stesso cluster
	for(int i=0; i<N; i++){for(int j=0; j<N; j++){
		if( *Mat[i][j]==-1)flip(i,j);
	}}

//adesso cambio il valore di label[k] (con k appartenente a labeleff) in modo che contenga il numero di elementi del cluster
	for(int i=0; i<N; i++){for(int j=0; j<N; j++){	label[N*i+j]=0;	}} //azzero
	for(int i=0; i<N; i++){for(int j=0; j<N; j++){	
			*Mat[i][j]+=1;	
	}}

/*
//-------------controllo output------------------------------------------------
cout<<"\n test del contatore elementi del cluster per vedere se funziona"<<endl;
	for(int i=0; i<labeleff.size(); i++){
		cout<<" cluster : "<<labeleff[i]<<" \t #° elementi= "<<label[labeleff[i]]<<endl;	
	}
//-------------------------------------------------------------
*/

int sizemax=massimo(label,N_nodi);
	*M_imp=(double)sizemax/(N_nodi);

	int sizequad=0;
	for(int i=0; i<N; i++){for(int j=0; j<N; j++){	
		sizequad=label[N*i+j]*label[N*i+j];
	}} 
	*M_quad_imp=(double)sizequad/(N_nodi*N_nodi);
	/*
//-------------controllo output------------------------------------------------
cout<<" numero di cluster : \t"<<labeleff.size()<<endl;
cout<<" taglia massima di cluster : \t"<<sizemax<<endl;
cout<<" magnetizza improved : \t"<<(double)sizemax/(N_nodi)<<endl;
//-------------------------------------------------------------
	*/
}

