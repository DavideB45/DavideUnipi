#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int num;
	struct nodo *nextPtr;
}Nodo;
typedef Nodo *nodoPtr;

int readint(void);
void insert(nodoPtr *headPtr);
void rem(int n, nodoPtr *headPtr);
void printlist(nodoPtr corrPtr);

int main(void){
	nodoPtr headPtr = NULL;
	insert(&headPtr);
	printlist(headPtr);
	int n = readint();
	rem(n, &headPtr);
	printlist(headPtr);
	return 0;
}

int readint(void){
	int num;
	while(scanf("%d", &num)!=1){
		printf("numero non valido : ");
		scanf("%*[^\n]");
		scanf("%*c");
	}
	scanf("%*[^\n]");
	scanf("%*c");
	return num;
}

void insert(nodoPtr *headPtr){
	int num;
	nodoPtr newPtr;
	
	newPtr = calloc(1, sizeof(Nodo));
	num = readint();	
	newPtr->num = num;
	(*headPtr) = newPtr;
	
	nodoPtr prec = (*headPtr);
	while (num = readint(), num > -1){
		newPtr = calloc(1, sizeof(Nodo));
		newPtr->num = num;
		prec->nextPtr = newPtr;
		prec = newPtr;
	}
}

void rem(int n, nodoPtr *headPtr){
	nodoPtr tokill = (*headPtr);
	while(  (*headPtr) != NULL  &&  n > 0  ){
		n--;
		(*headPtr) = (*headPtr)->nextPtr;
		free(tokill);
		tokill = (*headPtr);
	}
}

void printlist(nodoPtr corrPtr){
	while(corrPtr!=NULL){
		printf("%d -> ", corrPtr->num);
		corrPtr = corrPtr->nextPtr;
	}printf("NULL\n");
}