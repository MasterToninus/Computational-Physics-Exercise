/*
ALGORITMO CON IL  MIO PIVOTING
 ottimizzato per il tipo di matrici che prendo in esame io:
	- grandi
	- dense
	- entry < max (scelto a piacere)
	- valore delle entry uniformemente distribuito tra -max e max

*/

//trova l'elemento dell'ultima riga in modulo + grande 
 bool matrice::Cpu_Max_Pivoting (int* pivot_i) {  
		unsigned int offset = COL*(ROW-1);
		int l=0; float Max = A_host[offset+l];

		for(int j=1; j<COL ; j++){
			if (Max<=0)Max = -Max;	// considero il valore assoluto
			float test= A_host[offset + j];
			if( test > Max || -test > Max){
				l=j;
				Max = test;
			}
		}
		*pivot_i=l;
//			cout<<" pivot (0,"<<l<<") = "<<A[l]<<endl;
		if(A_host[offset+l]==0)return false;
		else return true;
	}
bool matrice::Cpu_Max_Pivoting_Speedy (int* pivot_i, float* pivot_value) {  
		unsigned int offset = COL*(ROW-1);
		int l=0; float Max = A_host[offset+l];

		for(int j=1; j<COL ; j++){
			if (Max<=0)Max = -Max;	// considero il valore assoluto
			float test= A_host[offset + j];
			if( test > Max || -test > Max){
				l=j;
				Max = test;
			}
		}
		*pivot_i=l;
		* pivot_value=A_host[offset+l];
//			cout<<" pivot (0,"<<l<<") = "<<A[l]<<endl;
		if(A_host[offset+l]==0)return false;
		else return true;
	}



 bool matrice::Gpu_Max_Pivoting (int* pivot_i) {  

	//Definisco i puntatori alle variabli device
	float *max_Value_dev;
	int   *max_Index_dev;

	//alloco le variabili host
	float max_Value_host; 
	int   max_Index_host;

	//Alloco le variabili device
 	cudaMalloc( (void **)&max_Value_dev, sizeof(float)  );
  	cudaMalloc( (void **)&max_Index_dev, sizeof(int)  );
 
	//Riempio le variabili host
	max_Value_host =0.0; 
        max_Index_host=0;
// Attenzione! l'inizializzazione del massimo va letto nella gpu! metto 0 perche' e' di sicuro il minimo del valore assoluto!
	//Riempio le variabili Device
	cudaMemset(max_Value_dev,0, sizeof(float));		//setto a 0 il valore del massimo sulla gpu, attenzione
	cudaMemset(max_Index_dev,0, sizeof(int));	
	//cudaMemcpy( max_Value_dev,  &max_Value_host, sizeof(float), cudaMemcpyHostToDevice);
	//cudaMemcpy( max_Index_dev,  &max_Index_host, sizeof(int), cudaMemcpyHostToDevice);

	//Setto la griglia 2D
        dim3 block0(THREAD_PER_BLOCK );
        dim3 grid0( 4 );

	//KERNEL!
	Lock lock;
	unsigned int offset = COL*(ROW-1);		// offset per saltare all'ultima riga		
  	MaxValue<<<grid0,block0>>>(lock,A_dev+offset,COL,
							max_Value_dev,max_Index_dev);

	//Pull back dei risultati
  	cudaMemcpy( &max_Value_host,  max_Value_dev, sizeof(float), cudaMemcpyDeviceToHost);
  	cudaMemcpy( &max_Index_host,  max_Index_dev, sizeof(int), cudaMemcpyDeviceToHost);

	*pivot_i=max_Index_host;
	
//cout<<"*****PIVOTING****** pivot ( "<<ROW-1 <<","<<max_Index_host<<") = "<<max_Value_host<<endl;
	//Libero la Memoria
	cudaFree( max_Value_dev); 
	cudaFree( max_Index_dev); 

	lock.reInit(); //Questo e' necessario! motivo: il kernel dopo la sua esecuzione lo distrugge! Quindi quando alla fine di questo metodo viene richiamato il distruttore il cudafree del lock da errore perche' la memoria e' gia' liberata!
	
	if(max_Value_host==0)return false;
	else return true;
	}

