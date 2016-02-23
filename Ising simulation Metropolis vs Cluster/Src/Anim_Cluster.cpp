/*
EXTRA: PRODUZIONE DI UN'ANIMAZIONE DELL'EVOLUZIONE DELLO STATO DEL SISTEMA ALGORITMO SWEN WANG

*/



#include <iostream>
#include <string>
#include <sstream> //per giocare con la classe string

#include <math.h>
#include <cstdlib> 
#include <ctime> 
#include <fstream>
#include <vector>

using namespace std;

#include "funzioni_statistica.h"
#include "funzioni_utili.h"
#include "Matrici.h"
#include "microstati_struttura.h"

#define beta_crit 0.4406868


int main()
{
	int L= 150;
	double beta= 0.78;
	microstato sistema(L);				//inizializzo la classe microstato
	stringstream sstm;
	sstm << "Preliminari/Animazione/"<<"prova.dat";
	string nomeFile = sstm.str();
	sistema.animazione_SwenWang(nomeFile,51,beta);


return(0);
}
