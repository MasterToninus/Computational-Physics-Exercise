/*Metodi di Overload dell'uguale*/
	void matrice::Cpu_copy(const matrice& tmp)
	{
		//copio tutti gli attributi della classe che non sono indirizzi
	        ROW = tmp.ROW;
	        COL = tmp.COL;
	        N = ROW*COL;
	        flagCuda = tmp.flagCuda;
	        flagMemory = tmp.flagMemory;
	        flagSquare = tmp.flagSquare;
	        GpuByteCount = 0;

		//libero tutte le variabili puntate (andranno riallocate)
		delete A_host;
		cudaFree( A_dev);

		//rialloco le variabili host
		A_host = new float[N] (); //specifico all'assegnazione di non copiarsi il puntatore!
		for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++)A_host[i*COL +j]=tmp.A_host[i*COL +j];

		//rialloco le variabili device
		unsigned int ByteSize = N*sizeof(float);
		GpuByteCount +=	ByteSize;
		if(flagCuda==true)cudaMalloc( (void **)&A_dev, ByteSize  );
		//non Copio il valore
		flagMemory=false;
	}	

	void matrice::Gpu_copy(const matrice& tmp)
	{
		//copio tutti gli attributi della classe che non sono indirizzi
	        this->ROW = tmp.ROW;
	        this->COL = tmp.COL;
	        this->N = tmp.N;
	        this->flagCuda = tmp.flagCuda;
	        this->flagMemory = tmp.flagMemory;
	        this->flagSquare = tmp.flagSquare;
	        this->GpuByteCount = 0;

		//libero tutte le variabili puntate (andranno riallocate)
		delete A_host;
		cudaFree( A_dev);

		//rialloco le variabili host
		A_host = new float[N] ();

		//rialloco le variabili device
		unsigned int ByteSize = N*sizeof(float);
		GpuByteCount +=	ByteSize;
		cudaMalloc( (void **)&A_dev, ByteSize  );

		//Copio le variabili device
		copy_vec<<<DIM_GRID,DIM_BLOCK>>>(A_dev,tmp.A_dev, N);
		//non Copio il valore
		flagMemory=false;

	}


	void matrice::operator=(const matrice& tmp)
   	{
		if(flagCuda==true){
			Gpu_copy( tmp);
			sync_DeviceToHost();
		}
		else{
			Cpu_copy( tmp);
			sync_HostToDevice();
		}	
	}


 /*Metodi di Overload dei bracket*/
	float* matrice::operator[]( int const n )
   		{
			if(flagCuda && !flagMemory)cout<<"!!!!   Attenzione  !!!!\n Copia gpu non aggiornata alla copia cpu";
			return &A_host[COL*n];
   		}

	float matrice::Cpu_pick( int const i, int const j )
   		{

      			return A_host[COL*i+j];
   		}

	float matrice::Gpu_pick( int const i, int const j )
   		{
			float value_host;
			cudaMemcpy( &value_host, &A_dev[COL*i+j], sizeof(float), cudaMemcpyDeviceToHost);
      			return value_host;
   		}



/*Metodi di Overload della Somma*/

        void matrice::Cpu_add(const matrice& In)
        {
		if(In.ROW != ROW && In.COL != COL)cout<<"errore: dimensione incompatibile"<<endl;
		for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++)A_host[i*COL+j] += In.A_host[i*COL+j] ;
		flagMemory=false;		

	}
        void matrice::Gpu_add(const matrice& In)
        {
		if(In.ROW != ROW && In.COL != COL)cout<<"errore: dimensione incompatibile"<<endl;
		add_vec<<<DIM_GRID,DIM_BLOCK>>>(A_dev,In.A_dev,N);
		flagMemory=false;		

	}

	matrice& matrice::operator+= (const matrice& In) {
		if(flagCuda){
			Gpu_add(In);
			sync_DeviceToHost();
		}
		else{
			Cpu_add(In);
			sync_HostToDevice();
		}

		return *this;
	}

	matrice matrice::operator+ (const matrice& In) {
		matrice result(0);
		result = *this;	// Make a deep copy of this Vector3D. attenzione, cosi' facendo la nuova matrice ha lo stesso indirizzo
		result += In;			// Use existing addition code.
		return result;
	}



