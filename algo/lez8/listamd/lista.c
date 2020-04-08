#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int val;
	struct nodo* nextPtr;
}Nodo;

int readInt(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("ritenta : ");
		while(getchar() != '\n');
	} while(getchar() != '\n'){}
	return num;
}

void reversePrint(Nodo * corrPtr){
	if(corrPtr==NULL)
		return;
	reversePrint(corrPtr->nextPtr);
	printf("%d\n", corrPtr->val);
	return;
}

int main(void){
	Nodo* headPtr = NULL;
	Nodo* corrPtr = malloc(sizeof(Nodo));
	if(corrPtr == NULL){
		printf("no memory\n");
		return 5;
	}
	headPtr = corrPtr;
	int dim = readInt();
	corrPtr->val = readInt();
	dim--;

	for(size_t i = 0; i < dim; i++){
		corrPtr->nextPtr = calloc(1, sizeof(Nodo));
		corrPtr = corrPtr->nextPtr;
		corrPtr->val = readInt();
	}

	reversePrint(headPtr);
	
	return 0;
}