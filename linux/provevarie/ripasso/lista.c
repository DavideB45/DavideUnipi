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
void removechosen(NodoPtr *head);
void ceck(void *Ptr);
void clean(void);

int main(void){
	NodoPtr headPtr = NULL;
	
	for (size_t i = 0; i < 9; i++){
		printf("Metti ancora %ld numeri : ", 9-i);
		insertionsort(&headPtr);
	}
	printlist(headPtr);
	
	removeduplicate(&headPtr);
	printlist(headPtr);

	removechosen(&headPtr);
	printlist(headPtr);

	return 0;
}

void ceck(void *Ptr){
	if(Ptr==NULL){
		puts("Memory Full");
		exit(1);
	}
}

void clean(void){
	scanf("%*[^\n]");
	scanf("%*c");
}

void insertionsort(NodoPtr *head){
	
	NodoPtr corrPtr = (*head);
	NodoPtr precPtr = NULL;
	NodoPtr newPtr = calloc(1, sizeof(Nodo));
	ceck(newPtr);

	while (scanf("%d", &(newPtr->num))!=1){
		printf("UN NUMERO INTERO : ");
		clean();
	}
	clean();

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

void removechosen(NodoPtr *head){
	int num;
	printf("metti il numero che vuoi togliere : ");
	while(scanf("%d", &num)!=1){
		printf("il numero non va bene : ");
		clean();
	}
	clean();
	
	NodoPtr corrPtr = (*head);
	NodoPtr precPtr = NULL;
	while(corrPtr!=NULL && corrPtr->num!=num){
		precPtr = corrPtr;
		corrPtr = corrPtr->nextPtr;
	}

	if(corrPtr==NULL){
		printf("Numero non trovato\n");
	} else {
		if(precPtr==NULL){
			*head = corrPtr->nextPtr;
		} else {
			precPtr->nextPtr = corrPtr->nextPtr;
		}
		free(corrPtr);
		printf("Numero rimosso\n");
	}
	
}