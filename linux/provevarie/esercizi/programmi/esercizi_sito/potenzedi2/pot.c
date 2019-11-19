#include <stdio.h>

int pot2(int n, int tot);

int read_positive_int(void);

int main(void){
	int n;
	n = read_positive_int();
	printf("%d\n", pot2(n, 1));
	return 0;
}

int pot2(int n, int tot){
	if(n==0){
		return tot;
	}
	else{
		tot = tot*2;
		return pot2(n-1, tot);
	}
}

int read_positive_int(void){
	int n;
	while(scanf("%d", &n)!=1 || n<0){
		scanf("%*[^\n]");
		scanf("%*c");
		printf("Errore.  Inserisci un numero intero positivo\n");
	}
	return n;
}	
