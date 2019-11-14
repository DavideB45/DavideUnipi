#include <stdio.h>

int read_positive_int(void);

void stampa_cifre(int n);

void stampa_inverso(int n);

int main(void){
	int num;
	num = read_positive_int();
	if(num!=0){
	stampa_inverso(num);
	stampa_cifre(num);
	}
	else{
	printf("0\n0\n");
	}
	return 0;
}

int read_positive_int(void){
	int n;
	while(scanf("%d", &n)!=1 || n<0){
		scanf("%*[^\n]");
		scanf("%*c");
		printf("Errore. Inserisci un intero positivo.\n");
	}
	return n;
}

void stampa_inverso(int n){
	int out;
	if(n==0){
		return;
	}
	else{
		out = n%10;
		printf("%d\n", out);
		return stampa_inverso(n/10);
	}
}

void stampa_cifre(int n){
	int out;
	if(n==0){
		return;
	}
	else{
		stampa_cifre(n/10);
		out = n%10;
		printf("%d\n", out);
		return;
	}
}












