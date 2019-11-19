#include <stdio.h>
//rapporto di cambio con euro di: euro, dollari, sterline
#define E 1
#define D 1,5
#define S 2

//restituisce il valore convertito
float covertitore(float importo, float cambio);
//restituisce un tipo di valuta
char inserimentovaluta(void);


int main(void)
{
	float importo, valorefinale;
	char origine, destinazione;

//inserimento importo	
	printf("inserire importo da convertire");
	while(scanf("%f", &importo) == 0 || importo < 0)
	{
		scanf("%*[^\n]");
		scanf("%*c");
		printf("\nimporto non valido, reinserire importo: ");
	}
	scanf("%*[^\n]");
	scanf("%*c");

//inserimento valuta di origine
	origine = inserimentovaluta();
//inserimento valuta finale
	destinazione = inserimentovaluta();
}

char inserimentovaluta(void)
{
	char valtemp;
	while(scanf("%[E,D,S]", &valtemp) == 0)
	{
		scanf("%*[^\n]");
		scanf("%*c");
		printf("\ninserire una valuta disponibile (E D S): ");
	}
	scanf("%*c");
	return valtemp;
}		
	

