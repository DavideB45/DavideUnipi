#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int val;
	struct nodo* left;
	struct nodo* right;
}Nodo;
typedef Nodo* NodoPtr;

int readInt(void);
void insert(NodoPtr *corrPtr, int val);//val = valore da inserire
void print_h(NodoPtr corrPtr, int liv);//liv = livelli da scendere
void freetree(NodoPtr *corrPtr);

int main(void){
	int N_nodi = readInt();
	NodoPtr headPtr = NULL;
	int val;
	for(size_t i = 0; i < N_nodi; i++){
		val = readInt();
		insert(&headPtr, val);
	}
	int livello = readInt();
	print_h(headPtr, livello);
	freetree(&headPtr);
	return 0;
}

int readInt(void){
	int num;
	while (scanf("%d", &num) != 1){
		printf("errore nell' input : ");
		while(getchar() != '\n');
	}
	return num;
}

void insert(NodoPtr *corrPtr, int val){
	if(*corrPtr == NULL){
		*corrPtr = (NodoPtr) calloc(1, sizeof(Nodo));
		(*corrPtr)->val = val;
	} else {
		if(val > (*corrPtr)->val){
			insert( &((*corrPtr)->right), val);
		} else {
			insert( &((*corrPtr)->left), val);
		}
	}
}

void print_h(NodoPtr corrPtr, int liv){
	

	if(corrPtr == NULL){
		return;
	}
	
	if(liv == 0 && corrPtr != NULL){
		printf("%d\n", corrPtr->val);
	} else {
		if(liv > 0){
			print_h(corrPtr->left, liv - 1);
			print_h(corrPtr->right, liv - 1);
		}
	}
}

void freetree(NodoPtr corrPtr){
	if(corrPtr== NULL)
		return ;
	freetree( ((corrPtr)->left)  );
	freetree( ((corrPtr)->right) );
	free(corrPtr);
}
