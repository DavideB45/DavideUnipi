#include <stdio.h>

void merge_sort(int *array,size_t dim);
void sort(int *a, size_t inizio, size_t fine);
void merge(int *a, size_t sx, size_t centro1, size_t centro2, size_t fine);



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
	merge_sort(matrice[0], dim);
	merge_sort(matrice[1], dim);
	merge_sort(matrice[2], dim);
	printmatrix(dim, matrice);

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



void merge_sort(int *array,size_t dim){
	sort(array, 0, dim-1);
}
void sort(int *a, size_t inizio, size_t fine){
	if(fine-inizio >= 1){
		size_t centro1 = (fine+inizio)/2;
		size_t centro2 = centro1+1;
		sort(a, inizio, centro1);
		sort(a, centro2, fine);
		merge(a, inizio, centro1,  centro2, fine);
	}
}
void merge(int *a, size_t sx, size_t centro1, size_t centro2, size_t fine){
	size_t sxI = sx, dxI = centro2;
	int unione[fine-sx];
	size_t unI = 0;
	while (sxI < centro2 && dxI <= fine){
		if(a[sxI]<a[dxI]){
			unione[unI++] = a[sxI++];
		} else {
			unione[unI++] = a[dxI++];
		}
	}
	if(sxI == centro2){
		while(dxI <= fine){
			unione[unI++] = a[dxI++];
		}
	} else {
		while(sxI <= centro1){
			unione[unI++] = a[sxI++];
		}
	}
	unI = 0;
	for(int i = sx; i <= fine; i++){
		a[i] = unione[unI++];
	}
}