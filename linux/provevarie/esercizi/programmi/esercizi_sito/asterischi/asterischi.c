#include <stdio.h>

void print(int n);

int main(void){
	int n;
	while(scanf("%d", &n)!=1 || n<0){
		printf("ncorretto. Inserisci un intero positivo.");
		scanf("%*c");
	}
	do{
		print(n);
		n = n-2;
	}while(n!=0 && n!=-1);
}

void print(int n){
	do{
		printf("*");
		n--;
	}while(n>0);
	printf("\n");
}
