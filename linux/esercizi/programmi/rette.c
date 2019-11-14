#include <stdio.h>
int divisione(int);

int main()
{
	int nrette;
	printf("inserire il numero di rette: ");
	scanf("%d", &nrette);
	
}

int divisione(int nrette)
{
	if(nrette == 1)
		return 2;
	else
		return divisione(nrette - 1) + nrette;
}
