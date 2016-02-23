/*
serve una classe matrice se voglio poter vedere come implementare i metodi di evoluzione
http://www.cplusplus.com/doc/tutorial/classes/

Ancora meglio servirebbe un template!
http://www.cplusplus.com/doc/tutorial/templates/
http://www.codeproject.com/Articles/268849/An-Idiots-Guide-to-Cplusplus-Templates-Part#OperOver


manca ifnotdef!
http://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files

*/

/*
//funzione stupidissima che date le componenti di una matrice come i,j restituisce l'indice lineare
int index(int i, int j){
	return( i*COL+j);
}
*/

#include "Cuda_Costant.h"
#include "Kernel/riempimento.cuh"
#include "Kernel/riempimento_random.cuh"
#include "Kernel/vectorsum.cuh"
#include "Kernel/copia.cuh"
#include "Kernel/max.cuh"
#include "Kernel/swap.cuh"
#include "Kernel/condensation.cuh"
 




class matrice
{
	float *A_host ;		//Definisco i puntatori alle variabli host
	float *A_dev ; 		//Definisco i puntatori alle variabli device
	unsigned int ROW,COL,N;

	bool flagCuda;		//se la scheda e' cudacapable posso sfruttarla!
	bool flagMemory;	//se uso la gpu avro' due copie della matrice (1 su host + 1 su device) ho bisogno di una flag di controllo che mi dica quando la versione host e' effettivamente aggiornata alla versione device
	bool flagSquare;	//flag matrice quadrata


  public:	
	unsigned int GpuByteCount;	//
        matrice(int n)		/*Creatore matrice Quadrata*/
	        {
			ROW=n; 					//creatore fissa dimensione e alloca la memoria opportuna.
			COL=ROW;
			N=ROW*COL;
			flagSquare=true;			
	 		srand (time(NULL));    			/* initialize random seed: *///Va spostato!


			//Verifico la Cuda Capability
			flagCuda=false;
  			int count;
  			cudaGetDeviceCount( &count);
			if(count>0)flagCuda=true; //cout<<"CUda test = "<< flagCuda<<endl;
			//Alloco le variabili Host
			A_host = new float[N] ();		//http://www.cplusplus.com/reference/new/operator%20new%5B%5D/
								//http://stackoverflow.com/questions/7546620/operator-new-initializes-memory-to-zero


			//Alloco le variabili device (riservo la memoria richiesta)
			unsigned int ByteSize = N*sizeof(float);
			GpuByteCount +=	ByteSize;
			if(flagCuda==true)cudaMalloc( (void **)&A_dev, ByteSize  );


 		}
                      
	matrice(int n, int m)	/*Creatore matrice Rettangolare*/
	        {
			ROW=n; 				//creatore fissa dimensione e alloca la memoria opportuna.
			COL=m;			
			N=ROW*COL;
	 		srand (time(NULL));    			/* initialize random seed: *///Va spostato!
			flagSquare=false;

			//Verifico la Cuda Capability
			flagCuda=false;
  			int count;
  			cudaGetDeviceCount( &count);
			if(count>0)flagCuda=true; //cout<<"CUda test = "<< flagCuda<<endl;

			//Alloco le variabili Host
			A_host = new float[N] ();
			//Alloco le variabili device (riservo la memoria richiesta)
			unsigned int ByteSize = N*sizeof(float);
			GpuByteCount +=	ByteSize;
			if(flagCuda==true)cudaMalloc( (void **)&A_dev, ByteSize  );

 		}		  //overload constructor http://www.cplusplus.com/doc/tutorial/classes/


        ~matrice()            	/*Distruttore*/
		{
			delete A_host;
			cudaFree( A_dev);
		}

 /*/\/\/\/\/\/\/\/\/\/\/\/\/\/\_ Metodi di Sync _/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
// private:
 public:
	void sync_HostToDevice();
	void sync_DeviceToHost();


 /*/\/\/\/\/\/\/\/\/\/\/\/\/\/\_ Metodi di Inizializzazione _/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
 public:
	void Cpu_Init(); 
	void Gpu_Init();
	void Init();
	void Cpu_Hilbert_Init(); 
	void Gpu_Hilbert_Init();
	void Hilbert_Init();
	void Cpu_Init_Rand(float, float);
	void Gpu_Init_Rand(float, float);
	void Init_Rand(float, float);
	void Resize(int,int);



 /*/\/\/\/\/\/\/\/\/\/\/\/\/\/\_ Metodi di Controllo _/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	void Cpu_print();
	void Gpu_print();
	bool print();
	bool print_tomath(const char *); 
	bool check_copy();

 /*/\/\/\/\/\/\/\/\/\/\/\/\/\/\_ Overload _/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	//assegnazione
	void Cpu_copy(const matrice& tmp);
	void Gpu_copy(const matrice& tmp);
	void operator=(const matrice& tmp);

	//bracket
	float Cpu_pick( int const i, int const j );
	float Gpu_pick( int const i, int const j );
	float* operator[]( int ); //overload dei bracket, deve ritornare il puntatare al primo elemento della riga n, così che il secondo [] restituisca l'elemento sulla riga!


