
//#include "Clusterclass.h"

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_


int microstato::testbond_up_V2(int i, int j,double Pbond){
	int test=0;
	int i_up=i+1;
	if(i_up==N)i_up=0;//condizione di bordo periodico
	
	if(StatoSpin[i][j]==StatoSpin[i_up][j]){
	double random=(double)rand()/RAND_MAX;
		if(random< Pbond)test=1;						//Pbond = 1-exp(-2*beta)
	}
	return(test);
}
int microstato::testbond_dx_V2(int i, int j,double Pbond){
	int test=0;
	int j_dx=j+1;
	if(j_dx == N)j_dx=0;//condizione di bordo periodico	

	if(StatoSpin[i][j]==StatoSpin[i][j_dx]){
	double random=(double)rand()/RAND_MAX;
		if(random< Pbond)test=1;						//Pbond = 1-exp(-2*beta)
	}
	return(test);
}


void microstato::step_SwenWang_V2(double Pbond){	
	int label[N][N];// ad ogni nodo associo il label del cluster a cui appartiene
	vector<cluster> Cluster; // ho un cluster per ogni nodo
	vector<int> labeleff;				

	//double Pbond = 1-exp(-2*beta); //lo calcolo una sola volta!

	for(int i=0; i<N; i++){for(int j=0; j<N; j++){ 
		label[i][j]=N*i+j;
		Cluster.push_back(cluster(label[i][j],i,j,N_nodi));
		labeleff.push_back(N*i+j);		
	}}
		/*
//-------------------controllo output------------------------------------------------------
cout<<"\n test dei cluster per vedere se funziona"<<endl;
for(int m=N-1; m>=0; m--){for(int n=0; n<N; n++){
	int flag= label[m][n];
	printf("\t %d",Cluster[flag].label);
}	cout<<endl;}
//-----------------------------------------------------------------------------------------
		*/
//comincio il ciclo dei bond attivati orizzontali
	for(int k=0; k<N; k++){for(int l=0; l<N; l++){
		int l_dx=l+1;
		if(l_dx==N)l_dx=0; 

		int labellosalvato= label[k][l_dx]; 
		if(label[k][l]!=labellosalvato){
			if(testbond_dx_V2( k, l, Pbond)==1){	
				cluster dummy= Cluster[labellosalvato];
				for(int f=0; f<dummy.N_ele; f++){ //tutti i nodi del cluster a destra hanno stesso label dei nodi del cluster di sinistra
					label[dummy.i[f]][dummy.j[f]]=label[k][l];
				}
				Cluster[label[k][l]]+=dummy; //costruisco cluster di sinistra = clu sin + clu dex	
				for(int i=0; i<labeleff.size(); i++){ 		//anche questo ciclo è brutto, deve controllare sequenziamente tutto
						if(labeleff[i]== dummy.label){	
						labeleff.erase (labeleff.begin()+i);
						break;								
					}
				}
			}
		}
	}}
		/*
//-------------------controllo output------------------------------------------------------
cout<<"\n test dei cluster per vedere se funziona"<<endl;
for(int m=N-1; m>=0; m--){for(int n=0; n<N; n++){
	int flag= label[m][n];
	printf("\t %d",Cluster[flag].label);
}	cout<<endl;}
//-----------------------------------------------------------------------------------------
		*/
	//comincio il ciclo dei bond attivati verticale
	for(int k=0; k<N; k++){for(int l=0; l<N; l++){
		int k_up=k+1;
		if(k_up==N)k_up=0; 

		int labellosalvato= label[k_up][l]; 
		if(label[k][l]!=labellosalvato){
			if(testbond_up_V2( k, l, Pbond)==1){	
				cluster dummy= Cluster[labellosalvato];
				for(int f=0; f<dummy.N_ele; f++){ //tutti i nodi del cluster a destra hanno stesso label dei nodi del cluster di sinistra
					label[dummy.i[f]][dummy.j[f]]=label[k][l];
				}
				Cluster[label[k][l]]+=dummy; //costruisco cluster di sinistra = clu sin + clu dex	
				for(int i=0; i<labeleff.size(); i++){ 		//anche questo ciclo è brutto, deve controllare sequenziamente tutto
						if(labeleff[i]== dummy.label){	
						labeleff.erase (labeleff.begin()+i);
						break;								
					}
				}
			}
		}
	}}
		/*
//-------------------controllo output------------------------------------------------------
cout<<endl;stampa_stato();
cout<<"\n test dei cluster per vedere se funziona"<<endl;
for(int m=N-1; m>=0; m--){for(int n=0; n<N; n++){
	int flag= label[m][n];
	printf("\t %d",Cluster[flag].label);
}	cout<<endl;}
//-----------------------------------------------------------------------------------------
		*/
//flip degli elementi del cluster con proprietà 50%
	for(int i=0; i<labeleff.size(); i++){
		int test=Spinrand();
		if( test==-1){//devo flippare tutti gli elementi che fanno parte del clusterone
			cluster dummy= Cluster[labeleff[i]];
				for(int f=0; f<dummy.N_ele; f++){ //tutti i nodi del cluster dummy vanno flippati
					flip(dummy.i[f],dummy.j[f]);
				}	
		}
	}
}




