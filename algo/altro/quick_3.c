#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int readInt(void);
void fillArray(int dim, int array[dim]);
void printArray(int dim, int array[dim]);

void quicksort(int *array, int start, int end);
void swap(int *a, int *b);

int main(void){
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
	scanf("%d", &num);
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

void quicksort(int *array, int start, int end){
	if(end > start){
		int min = start - 1, eq = start - 1, corr = start, piv = array[end];
		while(corr < end){
			if(array[corr] == piv){
				array[corr] = array[++eq];
				array[eq] = piv;
			} else {
				if(array[corr] < piv){
					swap(array + ++eq, array + corr);
					swap(array + ++min, array + eq);
				}
			}
			corr++;
		}
		swap(array + ++eq, array + end);
		quicksort(array, start, min );
		quicksort(array, eq + 1, corr);
	}
}
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
