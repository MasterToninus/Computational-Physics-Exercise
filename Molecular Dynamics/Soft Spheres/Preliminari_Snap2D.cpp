/*
PRELIMINARI - Istananee del sistema (2D)

PRODUCE:
	- 6 figure dello stato del sistema prima e dopo una termalizzazione di

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

#include "funzioni_utili.h"
#include "vettori_fisici_check.h"
#include "STRUTTURONA_sfere_soffici.h"


int main()
{

	int d= 2;
	int N=125;// numero esatto di particellle
	int Npassi = 500000;

	// Caso 1 densità molto alta e temperatura normale, le particelle si posizionano in un reticolo regolare
	double rho = 1.2; double T_D= 1.2;
	sistema_soffice sistema(d, N, rho);	
	sistema.stampa_stato_completo("Preliminari/SnapShot/Stato2D_Inizio_1.dat");

	sistema.termalizzazione_kTfissa(Npassi, T_D);	

	sistema.stampa_stato_completo("Preliminari/SnapShot/Stato2D_Fine_1.dat");


	// Caso 2 densità bassa Temperatura bassa, dovrebbe provocare nucleazione
	sistema.Rinizializza( N, 0.725); //bisogna dilatare un pò se no il sistema esplode
	rho = 0.25; double E_D= -1.5;
	sistema.Espandi( rho);
	sistema.stampa_stato_completo("Preliminari/SnapShot/Stato2D_Inizio_2.dat");

	sistema.termalizzazione_Efissa(5000, E_D); //termalizzo sistema alla energia richiesta
	sistema.evoluzione(Npassi);

	sistema.stampa_stato_completo("Preliminari/SnapShot/Stato2D_Fine_2.dat");

	// Caso 3 densità bassa Temperatura alta, dovrebbe essere fase liquida
	E_D= 	15;
	sistema.stampa_stato_completo("Preliminari/SnapShot/Stato2D_Inizio_3.dat");

	sistema.termalizzazione_Efissa(5000, E_D); //termalizzo sistema alla energia richiesta
	sistema.evoluzione(Npassi);

	sistema.stampa_stato_completo("Preliminari/SnapShot/Stato2D_Fine_3.dat");

return(0);
}
