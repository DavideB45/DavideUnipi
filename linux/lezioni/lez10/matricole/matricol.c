#include <stdio.h>
#include <stdlib.h>

typedef struct matricola{
	int numMatr;
	struct matricola* nextPtr;
}Matr;
typedef Matr* List;

int getint(void);//legge un intero non negativo
void insert(List *headPtr, List *endPtr, int matr);//inserisce la matricola in coda
void RecLenght(List corrPtr, int num);//conta il numero di matricole
void RecStampaInversa(List corrPtr);//stampa le matricole in ordile inverso
List kill(List corrPtr,List precPtr, int num);//killa le matricole multiple di nun
void RecStampa(List corrPtr);//stampa i superstiti
void PariDisp(List corrPtr, int *pari, int *dispari);//cerca la prma matricola pari e la prima dispari

int main(void){
	List headPtr = NULL;
	List endPtr = NULL;
	int num = getint();
	while(num>0){
		insert(&headPtr, &endPtr, num);
		num = getint();
	}
	//
	RecLenght(headPtr, 0);
	
	printf("Stampa l'elenco in ordine inverso di immissione (NULL se vuota):\n");
	RecStampaInversa(headPtr);
	printf("NULL\n");

	printf("Inserisci il numero richiesto:\n");
	while((num = getint())==0);
	headPtr = kill(headPtr, NULL, num);
	
	printf("Stampa l'elenco in ordine di immissione (NULL se vuota):\n");
	RecStampa(headPtr);

	int pari = -1, dispari = -1;
	PariDisp(headPtr, &pari, &dispari);
	printf("Dispari:%d\n", dispari);
	printf("Pari:%d\n", pari);
	return 0;
}

int getint(void){
	int num;
	while((scanf("%d", &num)!=1) || num<0){
		printf("Inserisci intero positivo o 0 per uscire\n");
		scanf("%*[^\n]");
		scanf("%*c");
	}
	return num;
}

void insert(List *headPtr, List *endPtr, int matr){
	List newPtr = malloc(sizeof(Matr));
	if(newPtr==NULL){
		printf("memoria esaurita\n");
		exit(1);
	}
	newPtr->numMatr = matr;
	if(*headPtr==NULL){
		newPtr->nextPtr = NULL;
		*headPtr = newPtr;
		*endPtr = newPtr;
	}
	else{
		(*endPtr)->nextPtr = newPtr;
		newPtr->nextPtr = NULL;
		*endPtr = newPtr;
	}
}

void RecLenght(List corrPtr, int num){
	if(corrPtr==NULL){
		printf("numero matricole: %d\n", num);
		return;
	}
	else{
		return RecLenght(corrPtr->nextPtr,++num);
	}
}

void RecStampaInversa(List corrPtr){
	if(corrPtr==NULL){
		return;
	}
	else{
		RecStampaInversa(corrPtr->nextPtr);
		printf("%d->", corrPtr->numMatr);
	}
}

List kill(List corrPtr,List precPtr, int num){
	if(corrPtr==NULL){
		return NULL;
	}
	corrPtr->nextPtr = kill(corrPtr->nextPtr, corrPtr, num);
	if(corrPtr->numMatr%num==0){
		if(precPtr==NULL){
			precPtr = corrPtr->nextPtr;//usato come corrPtr
			free(corrPtr);
			return precPtr;//usato come corrPtr
		}
		precPtr->nextPtr = corrPtr->nextPtr;
		free(corrPtr);
		return precPtr->nextPtr;
	}
	if(precPtr==NULL){
		return corrPtr;
	}
	else{
		return precPtr->nextPtr;
	}
}

void RecStampa(List corrPtr){
	if(corrPtr==NULL){
		printf("NULL\n");
		return;
	}
	else{
		printf("%d->", corrPtr->numMatr);
		return RecStampa(corrPtr->nextPtr);
	}
}

void PariDisp(List corrPtr, int *pari, int *dispari){
	if(corrPtr==NULL){
		return;
	}
	else{
		if((*pari)==-1 && corrPtr->numMatr%2==0){
			*pari = corrPtr->numMatr;
		}
		if((*dispari)==-1 && corrPtr->numMatr%2==1){
			*dispari = corrPtr->numMatr;
		}
		if((*dispari)==-1 || (*pari)==-1){
			return PariDisp(corrPtr->nextPtr, pari, dispari);
		}
		else{
			return;
		}
	}
}