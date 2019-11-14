#include <stdio.h>
#include <stdlib.h>
#define SCELTE 2

struct nodo {
	int dato;
	struct nodo *prossimoPtr;
};

typedef struct nodo Nodo;
typedef Nodo *NodoPtr;

void menu(short *scelta);
void insert(NodoPtr *lPtr, int val);
void delite(NodoPtr *lPtr, int val);
int is_empty(NodoPtr lPtr);
void stampa_lista(NodoPtr cPtr);

int main(void){
	Nodo *lPtr = NULL;
	int val;
	short scelta;
	menu(&scelta);
	while(scelta >= 0 && scelta <= SCELTE - 1){
		//la scelta e' fatta nella funzione menu
		printf("Valore da inserire o cancellare: ");
		while(scanf("%d", &val)!=1){
			printf("Valore da inserire o cancellare: ");
			while(getchar() != '\n');
		}
		void (*f[SCELTE])(NodoPtr *, int) = {insert, delite};
		(*f[scelta])(&lPtr, val);
		menu(&scelta);
	}
	//stampa_lista(lPtr);
}

void menu(short *scelta){
	printf("0. inserire un nodo\n\
	1. cancella un nodo\n\
	altro num. unscire\n");
	while(scanf("%hd", scelta)!=1){
		printf("ritenta: ");
		while(getchar()!='\n');
	}
	return;
}

void insert(NodoPtr *lPtr, int val){
	//alloco nuovo nodo
	NodoPtr nuovoPtr = malloc(sizeof(Nodo));
	if(nuovoPtr!=NULL){
		//l'asegnamento viene fatto alla fine
		nuovoPtr->dato = val;
		nuovoPtr->prossimoPtr = NULL;
		
		NodoPtr precedentePtr = NULL;
		NodoPtr correntePtr = *lPtr;
		
		//!=NULL non e' l'ultimo elemento 
		//durante l'inserimento ordina anche
		while(correntePtr != NULL && val > correntePtr->dato){
		//si sposta al prossimo elemento
			precedentePtr = correntePtr;
			correntePtr = correntePtr->prossimoPtr;
		}
		if(precedentePtr == NULL){
		//inserimento al primo elemeto;
			nuovoPtr->prossimoPtr = nuovoPtr;
			*lPtr = nuovoPtr;
		}
		else{
		//inserimento nel mezzo o alla fine
			precedentePtr->prossimoPtr = nuovoPtr;
			nuovoPtr->prossimoPtr = correntePtr;
		}
	}
	else{
		puts("Memoria esaurita");
	}
}

void delite(NodoPtr *lPtr, int val){
	//se la lista  
	/*if(*lPtr != NULL){
		if(val == (*lPtr)->dato){
			NodoPtr tempPtr = *lPtr;
			*lPtr = */
	return;
}


























	
