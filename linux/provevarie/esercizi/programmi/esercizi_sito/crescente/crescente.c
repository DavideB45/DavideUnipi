#include <stdio.h>

int read_positive_int(void){
	int n;
	while(scanf("%d", &n)!=1){
		scanf("%*[^\n]");
		scanf("%*c");
		printf("Errore.  Inserire un numero intero positivo oppure un numero intero negativo per terminare\n");
	}
	return n;
}

int main(void){
	_Bool si_no = 1;
	int n, prec = -1;
	do{
		n = read_positive_int();
		if(n<0){
			break;
		}
		if(prec >= n){
			si_no = 0;
		}
		prec = n;
	}while(1 == 1);
	if(si_no==1){
		printf("Sequenza in ordine strettamente crescente\n");
	}
	else{
		printf("Sequenza non in ordine strettamente crescente\n");
	}
	return 0;
}
