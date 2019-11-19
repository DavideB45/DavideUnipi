#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
	int info;
	struct elemento * next;
} ElementoDiLista;
typedef ElementoDiLista* ListaDiElementi;

void add(ListaDiElementi *headPtr, int num);//aggiunge el
void pop(ListaDiElementi *headPtr);//rim el
void printlist(ListaDiElementi headPtr);//visualizza lista

int main(void){
	int num;
	ListaDiElementi headPtr = NULL;
	do{
		scanf("%d", &num);
		if(num>0){
			add(&headPtr, num);
		}
		if(num==0){
			pop(&headPtr);
		}
	}while(num>=0);
	printlist(headPtr);
	return 0;
}

void add(ListaDiElementi *headPtr, int num){
	ListaDiElementi newPtr;
	if((newPtr = malloc(sizeof(ElementoDiLista)))==NULL){
		printf("memoria esaurita\n");
		return;
	}
	newPtr->info = num;
	newPtr->next = *headPtr;
	*headPtr = newPtr;
}

void pop(ListaDiElementi *headPtr){
	ListaDiElementi tempPtr;
	if(*headPtr!=NULL){
		tempPtr = *headPtr;
		*headPtr = (*headPtr)->next;
		free(tempPtr);
	}
}

void printlist(ListaDiElementi headPtr){
	ListaDiElementi tofreePtr;
	while (headPtr!=NULL){
		tofreePtr = headPtr;
		printf("%d\n", headPtr->info);
		headPtr = headPtr->next;
		free(tofreePtr);
	}
	return;
}