#include <stdio.h>
#include <stdlib.h>

typedef enum {ROSSO, BINACO} Color;
typedef struct nodo{
	int key;
	Color colore;
	struct nodo * left;
	struct nodo * right;
}nodo;
typedef nodo * nodoPtr;



int readInt(void);
void insert(int value, nodoPtr * corrPtr);
_Bool altezza(nodoPtr  corrPtr, int *h);


int main(void){
	int dim_albero = readInt();
	nodoPtr rootPtr = NULL;
	int key;
	for (size_t i = 0; i < dim_albero; i++){
		key = readInt();
		insert(key, &rootPtr);
	}
	int h;
	printf(altezza(rootPtr, &h)? "TRUE\n" : "FALSE\n");
	return 0;
}

int readInt(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("errore nell'input : ");
		while(getchar() != '\n');
	}
	return num;
}

void insert(int value, nodoPtr * corrPtr){
	if(*corrPtr == NULL){
		*corrPtr = (nodoPtr) calloc(1, sizeof(nodo));
		(*corrPtr)->key = value;
		(*corrPtr)->colore = readInt();
		return;
	} else {
		if(value < (*corrPtr)->key)
			insert(value, &((*corrPtr)->left));
		else
			insert(value, &((*corrPtr)->right));
	}
}

_Bool altezza(nodoPtr  corrPtr, int *h){
	if(corrPtr == NULL){
		*h = 0;
		return 1;
	} else {
		int lh, rh;
		_Bool lcond, rcond;
		lcond = altezza(corrPtr->left, &lh);		
		rcond = altezza(corrPtr->right, &rh);

		//printf("%d %d\n", corrPtr->key, corrPtr->colore);
		//printf("%d %d\n\n", lh, rh);


		if(lcond && rcond){

			if(rh >= lh && rh - lh <= 1){//la condizione e' valida
				if(corrPtr->colore == ROSSO){//aggiorno l'altezza
					//printf("agg = rh + 1\n");
					*h = rh + 1;
				} else {
					*h = rh;
					//printf("aggiorno = rh\n");
				}
				return 1;

			} else {

				if(lh > rh && lh - rh <= 1){//la condizione e' verificata l = r +1
					if(corrPtr->colore == ROSSO){//aggiorno l'altezza
						*h = lh + 1;
					} else {
						*h = lh;
					}
					return 1;
				} else {// c'e' troppa differenza tra hs e hr
					return 0;
				}

			}
		} else {
			return 0;
		}
	}
}