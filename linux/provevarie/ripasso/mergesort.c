#include <stdio.h>
#include <stdlib.h>

int readInt(void);
void fillArray(int dim, int *array);
void merge(int dim, int *array);
void sort(int inizio, int *array,int fine);
void mergeSort(int sx, int centro1,int centro2, int fine, int *array);
void printArray(int dim, int *array);

int main(void){
	int dim = readInt();
	int array[dim];
	fillArray(dim, array);
	merge(dim, array);
	printArray(dim, array);
}

int readInt(void){
	int num;
	while(scanf("%d", &num)!=1){
		printf("Valore non accettabile : ");
		scanf("%*[^\n]");
		scanf("%*c");
	}
	scanf("%*[^\n]");
	scanf("%*c");
	return num;
}

void fillArray(int dim, int *array){
	for (size_t i = 0; i < dim; i++){
		array[i] = readInt();
	}
}

void merge(int dim, int *array){
	sort(0, array, dim-1);
}

void sort(int inizio, int *array, int fine){
	if(fine-inizio >= 1){
		int centro1 = (fine + inizio)/2;
		int centro2 = centro1 + 1;
		sort(inizio, array, centro1);
		sort(centro2, array, fine);
		mergeSort(inizio, centro1, centro2, fine, array);
	}
}

void mergeSort(int sx, int centro1,int centro2, int fine, int *array){
	int sx_i = sx, dx_i = centro2;
	int combo[fine-sx+1];
	int c_i = 0;
	while(sx_i <= centro1 && dx_i <= fine){
		if(array[sx_i] < array[dx_i]){
			combo[c_i++] = array[sx_i++];
		} else {
			combo[c_i++] = array[dx_i++];
		}
	}
	while (sx_i <= centro1){
		combo[c_i++] = array[sx_i++];
	}
	while (dx_i <= fine){
		combo[c_i++] = array[dx_i++];
	}

	c_i = 0;
	for(int i = sx; i < fine; i++){
		array[i] = combo[c_i++];
	}
}

void printArray(int dim, int *array){
	for (size_t i = 0; i < dim; i++){
		printf("%d::", array[i]);
	}printf("\b\b  \n");
	
}