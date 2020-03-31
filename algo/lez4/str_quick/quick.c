#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readInt(void);
void fillArray(int dim, char *array[dim]);
void printArray(int dim, char *array[dim]);

void quicksort(char **array, int start, int end);
int partition(char **array, int start, int end);
void swap(char **a, char **b);

int main(void){
	printf("Inserire la dimensione dell'array : ");
	int dim = readInt();
	char *array[dim];
	fillArray(dim, array);

	quicksort(array, 0, dim - 1);

	printArray(dim, array);
	return 0;
}
//-------------------------------------------------------------
//-------------------------------------------------------------
int readInt(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("numero non valido : ");
		while(getchar() != '\n');
	}getchar();
	return num;
}
char* readstr(void){
	int dim = 5;
	int letters = 0;
	char read;
	unsigned char * parola = calloc(5, sizeof(unsigned char));
	while(read = getchar(), read != '\n'){
		if(dim > letters){
			parola[letters] = read;
		} else {
			dim = dim*2;
			parola = realloc(parola, dim);
			parola[letters] = read;
		}
		letters++;
	}
	parola[letters] = '\0';
	return realloc(parola, letters + 1);
}
//-------------------------------------------------------------
//-------------------------------------------------------------
void fillArray(int dim, char *array[dim]){
	for(size_t i = 0; i < dim; i++){
		array[i] = readstr();
	}
}
void printArray(int dim, char *array[dim]){
	for(size_t i = 0; i < dim; i++){
		printf("%s\n", array[i]);
	}
}
//-------------------------------------------------------------
//-------------------------------------------------------------
void quicksort(char **array, int start, int end){
	if(end > start){
		int q = partition(array, start, end);
		quicksort(array, start, q - 1);
		quicksort(array, q + 1, end);
	}
}
int partition(char **array, int start, int end){
	char* piv = array[end];
	int i = start - 1;
	for(size_t j = start; j < end; j++){
		if(strcmp(array[j], piv) <= 0){
			i++;
			swap(array + i, array + j);
		}
	}
	swap(array + (++i),array + end);
	return i;
}
void swap(char **a, char **b){
	char *temp = *a;
	*a = *b;
	*b = temp;
}