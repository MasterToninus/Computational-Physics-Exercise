
template <class T> matrice<T> matrice<T>::Chio_Condensation () { //versione semplice non controlla se il pivot e nullo! 
		matrice<T> Out(COL-1,ROW-1);
		T pivot =A[0];
		for(int i=0 ; i<Out.ROW ; i++)for(int j=0 ; j<Out.COL ; j++)Out[i][j]=pivot*A[(i+1)*COL+j+1] -A[j+1]*A[(i+1)*COL];
		return Out;
	}

template <class T> matrice<T> matrice<T>::Arbitrary_Condensation (int l) { //versione che in ingresso prende il pivot 
		matrice<T> Out(COL-1,ROW-1);
		T pivot =A[l];
		int i,j;
		for(i=0 ; i<Out.ROW ; i++)for(j=0 ; j<Out.COL ; j++){
			T result;
			if(j>=l)result = pivot*A[(i+1)*COL+j+1] -A[j+1]*A[(i+1)*COL+l];
			else result = -pivot*A[(i+1)*COL+j];//+A[j]*A[(i+1)*COL+j+1]; //attenzione! ho modificato la formula!
		Out[i][j]=result;
		}
		return Out;
	}

  
template <class T> matrice<T> matrice<T>::SalemSaid_Condensation () {
		//trova l'indice di colonna del primo elemento non nulla nella riga 0 
		int l=0;
		while (A[l]==0)	l++; 

		T pivot =A[l];
cout<<" pivot (0,"<<l<<") = "<<pivot<<endl;
		

		return Arbitrary_Condensation(l);
	}

template <class T> matrice<T> matrice<T>::Pivotal_Condensation () {
		//trova l'indice di colonna del elemento nella riga 0 più vicino ad 1 
		int l=0;
		T pivot =A[l]-1;
		for(int j=1; j<COL ; j++){
			T test= A[j]-1;
			if(test < pivot && test > -pivot)l=j;
		}

		pivot =A[l];
cout<<" pivot (0,"<<l<<") = "<<pivot<<endl;
		

		return Arbitrary_Condensation(l);
	}




//METODI PER IL CALCOLO DEL DETERMINANTE

template <class T> T matrice<T>::Determinant_Chio_Condensation () { //versione semplice non controlla se il pivot e nullo! 
		matrice<T>Out(0);
		Out = *this;
		int N= ROW;
		for(int k=0 ; k<=N-2 ; k++){
			Out=Out.Chio_Condensation();
			Out.print();
		}
		return Out[0][0];
	}

template <class T> T matrice<T>::Determinant_SalemSaid_Condensation () { //versione semplice non controlla se il pivot e nullo! 
		matrice<T>Out(0);
		Out = *this;
		int N= ROW;
		for(int k=0 ; k<=N-2 ; k++){
			Out=Out.SalemSaid_Condensation();
			Out.print();
		}
		return Out[0][0];
	}
	
	template <class T> T matrice<T>::Determinant_Pivotal_Condensation () { //versione semplice non controlla se il pivot e nullo! 
		matrice<T>Out(0);
		Out = *this;
		int N= ROW;
		for(int k=0 ; k<=N-2 ; k++)Out=Out.Pivotal_Condensation();
		return Out[0][0];
	}
