#include <stdio.h>
#include <stdlib.h>

typedef struct numeri{
	int val;
	struct numeri *nextPtr;
}Int;
typedef Int *List;

void insertnum(int val, List *headPtr);
void printlist(List lista);

int main(void){
	int val;
	List headPtr = NULL;
	scanf("%d", &val);
	while(val>=0){
		insertnum(val, &headPtr);
		scanf("%d", &val);
	}
	printlist(headPtr);
}

void insertnum(int val, List *headPtr){
	List newPtr = malloc(sizeof(Int));
	if(newPtr == NULL){
		printf("memoria esaurita\n");
		exit(1);
	}
	if(*headPtr == NULL){
		newPtr->val = val;
		newPtr->nextPtr = NULL;
		*headPtr = newPtr;
		return;
	}
	List precPtr = *headPtr;
	List corrPtr = *headPtr;
	while((corrPtr!=NULL) && (val > corrPtr->val)){
		precPtr = corrPtr;
		corrPtr = corrPtr->nextPtr;
	}
	//printf("\nh = %p\nc = %p\n\n", *headPtr, corrPtr);
	if(*headPtr==corrPtr){
		newPtr->val = val;
		newPtr->nextPtr = corrPtr;
		*headPtr = newPtr;
		return;
	}
	newPtr->val = val;
	newPtr->nextPtr = precPtr->nextPtr;
	precPtr->nextPtr = newPtr;
	return;
}

void printlist(List lista){
	do{
		printf("%d\n", lista->val);
		lista = lista->nextPtr;
	}while(lista!=NULL);
}