#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int num;
	struct nodo *nextPtr;
}Nodo;
typedef Nodo *NodoPtr;

int readInt(void);
_Bool revinsert(NodoPtr *headPtr);
void addforgotten(NodoPtr corrPtr);
void printlist(NodoPtr corrPtr);
void freelist(NodoPtr corrPtr);

int main(void){
	
	NodoPtr headPtr = NULL;
	while(revinsert(&headPtr));
	//printlist(headPtr);

	addforgotten(headPtr);
	printlist(headPtr);

/*	freelist(headPtr);*/
	return 0;
}

int readInt(void){
	int num;
	while(scanf("%d", &num)!=1){
		scanf("%*[\n]");
		scanf("%*c");
		printf("NO ");
	}
	return num;
}

void printlist(NodoPtr corrPtr){
	while (corrPtr!=NULL){
		printf("%d --> ", corrPtr->num);
		corrPtr = corrPtr->nextPtr;
	} printf("NULL\n");
	
}

_Bool revinsert(NodoPtr *headPtr){
	int num = readInt();
	if(num < 0){
		return 0;
	} else {
		NodoPtr corrPtr = *headPtr;
		NodoPtr precPtr = NULL;
		while(corrPtr!=NULL && corrPtr->num > num){
			precPtr = corrPtr;
			corrPtr = corrPtr->nextPtr;
		}
		if (precPtr==NULL){
			precPtr = calloc(1, sizeof(Nodo));
			precPtr->nextPtr = corrPtr;
			precPtr->num = num;
			*headPtr = precPtr;
		} else {
			NodoPtr newPtr = calloc(1, sizeof(Nodo));
			precPtr->nextPtr = newPtr;
			newPtr->num = num;
			newPtr->nextPtr = corrPtr;
		}
		return 1;
	}
}

void addforgotten(NodoPtr corrPtr){
	if(corrPtr==NULL || corrPtr->nextPtr==NULL){
		return;
	} else {
		NodoPtr precPtr = corrPtr;
		corrPtr = corrPtr->nextPtr;
		NodoPtr toadd = NULL;
		while (corrPtr!=NULL){
			if(precPtr->num > corrPtr->num + 1){
				toadd = calloc(1, sizeof(Nodo));
				toadd->num = precPtr->num - 1;
				toadd->nextPtr = corrPtr;
				precPtr->nextPtr = toadd;
				precPtr = toadd;
			} else {
				precPtr = corrPtr;
				corrPtr = corrPtr->nextPtr;
			}
		}
	}
}