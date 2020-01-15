#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int num;
	struct nodo *nextPtr;
}Nodo;
typedef Nodo *NodoPtr;

int readInt(void);
void ceckPtr(void *Ptr);
_Bool insert(NodoPtr*headPtr);
void printlist(NodoPtr corrPtr);
void freelist(NodoPtr corrPtr);

int main(void){
	NodoPtr headPtr = NULL;
	while(insert(&headPtr));
	printlist(headPtr);
	freelist(headPtr);
	return 0;
}

int readInt(void){
	int num;
	while(scanf("%d", &num)!=1){
		printf("Errore nell' input");
		scanf("%*[^\n]");
		scanf("%*c");
	}
	scanf("%*[^\n]");
	scanf("%*c");
	return num;
}

void ceckPtr(void *Ptr){
	if(Ptr==NULL){
		printf("Memoria Esaurita\n");
		exit(EXIT_FAILURE);
	}
}

_Bool insert(NodoPtr*headPtr){
	
	int num = readInt();
	if(num < 0){
		return 0;
	}
	
	NodoPtr corrPtr = (*headPtr);
	NodoPtr precPtr = NULL;
	while(corrPtr!=NULL && corrPtr->num < num){
		precPtr = corrPtr;
		corrPtr = corrPtr->nextPtr;
	}
	if(precPtr==NULL){//aggiunta in testa
		precPtr = calloc(1, sizeof(Nodo));
		precPtr->nextPtr = corrPtr;
		precPtr->num = num;
		(*headPtr) = precPtr;
	} else {//aggiunta in mezzo o infondo
		NodoPtr newPtr = calloc(1, sizeof(Nodo));
		newPtr->num = num;
		precPtr->nextPtr = newPtr;
		newPtr->nextPtr = corrPtr;
	}
}

void printlist(NodoPtr corrPtr){
	while (corrPtr!=NULL){
		printf("%d -> ", corrPtr->num);
		corrPtr = corrPtr->nextPtr;
	}
	printf("NULL \n");
}

void freelist(NodoPtr corrPtr){
	NodoPtr tofree;
	while(corrPtr!=NULL){
		tofree = corrPtr;
		corrPtr = corrPtr->nextPtr;
		free(tofree);
	}
}