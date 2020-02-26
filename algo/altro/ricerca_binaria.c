#include <stdio.h>
#include <stdlib.h>

void readInt(int *num);
int binary_search(int inizio, int fine, int *array, int k);


int main(void){
	
	int dim, to_find;

	readInt(&dim);
	int *array = calloc(dim, sizeof(int));
	for (size_t i = 0; i < dim; i++)
		readInt(array + i);
	
	readInt(&to_find);
	printf("%d",binary_search(0, dim, array, to_find));

	free(array);
	return 0;
}

void readInt(int *num){
	while(scanf("%d", num) != 1)
		while(getchar() != '\n');
}

int binary_search(int inizio, int fine, int *array, int k){
	
	if(inizio > fine) return -1;
	
	int q = (inizio + fine)/2;
	if(array[q]==k) return q;
	
	if(array[q] < k)
	return binary_search(q + 1, fine, array, k);
	
	return binary_search(inizio, q - 1, array, k);
}