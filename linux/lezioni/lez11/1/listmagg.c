#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int num;
	struct nodo *nextPtr;
}Nodo;
typedef Nodo *NPtr;


_Bool insert(NPtr *headPtr);
int readInt(void);
int sum(NPtr corrPtr);
int major(NPtr corrPtr, float mid);

int main(void){
	int n_el = 0;
	NPtr headPtr = NULL;
	
	while(insert(&headPtr));

	int somma = sum(headPtr);
	printf("%d\n", somma);

	printf("%d\n", major(headPtr, somma));

	return 0;	
}

int readInt(void){
	int num;
	while(scanf("%d", &num)!=1){
		while(getchar()!='\n');		
	} while(getchar()!='\n');
	return num;
}

_Bool insert(NPtr *headPtr){
	NPtr newPtr = calloc(1, sizeof(Nodo));
	if(newPtr==NULL){
		printf("Memoria Esaurita\n");
		exit(1);
	}

	int new = readInt();

	if(new < 0){
		return 0;
	} else {
		newPtr->nextPtr = (*headPtr);
		newPtr->num = new;
		(*headPtr) = newPtr;
		return 1;
	}
}

int sum(NPtr corrPtr){
	int sum = 0;
	while (corrPtr!=NULL){
		sum = sum + corrPtr->num;
		corrPtr = corrPtr->nextPtr;
	}
	return sum;
}

int major(NPtr corrPtr, float mid){
	int tot = 0;
	mid = mid/4;
	while (corrPtr!=NULL){
		if (corrPtr->num > mid){
			tot++;
		}
		corrPtr = corrPtr->nextPtr;
	}
	return tot;
}