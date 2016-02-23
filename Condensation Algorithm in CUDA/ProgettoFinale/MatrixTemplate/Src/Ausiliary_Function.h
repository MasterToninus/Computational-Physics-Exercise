// funzione che da il segno di una permutazione indicata come (i1,i2,i3,......), nel senso di mappa:
/*
 (1,2,3,...) ---> (i1,i2,i3,...)
*/

//algoritmo naive per determinare la parita' di una permutazione che si fa usualmente a mano!
int parity (unsigned int* Pin, unsigned int n){//stringa di interi e lunghezza della stringa di cui voglio calcolare la parita
	unsigned int P[n];
	for(int j=0; j<n; j++)P[j]=Pin[j];

	int swapnumber=0;
	for(int k=0;k<n;k++){ //scorro tutti i possibili numeri che formano la permutazione
		for(int i=k;i<n;i++){ 		//scorro la posizione del numero k nella permutazione
			if(P[i]==k){		//scorro la posizione del numero k nella permutazione		
				if(i!=k){	//se k non si trova nella posizione k vuol dire che ha permutato
					P[i]=P[k]; P[k]=k;	//quindi lo rimetto nella posizione k con uno swap
					swapnumber++;	//aumento il conteggio degli swap	
					break;
				}
			}
		}
	}
       return swapnumber;//va corretto con la divisibilita per 2, deve dare +- a seconda che sia pari o dispari
}

//http://en.cppreference.com/w/cpp/language/function_template
template<typename T>
T produttoria(T *Vec, int N)  //calcola la produttoria di elementi di un array
{
	T result=Vec[0];	
    	for(int i=1;i<N;i++){
		result*=Vec[i];
		//cout<<Vec[i]<<endl;
	}
	return result;
}
template<typename T>
bool divisione(T *Vec, int l,int N)  //divide i primi N elementi di un vettore per l'elemento i-simo
{
	bool test =0;	T dividendo = Vec[l];
	if(dividendo!=0){
		for(int i=0;i<N;i++){
			Vec[i]=(T)Vec[i]/dividendo;
//			cout<<"check che divide per il giusto pivot, dividendo = "<<Vec[l]<<endl;
		}
		test=1;
	}

	Vec[l]=1;
	return test;
}




