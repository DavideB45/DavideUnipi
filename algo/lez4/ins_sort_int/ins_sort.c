#include <stdio.h>

int readInt(void);

int main(void){
	int dim = readInt();
	int array[dim];
	for (size_t i = 0; i < dim; i++)
		array[i] = readInt();

	int j, k;
	for(int i = 1; i < dim; i++){
		k = array[i];
		j = i -1;
		while(j >= 0 && array[j] > k){
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = k;
	}

	for (size_t i = 0; i < dim; i++)
		printf("%d\n", array[i]);	
}

int readInt(void){
	int num;
	scanf("%d", &num);
	return num;
}