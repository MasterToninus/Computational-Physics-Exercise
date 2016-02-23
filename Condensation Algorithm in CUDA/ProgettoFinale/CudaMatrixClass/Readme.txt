COMPILAZIONE
	La compilazione di tutti i codici CUDA è stata testata con la flag -arch sm_11

ESECUZIONE
	Per Testare l'effettivo funzionamento delle chiamate di funzioni base di CUDA è possibile lanciare l'eseguibile con
		cuda-memcheck "nome file"


CONTENUTO CARTELLE
* / : sono presenti i file sorgente di programmi di test delle funzionalità della classe  Matrice 
*/src/: sono presenti i file header contentente la classe (Cuda_FloatMatriXClass.cuh) e i metodi della classe
*/src/kernel: sono presenti gli header contenenti i kernel utilizzati dalla classe matrice
*/Output: sono presenti i file con i dati utilizzati per realizzare i grafici e la macro gnuplot TimevsN.p utilizzata per produrre le immagini
