#include <stdio.h>

int main(void)
{
	int sum = 0;
	int incremento = 2;
	int limInferiore = 0;
	int limSuperiore = 0;
	
	printf("inserisci limite inferiore e limite superiore\n ");
	printf("separati da uno spazio: ");
	while((scanf("%d %d", &limInferiore, &limSuperiore) != 2) || (limSuperiore<limInferiore))
	{
		printf("input errato, reinserire i valori: ");
		scanf("%*[^\n]%*c");
	};

	for(int counter = limInferiore%2 == 1? ++limInferiore : limInferiore + 2; counter<limSuperiore; counter += incremento)
	{
		sum=sum + counter;
	}
	printf("%d \n", sum);
}