void microstato::evol_SwenWang_V2(double Pbond, int M){
	printf("##--- Ciclo di %d evoluzioni con Swen.-Wang con Pbond = %f \n",M,Pbond);
	clock_t startS=clock();	
	for( int i=0; i<M; i++){
		step_SwenWang(Pbond);
		end=clock();	tempo=((double)(end-start))/CLOCKS_PER_SEC;
		cout<<"##--# "<<i+1<<"-sima evoluzione \t \t t_esec: "<<tempo<<" sec" << string(300,'\b');
	}
	//end=clock();tempo=((double)(end-startS))/CLOCKS_PER_SEC;
	//cout<<"#----# Fine evoluzione del sistema  \t \t -------------- \t t_esec tot = "<<tempo<<" sec"<<endl;
	cout<<endl;
}




//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

double microstato::step_SwenWang_M_V2(double Pbond){	//versione con magnetizzazione
	int label[N][N];// ad ogni nodo associo il label del cluster a cui appartiene
	vector<cluster> Cluster; // ho un cluster per ogni nodo
	vector<int> labeleff;	//lista variabile dei label effettivamente usati				

	//double Pbond = 1-exp(-2*beta); //lo calcolo una sola volta!

	for(int i=0; i<N; i++){for(int j=0; j<N; j++){ 
		label[i][j]=N*i+j;
		Cluster.push_back(cluster(label[i][j],i,j,N_nodi));
		labeleff.push_back(N*i+j);		
	}}

//comincio il ciclo dei bond attivati orizzontali
	for(int k=0; k<N; k++){for(int l=0; l<N; l++){
		int l_dx=l+1;
		if(l_dx==N)l_dx=0; 

		if(testbond_dx_V2( k, l, Pbond)==1){	
			int labellosalvato= label[k][l_dx]; 
			if(label[k][l]!=labellosalvato){
				cluster dummy= Cluster[labellosalvato];
				for(int f=0; f<dummy.N_ele; f++){ //tutti i nodi del cluster a destra hanno stesso label dei nodi del cluster di sinistra
					label[dummy.i[f]][dummy.j[f]]=label[k][l];
				}
				Cluster[label[k][l]]+=dummy; //costruisco cluster di sinistra = clu sin + clu dex	
				for(int i=0; i<labeleff.size(); i++){ 		//questo ciclo è brutto, deve controllare sequenziamente tutto
						if(labeleff[i]== dummy.label){	
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
		if(testbond_up_V2( k, l, Pbond)==1){	
			int labellosalvato= label[k_up][l]; 

			if(label[k][l]!=labellosalvato){
				cluster dummy= Cluster[labellosalvato];
				for(int f=0; f<dummy.N_ele; f++){ //tutti i nodi del cluster a destra hanno stesso label dei nodi del cluster di sinistra
					label[dummy.i[f]][dummy.j[f]]=label[k][l];
				}
				Cluster[label[k][l]]+=dummy; //costruisco cluster di sinistra = clu sin + clu dex	
				for(int i=0; i<labeleff.size(); i++){ 		//anche questo ciclo è brutto, deve controllare sequenziamente tutto
						if(labeleff[i]== dummy.label){	
						labeleff.erase (labeleff.begin()+i);
						break;								
					}
				}
			}
		}
	}}
		/*
//-------------------controllo output------------------------------------------------------
cout<<endl;stampa_stato();
cout<<"\n test dei cluster per vedere se funziona"<<endl;
for(int m=N-1; m>=0; m--){for(int n=0; n<N; n++){
	int flag= label[m][n];
	printf("\t %d",Cluster[flag].label);
}	cout<<endl;}
//-----------------------------------------------------------------------------------------
		*/
//flip degli elementi del cluster con proprietà 50%
	for(int i=0; i<labeleff.size(); i++){	//ciclo su tutti i cluster del sistema
		int test=Spinrand();				//flip degli elementi del cluster con proprietà 50%
		if( test==-1){						
			cluster dummy= Cluster[labeleff[i]];
				for(int f=0; f<dummy.N_ele; f++){ //tutti i nodi del cluster dummy vanno flippati
					flip(dummy.i[f],dummy.j[f]);
				}	
		}
	}
		/*
//-------------controllo output------------------------------------------------
cout<<"\n test del contatore elementi del cluster per vedere se funziona"<<endl;
for(int i=0; i<labeleff.size(); i++){
	cluster dummy= Cluster[labeleff[i]];
	cout<<" cluster : "<<labeleff[i]<<" \t #° elementi= "<<dummy.N_ele<<endl;	
}
//-------------------------------------------------------------
		*/
	int sizemax=1;
	for(int i=0; i<labeleff.size(); i++){
		cluster dummy= Cluster[labeleff[i]];
		if(dummy.N_ele>sizemax) sizemax=dummy.N_ele;	
	}
		/*
//-------------controllo output------------------------------------------------
cout<<" numero di cluster : \t"<<labeleff.size()<<endl;
cout<<" taglia massima di cluster : \t"<<sizemax<<endl;	
cout<<" magnetizza improved : \t"<<(double)sizemax/(N_nodi)<<endl;
//-------------------------------------------------------------
		*/	
return((double)sizemax/(N_nodi));
}

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

void microstato::step_SwenWang_M_Quad_V2(double Pbond, double *M_imp, double *M_quad_imp){	//versione a 2 valori, restituisce m improved e m quadrato improved
	int label[N][N];// ad ogni nodo associo il label del cluster a cui appartiene
	vector<cluster> Cluster; // ho un cluster per ogni nodo
	vector<int> labeleff;	//lista variabile dei label effettivamente usati				

	//double Pbond = 1-exp(-2*beta); //lo calcolo una sola volta!

	for(int i=0; i<N; i++){for(int j=0; j<N; j++){ 
		label[i][j]=N*i+j;
		Cluster.push_back(cluster(label[i][j],i,j,N_nodi));
		labeleff.push_back(N*i+j);		
	}}

//comincio il ciclo dei bond attivati orizzontali
	for(int k=0; k<N; k++){for(int l=0; l<N; l++){
		int l_dx=l+1;
		if(l_dx==N)l_dx=0; 

		if(testbond_dx_V2( k, l, Pbond)==1){	
			int labellosalvato= label[k][l_dx]; 
			if(label[k][l]!=labellosalvato){
				cluster dummy= Cluster[labellosalvato];
				for(int f=0; f<dummy.N_ele; f++){ //tutti i nodi del cluster a destra hanno stesso label dei nodi del cluster di sinistra
					label[dummy.i[f]][dummy.j[f]]=label[k][l];
				}
				Cluster[label[k][l]]+=dummy; //costruisco cluster di sinistra = clu sin + clu dex	
				for(int i=0; i<labeleff.size(); i++){ 		//questo ciclo è brutto, deve controllare sequenziamente tutto
						if(labeleff[i]== dummy.label){	
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
		if(testbond_up_V2( k, l, Pbond)==1){	
			int labellosalvato= label[k_up][l]; 

			if(label[k][l]!=labellosalvato){
				cluster dummy= Cluster[labellosalvato];
				for(int f=0; f<dummy.N_ele; f++){ //tutti i nodi del cluster a destra hanno stesso label dei nodi del cluster di sinistra
					label[dummy.i[f]][dummy.j[f]]=label[k][l];
				}
				Cluster[label[k][l]]+=dummy; //costruisco cluster di sinistra = clu sin + clu dex	
				for(int i=0; i<labeleff.size(); i++){ 		//anche questo ciclo è brutto, deve controllare sequenziamente tutto
						if(labeleff[i]== dummy.label){	
						labeleff.erase (labeleff.begin()+i);
						break;								
					}
				}
			}
		}
	}}

//flip degli elementi del cluster con proprietà 50%
	for(int i=0; i<labeleff.size(); i++){	//ciclo su tutti i cluster del sistema
		int test=Spinrand();				//flip degli elementi del cluster con proprietà 50%
		if( test==-1){						
			cluster dummy= Cluster[labeleff[i]];
				for(int f=0; f<dummy.N_ele; f++){ //tutti i nodi del cluster dummy vanno flippati
					flip(dummy.i[f],dummy.j[f]);
				}	
		}
	}
		/*
//-------------controllo output------------------------------------------------
cout<<"\n test del contatore elementi del cluster per vedere se funziona"<<endl;
for(int i=0; i<labeleff.size(); i++){
	cluster dummy= Cluster[labeleff[i]];
	cout<<" cluster : "<<labeleff[i]<<" \t #° elementi= "<<dummy.N_ele<<endl;	
}
//-------------------------------------------------------------
		*/
	int sizemax=1;
	for(int i=0; i<labeleff.size(); i++){
		cluster dummy= Cluster[labeleff[i]];
		if(dummy.N_ele>sizemax) sizemax=dummy.N_ele;	
	}
	*M_imp=(double)sizemax/(N_nodi);

	int sizequad=0;
	for(int i=0; i<labeleff.size(); i++){
		int dummy=Cluster[labeleff[i]].N_ele;
		sizequad += dummy*dummy;
	}
	*M_quad_imp=(double)sizequad/(N_nodi*N_nodi);

		/*
//-------------controllo output------------------------------------------------
cout<<" numero di cluster : \t"<<labeleff.size()<<endl;
cout<<" taglia massima di cluster : \t"<<sizemax<<endl;
cout<<" magnetizza improved : \t"<<(double)sizemax/(N_nodi)<<endl;
//-------------------------------------------------------------
		*/	
}



