// Ricordare definizione di errore! non è la deviazione standard http://it.wikipedia.org/wiki/Errore_standard

#include <math.h>

void MediaErrore( float *a,int Ncomponents, float *media, float *errore){
	float somma =0;
	for(int i=0; i<Ncomponents; i++){
		somma+=a[i];
	}
	 *media = somma /Ncomponents;

	float deviazionestandard=0;

	for(int i=0; i<Ncomponents; i++){
		deviazionestandard+=pow((a[i] - *media),2);
	}
	deviazionestandard=sqrt(deviazionestandard);
	*errore = deviazionestandard/Ncomponents;


}


float Media(float *a, int Ncomponents){

	float somma =0;
	for(int i=0; i<Ncomponents; i++){
		somma+=a[i];
	}
	return somma /Ncomponents;
}



float Errore(float *a, int Ncomponents,float media){
	float deviazionestandard=0;

	for(int i=0; i<Ncomponents; i++){
		deviazionestandard+=pow((a[i] - media),2);
	}
	deviazionestandard=sqrt(deviazionestandard);
	return deviazionestandard/Ncomponents;


}

