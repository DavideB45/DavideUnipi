#include <stdio.h>
#define DIM 10

//tutto giusto ma avevo "confuso" un 2 con un 1 
//cio' mi e' costato 15 min
//tempo parziale 15 min
//per trovare l'errore 15 min

void merge_sort(int *array,size_t dim);
void sort(int *a, size_t inizio, size_t fine);
void merge(int *a, size_t sx, size_t centro1, size_t centro2, size_t fine);

int main(void){
	int array[DIM];
	for(int i = 0; i<DIM; i++){
		printf("Inserire il numero in posizione %d: ", i);
		while (scanf("%d", &array[i])!=1){
			printf("Errore nll'input");
			while(getchar()!='\n');
		}
	}
	merge_sort(array, DIM);
	for(int i = 0; i < DIM-1; i++){
		printf("%d::", array[i]);
	} printf("%d\n", array[DIM-1]);
	return 0;
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
	int unione[DIM];
	size_t unI = sx;
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
	for(int i = sx; i <= fine; i++){
		a[i] = unione[i];
	}
}