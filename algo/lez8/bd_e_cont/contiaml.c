#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	int count;
	struct node * nextPtr;
	struct node * precPtr;
}Nodo;
typedef Nodo * NodoPtr;

int readInt(void);
void addQueue(NodoPtr* headPtr, NodoPtr* codaPtr);
int research(int val, NodoPtr* headPtr);


int main(void){
	NodoPtr headPtr = NULL;
	NodoPtr codaPtr = NULL;
	int len = readInt();

	for (size_t i = 0; i < len; i++){
		addQueue(&headPtr, &codaPtr);
	}
	

	int val;
	int pos;
	do{
		val = readInt();


		/*codaPtr = headPtr;
		while(codaPtr!= NULL){
			printf("%d->",codaPtr->val);
			codaPtr = codaPtr->nextPtr;
		}puts("");*/

		pos = research(val, &headPtr);
		printf("%d\n", pos);

		/*codaPtr = headPtr;
		while(codaPtr!= NULL){
			printf("%d->",codaPtr->val);
			codaPtr = codaPtr->nextPtr;
		}puts("\n");*/
	
	}while(pos >= 0);
	

	return 0;
}

int readInt(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("ritenta : ");
		while(getchar() != '\n');
	}
	return num;
}

void addQueue(NodoPtr* headPtr, NodoPtr* codaPtr){
	if(*codaPtr == NULL){
		*codaPtr = calloc(1, sizeof(Nodo));
		*headPtr = *codaPtr;
		(*codaPtr)->val = readInt();
	} else {
		(*codaPtr)->nextPtr = calloc(1, sizeof(Nodo));
		(*codaPtr)->nextPtr->precPtr = (*codaPtr);
		(*codaPtr) = (*codaPtr)->nextPtr;
		(*codaPtr)->val = readInt();
	}
}

int research(int val, NodoPtr* headPtr){
	int distance = 0;
	NodoPtr corrPtr = *headPtr;
	NodoPtr insert;
	while(corrPtr != NULL && corrPtr->val != val){
		distance++;
		corrPtr = corrPtr->nextPtr;
	}
	if(corrPtr == NULL){
		return -1;
	} else {
		corrPtr->count++;
		if(distance == 0){
			return 0;
		}
		if(corrPtr->nextPtr != NULL){
			corrPtr->nextPtr->precPtr = corrPtr->precPtr;
		}
		corrPtr->precPtr->nextPtr = corrPtr->nextPtr;
		insert = corrPtr->precPtr;
		while(insert != NULL && insert->count < corrPtr->count){
			insert = insert->precPtr;
		}
		if(insert==NULL){//nuova testa
			//printf("Nuova testa\n");
			(*headPtr)->precPtr = corrPtr;
			corrPtr->nextPtr = *headPtr;
			corrPtr->precPtr = NULL;
			*headPtr = corrPtr;
			return distance;
		}
		corrPtr->precPtr = insert;
		corrPtr->nextPtr = insert->nextPtr;
		if(corrPtr->nextPtr != NULL){
			corrPtr->nextPtr->precPtr = corrPtr;
		}
		corrPtr->nextPtr = insert->nextPtr;
		insert->nextPtr = corrPtr;
		
		return distance;
	}

}