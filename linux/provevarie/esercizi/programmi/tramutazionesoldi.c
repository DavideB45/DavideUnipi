#include <stdio.h>
//Conversione valuta da euro a value straniere (anche fra di loro) e viceversa.
/* Autore: Davide Borghini */

#define Eu 1 //Euro
#define Do 1.5 //Dollaro US
#define St 2.12 //Sterlina

float inserimentoValuta(void);

int main(void)
{
	float importo, valorefinale, origine, destinazione;
	//char origine, destinazione;
	
	printf("inserire importo da convertire: ");
	while(scanf("%f", &importo) == 0 || importo < 0)
	{
		scanf("%*[^\n]");
		scanf("%*c");
		printf("\nimporto non valido, reinserire importo: ");
	}
	scanf("%*[^\n]");
	scanf("%*c");
	printf("E = Euro\nD = Dollari\nS = Sterline\n");
	printf("inserire valuta iniziale: ");
	origine = inserimentoValuta();
	//printf("origine = %f \n", origine);
	printf("inserire valuta finale: ");
	destinazione = inserimentoValuta();
	//printf("destinazione = %f \n", destinazione);
	valorefinale = importo*(destinazione/origine);
	printf("\nil valore convertito e': %.2f \n", valorefinale);	

}

//restituisce un tipo di valuta
float inserimentoValuta(void)
{
	char valtemp;
	float valore;

	while(scanf("%[E,D,S]", &valtemp) == 0)
	{
		scanf("%*[^\n]");
		scanf("%*c");
		printf("\ninserire una valuta disponibile (E D S): ");
	}
	scanf("%*[^\n]");
	scanf("%*c");
	if(valtemp == 'E')
		valore = Eu;
	if(valtemp == 'D')
		valore = Do;
	if(valtemp == 'S')
		valore = St;

	return valore;
}	