bool matrice::Gpu_Max_Pivoting_Speedy (int* pivot_i, float* pivot_value) {  

	//Definisco i puntatori alle variabli device
	float *max_Value_dev;
	int   *max_Index_dev;

	//Alloco le variabili device
 	cudaMalloc( (void **)&max_Value_dev, sizeof(float)  );
  	cudaMalloc( (void **)&max_Index_dev, sizeof(int)  );
 
	//Riempio le variabili Device
	cudaMemset(max_Value_dev,0, sizeof(float));		//setto a 0 il valore del massimo sulla gpu, attenzione
	cudaMemset(max_Index_dev,0, sizeof(int));	

	//Setto la griglia 2D
        dim3 block0(THREAD_PER_BLOCK );
	unsigned int block_per_thread =imin(N/THREAD_PER_BLOCK +1,16);
        dim3 grid0( block_per_thread );

	//KERNEL!
	Lock lock;
	unsigned int offset = COL*(ROW-1);		// offset per saltare all'ultima riga		
  	MaxValue<<<grid0,block0>>>(lock,A_dev+offset,COL,
							max_Value_dev,max_Index_dev);

	//Pull back dei risultati
  	cudaMemcpy( pivot_i,  max_Index_dev, sizeof(int), cudaMemcpyDeviceToHost);
	*pivot_value=Gpu_pick(ROW-1,*pivot_i);

//cout<<"*****PIVOTING****** pivot ( "<<ROW-1 <<","<<max_Index_host<<") = "<<max_Value_host<<endl;
	//Libero la Memoria
	cudaFree( max_Value_dev); 
	cudaFree( max_Index_dev); 

	lock.reInit(); //Questo e' necessario! motivo: il kernel dopo la sua esecuzione lo distrugge! Quindi quando alla fine di questo metodo viene richiamato il distruttore il cudafree del lock da errore perche' la memoria e' gia' liberata!
	
	if(pivot_value==0)return false;
	else return true;
	}


//Divido ultima riga per il dato elemento della linea
void matrice::Cpu_Division (int pivot_i) {  
	unsigned int offset = COL*(ROW-1);
	float lambda = 1/A_host[offset+pivot_i];
	for(int j=0; j<COL ; j++)A_host[offset+j]*=lambda;
	A_host[offset+pivot_i]=1;	
	flagMemory=false;	
		
	}

void matrice::Gpu_Division (int pivot_i) {  
	unsigned int offset = COL*(ROW-1);
	float lambda = Gpu_pick(ROW-1,pivot_i);	
	lambda = 1/lambda;

        dim3 block0(THREAD_PER_BLOCK );
	unsigned int block_per_grid = THREAD_PER_BLOCK;
        dim3 grid0( block_per_grid );
	linear_vec<<<grid0,block0>>>( A_dev + offset, lambda,COL);
	//float dummy=1;
	//cudaMemcpy( (A_dev +offset+ pivot_i),  &dummy, sizeof(float), cudaMemcpyHostToDevice); //uso aritmetica degli indirizzi
	flagMemory=false;
	}

void matrice::Gpu_Division_Speedy (float *dividendo) {  
	unsigned int offset = COL*(ROW-1);
	float lambda = 1/ (*dividendo);

 	linear_vec<<<THREAD_PER_BLOCK,THREAD_PER_BLOCK>>>( A_dev + offset, lambda,COL);
	flagMemory=false;
	}



//swap di righe (questo e' ideale perche' la matrice e' srotolata in questo senso) '
void matrice::Cpu_Swap_Row(int i1, int i2) {  
	float dummy;
	for(int j=0; j<COL ; j++){
		dummy=A_host[i1*COL+j];

		A_host[i1*COL+j]=A_host[i2*COL+j];
		A_host[i2*COL+j]=dummy;

	}
	flagMemory=false;	
	}

void matrice::Gpu_Swap_Row(int i1, int i2) {  
	swapRow <<<BLOCK_PER_GRID,THREAD_PER_BLOCK>>>(A_dev, i1, i2, COL);
	flagMemory=false;	
	}

//swap di colonne (questo e' problematico visto che la matrice e'
void matrice::Cpu_Swap_Col(int j1, int j2) {  
	float dummy;
	for(int i=0; i<COL ; i++){
		dummy=A_host[i*COL+j1];
		A_host[i*COL+j1]=A_host[i*COL+j2];
		A_host[i*COL+j2]=dummy;

	}
	flagMemory=false;	
	}

void matrice::Gpu_Swap_Col(int j1, int j2) {  
	swapCol <<<BLOCK_PER_GRID,THREAD_PER_BLOCK>>>(A_dev, j1, j2, COL,ROW);
	flagMemory=false;	
	}



