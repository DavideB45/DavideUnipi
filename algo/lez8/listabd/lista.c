#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int val;
	struct nodo* nextPtr;
	struct nodo* precPtr;
}Nodo;
typedef Nodo* NodoPtr;

int readInt(void);
void addQueue(NodoPtr* headPtr, NodoPtr* codaPtr);
void printBack(NodoPtr corrPtr);

int main(void){
	NodoPtr headPtr = NULL;
	NodoPtr codaPtr = NULL;
	int len = readInt();

	for (size_t i = 0; i < len; i++){
		addQueue(&headPtr, &codaPtr);
	}
	
	printBack(codaPtr);

	return 0;
}

int readInt(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("ritenta : ");
		while(getchar() != '\n');
	} while(getchar() != '\n');
	return num;
}

void addQueue(NodoPtr* headPtr, NodoPtr* codaPtr){
	if(*codaPtr == NULL){
		*codaPtr = calloc(1, sizeof(Nodo));
		*headPtr = *codaPtr;
		(*codaPtr)->val = readInt();
	} else {
		(*codaPtr)->nextPtr = calloc(1, sizeof(Nodo));
		(*codaPtr)->nextPtr->precPtr = (*codaPtr);
		(*codaPtr) = (*codaPtr)->nextPtr;
		(*codaPtr)->val = readInt();
	}
}

void printBack(NodoPtr corrPtr){
	while(corrPtr != NULL){
		printf("%d\n", corrPtr->val);
		corrPtr = corrPtr->precPtr;
	}
}
