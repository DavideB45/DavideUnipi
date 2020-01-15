#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int val;
	struct nodo *nextPtr;
}Nodo;
typedef Nodo *NodoPtr;

int readInt(void);
_Bool insert(NodoPtr *headPtr);
NodoPtr fusion(NodoPtr *h1Ptr, NodoPtr *h2Ptr);
void printlist(NodoPtr corrPtr);
void freelist(NodoPtr corrPtr);

int main(void){
	NodoPtr h1Ptr = NULL;
	while(&h1Ptr);
	NodoPtr h2Ptr = NULL;
	while(&h2Ptr);

	NodoPtr fusPtr = fusion(h1Ptr, h2Ptr);

	printlist(fusPtr);

	freelist(fusPtr);
	
	return 0;
}

int readInt(void){
	int num;
	while(scanf("%d", &num)!=1){
		printf("NO ");
		scanf("%*[\n]");
		scanf("%*c");
	}
	scanf("%*[\n]");
	scanf("%*c");
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

NodoPtr fusion(NodoPtr *h1Ptr, NodoPtr *h2Ptr){
	if((*h1Ptr)->val < (*h2Ptr)->val){
		NodoPtr start =	*h2Ptr;
	} else {
		NodoPtr start = *h2Ptr;
	}
	NodoPtr tempPtr;
	while((*h1Ptr)!=NULL && (*h2Ptr!=NULL)){
		if((*h1Ptr)->val < (*h2Ptr)->val){
			
		}
	}
	
}