#include <stdio.h>
#include <stdlib.h>
#define DIM 7


void merge(int a[], size_t sin, size_t centro1, size_t centro2, size_t dx) {
	size_t sin_i = sin;
	size_t dx_i = centro2;
	size_t fondi_i = sin;
	int temp_a[DIM];
	while (sin_i <= centro1 && dx_i <= dx) {
		if (a[sin_i] <= a[dx_i]) {
			temp_a[fondi_i++] = a[sin_i++];
		} else {
			temp_a[fondi_i++] = a[dx_i++];
		}
	}
	// se esaurisco il sotto-array sinistro
	if (sin_i == centro2) {
		while (dx_i <= dx) {
			temp_a[fondi_i++] = a[dx_i++];
		}
	} else {
	// ho esaurito il sotto-array destro
		while (sin_i <= centro1) {
			temp_a[fondi_i++] = a[sin_i++];
		}
	}
	
	for (size_t i = sin; i <= dx; i++) {
		a[i] = temp_a[i];
	}
}

void sort(int a[], size_t inizio, size_t fine) {
	if ((fine - inizio) >= 1) {
		// non è il caso base
		size_t centro1 = (inizio + fine)/2;
		size_t centro2 = centro1 + 1;
		// divide l'array e ordina i due sotto-array
		// ricorsivamente
		sort(a, inizio, centro1);
		sort(a, centro2, fine);
		// fonde i due sotto-array ordinati
		merge(a, inizio, centro1, centro2, fine);
	}
}

void merge_sort(int a[], size_t dim) {
 sort(a, 0, dim-1);
}

int main(){
    int array[DIM];
    printf("RIEMPIRE IL PRIMO ARRAY\n");
    for(int i = 0; i<DIM; i++){
        printf("inserire il numero %d: ", i);
        while(scanf("%d", &array[i])!=1){
            printf("inserire un numero: ");
            while(getchar()!='\n');
        }
    }
	merge_sort(array, DIM);
    for(int i = 0; i<DIM; i++){
        printf("%d::", array[i]);
    }
    printf("[]\n");
}