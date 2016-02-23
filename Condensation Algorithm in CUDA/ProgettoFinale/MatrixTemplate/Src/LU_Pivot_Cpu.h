/* Da rivedere !*/

//metodo ausiliario utilizzato per il pivot parziale // cio' serve anche per il pivot di conde
template <class T> int matrice<T>::max_incolumn_rowindex (int j_test) {
		int imax;
		T big=0;

		for(int i=0 ; i<ROW ; i++){

			T temp = A[i*COL+j_test];
			if(temp>big || temp<(-big)){
				big=temp;
				imax=i;
			}


			//versione che utilizza c math
/*			T temp = abs(A[i*COL+j_test]);
			if(temp>big){
				big=temp;
				imax=i;
			}*/

		}	
		return imax;
	}
template <class T> int matrice<T>::max_inrow_columnindex (int i_test) {
		int jmax;
		T big=0;

		for(int j=0 ; j<COL ; j++){

			T temp = A[i_test*COL+j];
			if(temp>big || temp<(-big)){
				big=temp;
				jmax=j;
			}


			//versione che utilizza c math
/*			T temp = abs(A[i*COL+j_test]);
			if(temp>big){
				big=temp;
				imax=i;
			}*/

		}	
		return jmax;
	}

/* Da rivedere fin qui!*/


//metodo di Lu con pivot (fondamentalmente scopiazzato dalle recipes) con solo in piu' il riempimento di un vettore  P[n] che tiene conto delle permutazioni che sono state usate

template <class T> matrice<T> matrice<T>::LUDecomposition_rightlooking_Pivot(int *P, int &sign) {
	
		int n= ROW;		// per semplicita' salvo il numero di elementi per riga
		const T TINY=1.0e-14;	//se la matrice e' singolare prima o poi avro' un elemento diagonale zero per cui dividere, ma io voglio un template che funzioni con variabili di ogni tipo! quindi qui ci sono possibili problemi con gli interi
		T temp;T big;			// variabile dummy
		sign=1;			// variabile per tenere conto del segno della permutazione totale utilizzata 

		matrice<T> lu(0);// nel recipes viene fatto come member initialization http://www.cplusplus.com/doc/tutorial/classes/
		lu = *this;

		for(int i=0 ; i<n ; i++)P[i]=i; //inizializzo il vettore delle permutazioni

		
//Fase 1: scrivo l'implicit scaling di ogni riga
		T vv[n];
		for(int i=0 ; i<n ; i++){
			int j = max_inrow_columnindex (i);
			big = A[i*COL+j];
			vv[i]=(T)1/big;
			vv[i]=1;
		}

/*INIZIO IL CICLOOO*///cout<<"INIZIO IL CICLO"<<endl;
		int i,j,k;	//alloco gli indici una volta per tutte
		for( k=0; k<n; k++){  //Ciclo ogni cornice
//Fase 2: Identifico riga pivotale della cornice
			//cout<<"IDENTIFICO RIGA PIVOTALE"<<endl;
			big=0;
			int imax;
			for( i=k; i<n; i++){
				temp=vv[i]*lu[i][k];
				if(temp>big || temp<(-big)){
					big=temp;
					imax=i;
				}				
			}


//Fase 3: permuto la matrice di conseguenza
			//cout<<"PERMUTAZIONE"<<endl;
			if(k != imax){cout<<"PERMUTAZIONE di "<<imax<<" in "<<k<<endl;
				for(j=0; j<n ; j++){
					temp=lu[imax][j];
					lu[imax][j]=lu[k][j];			
					lu[k][j]=temp;
				}
				sign = - sign;	       //cambio segno
				vv[imax]=vv[k]; //tengo conto della permutazione anche per quanto riguarda la lista pivotale
			}
			int tempi=P[imax];
			P[imax]=P[k];
			P[k]=tempi;	       //storo la permutazione effettivamente applicata!

			lu.print();
//Fase 4: uso il metodo di LUDEC con la matrice  permutata
			//cout<<"INIZIO LUDECOMP"<<endl;
			if (lu[k][k]==0) lu[k][k]=TINY; //se i pivot sono zero li pongo ad un numero piccolo cosi' non segmento!
			for( i=k+1;i<n;i++){
				temp=lu[i][k]/=lu[k][k];
				for( j=k+1;j<n;j++){
					lu[i][j]-=temp*lu[k][j];
				}	
			}
		}
		return lu;
	}




