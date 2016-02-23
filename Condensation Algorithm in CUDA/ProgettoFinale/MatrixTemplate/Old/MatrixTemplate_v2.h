/*
serve una classe matrice se voglio poter vedere come implementare i metodi di evoluzione
http://www.cplusplus.com/doc/tutorial/classes/

Ancora meglio servirebbe un template!
http://www.cplusplus.com/doc/tutorial/templates/
http://www.codeproject.com/Articles/268849/An-Idiots-Guide-to-Cplusplus-Templates-Part#OperOver

Inoltre servirebbe anche una "specializzazione di questa classe" al tipo pernsonalizzato numero complesso, perchè in qualche caso serve il coniugio!


*/

/*
//funzione stupidissima che date le componenti di una matrice come i,j restituisce l'indice lineare
int index(int i, int j){
	return( i*ROW+j);
}
*/
template <class T> class matrice
{
	T *A ;
	int ROW,COL;

  public:	
        matrice(int n)		/*Creatore*/
	        {
			ROW=n; 				//creatore fissa dimensione e alloca la memoria opportuna.
			COL=ROW;			
			A = new T[(ROW*COL)];		//http://www.cplusplus.com/reference/new/operator%20new%5B%5D/
 		}
                      
	matrice(int n, int m)	/*Creatore*/
	        {
			ROW=n; 				//creatore fissa dimensione e alloca la memoria opportuna.
			COL=m;			
			A = new T[(ROW*COL)];		//http://www.cplusplus.com/reference/new/operator%20new%5B%5D/
 		}		  //overload constructor http://www.cplusplus.com/doc/tutorial/classes/


//        ~matrice()            	/*Distruttore*/ mi da errori strani!
//		{
//			delete A;
//		}


 /*/\/\/\/\/\/\/\/\/\/\/\/\/\/\_ Metodi _/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	void Init();     		  
	void print();

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


/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\_ Altri Metodi di ALGEBRA LINEARE _/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/


};
/*----------------------------------------------------------------*/


#include "metod.h"