//step di condensazione prende in ingresso la matrice precedentemente swappata in modo che il pivot posto a 1 sia nell'angolo in basso a sinistra
void matrice::Cpu_Step_Condensation_Simple(){
 	int newROW = ROW-1;
	int newCOL = COL-1;	
	//non disalloco la memoria perche' la prospettiva e' sempre quella di non distruggere la matrice iniziale alla fine del calcolo

	for(int i=0 ; i<newROW ; i++){
		for(int j=0 ; j<newCOL ; j++){
				A_host[i*newCOL+j] =A_host[i*COL+j]-A_host[i*COL+COL-1]*A_host[(ROW-1)*COL+j];
			}
		}
	ROW=newROW;
	COL=newCOL;
	N=newROW*newCOL;
	//QUESTO NON VA BENE PERCHE' PERDO IL RICORDO DI QUALI FOSSERO LE DIMENSIONI DELLA MATRICE PRIMA DELLA CONDENSAZIONE!
	flagMemory=false;
}



void matrice::Gpu_Step_Condensation_Simple(){

  if(flagSquare){
	float *pivot_Column = 0;
	unsigned int numBytes = ROW*sizeof(float);

	//Alloco la memoria lineare sulla gpu dove caricare la colonna di pivot
	cudaMalloc((void**)&pivot_Column, numBytes);

	//Chiamo kernel che mette la colonna in memoria lineare
	copy_Col<<<BLOCK_PER_GRID,THREAD_PER_BLOCK>>>(pivot_Column, A_dev ,COL-1, COL, ROW);

	//Bindo a texture la memoria lineare
	cudaBindTexture(NULL, texRef, pivot_Column);

	//Alloco il vettore che deve contenere la matrice condendata
	float *B_dev = 0;
	ROW--;
	COL--;
	N=ROW*COL;
	numBytes = N*sizeof(float);

	cudaMalloc((void**)&B_dev, numBytes);

	//Setto la griglia 2D

	//Chiamo kernel che esegue lo step 
	stepCondensationSimple_v4<<<BLOCK_PER_GRID,16>>>( B_dev,A_dev, COL,ROW); 

	//unbind della texture
	cudaUnbindTexture ( texRef );
	cudaFree (pivot_Column);

	//Libero l'array matrice superfluo
	cudaFree( A_dev); //libero la memoria all'indirizzo dove si trova la matrice vecchia
	A_dev=B_dev;	   //come indirizzo di matrice utilizzo l'indirizzo 

	flagMemory=false;
  }

}


void matrice::Gpu_Step_Condensation_Simple_Best(){

  if(flagSquare){

	//Bindo a texture tutta la matrice in modo che e' bindato anche il vettore che mi interessa
	 cudaBindTexture(NULL, texRef2, A_dev);

	//Alloco il vettore che deve contenere la matrice condensata
	float *B_dev = 0;
	ROW--;
	COL--;
	N=ROW*COL;
	unsigned int numBytes = N*sizeof(float);

	cudaMalloc((void**)&B_dev, numBytes);

	//Setto la griglia 2D
	unsigned int thread_per_row = imin(COL,MAX_DIM_BLOCK);
        dim3 block0(thread_per_row );  // 512 x 1 x 1    

        unsigned int block_per_row = ROW/THREAD_PER_BLOCK + 1;
        unsigned int block_per_col =  imin(COL, MAX_DIM_GRID / block_per_row);
        dim3 grid0( block_per_row, block_per_col );         // 512 x 1 x 1

//        cout<<"blocchi : "<<thread_per_row<<" x 1 x 1 "<<endl;
//        cout<<"griglia : "<< block_per_row <<" x "<< block_per_col << " x 1"<<endl;


	//Chiamo kernel che esegue lo step 
	stepCondensationSimple_v6<<<grid0,block0>>>(B_dev,A_dev, COL,ROW);	


	//unbind della texture
	cudaUnbindTexture ( texRef2 );

	//Libero l'array matrice superfluo
	cudaFree( A_dev); //libero la memoria all'indirizzo dove si trova la matrice vecchia
	A_dev=B_dev;	   //come indirizzo di matrice utilizzo l'indirizzo 

	flagMemory=false;
  }

}




