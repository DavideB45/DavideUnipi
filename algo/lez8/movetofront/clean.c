#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int val;
	struct nodo* nextPtr;
}nodo;
typedef nodo * nodoPtr;

int readInt(void);
nodoPtr fillqueue(int tot);
int find(int num,nodoPtr* headPtr);
void freeall(nodoPtr corrPtr);

int main(void){
	int dim = readInt();
	nodoPtr headPtr = fillqueue(dim);
	
	int pos, num;
	num = readInt();
	pos = find(num, &headPtr);
	while(pos >= 0){
		printf("%d\n", pos);
		num = readInt();
		pos = find(num, &headPtr);
	}
	printf("-1\n");
	freeall(headPtr);
	return 0;
}

int readInt(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("metti un numero : ");
		while(getchar() != '\n');
	}
	return num;
}

nodoPtr fillqueue(int tot){
	nodoPtr headPtr = (nodoPtr) malloc(sizeof(nodo));
	headPtr->val = readInt();
	if(headPtr == NULL){
		printf("mem error\n");
		exit(EXIT_FAILURE);
	}
	tot--;
	nodoPtr corrPtr = headPtr;
	for(size_t i = 0; i < tot; i++){
		corrPtr->nextPtr = (nodoPtr) malloc(sizeof(nodo));
		corrPtr = corrPtr->nextPtr;
		corrPtr->val = readInt(); 
	}
	corrPtr->nextPtr = NULL;
	return headPtr;
}

int find(int num,nodoPtr* headPtr){
	int pos = 0;
	nodoPtr corrPtr = *headPtr;
	nodoPtr precPtr = NULL;
	while(corrPtr != NULL && corrPtr->val != num){
		pos++;
		precPtr = corrPtr;
		corrPtr = corrPtr->nextPtr;
	}
	if(corrPtr == NULL){//non c'e'
		return -1;
	} else {
		if(precPtr == NULL){//prima pos
			return 0;
		} else {//altro
			precPtr->nextPtr = corrPtr->nextPtr;
			corrPtr->nextPtr = *headPtr;
			*headPtr = corrPtr;
			return pos;
		}
	}
}
void freeall(nodoPtr corrPtr){
	if(corrPtr!=NULL)
		free(corrPtr->nextPtr);
}
