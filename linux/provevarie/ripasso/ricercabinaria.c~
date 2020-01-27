#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 100

int ricercabinaria(int *array, int ricercato);
void fill(int array[DIM]);
void print(int array[DIM]);

int main(void){
	
	int array[DIM];
	srand(time(NULL));
	fill(array);
	print(array);

	int ricercato;
	if(scanf("%d", &ricercato)!=1){
		printf("non e' un numero \n");
		return 7;
	}
	int mezzo = ricercabinaria(array, ricercato);
	
	if(array[mezzo] == ricercato){
		printf("numero in posizione %d -> %d\n", mezzo+1, array[mezzo]);
	} else {
		printf("Non c'e'\n");
	}

	return 0 ;
}

void fill(int array[DIM]){
	int min = 0;
	for (size_t i = 0; i < DIM; i++){
		array[i] = min + rand()%10;
		min = array[i];
	}
	return;
}

void print(int array[DIM]){
	for (size_t i = 1; i < DIM + 1; i++){
		printf("%4d", array[i-1]);
		if(i%10==0){
			printf("\n");
		}
	} printf("\n");
}

int ricercabinaria(int *array, int ricercato){
	_Bool found = 0;
	int sx = 0, dx = DIM, mezzo;
	
	while(  (!found)  &&  (sx+1 != dx)  ){
		mezzo = (dx+sx)/2;
		if(array[mezzo] > ricercato){
			dx = mezzo;
		} else {
			if(array[mezzo] < ricercato){
				sx = mezzo;
			} else {
				found = 1;
			}
		}
	}
	return mezzo;
}