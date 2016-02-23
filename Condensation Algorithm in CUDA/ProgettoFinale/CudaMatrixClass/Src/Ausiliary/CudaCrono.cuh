/*
provo a definire una struttura cuda crono.
Quando la instazio fa partire setta il tempo di start 1 e fa partire stop1

c'e' un unico metodo Cudacrono che restituisce come float il tempo che e' passato dalla precedente chiamata di cudacrono o dal creatore

memento: hai dimenticato per la quarta volta come si usano le classi!
http://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/

*/


struct CudaCrono {
  /* Variabili della Classe*/	
  // alloco (sulla cpu) la "struttura dati" dedicata cuda per cronometrare il tempo 
  cudaEvent_t start1,stop1;
  // dichiaro la variabile sull'host da usare poi per stampare i tempu
  float time1;

	CudaCrono();  			  /*Creatore*/

	~CudaCrono();    	  /*Distruttore*/

	float CronoTime();     /*Metodi*/


};


	 /*Creatore*/
	CudaCrono::CudaCrono()
	{
		/* 
la possibilita' di misurare la durata di un evento viene resa possibile dall'utilizzo di tag, che possono essere associati a due istanti temporali e al relativo utilizzo della GPU
		*/
		cudaEventCreate(&start1);
		cudaEventCreate(&stop1);
		//da questo istante misuriamo il tempo trascorso sulla GPU
  		cudaEventRecord(start1,0);
	}

  /*Distruttore*/
	CudaCrono::~CudaCrono()
	{
  		cudaEventDestroy(start1);
  		cudaEventDestroy(stop1);
	}

  /*Metodi*/
	float CudaCrono::CronoTime()
	{

	  //il contatore finale viene misurato
	  cudaEventRecord(stop1,0);
	  //si chiede che la GPU abbia completato le sue operazioni prima di restituire
	  // il valore del contatore stop1 
	  cudaEventSynchronize(stop1);
		/*
	cosi sembrerebbe anti intuitivo! prima misuro e poi aspetto che le operazioni sulla gpu siano completate?
		http://stackoverflow.com/questions/5801717/cuda-cudaevent-t-and-cudathreadsynchronize-usage
		http://docs.nvidia.com/cuda/cuda-c-best-practices-guide/index.html#using-cpu-timers
		*/


 	 //la differenza tra start1 e stop1 corrisponde al tempo trascorso
	 //misurato in millisecond
	 //Computes the elapsed time between two events (in milliseconds with a resolution of around 0.5 microseconds).
  	  cudaEventElapsedTime(&time1, start1, stop1);
	  cudaEventRecord(start1,0);		

	return(time1);
	}