	//addizione
	void Cpu_add (const matrice&);
	void Gpu_add (const matrice&);
	matrice& operator +=  (const matrice&);
	matrice operator +  (const matrice&);

	//sottrazione
	void Cpu_subtract (const matrice&);
	void Gpu_subtract (const matrice&);
	matrice& operator -=  (const matrice&);
	matrice operator -  (const matrice&);

	//prodotto per uno scalare
	void Cpu_linearproduct (const float);
	void Gpu_linearproduct (const float);
	matrice& operator *=  (const float);
	matrice operator *  (const float);

	//prodotto tra matrici
	void Cpu_matrixproduct(const matrice&);
		// Place-Holder

/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\_ Altri Metodi Algebra Lineare _/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	//trasposizione cpu, gpu, complessiva
	//permutazione di righe o colonne
	//inversa


/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\_ Metodi Ausiliari _/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	//swap di riga cpu, gpu, complessivo
	//max in riga

/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\_ Metodi Condensation _/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	bool Cpu_Max_Pivoting (int*);	//restituiscono true se esiste un pivot diverso da zero e riempiono l'argomento con l'indice
	bool Cpu_Max_Pivoting_Speedy (int*, float*);
	bool Gpu_Max_Pivoting (int*);
	bool Gpu_Max_Pivoting_Speedy (int*, float*);

	void Cpu_Division(int);
	void Gpu_Division(int);
	void Gpu_Division_Speedy(float*);

	void Cpu_Swap_Row(int,int);
	void Gpu_Swap_Row(int,int);

	void Cpu_Swap_Col(int,int);
	void Gpu_Swap_Col(int,int);

	void Cpu_Step_Condensation_Simple();
	void Gpu_Step_Condensation_Simple();
	void Gpu_Step_Condensation_Simple_Best(); //secondo i test fatti in testkernel è il modo + veloce di implementare

	bool Cpu_Condensation(float * );
	bool Gpu_Condensation(float * );
	bool Gpu_Condensation_Best(float *);
	bool Ibrid_Condensation(float * );
	bool Ibrid_Condensation_Best(float *);


	float Cpu_Determinant_Condensation();
	float Gpu_Determinant_Condensation();
	float Gpu_Determinant_Condensation_Best();
	float Ibrid_Determinant_Condensation();
	float Ibrid_Determinant_Condensation_Best();



/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\_ Metodi LU _/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/


};

/*Metodi di Sync*/
	void matrice::sync_HostToDevice()
        {
		//Copio la matrice host su quella device
		cudaMemcpy( A_dev, A_host, N*sizeof(float), cudaMemcpyHostToDevice);
		flagMemory=true;
        }

	void matrice::sync_DeviceToHost()
        {
		//Copio la matrice device su quella host
		cudaMemcpy( A_host, A_dev, N*sizeof(float), cudaMemcpyDeviceToHost);
		flagMemory=true;
        }


