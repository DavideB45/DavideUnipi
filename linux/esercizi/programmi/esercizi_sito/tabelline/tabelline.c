#include <stdio.h>

int main(void){
	int n;
	while(scanf("%d", &n)!=1 || n<0){
		printf("Incorretto. Inserisci un intero positivo.\n");
		scanf("%*[^\n]");
		scanf("%*c");
	}
	for(int i = 1; i<11; i++){
		printf("%d\n", n*i);
	}
	return 0;
}
