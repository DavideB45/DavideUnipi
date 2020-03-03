#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 100

int readInt(void);
void fillArray(int dim, char array[dim][DIM]);

int main(void){

	int dim = readInt();
	char array[dim][DIM];
	fillArray(dim, array);

	int j;
	char k[DIM];
	for(int i = 1; i < dim; i++){
		strncpy(k, array[i], strlen(array[i]) + 1);//k = array[i];
		j = i -1;
		while(j >= 0 && strcmp(array[j], k) > 0/*array[j] > k*/){
			strncpy(array[j + 1], array[j], strlen(array[j]) + 1);//array[j + 1] = array[j];
			j--;
		}
		strncpy(array[j + 1], k, strlen(k) + 1);//array[j + 1] = k;
	}

	for (size_t i = 0; i < dim; i++)
		printf("%s\n", array[i]);
}

int readInt(void){
	int num;
	scanf("%d", &num);
	return num;
}

void fillArray(int dim, char array[dim][DIM]){
	for (size_t i = 0; i < dim; i++){
		scanf("%s", array[i]);
	}
}