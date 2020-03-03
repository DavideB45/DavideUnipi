#include <stdio.h>

int readInt(void);

int main(void){
	int dim = readInt();
	int array[dim];
	for (size_t i = 0; i < dim; i++)
		array[i] = readInt();

	int min, temp;
	for(size_t i = 0; i < dim; i++){
		min = i;
		for (size_t j = i; j < dim; j++){
			if(array[min] > array[j]){
				min = j;
			}
		}
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
	for (size_t i = 0; i < dim; i++)
		printf("%d::", array[i]);
	printf("\n");
	
}

int readInt(void){
	int num;
	scanf("%d", &num);
	return num;
}