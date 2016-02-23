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
#include "vettori_fisici_check.h"
#include "STRUTTURONA_sfere_soffici.h"


int main()
{

int d= 3;
int N=250;// numero esatto di particellle
double rho = 0.6;
double T_D = 0.05;	


	//sistema_soffice sistema(1);	
	
	sistema_soffice sistema(d, N,rho);	

	int Npassi = 10000;
	int Nsnap = 600;
	sistema.evoluzione(Npassi);
	sistema.termalizzazione_kTfissa(Npassi, T_D);
	sistema.animazione_completo( Nsnap, "Preliminari/Animazione/prova.dat");

return(0);
}
