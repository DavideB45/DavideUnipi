#include <stdio.h>
#include <stdlib.h>

int readInt();
void fillArray(int dim, int *array);
void quicksort(int *array, int inizio, int fine);
void printArray(int dim, int *array);

int main(void){
	//printf("Inserire dimensione : ");
	int dim = readInt();
	int *array = malloc(dim*sizeof(int));
	fillArray(dim, array);

	quicksort(array, 0, dim - 1);

	//printf("\n");
	printArray(dim, array);

	free(array);
	return 0;
}

int readInt(){
	int num;
	while(scanf("%d", &num) != 1){
		printf("numero  non valido : ");
		while(getchar() != '\n'){}
	}
	return num;
}

void fillArray(int dim, int *array){
	for (size_t i = 0; i < dim; i++){
		//printf("inserire in pos %lu : ", i);
		array[i] = readInt();
	}
	
}

void quicksort(int *array, int inizio, int fine){
	if(fine - inizio >= 1){
		int piv_pos = fine, r_i = inizio;
		int piv = array[piv_pos];
		printArray(fine - inizio + 1, array);
		printf("piv = %d\n", piv);
		printf("inizio = %d\nfine = %d\n", inizio, fine);
		while(r_i < piv_pos){
			if(array[r_i] > piv){
				array[piv_pos] = array[r_i];
				array[r_i] = array[--piv_pos];
				array[piv_pos] = piv; 
			} else {
				r_i++;
			}
			//printArray(fine - inizio, array + inizio);
		}

		quicksort(array, piv_pos + 1, fine);
		quicksort(array, inizio, piv_pos - 1);
	}
}

void printArray(int dim, int *array){
	for (size_t i = 0; i < dim; i++){
		printf("%d ", array[i]);
	} printf("\n");	
}
