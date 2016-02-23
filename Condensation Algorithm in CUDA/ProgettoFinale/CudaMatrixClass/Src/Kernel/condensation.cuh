/*//---------------------------------------------------------------------------------------------------------
|
|  VERSIONE 4: UTILIZZO DI MEMORIA TEXTURE il kernel si aspetta che la colonna dei pivot sia precaricata in un array bindato texture
|
*///---------------------------------------------------------------------------------------------------------
//Pensato per essere eseguito con griglia 2d di blocchi 1d
//Scrive la matrice condensato nell'indirizzo B precedentemente allocato! quindi devo avere 2 copie della matrice!


// 1D float texture
texture <float> texRef;

//Pensato per essere eseguito con griglia 2d di blocchi 1d
//Scrive la matrice condensato nell'indirizzo B precedentemente allocato! quindi devo avere 2 copie della matrice!

__global__ void stepCondensationSimple_v4(float * B,float * A, int numBColumn,int numBRow) 
{

   //indice proprio del thread che gli dice dove si trova nel suo blocco
   unsigned int cacheIndex = threadIdx.x;
 
   //indice proprio del thread che gli dice su quale sito della matrice sta lavorando, visito ogni sito una sola volta!
   unsigned int tid_i = blockDim.y * blockIdx.y ;
   unsigned int tid_j = blockDim.x * blockIdx.x + threadIdx.x ;
   const unsigned int incremento_verticale = blockDim.y*gridDim.y;
   const unsigned int incremento_orizzontale = blockDim.x * gridDim.x;



   //fase zero, voglio che ogni thread si copi nella shared // i valori della riga pivot da utilizzare  		
   __shared__ float rigaPivot[THREAD_PER_BLOCK]; //__shared__ float rigaPivot[THREAD_PER_BLOCK];

   // il valore dell'unica colonna pivot da utilizzare e' precaricaricato nella memoria texture quindi alloco una variabile local
   float colonnaPivot;

  while(tid_j<numBColumn){// per ogni macro colonna
	rigaPivot[cacheIndex] = A[(numBColumn)*(numBColumn+1) + tid_j];	//copia la riga pivot nella cache, piu' precisamente ogni thread si copia nella shared il valore che lui stesso (solo lui) usera' piu' volte! per questo non serve sincare
	//notare numBColum= numAcolum -1!

	while(tid_i<numBRow){	//per ogni macro riga
 		colonnaPivot = tex1Dfetch ( texRef, tid_i );    //ogni thread nel blocco copiera' lo stesso elemento piu' volte, quindi uso texture!
		B[tid_i*(numBColumn) + tid_j] = A[tid_i*(numBColumn+1) + tid_j] - rigaPivot[cacheIndex]*colonnaPivot;

		tid_i += incremento_verticale;
	}
	//Una volta finito di scorrere in verticale passo alla seconda colonna
	tid_i = blockDim.y * blockIdx.y ;
  	tid_j+= incremento_orizzontale;
  }

}


/*//---------------------------------------------------------------------------------------------------------
|
|  VERSIONE 6: UTILIZZO SOLO DELLA COPIA MEMORIA TEXTURE GRANDE
	il kernel si aspetta che la  l'intera matrice da trasformare sia bindato texture
|
*///---------------------------------------------------------------------------------------------------------
//Pensato per essere eseguito con griglia 2d di blocchi 1d
//Scrive la matrice condensato nell'indirizzo B precedentemente allocato! quindi devo avere 2 copie della matrice!


// 1D float texture
	//texture <float> texRef;
// 1D float texture
	texture <float> texRef2;

//Pensato per essere eseguito con griglia 2d di blocchi 1d
//Scrive la matrice condensato nell'indirizzo B precedentemente allocato! quindi devo avere 2 copie della matrice!