/*Metodi di Inizializzazione*/
        void matrice::Cpu_Init()
        {		
		//attenzione! una matrice siffatta ha determinante zero!
		for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++)A_host[i*COL+j]=COL*i+j;
		flagMemory=false;		
		//sync_HostToDevice();
        }

        void matrice::Gpu_Init()
        {		
		//attenzione! una matrice siffatta ha determinante zero!
		riempimento<<<DIM_GRID,DIM_BLOCK>>>(A_dev,N);
		flagMemory=false;
		//sync_DeviceToHost();
        }

        void matrice::Init()
        {		
		if(flagCuda){
			Gpu_Init();
			sync_DeviceToHost();

		}
		else {
			Cpu_Init();
			sync_HostToDevice();
		}
        }

	//Matrice patologica, sfruttata da articolo Haque - Maza per determinare la stabilita' numerica
        void matrice::Cpu_Hilbert_Init()
        {		
		for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++)A_host[i*COL+j]=1/((float)i+j+1);
		flagMemory=false;		
		//sync_HostToDevice();
        }

        void matrice::Gpu_Hilbert_Init()
        {		
	        dim3 block0(16,16 );
	        dim3 grid0( 64,64 );
		riempimento_Hilbert<<<grid0,block0>>>(A_dev,COL,ROW);
		flagMemory=false;
		//sync_DeviceToHost();
        }

        void matrice::Hilbert_Init()
        {		
		if(flagCuda){
			Gpu_Hilbert_Init();
			sync_DeviceToHost();

		}
		else {
			Cpu_Hilbert_Init();
			sync_HostToDevice();
		}
        }



        void matrice::Cpu_Init_Rand(float min, float max)//inizializzatore ogni elemento disposto uniformemente tra min e max
        {
		
		if(max<min){
			float dummy=max;
			max=min;min=dummy;
			}

		float delta= max-min;
		for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++)A_host[i*COL+j]=	delta * ( (float)rand() / (float)RAND_MAX ) + min;
		flagMemory=false;		
		//sync_HostToDevice();

        }

        void matrice::Gpu_Init_Rand(float min, float max)//inizializzatore ogni elemento disposto uniformemente tra min e max
        {
		
		if(max<min){
			float dummy=max;
			max=min;min=dummy;
			}

		//Inizializzo i seed per il random ogni thread avra' il suo seed
		curandState *dev_State ;


		unsigned int nThreads = DIM_GRID*DIM_BLOCK;
		unsigned int ByteSize = nThreads*sizeof(curandState);
		GpuByteCount +=	ByteSize;
		cudaMalloc( (void **)&dev_State, ByteSize );
		int seed =time( 0 );
		initRandom<<<DIM_GRID,DIM_BLOCK>>>(dev_State,seed);


		//Riempio le variabili device

		riempimento_random<<<DIM_GRID,DIM_BLOCK>>>(A_dev,N,dev_State,min,max);
	
		//riempio le variabili host
		//sync_DeviceToHost();
		flagMemory=false;

		//Disalloco la memoria riservata sulla scheda
		cudaFree( dev_State);
		GpuByteCount -=	ByteSize;


        }

        void matrice::Init_Rand(float min, float max)//inizializzatore ogni elemento disposto uniformemente tra min e max
        {
		//questa implementazione del curand non sembra particolarmente efficiente.. per questo utilizzo in ogni caso il rand del c++ per inizializzare.. Notare pero' che su jacobi il curand e' molto piu' performante!
		Cpu_Init_Rand(min, max);
		if(flagCuda)sync_HostToDevice();

/*		if(flagCuda){
			Gpu_Init_Rand(min, max);
			sync_DeviceToHost();

		}
		else {
			Cpu_Init_Rand(min, max);
			sync_HostToDevice();
		}*/
        }


        void matrice::Resize(int n, int m)//inizializzatore ogni elemento disposto uniformemente tra min e max
        {
		//Riaggiorno gli attributi della classe
		ROW=n;                          //creatore fissa dimensione e alloca la memoria opportuna.
                COL=m;
                N=ROW*COL;
                flagSquare=(ROW=COL);

		//Rialloco la copia Host
		delete A_host;
                A_host = new float[N] ();
 
                //RiAlloco le variabili device (riservo la memoria richiesta)
		cudaFree( A_dev);
               	 unsigned int ByteSize = N*sizeof(float);
                	//GpuByteCount += ByteSize;
                if(flagCuda==true)cudaMalloc( (void **)&A_dev, ByteSize  );
        }


/*Metodi di Controllo*/
        void matrice::Cpu_print()
        {
		for(int i=0 ; i<ROW ; i++){
			for(int j=0 ; j<COL ; j++){
				//printf(" %.1f ",A[i*COL+j]);
				cout<< A_host[i*COL+j] << " ";
			}
			cout<<endl;
		}
		cout<<endl;        
	}

        void matrice::Gpu_print()		//potrebbe essere piu' conveniente copiare intermente il contenuto della gpu sull'host e poi stamparlo
        {
		for(int i=0 ; i<ROW ; i++){
			for(int j=0 ; j<COL ; j++){
				//printf(" %.1f ",A[i*COL+j]);
				cout<< Gpu_pick(i,j) << " ";
			}
			cout<<endl;
		}
		cout<<endl;        
	}

	bool matrice::print()
        {
		bool flagSuccess=true;
		if(flagCuda && !flagMemory){
			cout<<"!!!!   Attenzione  !!!!\n Copia gpu non aggiornata alla copia cpu\n Gpu_print() per stampa gpu\n";
			flagSuccess=false;
		}
		Cpu_print();
		return(flagSuccess);
        }


	//richiede #include <fstream>
	//http://reference.wolfram.com/mathematica/howto/InputAMatrix.html
        bool matrice::print_tomath(const char *FILE_NAME)
        {
  		ofstream myfile;
  		myfile.open (FILE_NAME);

		for(int i=0 ; i<ROW ; i++){
			for(int j=0 ; j<COL ; j++){
				//printf(" %.1f ",A[i*COL+j]);
				myfile << A_host[i*COL+j]<< " ";
			}
			myfile <<endl;
		}
		
  		myfile.close();
		bool flagSuccess=true;
		if(flagCuda && !flagMemory){
			cout<<"!!!!   Attenzione  !!!!\n Copia gpu non aggiornata alla copia cpu\n Gpu_print() per stampa gpu\n";
			flagSuccess=false;
		}
		return(flagSuccess);
	}


	bool matrice::check_copy()        {  //att: vedi gpu print, qui la logica e' molto diversa!

		float A_dev_copy[N];
		//Copio la matrice host su quella device
		cudaMemcpy( A_dev_copy, A_dev, N*sizeof(float), cudaMemcpyDeviceToHost);  

		bool flagSuccess=true;
		for(int i=0 ; i<ROW ; i++){
			for(int j=0 ; j<COL ; j++){
				if( A_host[i*COL+j]!=A_dev_copy[i*COL+j]){
				flagSuccess=false;
				cout<<" inconsistenza matrici gpu-cpu alla posizione ( "<<i<<" , "<<j<<" )"<<endl;
				}
			}
		}
		
		return(flagSuccess);
	}

/*Metodi di Overload*/
#include "Overload.cuh"

/*Metodi per La Condensazione*/
#include "Condensation.cuh"





 
