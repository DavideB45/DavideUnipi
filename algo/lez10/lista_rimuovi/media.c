#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int num;
	struct nodo* nextPtr;
}nodo;
typedef nodo* nodoPtr;

int readint();
nodoPtr add_queue(int contatore, int *tot);
void remove_under(int num, nodoPtr *headPtr);
void print_list(nodoPtr corrPtr);
void free_list(nodoPtr corrPtr);

int main(void){
	int dim = readint();
	int tot = 0;
	nodoPtr headPtr = add_queue(dim, &tot);


	printf("%d\n", (int) tot/dim);
	print_list(headPtr);

	remove_under((int) tot/dim, &headPtr);
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

nodoPtr add_queue(int contatore, int *tot){
	if(contatore == 0){
		return NULL;
	} else {
		
		nodoPtr corrPtr = malloc(sizeof(nodoPtr));
		int value = readint();
		corrPtr->num = value;
		*tot += value;
		corrPtr->nextPtr = add_queue(contatore-1, tot);
		return corrPtr;
	}
	
}

void remove_under(int num, nodoPtr *headPtr){
	nodoPtr corrPtr = *headPtr;
	nodoPtr succPtr = NULL;
	
	while(corrPtr != NULL && corrPtr->num <= num){
		succPtr = corrPtr->nextPtr;
		free(corrPtr);
		corrPtr = succPtr;
	}

	*headPtr = corrPtr;
	succPtr = corrPtr->nextPtr;
	while(succPtr != NULL){
		if(succPtr->num <= num){
			corrPtr->nextPtr = succPtr->nextPtr;
			free(succPtr);
			succPtr = corrPtr->nextPtr;
		} else {
			corrPtr = succPtr;
			succPtr = succPtr->nextPtr;
		}
	}
}

void print_list(nodoPtr corrPtr){
	while(corrPtr != NULL){
		printf("%d ", corrPtr->num);
		corrPtr = corrPtr->nextPtr;
	}printf("\n");
}
