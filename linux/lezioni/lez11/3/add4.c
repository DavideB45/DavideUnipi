#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int num;
	struct nodo *nextPtr;
}Nodo;
typedef Nodo *NodoPtr;

void insert(NodoPtr *headPtr);
int readInt(void);
void ceck(void *Ptr);
void add4(NodoPtr *headPtr);
void printlist(NodoPtr corrPtr);

int main(void){
	NodoPtr headPtr = NULL;
	insert(&headPtr);
	add4(&headPtr);
	printlist(headPtr);
}

int readInt(void){
	int num;
	while(scanf("%d", &num)!=1){
		printf("ritenta : ");
		scanf("%*[^\n]");
		scanf("%*c");
	}
	scanf("%*[^\n]");
	scanf("%*c");
	return num;
}

void ceck(void *Ptr){
	if(Ptr == NULL){
		exit(1);
	}
}

void insert(NodoPtr *headPtr){
	
	int num = readInt();
	if(num > -1){	
		NodoPtr newPtr = calloc(1, sizeof(Nodo));
		ceck(newPtr);
		(*headPtr) = newPtr;
		newPtr->num = num;

		NodoPtr precPtr = newPtr;
		while(num = readInt(), num > -1){
			NodoPtr newPtr = calloc(1, sizeof(Nodo));
			ceck(newPtr);
			precPtr->nextPtr = newPtr;
			precPtr = newPtr;
			newPtr->num = num;			
		}
	}
}

void add4(NodoPtr *headPtr){
	NodoPtr new = calloc(1, sizeof(Nodo));
	ceck(new);
	new->num = readInt();

	if((*headPtr)==NULL){
		(*headPtr) = new;
	} else {
		NodoPtr corrPtr  = (*headPtr);
		int quattro = 4;

		while(quattro > 1 && corrPtr->nextPtr!=NULL){
			corrPtr = corrPtr->nextPtr;
			quattro--;
		}
		
		new->nextPtr = corrPtr->nextPtr;
		corrPtr->nextPtr = new;
	}

}

void printlist(NodoPtr corrPtr)
{
	while(corrPtr!=NULL)
	{
		printf("%d -> ", corrPtr->num);
		corrPtr = corrPtr->nextPtr;
	} printf("\n");
}