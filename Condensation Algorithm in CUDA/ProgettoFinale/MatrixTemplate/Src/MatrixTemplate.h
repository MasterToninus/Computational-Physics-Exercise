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

template <class T> class matrice
{
	T *A ;
	int ROW,COL;
	//bool flagCuda;	//se la scheda e' cudacapable posso sfruttarla!
	//bool flagMemory;	//se uso la gpu avro' due copie della matrice (1 su host + 1 su device) ho bisogno di una flag di controllo che mi dica quando la versione host e' effettivamente aggiornata alla versione device


  public:	
        matrice(int n)		/*Creatore matrice Quadrata*/
	        {
			ROW=n; 				//creatore fissa dimensione e alloca la memoria opportuna.
			COL=ROW;			
			A = new T[(ROW*COL)] ();		//http://www.cplusplus.com/reference/new/operator%20new%5B%5D/
								//http://stackoverflow.com/questions/7546620/operator-new-initializes-memory-to-zero
			/* initialize random seed: *///Va spostato!
	 		srand (time(NULL));
 		}
                      
	matrice(int n, int m)	/*Creatore matrice Rettangolare*/
	        {
			ROW=n; 				//creatore fissa dimensione e alloca la memoria opportuna.
			COL=m;			
			A = new T[(ROW*COL)];		//http://www.cplusplus.com/reference/new/operator%20new%5B%5D/
			/* initialize random seed: *///Va spostato!
	 		srand (time(NULL));
 		}		  //overload constructor http://www.cplusplus.com/doc/tutorial/classes/


//        ~matrice()            	/*Distruttore*/ mi da errori strani!
//		{
//			delete A;
//		}


 /*/\/\/\/\/\/\/\/\/\/\/\/\/\/\_ Metodi di Test _/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	void Init(); 
	void Init_Rand();  	//serve la libreria per il random	  
	void Init_Rand(int);
	void print();
	void print_tomath(const char *);

 /*/\/\/\/\/\/\/\/\/\/\/\/\/\/\_ OverLoad _/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	//http://www.cplusplus.com/doc/tutorial/templates/
	//http://www.stanford.edu/class/cs106l/course-reader/Ch10_OperatorOverloading.pdf



	matrice<T>& operator +=  (const matrice&);
	matrice<T> operator +  (const matrice&);

	matrice<T>& operator -=  (const matrice&);
	matrice<T> operator -  (const matrice&);

	matrice<T>& operator *=  (const T&);
	matrice<T> operator *  (const T&);	//il prodotto cosi' definito non e' commutativo! nel senso che scalare*matrice non funziona	

	matrice<T>& operator *=  (const matrice&);
	matrice<T> operator *  (const matrice&);

	T* operator[]( int ); //overload dei bracket, deve ritornare il puntatare al primo elemento della riga n, così che il secondo [] restituisca l'elemento sulla riga!
	//http://stackoverflow.com/questions/15762878/c-overload-operator

	T* operator=(const matrice&);


/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\_Altri di Algebra LIneare Metodi _/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	matrice<T> transpose();
	matrice<T> minor_submatrix (int i_canc, int j_canc);
	matrice<T> swap_row(int, int);
	matrice<T> swap_column(int, int);

	matrice<T> permutation_row(int*);
	matrice<T> permutation_column(int*);

/* METODI DI LU DECOMPOSITION */
	void LUDecomposition();
	matrice<T> LUDecomposition_leftlooking();

	matrice<T> LUDecomposition_rightlooking();	

	matrice<T> LUDecomposition_crout();

/* METODI DI LU DECOMPOSITION PIVOT */
	int max_incolumn_rowindex (int); 
	int maxscaled_incolumn_rowindex (int);
	int max_inrow_columnindex (int);

	matrice<T> LUDecomposition_rightlooking_Pivot(int*,int & );

/* METODI DI CONDENSATION */
//	matrice<T> Chio_Condensation();
//	matrice<T> Arbitrary_Condensation (int) ;
//	matrice<T> SalemSaid_Condensation();
//	matrice<T> Pivotal_Condensation();

//	T Determinant_Chio_Condensation () ;
//	T Determinant_SalemSaid_Condensation () ;
//	T Determinant_Pivotal_Condensation () ;

	bool SalemSaid_Pivoting (int*);
	matrice<T> Step_Condensation (int) ;
	bool SalemSaid_Condensation (T*);
	T SalemSaid_Determinant ();

	bool Max_Pivoting (int*);
	matrice<T> Step_Condensation_Simple (int) ;
	bool Mia_Condensation (T*);
	T Mia_Determinant ();





/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\_Altri di Algebra LIneare Metodi _/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	//metodo inversa (richiede l'inversa)
	//metodo adj (agisce come la trasposta a meno che il tipo non sia un complesso per cui deve anche coniugare)


/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\_Altri di Algebra LIneare Metodi _/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	//http://en.wikipedia.org/wiki/Givens_rotation
	//http://en.wikipedia.org/wiki/Jacobi_eigenvalue_algorithm
	//Questione Lasciata in sospeso! mi dedichero' alla prima classe di problemi




};
/*----------------------------------------------------------------*/







 						/*Metodi*/
        template <class T> void matrice<T>::Init()
        {
		//attenzione! una matrice siffatta ha determinante zero!
		for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++)A[i*COL+j]=i+j;
        }

        template <class T> void matrice<T>::Init_Rand()
        {


		for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++)A[i*COL+j]=(T)(rand() % 10 + 1);
        }

        template <class T> void matrice<T>::Init_Rand(int max)//inizializzatore ogni elemento disposto uniformemente tra -max e max
        {

		for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++)A[i*COL+j]=	max * (2*( (double)rand() / (double)RAND_MAX ) - 1);

        }

        template <class T> void matrice<T>::print()
        {
		for(int i=0 ; i<ROW ; i++){
			for(int j=0 ; j<COL ; j++){
				//printf(" %.1f ",A[i*COL+j]);
				cout<< A[i*COL+j] << " ";
			}
			cout<<endl;
		}
		cout<<endl;        
	}

	//richiede #include <fstream>
	//http://reference.wolfram.com/mathematica/howto/InputAMatrix.html
        template <class T> void matrice<T>::print_tomath(const char *FILE_NAME)
        {
  		ofstream myfile;
  		myfile.open (FILE_NAME);

		for(int i=0 ; i<ROW ; i++){
			for(int j=0 ; j<COL ; j++){
				//printf(" %.1f ",A[i*COL+j]);
				myfile << A[i*COL+j]<< " ";
			}
			myfile <<endl;
		}
		
  		myfile.close();

	}



 /*/\/\/\/\/\/\/\/\/\/\/\/\/\/\_ OverLoad _/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/

	template <class T> matrice<T>& matrice<T>::operator+= (const matrice& In) {
		if(In.ROW != ROW && In.COL != COL)cout<<"errore: dimensione incompatibile"<<endl;
		for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++)A[i*COL+j] += In.A[i*COL+j] ;

		return *this;
	}

	template <class T> matrice<T> matrice<T>::operator+ (const matrice& In) {
		matrice<T> result = *this;	// Make a deep copy of this Vector3D. attenzione, cosi' facendo la nuova matrice ha lo stesso indirizzo
		result += In;			// Use existing addition code.
		return result;
	}

	template <class T> matrice<T>& matrice<T>::operator-= (const matrice& In) {
		if(In.ROW != ROW && In.COL != COL)cout<<"errore: dimensione incompatibile"<<endl;
		for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++)A[i*COL+j] -= In.A[i*COL+j] ;

		return *this;
	}

	template <class T> matrice<T> matrice<T>::operator- (const matrice& In) {
		matrice<T> result = *this;	
		result -= In;			
		return result;
	}


	template <class T> matrice<T>& matrice<T>::operator*= (const T& lambda) {
		for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++)A[i*COL+j] *= lambda;

		return *this;
	}

	template <class T> matrice<T> matrice<T>::operator* (const T& lambda) {
		matrice<T> result = *this;	
		result *= lambda;			
		return result;
	}

	template <class T> matrice<T>& matrice<T>::operator*= (const matrice& In) {
		if(In.ROW != COL )cout<<"errore: dimensione incompatibile"<<endl;

		matrice<T> dummy = *this; //copio la matrice originale per poter fare i calcoli
		COL= In.COL;		  //Rialloco la memoria per la matrice risultato
		delete A ;
		A= new T[(ROW*COL)];
	
		T sum ;
		for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++){
			sum = 0;
			for(int k=0; k<In.ROW; k++)
				sum+= dummy.A[i*dummy.COL+k] * In.A[k*In.COL+j] ;
			A[i*COL +j]= sum;
			}
		
		return *this;
	}

	template <class T> matrice<T> matrice<T>::operator* (const matrice& In) {
		if(In.ROW != COL )cout<<"errore: dimensione incompatibile"<<endl;
		T sum ;
		matrice<T> result (ROW,In.COL);

		for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<In.COL ; j++){
			sum = 0;
			for(int k=0; k<COL; k++)
				sum+=A[i*COL+k]*In.A[k*In.COL+j] ;
			result.A[i*In.COL +j]= sum;
			}

		return result;
	}

	template <class T>T* matrice<T>::operator[]( int const n )
   		{
      			return &A[COL*n];
   		}

	template <class T>T* matrice<T>::operator=( const matrice& tmp )
   	{
		//http://stackoverflow.com/questions/13536115/matrix-class-and-operator-overloading

	        this->ROW = tmp.ROW;
	        this->COL = tmp.COL;
		A = new T[(ROW*COL)] (); //specifico all'assegnazione di non copiarsi il puntatore!
		for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++)A[i*COL +j]=tmp.A[i*COL +j];
	
	}


//////////////////////////////////////////////////////////////////////////
/* METODI AUSILIARI */
#include "Ausiliary_Cpu.h"


//////////////////////////////////////////////////////////////////////////
/* METODI DI LU DECOMPOSITION */
#include "LU_Nopivot_Cpu.h"
#include "LU_Pivot_Cpu.h"





//////////////////////////////////////////////////////////////////////////
/* METODI DI Condensation */
#include "Condensation_Cpu.h"





