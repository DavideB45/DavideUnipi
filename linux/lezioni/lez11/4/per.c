#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int value;
	struct nodo *nextPtr;
}Nodo;
typedef Nodo *NodoPtr;


void ceck(void *Ptr);
int readInt(void);
_Bool insort(NodoPtr *headPtr);
int prodotto(int inizio, int fine, NodoPtr corrPtr);
void removeduplicate(NodoPtr corrPtr);
void freee(NodoPtr *corrPtr);
void printlist(NodoPtr corrPtr);


int main(){
	int inizio = readInt();
	int fine = readInt();
	printf("Inizia a mettere la lista : \n");
	NodoPtr headPtr = NULL;
	while(insort(&headPtr));
	printlist(headPtr);
	removeduplicate(headPtr);
	printlist(headPtr);
	int prod = prodotto(inizio, fine, headPtr);
	printf("il prodotto vale : %d\n", prod);
	freee(&headPtr);
	return 0;
}

void ceck(void *Ptr){
	if(Ptr == NULL){
		printf("memoria esaurita \n");
		exit(1);
	}
}

int readInt(void){
	int num;
	while(scanf("%d", &num)!=1){
		printf("Errore nell'input : ");
		scanf("%*[\n]");
		scanf("%*c");
	}
	return num;
}

_Bool insort(NodoPtr *headPtr){
	int num = readInt();
	if(num < 0){
		return 0;
	} else {
		NodoPtr newPtr = calloc(1, sizeof(Nodo));
		ceck(newPtr);
		newPtr->value = num;
		newPtr->nextPtr = NULL;
		if((*headPtr)==NULL){
			(*headPtr) = newPtr;
		} else {
			NodoPtr corrPtr = (*headPtr);
			NodoPtr precPtr = NULL;
			while(corrPtr!=NULL && corrPtr->value < num){
				precPtr = corrPtr;
				corrPtr = corrPtr->nextPtr;
			}
			if(precPtr == NULL){
				newPtr->nextPtr = (*headPtr);
				(*headPtr) = newPtr;
			} else {
				precPtr->nextPtr = newPtr;
				newPtr->nextPtr = corrPtr;
			}
		}
		return 1;
	}
}

void removeduplicate(NodoPtr corrPtr){
	if(corrPtr==NULL){
		return;
	}
	NodoPtr nextPtr = corrPtr->nextPtr;
	NodoPtr tokill;
	while(nextPtr!=NULL){
		if(corrPtr->value==nextPtr->value){
			tokill = nextPtr;
			nextPtr = nextPtr->nextPtr;
			free(tokill);
			corrPtr->nextPtr = nextPtr;
		} else {
			corrPtr = nextPtr;
			nextPtr = nextPtr->nextPtr;
		}
	}
	
}

void printlist(NodoPtr corrPtr){
	while(corrPtr!=NULL){
		printf("%d->", corrPtr->value);
		corrPtr = corrPtr->nextPtr;
	} printf("fine\n");
}

void freee(NodoPtr *corrPtr){
	NodoPtr tokill = (*corrPtr);
	while((*corrPtr)!=NULL){
		(*corrPtr) = (*corrPtr)->nextPtr;
		free(tokill);
		tokill = (*corrPtr);
	}
}

int prodotto(int inizio, int fine, NodoPtr corrPtr){
	if(corrPtr==NULL){
		return -1;
	} else {
		int per = 1;
		while(corrPtr!=NULL && corrPtr->value <= inizio){
			printf("%d->\n", corrPtr->value);
			corrPtr = corrPtr->nextPtr;
		}
		printf("\n");
		while(corrPtr!=NULL && corrPtr->value < fine){
			printf("%d->\n", corrPtr->value);
			per = per*(corrPtr->value);
			corrPtr = corrPtr->nextPtr;
		}
		return per;
	}
}