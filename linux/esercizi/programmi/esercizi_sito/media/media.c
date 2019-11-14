#include <stdio.h>

float media(int indice, _Bool segno, int tot, int nn);

int main(void){
	int n;
	while(scanf("%d", &n)!=1){
		printf("Inserisci un intero.\n");
		scanf("%*[^\n]");
		scanf("%*c");
	}
	if(n<0){
		media(9, 0, n, 1);
	}
	else{
		media(9, 1, n, 1);
	}
	return 0;
}

float media(int indice, _Bool segno, int tot, int nn){
	if(indice==0){
		printf("%.2f", (float) tot/nn);
		return 0;
	}
	int n;
	_Bool controllo;	
	while(scanf("%d", &n)!=1){
		printf("Inserisci un intero.\n");
		scanf("%*[^\n]");
		scanf("%*c");
	}
	if(n<0){
		controllo = 0;
	}
	else{
		controllo = 1;
	}
	if(segno == controllo && n!=0){
		tot = tot + n;
		nn++;
	}
	return media(indice-1, segno, tot, nn);
}
	

































