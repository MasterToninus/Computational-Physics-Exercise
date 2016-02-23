/*
ALGORITMO DI SALEM SAID
*/



template <class T> bool matrice<T>::SalemSaid_Pivoting (int* pivot_i) { //metodo che prende come pivot salem said
		//trova l'indice di colonna del primo elemento non nullo nella riga 0 
		
		int l=0;
		while (A[l]==0)	l++; 
		*pivot_i=l;
//			cout<<" pivot (0,"<<l<<") = "<<A[l]<<endl;
		if(l==COL)return false;
		else return true;
	}

template <class T> matrice<T> matrice<T>::Step_Condensation (int l) { //versione che in ingresso prende il pivot 
		matrice<T> Out(COL-1,ROW-1);
		T pivot =A[l];
		int i,j;
		for(i=0 ; i<Out.ROW ; i++)for(j=0 ; j<Out.COL ; j++){
			T result;
			if(j>=l)result = pivot*A[(i+1)*COL+j+1] -A[j+1]*A[(i+1)*COL+l];
			else result = A[j]*A[(i+1)*COL+l]-pivot*A[(i+1)*COL+j]; 
		Out[i][j]=result;
		}
		return Out;
	}

template <class T> bool matrice<T>::SalemSaid_Condensation (T* pivot) {

		int pivot_j;
		bool test;

		matrice<T>Dummy(0);
		Dummy = *this;
		for(int k=0 ; k<ROW-1 ; k++){
			if(Dummy.SalemSaid_Pivoting (&pivot_j)){
				if(Dummy.ROW<=2)pivot[k]=1;
				else pivot[k]=pow((T)1/Dummy[0][pivot_j],Dummy.ROW-2);
				
				Dummy=Dummy.Step_Condensation(pivot_j);
				test=true;
			}
			else {
				test=false;
				cout<<" Matrice singolare"<<endl;
				pivot[k]=0;
				exit;
				}
		}
		pivot[ROW-1]=Dummy[0][0];
		return test;
	}

template <class T> T matrice<T>::SalemSaid_Determinant () {
		T condensation_array [ROW];
		SalemSaid_Condensation(condensation_array);

		return produttoria<T>(condensation_array,ROW);
}


/*
ALGORITMO CON IL  MIO PIVOTING
 ottimizzato per il tipo di matrici che prendo in esame io:
	- grandi
	- dense
	- entry < max (scelto a piacere)
	- valore delle entry uniformemente distribuito tra -max e max

*/


template <class T> bool matrice<T>::Max_Pivoting (int* pivot_i) {  
		//trova l'elemento della prima colonna in modulo + grande 
		int l=0; T max = A[l];

		for(int j=1; j<COL ; j++){
			if (max<=0)max = -max;	// considero il valore assoluto
			T test= A[j];
			if( test > max || -test > max){
				l=j;
				max = A[l];
			}
		}
		*pivot_i=l;
//			cout<<" pivot (0,"<<l<<") = "<<A[l]<<endl;
		if(A[l]==0)return false;
		else return true;
	}

template <class T> matrice<T> matrice<T>::Step_Condensation_Simple (int l) { //versione che in ingresso prende il pivot che e' stato precedentemente posto ad 1
		matrice<T> Out(COL-1,ROW-1);
		int i,j;
		for(i=0 ; i<Out.ROW ; i++)for(j=0 ; j<Out.COL ; j++){
			T result;
			if(j>=l)result = A[(i+1)*COL+j+1] - A[j+1]*A[(i+1)*COL+l];
			else result = A[j]*A[(i+1)*COL+l] - A[(i+1)*COL+j]; 
		Out[i][j]=result;
		}
		return Out;
	}

template <class T> bool matrice<T>::Mia_Condensation (T* pivot) {

		int pivot_j;
		bool test;
		int N=ROW;

		matrice<T>Dummy(0);
		Dummy = *this;
		for(int k=0 ; k<ROW-1 ; k++){
			if(Dummy.Max_Pivoting (&pivot_j)){

				pivot[k]=Dummy[0][pivot_j];

				divisione(Dummy[0], pivot_j,Dummy.ROW);
//	cout<<" divido per pivot A[0]["<<pivot_j<<"] = "<<pivot[k]<<endl;	Dummy.print();

				Dummy=Dummy.Step_Condensation_Simple(pivot_j);
//	cout<<" Condenso"<< endl;	Dummy.print();
				test=true;
			}
			else {
				test=false;
				cout<<" Matrice singolare"<<endl;
				pivot[k]=0;
				exit;
				}
		}
		pivot[ROW-1]=Dummy[0][0];
		return test;
	}



template <class T> T matrice<T>::Mia_Determinant () {
		T condensation_array [ROW];
		Mia_Condensation(condensation_array);

		return produttoria<T>(condensation_array,ROW);
}

