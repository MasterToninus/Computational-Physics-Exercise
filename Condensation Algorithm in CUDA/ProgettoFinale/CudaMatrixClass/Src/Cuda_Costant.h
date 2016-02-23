// Numero di thread prudente
#define DIM_GRID 64
#define DIM_BLOCK 64

// Disusati sarebbero da sostituire
#define BLOCK_PER_GRID DIM_GRID
#define THREAD_PER_BLOCK DIM_BLOCK


/*     DIMENSIONALIZZAZIONE DEI THREAD    */
// Numero di thread "Limite"
#define imin(a,b) (a<b?a:b)

//trucco per ottimizzare il numero di blocchi
//const int blocksPerGrid = imin(32,(N+threadsPerBlock-1)/threadsPerBlock);

#define MAX_DIM_BLOCK 512
#define MAX_DIM_GRID 524288 //in realtà il max numero di thrad è un po' di piu', questa è la potenza di 2 più vicina
#define DIM_WARP 32


