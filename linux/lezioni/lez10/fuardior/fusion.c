#include <stdio.h>
#include <stdlib.h>

int readint(void);
void createarray(size_t dim, int **arrPtr);
void printarray(size_t dim, int *arrPtr);
int* fondi(size_t dimA, int *APtr, size_t dimB, int *BPtr);
int isordered(size_t dim, int *arrPtr);

int main(void){
	int *A;
	int *B;
	int dimA, dimB;

	dimA = readint();
	createarray(dimA, &A);
	dimB = readint();
	createarray(dimB, &B);

	printf("Array A:\n");
	printarray(dimA, A);
	printf("Array B:\n");
	printarray(dimB, B);
	
	int *C = fondi(dimA, A, dimB, B);
	printf("Array risultato C\n");
	printarray(dimA + dimB, C);
	printf("Ordinato: %d\n", isordered(dimA + dimB, C));
	return 0;
}

int readint(void){
	int  num;
	while(scanf("%d", &num)!=1){
		printf("inserire un numero positivo");
		scanf("%*[\n]");
		scanf("%*c");
	}
	return num;
}

void createarray(size_t dim, int **arrPtr){
	*arrPtr = calloc(dim, sizeof(int));
	for (size_t i = 0; i < dim; i++){
		*(*arrPtr + i) = readint();
	}
	return;
}

void printarray(size_t dim, int *arrPtr){
	for(size_t i = 0; i < dim ; i++){
		printf("%d ", *(arrPtr + i));
	}
	printf("\n");
	return;
}

int* fondi(size_t dimA, int *APtr, size_t dimB, int *BPtr){
	int* CPtr = calloc((dimA+dimB), sizeof(int));
	int indA = 0, indB = 0, indC = 0;
	while(indA<dimA && indB<dimB){
		if(*(APtr + indA)<*(BPtr + indB)){
			*(CPtr + indC) = *(APtr + indA);
			indA++;
			indC++;
		}
		else{
			*(CPtr + indC) = *(BPtr + indB);
			indB++;
			indC++;
		}
	}
	for(size_t i = indA; i < dimA; i++){
		*(CPtr + indC) = *(APtr + indA);
		indC++;
		indA++;
	}
	for(size_t i = indB; i < dimB; i++){
		*(CPtr + indC) = *(BPtr + indB);
		indC++;
		indB++;
	}
	return CPtr;
}

int isordered(size_t dim, int *arrPtr){
	if(dim -1 == 0){
		return 1;
	}
	if(*arrPtr <= *(arrPtr + 1)){
		return isordered((dim - 1), (arrPtr + 1));
	}
	else{
		return 0;
	}
}