/*Metodi di Overload della Sottrazione*/

        void matrice::Cpu_subtract(const matrice& In)
        {
		if(In.ROW != ROW && In.COL != COL)cout<<"errore: dimensione incompatibile"<<endl;
		for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++)A_host[i*COL+j] -= In.A_host[i*COL+j] ;
		flagMemory=false;		
	}
        void matrice::Gpu_subtract(const matrice& In)
        {
		if(In.ROW != ROW && In.COL != COL)cout<<"errore: dimensione incompatibile"<<endl;
		sub_vec<<<DIM_GRID,DIM_BLOCK>>>(A_dev,In.A_dev,N);
		flagMemory=false;		

	}

	matrice& matrice::operator-= (const matrice& In) {
		if(flagCuda){
			Gpu_subtract(In);
			sync_DeviceToHost();
		}
		else{
			Cpu_subtract(In);
			sync_HostToDevice();
		}


		return *this;
	}

	matrice matrice::operator- (const matrice& In) {
		matrice result(0);
		result = *this;
		result -= In;			// Use existing addition code.
		return result;
	}

/*Metodi di Overload del prodotto per uno scalare*/
        void matrice::Cpu_linearproduct(const float lambda)
        {
		for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++)A_host[i*COL+j] *= lambda ;
		flagMemory=false;		
	}
        void matrice::Gpu_linearproduct(const float lambda)
        {
		linear_vec<<<DIM_GRID,DIM_BLOCK>>>(A_dev,lambda,N);
		flagMemory=false;		
	}

	matrice& matrice::operator*= (const float lambda) {
		if(flagCuda){
			Gpu_linearproduct(lambda);
			sync_DeviceToHost();
		}
		else{
			Cpu_linearproduct(lambda);
			sync_HostToDevice();
		}

		return *this;
	}

	matrice matrice::operator* (const float lambda) {
		matrice result(0);
		result = *this;
		result *= lambda;			// Use existing addition code.
		return result;
	}


/*Metodi di Overload del prodotto tra matrici*/
        void matrice::Cpu_matrixproduct(const matrice& In){
		if(In.ROW != COL )cout<<"errore: dimensione incompatibile"<<endl;

		// faccio una copia (cpu only) dei valori contenuti nella matrice originale
		float A_dummy[N];
		for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++)A_dummy[i*COL+j] = A_host[i*COL+j];	
		unsigned int dummy_COL=COL;
		//unsigned int dummy_ROW=ROW;

		//libero tutte le variabili puntate (andranno riallocate)
		delete A_host;
		cudaFree( A_dev);
		unsigned int ByteSize = N*sizeof(float);
		GpuByteCount -=	ByteSize;

		// ridimensiono la matrice originale
		COL= In.COL;		 
		N=ROW*COL;


		//rialloco le variabili host
		A_host = new float[N] (); //specifico all'assegnazione di non copiarsi il puntatore!

		//rialloco le variabili device
		ByteSize = N*sizeof(float);
		GpuByteCount +=	ByteSize;
		if(flagCuda==true)cudaMalloc( (void **)&A_dev, ByteSize  );


		//eseguo infine il prodotto
		float sum ;
		for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++){
			sum = 0;
			for(int k=0; k<In.ROW; k++)
				sum+= A_dummy[i*dummy_COL+k] * In.A_host[k*In.COL+j] ;
				A_host[i*COL +j]= sum;
			}
		flagMemory=false;
	}

//	matrice& operator *=  (const matrice& In);
//	matrice operator *  (const matrice& In);


