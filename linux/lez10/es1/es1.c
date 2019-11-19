#include <stdio.h>
#include <stdlib.h>

typedef struct numeri{
	int val;
	struct numeri *nextPtr;
}Int;
typedef Int *List;

List insert(List lPtr);
void add1(List *headPtr, List precPtr, List corrPtr);
void printlist(List lista);

int main(void){
	List lista = NULL;
	lista = insert(lista);
	add1(&lista, NULL, lista);
	printlist(lista);
	return 0;
}

List insert(List lPtr){
	int num;
	scanf("%d", &num);
	if(num<0){
		return lPtr;
	}
	else{
		List newPtr = malloc(sizeof(Int));
		if(newPtr==NULL){
			printf("memoria esaurita\n");
			exit(1);
		}
		newPtr->nextPtr = lPtr;
		newPtr->val = num;
		insert(newPtr);
	}
}

void add1(List *headPtr, List precPtr, List corrPtr){
	if(corrPtr==NULL){
		return;
	}
	if(corrPtr->val%2==0){
		List parPtr = malloc(sizeof(Int));
		if(parPtr==NULL){
			printf("memoria esaurita\n");
			exit(1);
		}
		parPtr->val = -1;
		parPtr->nextPtr = corrPtr;
		if(precPtr==NULL){
			*headPtr = parPtr;
		}
		else{
			precPtr->nextPtr = parPtr;
		}
	}
	add1(headPtr, corrPtr, corrPtr->nextPtr);
}

void printlist(List lista){
	while(lista!=NULL){
		printf("%d -> ", lista->val);
		lista = lista->nextPtr;
	};
	printf("NULL\n");
}