__global__ void stepCondensationSimple_v6(float * B,float * A, int numBColumn,int numBRow) 
{
 
   //indice proprio del thread che gli dice su quale sito della matrice sta lavorando, visito ogni sito una sola volta!
   unsigned int tid_i = blockDim.y * blockIdx.y ;
   unsigned int tid_j = blockDim.x * blockIdx.x + threadIdx.x ;
   const unsigned int incremento_verticale = blockDim.y*gridDim.y;
   const unsigned int incremento_orizzontale = blockDim.x * gridDim.x;



   // il valore dell'unica colonna pivot da utilizzare e della riga sono precaricaricati nella memoria texture quindi alloco una variabile local
   float colonnaPivot;
   float rigaPivot;

  while(tid_j<numBColumn){// per ogni macro colonna
	rigaPivot = tex1Dfetch ( texRef2, (numBColumn)*(numBColumn+1) + tid_j );
	//notare numBColum= numAcolum -1!

	while(tid_i<numBRow){	//per ogni macro riga
 		colonnaPivot = tex1Dfetch ( texRef2, (numBColumn+1)* tid_i + numBColumn );    //ogni thread nel blocco copiera' lo stesso elemento piu' volte, quindi uso texture!
		B[tid_i*(numBColumn) + tid_j] = tex1Dfetch ( texRef2,tid_i*(numBColumn+1) + tid_j) - rigaPivot*colonnaPivot;
		tid_i += incremento_verticale;
	}
	//Una volta finito di scorrere in verticale passo alla seconda colonna
	tid_i = blockDim.y * blockIdx.y ;
  	tid_j+= incremento_orizzontale;
  }

}




/*//---------------------------------------------------------------------------------------------------------
|
|  VERSIONE 7: UTILIZZO DELLA COPIA MEMORIA TEXTURE GRANDE e DELLA MEMORIA SHARED
	il kernel si aspetta che la  l'intera matrice da trasformare sia bindato texture
	e che venga chiamato con una griglia costituita da 1 blocco 2d largo come il warp
|
*///---------------------------------------------------------------------------------------------------------
//Scrive la matrice condensato nell'indirizzo B precedentemente allocato! quindi devo avere 2 copie della matrice!

// 1D float texture
	//texture <float> texRef2;

__global__ void stepCondensationSimple_v7(float * B,float * A, int numBColumn,int numBRow) 
{
   //indice proprio del thread che gli dice dove si trova nel suo blocco
   unsigned int cacheIndex = threadIdx.x; 
   unsigned int cacheCheck =threadIdx.y;

   //indice proprio del thread che gli dice su quale sito della matrice sta lavorando, visito ogni sito una sola volta!
   unsigned int tid_i = blockDim.y * blockIdx.y + threadIdx.y ;
   unsigned int tid_j = blockDim.x * blockIdx.x + threadIdx.x ;
   const unsigned int incremento_verticale = blockDim.y*gridDim.y;
   const unsigned int incremento_orizzontale = blockDim.x * gridDim.x;

   //fase zero, voglio che ogni blocco abbia nella shared una copia  della riga pivot                  
   __shared__ float rigaPivot[DIM_WARP];
   if(!cacheCheck)rigaPivot[cacheIndex] = tex1Dfetch ( texRef2, (numBColumn)*(numBColumn+1) + tid_j );
  __syncthreads(); 

   // il valore dell'unica colonna pivot da utilizzare e della riga sono precaricaricati nella memoria texture quindi alloco una variabile local
   float colonnaPivot;


  while(tid_j<numBColumn){// per ogni macro colonna se dimensionalizzo bene questo ha un solo step
	//notare numBColum= numAcolum -1!
	while(tid_i<numBRow){	//per ogni macro riga
 		colonnaPivot = tex1Dfetch ( texRef2, (numBColumn+1)* tid_i + numBColumn );    //ogni thread nel blocco copiera' lo stesso elemento piu' volte, quindi uso texture!
		B[tid_i*(numBColumn) + tid_j] = tex1Dfetch ( texRef2,tid_i*(numBColumn+1) + tid_j) - rigaPivot[cacheIndex]*colonnaPivot;
		tid_i += incremento_verticale;
	}
	//Una volta finito di scorrere in verticale passo alla seconda colonna
	tid_i = blockDim.y * blockIdx.y ;
  	tid_j+= incremento_orizzontale;
  }

}



/*//---------------------------------------------------------------------------------------------------------
|
|  CONTEGGIO MEMORIA ALLOCATA NELLA CACHE
|
*///---------------------------------------------------------------------------------------------------------
//OGNI thread alloca 5 unsigned int e 2 float ---> 7*4= 28 byte






