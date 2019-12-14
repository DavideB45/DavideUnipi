#include <stdio.h>

//25 min
//~15 per scriverlo
//10 persi per fil for finale nella parte merge

void merge_sort(int *array, size_t dim);
void sort(int *array, size_t inizio, size_t fine);
void merge(int *array, size_t sx, size_t centro1, size_t centro2, size_t fine);

int main(void){
	int dim;
	printf("inserire dimensione dell'array: ");
	while(scanf("%d", &dim)!=1 || dim<1){
		printf("inserire una lunghezza valida : ");
		while(getchar()!='\n');
	}
	int array[dim];
	for(int i = 0; i < dim; i++){
		printf("inserire un numero in posizione %d: ", i);
		while (scanf("%d", &array[i])!=1){
			printf("inserire un numero : ");
		}
	}
	merge_sort(array, dim);
	for(int i = 0; i < dim-1; i++){
		printf("%d::", array[i]);
	}printf("%d\n", array[dim-1]);
	return 0;
}

void merge_sort(int *array, size_t dim){
	sort(array, 0, dim-1);
}

void sort(int *array, size_t inizio, size_t fine){
	if(fine - inizio >= 1){
		size_t centro1 = (inizio+fine)/2;
		size_t centro2 = centro1 + 1;
		sort(array, inizio, centro1);
		sort(array, centro2, fine);
		merge(array, inizio, centro1, centro2, fine);
	}
}

void merge(int *array, size_t sx, size_t centro1, size_t centro2, size_t fine){
	int combin[fine-sx+1];
	size_t sxI = sx, dxI = centro2, coI = 0;
	while(sxI <= centro1 && dxI <= fine){
		if(array[sxI]<array[dxI]){
			combin[coI++] = array[sxI++];
		} else {
			combin[coI++] = array[dxI++];
		}
	}
	if(sxI == centro2){
		while (dxI <= fine){
			combin[coI++] = array[dxI++];
		}
	} else {
		while (sxI <= centro1){
			combin[coI++] = array[sxI++];
		}
	}
	coI = 0;
	for (size_t i = sx; i <= fine; i++){
		array[i] = combin[coI++];
	}
}