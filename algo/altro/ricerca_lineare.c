#include <stdio.h>
#include <stdlib.h>

void readInt(int *num);

int main(void){
	
	int dim, to_find;

	readInt(&dim);
	int *array = calloc(dim, sizeof(int));
	for (size_t i = 0; i < dim; i++)
		readInt(array + i);
	
	readInt(&to_find);
	while(dim--,dim >= 0 && array[dim] != to_find);
	printf("%d\n", dim);

	free(array);
	return 0;
}

void readInt(int *num){
	while(scanf("%d", num) != 1)
		while(getchar() != '\n');
}