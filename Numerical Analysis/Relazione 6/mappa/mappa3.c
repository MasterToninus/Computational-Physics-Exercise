#include <iostream>
#include <math.h>
#include <fstream>
#include <cstdlib> 
#include <ctime> 
#include "mappa.h"
using namespace std;

//grafici globali tipo albero completo regione caotica ingrandimento zona stabilità


int main()
{
int n = 64; //numero di punti
srand((unsigned)time(0));
long double x=((long double)rand()/RAND_MAX), r; 
	

cout<<".......calcolo......"<<endl;


	FILE * pFile; FILE * pFile1;FILE * pFile2;FILE * pFile3;FILE * pFile31;FILE * pFile4;FILE * pFile41;FILE * pFile42;FILE * pFile43;FILE * pFile5;FILE * pFile51;FILE * pFile52;FILE * pFile53;FILE * pFile54;FILE * pFile55;FILE * pFile56;FILE * pFile57;FILE * pFile58;
	
pFile = fopen ("grafici/mappa3/r=1","w");r=1;
for(int i=0 ; i<n ;i=i+1)
	{
	x=mappalogistica(r,x);
	fprintf (pFile, "%d \t %21.20Lf \n",i,x);
	}

pFile1 = fopen ("grafici/mappa3/r=2","w");r=2;
for(int i=0 ; i<n ;i=i+1)
	{
	x=mappalogistica(r,x);
	fprintf (pFile1, "%d \t %21.20Lf \n",i,x);
	}

pFile2 = fopen ("grafici/mappa3/r=3","w");r=3;
for(int i=0 ; i<n ;i=i+1)
	{
	x=mappalogistica(r,x);
	fprintf (pFile2, "%d \t %21.20Lf \n",i,x);
	}

pFile3 = fopen ("grafici/mappa3/2punti_1","w");pFile31 = fopen ("grafici/mappa3/2punti_2","w");r=3.2;
for(int i=0 ; i<(n) ;i=i+2)
	{
	x=mappalogistica(r,x);
	fprintf (pFile3, "%d \t %21.20Lf \n",i,x);
	x=mappalogistica(r,x);
	fprintf (pFile31, "%d \t %21.20Lf \n",i+1,x);
	}

pFile4 = fopen ("grafici/mappa3/4punti_1","w");pFile41= fopen ("grafici/mappa3/4punti_2","w");pFile42 = fopen ("grafici/mappa3/4punti_3","w");pFile43 = fopen ("grafici/mappa3/4punti_4","w");r=3.51;
for(int i=0 ; i<n ;i=i+4)
	{
	x=mappalogistica(r,x);	fprintf (pFile4, "%d \t %21.20Lf \n",i,x);
	x=mappalogistica(r,x);	fprintf (pFile41, "%d \t %21.20Lf \n",i+1,x);
	x=mappalogistica(r,x);	fprintf (pFile42, "%d \t %21.20Lf \n",i+2,x);
	x=mappalogistica(r,x);	fprintf (pFile43, "%d \t %21.20Lf \n",i+3,x);
	
	}

pFile5 = fopen ("grafici/mappa3/8punti","w");pFile51 = fopen ("grafici/mappa3/8punti_1","w");pFile52 = fopen ("grafici/mappa3/8punti_2","w");pFile53 = fopen ("grafici/mappa3/8punti_3","w");pFile54 = fopen ("grafici/mappa3/8punti_4","w");pFile55 = fopen ("grafici/mappa3/8punti_5","w");pFile56 = fopen ("grafici/mappa3/8punti_6","w");pFile57 = fopen ("grafici/mappa3/8punti_7","w");pFile58 = fopen ("grafici/mappa3/8punti_8","w");r=3.55;
for(int i=0 ; i<n ;i=i+8)
	{
	x=mappalogistica(r,x);	fprintf (pFile51, "%d \t %21.20Lf \n",i,x);fprintf (pFile5, "%d \t %21.20Lf \n",i,x);
	x=mappalogistica(r,x);	fprintf (pFile52, "%d \t %21.20Lf \n",i+1,x);	fprintf (pFile5, "%d \t %21.20Lf \n",i+1,x);
	x=mappalogistica(r,x);	fprintf (pFile53, "%d \t %21.20Lf \n",i+2,x);	fprintf (pFile5, "%d \t %21.20Lf \n",i+2,x);
	x=mappalogistica(r,x);	fprintf (pFile54, "%d \t %21.20Lf \n",i+3,x);	fprintf (pFile5, "%d \t %21.20Lf \n",i+3,x);
	x=mappalogistica(r,x);	fprintf (pFile55, "%d \t %21.20Lf \n",i+4,x);	fprintf (pFile5, "%d \t %21.20Lf \n",i+4,x);
	x=mappalogistica(r,x);	fprintf (pFile56, "%d \t %21.20Lf \n",i+5,x);	fprintf (pFile5, "%d \t %21.20Lf \n",i+5,x);
	x=mappalogistica(r,x);	fprintf (pFile57, "%d \t %21.20Lf \n",i+6,x);	fprintf (pFile5, "%d \t %21.20Lf \n",i+6,x);
	x=mappalogistica(r,x);	fprintf (pFile58, "%d \t %21.20Lf \n",i+7,x);	fprintf (pFile5, "%d \t %21.20Lf \n",i+7,x);
	
	}


	fclose (pFile);fclose (pFile1);fclose (pFile2);fclose (pFile3);fclose (pFile31);fclose (pFile4);fclose (pFile41);fclose (pFile42);fclose (pFile43);fclose (pFile5);fclose (pFile51);fclose (pFile52);fclose (pFile53);fclose (pFile54);fclose (pFile55);fclose (pFile56);fclose (pFile57);fclose (pFile58);
return(0);}
