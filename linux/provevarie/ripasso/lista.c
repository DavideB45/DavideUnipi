#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int num;
	struct nodo *nextPtr;
} Nodo;
typedef Nodo *NodoPtr;

void insertionsort(NodoPtr *head);
void printlist(NodoPtr corrPtr);
void removeduplicate(NodoPtr *head);
void ceck(void *Ptr);

int main(void){
	NodoPtr headPtr = NULL;
	
	for (size_t i = 0; i < 9; i++){
		insertionsort(&headPtr);
	}
	printlist(headPtr);
	
	removeduplicate(&headPtr);
	printlist(headPtr);

	return 0;
}

void ceck(void *Ptr){
	if(Ptr==NULL){
		puts("Memory Full");
		exit(1);
	}
}

void insertionsort(NodoPtr *head){
	NodoPtr newPtr = calloc(1, sizeof(Nodo));
	NodoPtr corrPtr = (*head);
	NodoPtr precPtr = NULL;

	while (scanf("%d", &(newPtr->num))!=1){
		printf("UN NUMERO INTERO : ");
		scanf("%*[^\n]");
		scanf("%*c");
	}
	ceck(newPtr);
	while(corrPtr != NULL  &&  corrPtr->num < newPtr->num){
		precPtr = corrPtr;
		corrPtr = corrPtr->nextPtr;
	}
	if(precPtr==NULL){
		newPtr->nextPtr = (*head);
		(*head) = newPtr;
	} else {
		newPtr->nextPtr = corrPtr;
		precPtr->nextPtr = newPtr;
	}
	return;
}

void printlist(NodoPtr corrPtr){
	while(corrPtr!=NULL){
		printf("%d->", corrPtr->num);
		corrPtr = corrPtr->nextPtr;
	} printf("\n\n");
	return;
}

void removeduplicate(NodoPtr *head){
	NodoPtr corrPtr = (*head)->nextPtr;
	NodoPtr precPtr = *head;

	while(corrPtr!=NULL){
		if(precPtr->num==corrPtr->num){
			precPtr->nextPtr = corrPtr->nextPtr;
			free(corrPtr);
			corrPtr = precPtr->nextPtr;
		} else {
			precPtr = corrPtr;
			corrPtr = corrPtr->nextPtr;
		}
	}
}