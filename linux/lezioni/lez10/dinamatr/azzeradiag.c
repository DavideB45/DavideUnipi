#include <stdio.h>
#include <stdlib.h>

int getint(void);
int *insert(size_t dim, int *matr);
void azzera(size_t dim, int *matr);
void printmatr(size_t dim, int *matr);

int main(void){
	int *matr;
	int dim = getint();
	matr = insert(dim, matr);
	azzera(dim, matr);
	printmatr(dim, matr);
	return 0;
}

int getint(void){
	int num;
	while(scanf("%d", &num)!=1){
		printf("metti un numero\n");
		scanf("%*[^\n]");
		scanf("%*c");
	}
	return num;
}

int *insert(size_t dim, int *matr){
	matr = calloc(dim * dim, sizeof(int));
	for (size_t i = 0; i < dim; i++){
		for (size_t j = 0; j < dim; j++){
			*(matr + j + i*dim) = getint();
		}
	}
	return matr;	
}

void azzera(size_t dim, int *matr){
	for (size_t i = 0; i < dim; i++){
		*(matr + i*dim + i) = 0;
		*(matr + (dim-1) + (dim-1)*i) = 0;
	}
}

void printmatr(size_t dim, int *matr){
	for (size_t i = 0; i < dim; i++){
		for (size_t j = 0; j < dim; j++){
			printf("%d ", *(matr+(i*dim)+j));
		}
		printf("\n");
	}
	return;
}