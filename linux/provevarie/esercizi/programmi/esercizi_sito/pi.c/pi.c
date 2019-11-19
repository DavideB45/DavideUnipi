#include <stdio.h>

int read_positive_int(void);

float approx_pi(int indice, float pi, float numero, int segno);

int main(void){
	int indice;
	indice = read_positive_int();
	printf("%.6f\n", approx_pi(indice, 0, 1, 0));
	return 0;
}

int read_positive_int(void){
	int n;
	while(scanf("%d", &n)!=1 || n<0){
		scanf("%*[^\n]");
		scanf("%*c");
		printf("Inserisci un intero positivo.\n");
	}
	return n;
}

float approx_pi(int indice, float pi, float numero, int segno){
	if(indice==0){
		return pi;
	}
	else{
		if(segno%2==0){ 
			pi = pi + 4/numero;
		}
		else{
			pi = pi - 4/numero;
		}
		return approx_pi(indice-1, pi, numero + 2, segno + 1);
	}
}
