#include <stdio.h>

void iva(float prezzo, float aumento);

void scontato(float prezzo, float sconto);

float leggiprezzo(void);

float leggisconto(void);

int main(void){
	int scelta;
	float prezzo;
	float sconto;
	do{
	while(scanf("%d", &scelta)!=1 || scelta>1){
		printf("scelta non valida\n");
		scanf("%*[^\n]");
		scanf("%*c");
	}
	if(scelta<0){
		return 0;
	}
	prezzo = leggiprezzo();
	sconto = leggisconto();
	if(scelta==0){
		scontato(prezzo, sconto);
	}
	else{
		iva(prezzo, sconto);
	}
	}
	while(1 == 1);
}

void iva(float prezzo, float aumento){
	printf("%20s\t%20s\t%20s\n", "Prezzo_Init", "Percentuale", "Prezzo_ivato");
	printf("%20.2f\t%20.2f\t%20.2f\n", prezzo, aumento, (prezzo+ prezzo*(aumento/100)));
	return;
}

void scontato(float prezzo, float sconto){
	printf("%20s\t%20s\t%20s\n", "Prezzo_Init", "Percentuale", "Prezzo_scontato");
	printf("%20.2f\t%20.2f\t%20.2f\n", prezzo, sconto, (prezzo- prezzo*(sconto/100)));
	return;
}

float leggiprezzo(void){
	float prezzo;
	while(scanf("%f", &prezzo)!=1 || prezzo<0){
		printf("Prezzo non valido\n");
		scanf("%*[^\n]");
		scanf("%*c");
	}
return prezzo;
}

float leggisconto(void){
	float sconto;
	while(scanf("%f", &sconto)!=1 || (sconto<0 || sconto>100)){
		printf("Percentuale non valido\n");
		scanf("%*[^\n]");
		scanf("%*c");
	}
return sconto;
}




















