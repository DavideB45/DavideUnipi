#include <stdio.h>

int main(void){
	int max;
	while(scanf("%d", &max)!=1 || max<0 || max>100){
		printf("Inserisci un intero positivo compreso fra 1 e 100.\n");
		scanf("%*[^\n]");
		scanf("%*c");
	}
	int array[max];
	for(int i = 0; i<max; i++){
		while(scanf("%d", &array[i])!=1){
			printf("Inserisci un intero.\n");
			scanf("%*[^\n]");
			scanf("%*c");
		}
	}
	for(int i = 0; i<max; i++){
		if(array[i]>=0 && array[i]%2 == 0){
			printf("%d\n", array[i]);
		}
		else{
			if(i<max-1 && array[i+1] >= 0 && array[i]<0){
				printf("%d\n", array[i]);
			}
		}
	}	
}
