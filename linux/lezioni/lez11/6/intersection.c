#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int val;
	struct nodo *nextPtr;
}Nodo;
typedef Nodo *NodoPtr;

int readInt(void);
_Bool insert(NodoPtr *headPtr);
void fusion(NodoPtr *h1Ptr, NodoPtr *h2Ptr);
void printlist(NodoPtr corrPtr);
void freelist(NodoPtr corrPtr);

int main(void){
	
	NodoPtr h1Ptr = NULL;
	while(insert(&h1Ptr));
	//printlist(h1Ptr);

	NodoPtr h2Ptr = NULL;
	while(insert(&h2Ptr));
	//printlist(h2Ptr);

	fusion(&h1Ptr, &h2Ptr);

	printlist(h1Ptr);

	freelist(h1Ptr);
	
	return 0;
}

int readInt(void){
	int num;
	while(scanf("%d", &num)!=1){
		printf("NO ");
		scanf("%*[\n]");
		scanf("%*c");
	}
//	scanf("%*[\n]");
//	scanf("%*c");
	return num;
}

_Bool insert(NodoPtr *headPtr){
	int num = readInt();
	if(num < 0){
		return 0;
	} else {
		NodoPtr corrPtr = (*headPtr);
		NodoPtr precPtr = NULL;
		while(corrPtr != NULL && corrPtr->val < num){
			precPtr = corrPtr;
			corrPtr = corrPtr->nextPtr;
		}
		if(precPtr==NULL){
			precPtr = calloc(1, sizeof(Nodo));
			precPtr->val = num;
			precPtr->nextPtr = corrPtr;
			(*headPtr) = precPtr;
		} else {
			NodoPtr newPtr = calloc(1, sizeof(Nodo));
			newPtr->val = num;
			newPtr->nextPtr = corrPtr;
			precPtr->nextPtr = newPtr;
		}
		return 1;
	}
}

void fusion(NodoPtr *h1Ptr, NodoPtr *h2Ptr){
	NodoPtr start;
	if(*h2Ptr==NULL){
		return;
	} else {
		if(*h1Ptr==NULL){
			*h1Ptr = *h2Ptr;
			return;
		}
	}
	
	if((*h1Ptr)->val < (*h2Ptr)->val){
		start =	*h1Ptr;
	} else {
		start = *h2Ptr;
	}
	NodoPtr tempPtr;
	NodoPtr precPtr = NULL;
	while((*h1Ptr)!=NULL && (*h2Ptr!=NULL)){
		if((*h1Ptr)->val < (*h2Ptr)->val){
			precPtr = *h1Ptr;
			*h1Ptr = (*h1Ptr)->nextPtr;
		} else {
			tempPtr = (*h2Ptr)->nextPtr;
			(*h2Ptr)->nextPtr = *h1Ptr;
			if(precPtr!=NULL){
				precPtr->nextPtr = *h2Ptr;
				(*h2Ptr)->nextPtr = *h1Ptr;
				precPtr = *h2Ptr;
			} else {
				precPtr = *h2Ptr;
			}
			*h2Ptr = tempPtr;
		}
	}
	if(*h1Ptr==NULL){
		*h1Ptr = start;
		while((*h1Ptr)->nextPtr!=NULL){
			*h1Ptr = (*h1Ptr)->nextPtr;
		}
		(*h1Ptr)->nextPtr = *h2Ptr;
	}
	*h1Ptr = start;
}

void printlist(NodoPtr corrPtr){
	while (corrPtr!= NULL){
		printf("%d --> ", corrPtr->val);
		corrPtr = corrPtr->nextPtr;
	} printf("NULL\n");
}

void freelist(NodoPtr corrPtr){
	NodoPtr tofree = corrPtr;
	while (corrPtr!=NULL){
		tofree = corrPtr;
		corrPtr = corrPtr->nextPtr;
		free(tofree);	
	}
}