//Metodi di condensazione vera e propria, restituiscono il vettore dei pivot
bool matrice::Cpu_Condensation(float * pivot){
  int ROW_0 =ROW;	//mi salvo un ricordo delle dimensioni iniziali della matrice
  int COL_0 =COL;

  int pivot_j;
  bool flag;

    for(int k=0 ; k<ROW_0-1 ; k++){
//cout<<" Step "<<k<<" di"<<ROW-1<<endl;

	
	//1) trovo l'indice del pivot
	flag = Cpu_Max_Pivoting (&pivot_j);
//cout<<" Pivot A[ "<<COL-1<<" ]["<<pivot_j<<"] = "<<A_host[(ROW-1)*COL +pivot_j]<<endl;
	if(flag){
		pivot[k]= A_host[(ROW-1)*COL +pivot_j];
	//2) divido l'ultima riga per il pivot
		Cpu_Division(pivot_j);
//cout<<" divido ultima riga per il pivot A "<<endl;	Cpu_print();
	//3) swappo la colonna se indice non e' l'ultimo
		if(pivot_j!=COL-1){
			Cpu_Swap_Col(pivot_j, COL-1);
			pivot[k]=-pivot[k];}
//cout<<" swappo il pivot mettendolo alla fine"<<endl;	Cpu_print();


	//4) Condenso
		Cpu_Step_Condensation_Simple();
//cout<<" Condenso"<< endl;	Cpu_print();

	}

	else if(!flag) {
		cout<<" Matrice singolare"<<endl;
		pivot[k]=0;
		break;
	}
    }
    pivot[ROW_0-1]=A_host[0];
    COL =COL_0;
    ROW =ROW_0;
    N=COL*ROW;
    sync_DeviceToHost();//Attenzione ricopio la copia storata sul device.. e se quella non esiste? dovrei fare un if con in caso una copia host


return flag;
}


bool matrice::Gpu_Condensation(float * pivot){   //Ibrida, salvo la lista dei pivot sull'host e faccio fare a lui la produttoria! (in termini generali il determinante per matrici grandi converge rapidamente a 0 o all'infinito. c'e' grande rischio di overflow e underflow, quindi per trattarlo sarebbe necessario una struttura "numero grande"
  int ROW_0 =ROW;	//mi salvo un ricordo delle dimensioni iniziali della matrice
  int COL_0 =COL;

  int pivot_j;
  float pivot_value;
  bool flag;

    for(int k=0 ; k<ROW_0-1 ; k++){
//cout<<" Step "<<k<<" di"<<ROW-1<<endl;

	
	//1) trovo l'indice del pivot (GPU)
	flag = Gpu_Max_Pivoting_Speedy (&pivot_j, &pivot_value);
	pivot[k]= pivot_value;
//cout<<" Pivot A[ "<<COL-1<<" ]["<<pivot_j<<"] = "<<pivot[k]<<endl;
	if(flag){
		
	//2) divido l'ultima riga per il pivot
		Gpu_Division_Speedy(&pivot_value);
//cout<<" divido ultima riga per il pivot A "<<endl;	Gpu_print();
	//3) swappo la colonna se indice non e' l'ultimo
		if(pivot_j!=COL-1){
			Gpu_Swap_Col(pivot_j, COL-1);
			pivot[k]=-pivot[k];}
//cout<<" swappo il pivot mettendolo alla fine"<<endl;	Gpu_print();


	//4) Condenso
		Gpu_Step_Condensation_Simple();
//cout<<" Condenso"<< endl;	Gpu_print();

	}

	else if(!flag) {
		cout<<" Matrice singolare"<<endl;
		pivot[k]=0;
		break;
	}
    }

    pivot[ROW_0-1]=Gpu_pick(0,0);

    //Ricostruzione della matrice distrutta dalla condensazione
    cudaFree( A_dev); //libero la memoria all'indirizzo dove si trova la matrice devastata (questo perche' ora e' molto piu' piccola!)
    COL =COL_0;
    ROW =ROW_0;
    N=COL*ROW;
    unsigned int ByteSize = N*sizeof(float);
    //GpuByteCount +=	ByteSize;
    cudaMalloc( (void **)&A_dev, ByteSize  );
    sync_HostToDevice();//Attenzione ricopio la copia storata sul host.. e se quella non esiste? dovrei fare un if con in caso una copia host


return flag;
}



