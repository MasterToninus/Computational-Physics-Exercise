#include <iostream>
#include <string>
#include <sstream> //per giocare con la classe string

#include <math.h>
#include <cstdlib> 
#include <ctime> 
#include <fstream>
#include <vector>


using namespace std;

#include "funzioni_utili.h"
#include "vettori_fisici.h"
#include "tempi_collisione.h"
#include "STRUTTURONA_sfere_rigide.h"



int main()
{

int d= 2;
int N=15;// numero esatto di particellle

	double eta = 0.30;
	double dt=0.01;

	sistema_rigido sistema(d, N, eta);

	int Npassi = 10000;
	sistema.evoluzione(Npassi);

	sistema.animazione_completo( 600,dt, "Preliminari/Animazione/prova.dat");
//	sistema.stampa_stato_completo("Preliminari/Stato.dat");

return(0);
}
