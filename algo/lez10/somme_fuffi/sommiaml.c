#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int num;
	struct nodo* nextPtr;
}nodo;
typedef nodo* nodoPtr;

int readint();
nodoPtr add_queue(int contatore);
void print_list(nodoPtr corrPtr);
int sommiaml(nodoPtr corrPtr);
void free_list(nodoPtr corrPtr);

int main(void){
	int dim = readint();
	nodoPtr headPtr = add_queue(dim);


	print_list(headPtr);

	sommiaml(headPtr);

	print_list(headPtr);

	return 0;
}

int readint(){
	int num;
	while(scanf("%d", &num) != 1){
		printf("errore : ");
		while(getchar() != '\n');
	}while(getchar() != '\n');
	return num;
}

nodoPtr add_queue(int contatore){
	if(contatore == 0){
		return NULL;
	} else {
		nodoPtr corrPtr = malloc(sizeof(nodoPtr));
		int value = readint();
		corrPtr->num = value;
		corrPtr->nextPtr = add_queue(contatore-1);
		return corrPtr;
	}
}

int sommiaml(nodoPtr corrPtr){
	if(corrPtr == NULL)
		return 0;
	int tot = corrPtr->num;
	corrPtr->num = sommiaml(corrPtr->nextPtr);
	return corrPtr->num + tot;
}


void print_list(nodoPtr corrPtr){
	while(corrPtr != NULL){
		printf("%d ", corrPtr->num);
		corrPtr = corrPtr->nextPtr;
	}printf("\n");
}