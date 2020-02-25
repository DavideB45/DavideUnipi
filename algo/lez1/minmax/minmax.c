#include <stdio.h>
#include <stdlib.h>
#define DIM 10

int readInt(void);
void fill_array(int dim,int* array);
void minmax(int dim, int* array, int *min, int *max);

int main(void){
	int array[DIM];
	fill_array(DIM, array);
	int *min = calloc(1, sizeof(int)), *max = calloc(1, sizeof(int));
	minmax(DIM, array, min, max);
	printf("%d -> %d\n", *min, array[*min]);
	printf("%d -> %d\n", *max, array[*max]);
	return 0;
}

int readInt(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("inserire un numero : ");
		while(getchar() != '\n');
	}
	return num;
}

void fill_array(int dim,int* array){
	for(int i = 0; i < dim; i++){
		array[i] = readInt();
	}
}

void minmax(int dim, int* array, int *min, int *max){
	*min = 0;
	*max = 0;
	for(int i = 0; i < dim; i++){
		if(array[i] < array[*min]){
			*min = i;
		} else if(array[i] > array[*max]){
			*max = i;
		}
	}
}