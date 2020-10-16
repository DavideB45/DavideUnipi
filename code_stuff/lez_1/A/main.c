#include <stdio.h>
#include <stdlib.h>

int main(void){
	int count;
	size_t num;//numero da calcolare
	size_t tot;//numero da stampare
	size_t to_remove;//il numero da rimuovere ad ogni iterazione

	printf("inserire quanti numeri si vogliono calcolare : ");
	scanf("%d", &count);

	for (size_t i = 0; i < count; i++){
		
		printf("numero da calcolare : ");
		scanf("%ld", &num);
		tot = (num * (num + 1))/2;

		to_remove = 1;//il numero da rimuovere ad ogni iterazione

		while (to_remove <= num){
			tot = tot - 2*to_remove;
			to_remove = to_remove*2;	
			printf("%ld\t%ld\n", tot, to_remove);
		}
		
		printf("risultato %ld : %ld\n\n", i, tot);
	}
	return 0;
	
}