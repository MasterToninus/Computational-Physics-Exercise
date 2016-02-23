COMPILAZIONE
	La compilazione di tutti i codici CUDA è stata testat con la flag -arch sm_11

ESECUZIONE
	Per Testare l'effettivo funzionamento delle chiamate di funzioni base di CUDA è possibile lanciare l'eseguibile con
		cuda-memcheck "nome file"


CONTENUTO CARTELLE
* CudaMatrixClass : il progetto finale di libreria ibrida cpu-gpu con modulo di calcolo del determinante con condensazione
* KernelTest	  : Programmi che testano singolarmente i kernel implementati nella libreria
* MatrixTemplate  : Lavoro preliminare di design della versione solo cpu della libreria di algebra lineare
* ParteMathematica: Alcuni notebook per testare che il calcolo numerico del determinante fosse corretto

