template <class T> matrice<T> matrice<T>::transpose () {
		matrice<T> Out(COL,ROW);//il risultato ha tante righe quante colonne ha l'altra! ecc
		for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++)Out.A[j*Out.COL+i]=A[i*COL+j];
		return Out;
	}

template <class T> matrice<T> matrice<T>::minor_submatrix (int i_canc, int j_canc) {
		matrice<T> Out(ROW-1,COL-1);//il risultato e' una matrice con una riga e una colonna in meno
		for(int i=0 ; i<ROW ; i++){
			int i_eff=i;
			if( i>i_canc)i_eff=i-1;

			for(int j=0 ; j<COL ; j++){
				int j_eff=j;
				if( j>j_canc)j_eff--;
				Out[i_eff][j_eff]=A[i*COL+j];
			}
		}	
		return Out;
	}

template <class T> matrice<T> matrice<T>::swap_row(int i1, int i2){
	matrice<T> Out(1);//il risultato ha tante righe quante colonne ha l'altra! ecc
	Out= *this;//copio

	for(int j=0 ; j<COL ; j++){	//swap
	Out[i1][j]=A[i2*COL+j];
	Out[i2][j]=A[i1*COL+j];
	}
	return Out;
}

template <class T> matrice<T> matrice<T>::swap_column(int j1, int j2){
	matrice<T> Out(1);//il risultato ha tante righe quante colonne ha l'altra! ecc
	Out= *this;//copio

	for(int i=0 ; i<ROW ; i++){	//swap
	Out[i][j1]=A[i*COL+j2];
	Out[i][j2]=A[i*COL+j1];
	}
	return Out;
}


template <class T> matrice<T> matrice<T>::permutation_row(int *P){
	matrice<T> Out(1);//il risultato ha tante righe quante colonne ha l'altra! ecc
	Out= *this;//copio

		for(int k=0 ; k<ROW ; k++){	//swap
			for(int j=0 ; j<COL ; j++){
				Out[k][j]=A[P[k]*COL+j];
			}
		}
	return Out;
}

template <class T> matrice<T> matrice<T>::permutation_column(int *P){
	matrice<T> Out(1);//il risultato ha tante righe quante colonne ha l'altra! ecc
	Out= *this;//copio

		for(int k=0 ; k<ROW ; k++){	//swap
			for(int i=0 ; i<ROW ; i++){
				Out[i][k]=A[i*COL + P[k]];
			}
		}
	return Out;
}
