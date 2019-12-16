#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define COLONNE 8

typedef struct nodo{
	char *riga;
	struct nodo* nextPtr;
}Nodo;
typedef Nodo *NodoPtr;

void read(size_t righe, char matrice[righe][COLONNE]);
_Bool isok(char *stringa);
void printlist(NodoPtr *correntePtr);
void easysort(size_t righe, char matrice[righe][COLONNE], NodoPtr *headPtr);

int main(void){
	int righe;
	printf("inserire righe : ");
	while(scanf("%d", &righe)!=1  || righe<1){
		printf("inserire interi positivi: ");
		while(getchar()!='\n');
	}
	char matrice[righe][COLONNE];
	read(righe, matrice);

	NodoPtr headPtr = NULL;
	//easysort(righe, matrice, &headPtr);

	//printlist(&headPtr);
}

_Bool isok(char *stringa){
	while(!errore &&)
}

void read(size_t righe, char matrice[righe][COLONNE]){
	for(int i = 0; i < righe; i++){
		while(scanf("%s", &matrice[i]), !isok(matrice[i]));
		printf("%s\n", matrice[i]);
	}
}