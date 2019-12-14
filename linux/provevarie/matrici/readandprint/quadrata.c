#include <stdio.h>
#include <stdlib.h>

int nofelement(int n, size_t dim, int matrice[dim][dim]);
void riempi(size_t dim, int maitrice[dim][dim]);
void printmatrix(size_t dim, int matrice[dim][dim]);

int main(void){
	size_t dim;
	printf("inserire la dimensione: ");
	while(scanf("%lu", &dim)!=1){
		printf("Inserire una dimensione valida: ");
		while(getchar()!='\n');
	}
	int matrice[dim][dim];
	riempi(dim, matrice);
	printmatrix(dim, matrice);
	int tocount;
	scanf("%d", &tocount);
	printf("ci sono %d '%d'\n", nofelement(tocount, dim, matrice), tocount);
	return 0;
}

void riempi(size_t dim, int matrice[dim][dim]){
	for(int i = 0; i < dim; i++){
		for(int j = 0; j < dim; j++){
			while(scanf("%d", &matrice[i][j])!=1){
				printf("Valore non valido : ");
				while(getchar()!='\n');
			}
		}
	}
}

void printmatrix(size_t dim, int matrice[dim][dim]){
	for(int i = 0; i < dim; i++){
		for(int j = 0; j < dim; j++){
			printf("%d\t", matrice[i][j]);
		}
		printf("\n");
	}
}

int nofelement(int n, size_t dim, int matrice[dim][dim]){
	int count = 0;
	for(int i = 0; i < dim; i++){
		for(int j = 0; j < dim; j++){
			if(n == matrice[i][j]){
				count++;
			}
		}
	}
	return count;
}