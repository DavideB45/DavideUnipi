#include <stdio.h>
#include <time.h>
#define DIM 100000

void read(size_t dim, int array[dim]);
void print(size_t dim, int array[dim]);

void merge_sort(size_t dim, int array[dim]);
void sort(size_t inizio, size_t fine, int *array);
void merge(size_t sx, size_t centro1, size_t centro2, size_t fine, int *array);

int main(void){
	//int dim;

	//while (scanf("%d", &dim)!=1 && dim < 1);
	int array[DIM];
	clock_t inizio = clock();
	
	for(int j = 0; j<10000 ; j++){
		//read(dim, array);
		for(int i = 0; i < DIM; i++){
			array[DIM-1-i] = i;
		}

		merge_sort(DIM, array);
	}

	clock_t fine = clock();
	print(DIM, array);
	printf("\n\n%f\n", (double)(fine-inizio)/10000);
	printf("tempo medio = %f\n", (double)(fine-inizio)/(CLOCKS_PER_SEC*10000));
	printf("tempo totale = %f\n", (double)(fine-inizio)/CLOCKS_PER_SEC);

	return 0;
}

void read(size_t dim, int array[dim]){
	for (size_t i = 0; i < dim; i++){
		printf("inserire numero in posizione %ld: ", i);
		while (scanf("%d", &array[i])!=1){
			printf("errore : ");
			while(getchar()!='\n');
		}
	}
}

void print(size_t dim, int array[dim]){
	for (size_t i = 0; i < dim; i++){
		printf("%d::", array[i]);
	}
}

void merge_sort(size_t dim, int array[dim]){
	sort(0, dim-1, array);
}

void sort(size_t inizio, size_t fine, int *array){
	if(fine-inizio >= 1){
		size_t centro1 = (fine+inizio)/2;
		size_t centro2 = centro1 + 1;
		sort(inizio, centro1, array);
		sort(centro2, fine, array);
		merge(inizio, centro1, centro2, fine, array);
	}
}

void merge(size_t sx, size_t centro1, size_t centro2, size_t fine, int *array){
	size_t sxI = sx, dxI = centro2, coI = 0;
	int combinato[fine-sx+1];
	while(sxI <= centro1 && dxI <= fine){
		if(array[sxI] < array[dxI]){
			combinato[coI++] = array[sxI++];
		} else {
			combinato[coI++] = array[dxI++];
		}
	}
	while (sxI <= centro1){
		combinato[coI++] = array[sxI++];		
	}
	while (dxI <= fine){
		combinato[coI++] = array[dxI++];		
	}
	coI = 0;
	for (size_t i = sx; i <= fine; i++)	{
		array[i] = combinato[coI++];
	}	
}