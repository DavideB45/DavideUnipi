#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int readInt(void);
void fillArray(int dim, int array[dim]);
void printArray(int dim, int array[dim]);

void quicksort(int *array, int start, int end);
int partition(int *array, int start, int end);
void swap(int *a, int *b);

int main(void){
	printf("Inserire la dimensione dell'array : ");
	int dim = readInt();
	int array[dim];
	srand(time(NULL));
	fillArray(dim, array);

	quicksort(array, 0, dim - 1);

	printArray(dim, array);
	return 0;
}

int readInt(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("numero non valido : ");
		while(getchar() != '\n');
	}
	return num;
}
void fillArray(int dim, int array[dim]){
	for(size_t i = 0; i < dim; i++){
		//printf("inserire num in pos %lu : ", i);
		//array[i] = readInt();
		array[i] = rand() % 1000;
	}
}
void printArray(int dim, int array[dim]){
	for(size_t i = 0; i < dim; i++){
		printf("%d->", array[i]);
	}printf("\n");
}

void quicksort(int *array, int start, int end){
	if(end > start){
		int q = partition(array, start, end);
		quicksort(array, start, q - 1);
		quicksort(array, q + 1, end);
	}
}
int partition(int *array, int start, int end){
	int piv = array[end];
	int i = start - 1;
	for(size_t j = start; j < end; j++){
		if(array[j] <= piv){
			i++;
			swap(array + i, array + j);
		}
	}
	swap(array + (++i),array + end);
	return i;
}
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}