bool matrice::Gpu_Condensation_Best(float * pivot){   //Ibrida, salvo la lista dei pivot sull'host e faccio fare a lui la produttoria! (in termini generali il determinante per matrici grandi converge rapidamente a 0 o all'infinito. c'e' grande rischio di overflow e underflow, quindi per trattarlo sarebbe necessario una struttura "numero grande"
  int ROW_0 =ROW;	//mi salvo un ricordo delle dimensioni iniziali della matrice
  int COL_0 =COL;

  int pivot_j;
  float pivot_value;
  bool flag;

    for(int k=0 ; k<ROW_0-1 ; k++){
//cout<<" Step "<<k<<" di"<<ROW-1<<endl;

	
	//1) trovo l'indice del pivot (GPU)
	flag = Gpu_Max_Pivoting_Speedy (&pivot_j, &pivot_value);
	pivot[k]= pivot_value;
//cout<<" Pivot A[ "<<COL-1<<" ]["<<pivot_j<<"] = "<<pivot[k]<<endl;
	if(flag){
		
	//2) divido l'ultima riga per il pivot
		Gpu_Division_Speedy(&pivot_value);
//cout<<" divido ultima riga per il pivot A "<<endl;	Gpu_print();
	//3) swappo la colonna se indice non e' l'ultimo
		if(pivot_j!=COL-1){
			Gpu_Swap_Col(pivot_j, COL-1);
			pivot[k]=-pivot[k];}
//cout<<" swappo il pivot mettendolo alla fine"<<endl;	Gpu_print();


	//4) Condenso
		Gpu_Step_Condensation_Simple_Best();
//cout<<" Condenso"<< endl;	Gpu_print();

	}

	else if(!flag) {
		cout<<" Matrice singolare"<<endl;
		pivot[k]=0;
		break;
	}
    }

    pivot[ROW_0-1]=Gpu_pick(0,0);

    //Ricostruzione della matrice distrutta dalla condensazione
    cudaFree( A_dev); //libero la memoria all'indirizzo dove si trova la matrice devastata (questo perche' ora e' molto piu' piccola!)
    COL =COL_0;
    ROW =ROW_0;
    N=COL*ROW;
    unsigned int ByteSize = N*sizeof(float);
    //GpuByteCount +=	ByteSize;
    cudaMalloc( (void **)&A_dev, ByteSize  );
    sync_HostToDevice();//Attenzione ricopio la copia storata sul host.. e se quella non esiste? dovrei fare un if con in caso una copia host


return flag;
}







//Metodi che infine calcolano la produttoria
float matrice::Cpu_Determinant_Condensation(){
  float determinant; 
  bool flagSingularity;
  if(flagSquare){ //la condensazione in teoria funzionerebbe anche per matrici non quadrate...
	float pivot[ROW];
	flagSingularity=Cpu_Condensation(pivot);
	if(flagSingularity){
	determinant=pivot[0];
	//for(int k=0 ; k<ROW ; k++)cout<<pivot[k]<<endl;
	for(int k=1 ; k<ROW ; k++)determinant*=pivot[k];
	}
	else determinant=0;
  }
  else cout<<"errore! determinante solo per matrici quadrate!"<<endl;
return determinant;
}


float matrice::Gpu_Determinant_Condensation(){
  float determinant; 
  if(flagSquare){ //la condensazione in teoria funzionerebbe anche per matrici non quadrate...
	float pivot[ROW];//conviene inizializzarli a zero! cosi' se il pivot trova uno zero breakka tutto  e chiude velocemente la routine!
	Gpu_Condensation(pivot);
	determinant=pivot[0];
	//for(int k=0 ; k<ROW ; k++)cout<<pivot[k]<<endl;
	for(int k=1 ; k<ROW ; k++)determinant*=pivot[k];


  }
  else cout<<"errore! determinante solo per matrici quadrate!"<<endl;
return determinant;
}





float matrice::Gpu_Determinant_Condensation_Best(){
  float determinant; 
  if(flagSquare){ //la condensazione in teoria funzionerebbe anche per matrici non quadrate...
	float pivot[ROW];//conviene inizializzarli a zero! cosi' se il pivot trova uno zero breakka tutto  e chiude velocemente la routine!
	Gpu_Condensation_Best(pivot);
	determinant=pivot[0];
	//for(int k=0 ; k<ROW ; k++)cout<<pivot[k]<<endl;
	for(int k=1 ; k<ROW ; k++)determinant*=pivot[k];


  }
  else cout<<"errore! determinante solo per matrici quadrate!"<<endl;
return determinant;
}


