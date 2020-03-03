//per ottimizzare basta fare il merge/quick sort
//poi usare lo stesso codice dell' intersezione ordinata
#include <stdio.h>
#include <stdlib.h>

int readInt(void);
void fillArray(int dim, int *array);
int intersection(int dimA, int *A, int dimB, int *B);

int main(void){
	int dimA = readInt();
	int *A = malloc(dimA*sizeof(int));
	fillArray(dimA, A);
	int dimB = readInt();
	int *B = malloc(dimB*sizeof(int));
	fillArray(dimB, B);

	printf("%d\n", intersection(dimA, A, dimB, B));
	free(A);
	free(B);
	return 0;
}

int readInt(void){
	int num;
	while(scanf("%d", &num) != 1){
		while(getchar() != '\n');
		printf("input errato : ");
	}
	return num;
}

void fillArray(int dim, int *array){
	for (size_t i = 0; i < dim; i++)
		array[i] = readInt();
}

int intersection(int dimA, int *A, int dimB, int *B){
	int total = 0;
	for (size_t i = 0; i < dimA; i++){
		for (size_t j = 0; j < dimB; j++){
			if(A[i] == B[j]){
				total++;
				break;
			}
		}
	}
	return total;
}