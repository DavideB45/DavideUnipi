#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int readInt(void);
void fillArray(int dim, int array[dim]);
void printArray(int dim, int array[dim]);

void quickstramb(int *array, int end);

void quicksort(int *array, int start, int end);
int partition(int *array, int start, int end);
void swap(int *a, int *b);

int main(void){
	int dim = readInt();
	int array[dim];
	srand(time(NULL));
	fillArray(dim, array);

	quickstramb(array,dim);

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
		array[i] = rand() % 200 - 100;
	}
}
void printArray(int dim, int array[dim]){
	for(size_t i = 0; i < dim; i++){
		printf("%d ", array[i]);
	}printf("\n");
}

void quickstramb(int *array, int end){
	int disp = end;
	for(int i = 0; i < disp; i++){
		if(array[i]%2 != 0){//se [ dispari]
			swap(array + i,array + --disp);
			i--;
		}
	}
	quicksort(array, 0, disp - 1);
	quicksort(array, disp, end - 1);
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