/* Implementazione banale del metodo pag 50 recipes LU DECOMPOSITION LEFT LOOKING (recipes dice crout ma volendo quello e' diverso*/
// Senza Pivoting! calcolo la matrice cosi' come e' ( in ogni caso dovrebbe funzionare per le matrici costituite da interi... no! perche' c'e' una divisione! )
// senza utilizzo saggio della memoria che suggerisce le recipes
// senza verificare se la matrice sia quadrata

       template <class T> void matrice<T>::LUDecomposition()
        {
		int n= ROW;		// per semplicita' salvo il numero di elementi per riga
		matrice<T> L (n);	//matrice lower diagonal
		matrice<T> U (n);	//matrice upper diagonal
		for(int i=0 ; i<n ; i++)L[i][i]=1;

		const T TINY=1.0e-14;
		for(int j=0 ; j<n ; j++){
			for(int i=0; i<=j; i++){
				U[i][j]= A[i*n+j];
				for(int k=0; k<=i-1;k++){ // se k>i-1 il ciclo non parte! quindi sono a posto
					U[i][j]-= ( L[i][k] )*( U[k][j]);
				}
			}

			T temp= U[j][j];
			if (temp==0) temp=TINY; //se i pivot sono zero li pongo ad un numero piccolo cosi' non segmento!

			for(int i=j+1; i<n; i++){
				L[i][j]= A[i*n+j];
				for(int k=0; k<=j-1;k++){
					L[i][j]-=L[i][k]*U[k][j];
				}
				L[i][j] /=temp; //con gli interi avrei problemi con questa divisione! (infatti non va!)
			}
		}
		//magari usare http://hughm.cs.ukzn.ac.za/~murrellh/os/notes/ncurses.html per formatarre meglio questo output
		cout<<"L= "<<endl;	L.print();
		cout<<"U= "<<endl;	U.print();
		cout<<"L*U - A= "<<endl;(L*U-*this).print();

        }

//variante con utilizzo astuto della memoria,non e' scopiazzato da recipes (quello e' in realta' il right looking!)

	template <class T> matrice<T> matrice<T>::LUDecomposition_leftlooking() {
		matrice<T> lu(0);		
		lu = *this;	//voglio fare una copia dell'elemento this! ma nelle sue variabili c'e' un puntatore! per questo ho definito opportunamente l'operatore di assegnazione!
				//i puntatori devono essere diversi! cio' che deve essere uguale sono le componenti	cout<<A<<"\t"<<lu.A<<endl;
				// per questo non devo fare matrice<T> lu =*this;perche ne realizzerebbe una hard copy!

		int n= ROW;			// per semplicita' salvo il numero di elementi per riga
		const T TINY=1.0e-14;		//se la matrice e' singolare prima o poi avro' un elemento diagonale zero per cui dividere, ma io voglio un template che funzioni con variabili di ogni tipo! quindi qui ci sono possibili problemi con gli interi
		
		for(int j=0 ; j<n ; j++){
			if (lu[j][j]==0) lu[j][j]=TINY; //se i pivot sono zero li pongo ad un numero piccolo cosi' non segmento!
			for(int i=0; i<=j; i++){
				for(int k=0; k<=i-1;k++){ // se k>i-1 il ciclo non parte! quindi sono a posto
					lu[i][j]-= ( lu[i][k] )*( lu[k][j]);
				}
			}

			T temp= lu[j][j];
			if (temp==0) temp=TINY; //se i pivot sono zero li pongo ad un numero piccolo cosi' non segmento!

			for(int i=j+1; i<n; i++){
				for(int k=0; k<=j-1;k++){
					lu[i][j]-=lu[i][k]*lu[k][j];
				}
				lu[i][j] /=temp; //con gli interi avrei problemi con questa divisione! (infatti non va!)
			}
		}

		return lu;
	}





/*Questa e' la LU Decomposition di right looking!*/
//scopiazzato da recipes (quello e' in realta' il right looking!)

/* Implementazione banale del metodo di F7 e recipes */
// Senza Pivoting! calcolo la matrice cosi' come e' ( in ogni caso dovrebbe funzionare per le matrici costituite da interi... no! perche' c'e' una divisione! )
// senza verificare se la matrice sia quadrata
// Variante di Crout
	template <class T> matrice<T> matrice<T>::LUDecomposition_rightlooking() {
		matrice<T> lu(0);		
		lu = *this;		// nel recipes viene fatto come member initialization http://www.cplusplus.com/doc/tutorial/classes/
		int n= ROW;			// per semplicita' salvo il numero di elementi per riga
		const T TINY=1.0e-14;	//se la matrice e' singolare prima o poi avro' un elemento diagonale zero per cui dividere, ma io voglio un template che funzioni con variabili di ogni tipo! quindi qui ci sono possibili problemi con gli interi
		T temp;				// variabile dummy
		lu = *this;
		for(int k=0; k<n; k++){
			if (lu[k][k]==0) lu[k][k]=TINY; //se i pivot sono zero li pongo ad un numero piccolo cosi' non segmento!
			for(int i=k+1;i<n;i++){
				temp=lu[i][k]/=lu[k][k];
				for(int j=k+1;j<n;j++){
					lu[i][j]-=temp*lu[k][j];
				}	
			}
		}
		return lu;
	}


//variante di Crout, come presentato nella fonte f8

	template <class T> matrice<T> matrice<T>::LUDecomposition_crout() {
		matrice<T> lu(0);		
		lu = *this;	

		int n= ROW;			// per semplicita' salvo il numero di elementi per riga
		const T TINY=1.0e-14;		
		
		for(int j=0 ; j<n ; j++){

			for(int i=j; i<n; i++){
				for(int k=0; k<=j-1;k++){ // se k>i-1 il ciclo non parte! quindi sono a posto
					lu[j][i]-= ( lu[j][k] )*( lu[k][i]);
				}
			}

			if (lu[j][j]==0) lu[j][j]=TINY; //se i pivot sono zero li pongo ad un numero piccolo cosi' non segmento!
			T temp= lu[j][j];


			for(int i=j+1; i<n; i++){
				for(int k=0; k<=j-1;k++){
					lu[i][j]-=lu[i][k]*lu[k][j];
				}
				lu[i][j] /=temp; //con gli interi avrei problemi con questa divisione! (infatti non va!)
			}
		}

		return lu;
	}
