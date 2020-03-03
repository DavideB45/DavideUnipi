#include <stdio.h>

int readInt(void);
void fillArray(int dim, int *array);
void merge(int dimA, int *A, int dimB, int *B);

int main(void){
	int dimA = readInt();
	int A[dimA];
	fillArray(dimA, A);

	int dimB = readInt();
	int B[dimB];
	fillArray(dimB, B);

	merge(dimA, A, dimB, B);

	return 0;
}

int readInt(void){
	int num;
	while (scanf("%d", &num) != 1){
		while(getchar() != '\n');
		printf("no : ");
	}
	return num;
}

void fillArray(int dim, int *array){
	for (size_t i = 0; i < dim; i++)
		array[i] = readInt();
}

void merge(int dimA, int *A, int dimB, int *B){
	int a_i = 0, b_i = 0;
	while(a_i < dimA && b_i < dimB){
		if(A[a_i] < B[b_i]){
			printf("%d\n", A[a_i++]);
		} else {
			printf("%d\n", B[b_i++]);
		}
	}
	while(a_i < dimA){
		printf("%d\n", A[a_i++]);
	}
	while(b_i < dimB){
		printf("%d\n", B[b_i++]);
	}
}