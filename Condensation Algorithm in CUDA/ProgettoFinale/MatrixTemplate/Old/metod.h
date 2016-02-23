



 						/*Metodi*/
        template <class T> void matrice<T>::Init()
        {
		for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++)A[i*ROW+j]=i*ROW+j;
        }

        template <class T> void matrice<T>::print()
        {
		for(int i=0 ; i<ROW ; i++){
			for(int j=0 ; j<COL ; j++){
				//printf(" %.1f ",A[i*ROW+j]);
				cout<< A[i*ROW+j] << " ";
			}
		cout<<endl;
		}
        }



 /*/\/\/\/\/\/\/\/\/\/\/\/\/\/\_ OverLoad _/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/

	template <class T> matrice<T>& matrice<T>::operator+= (const matrice& In) {
		//if(In.ROW != ROW)cout<<"errore dimensione errata"<<endl;
		for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++)A[i*ROW+j] += In.A[i*ROW+j] ;

		return *this;
	}

	template <class T> matrice<T> matrice<T>::operator+ (const matrice& In) {
		//if(In.ROW != ROW)cout<<"errore dimensione errata"<<endl;
		matrice<T> result = *this;	// Make a deep copy of this Vector3D.
		result += In;			// Use existing addition code.
		return result;
	}

	template <class T> matrice<T>& matrice<T>::operator-= (const matrice& In) {
		//if(In.ROW != ROW)cout<<"errore dimensione errata"<<endl;
		for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++)A[i*ROW+j] -= In.A[i*ROW+j] ;

		return *this;
	}

	template <class T> matrice<T> matrice<T>::operator- (const matrice& In) {
		//if(In.ROW != ROW)cout<<"errore dimensione errata"<<endl;
		matrice<T> result = *this;	
		result -= In;			
		return result;
	}


	template <class T> matrice<T>& matrice<T>::operator*= (const T& lambda) {
		for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++)A[i*ROW+j] *= lambda;

		return *this;
	}

	template <class T> matrice<T> matrice<T>::operator* (const T& lambda) {
		matrice<T> result = *this;	
		result *= lambda;			
		return result;
	}

	template <class T> matrice<T>& matrice<T>::operator*= (const matrice& In) {
		//if(In.COL != ROW)cout<<"errore dimensione errata"<<endl;
		T sum ;
		for(int i=0 ; i<ROW ; i++)for(int j=0 ; j<COL ; j++){
			sum = 0;
			for(int k=0; k<ROW; k++)
				sum+=A[i*ROW+k]*In.A[k*ROW+j] ;
			A[i*ROW +j]= sum;
			}
		return *this;
	}

	template <class T> matrice<T> matrice<T>::operator* (const matrice& In) {
		//if(In.ROW != ROW)cout<<"errore dimensione errata"<<endl;
		matrice<T> result = *this;	
		result *= In;			
		return result;
	}

	template <class T>T* matrice<T>::operator[]( int const n )
   		{
      			return &A[ROW*n];
   		}


