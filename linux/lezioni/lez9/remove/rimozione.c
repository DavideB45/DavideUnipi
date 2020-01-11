#include <stdio.h>
#include <stdlib.h>

typedef struct val{
	int num;
	struct val *nextPtr;
}Int;
typedef Int *List;

void addhead(List *headPtr, List *tiePtr, int num);
void addtie(List *headPtr, List *tiePtr, int num);
void cut(List *headPtr, List *tiePtr, int num);
void printlist(List headPtr);

int main(void){
	int num;
	Int *headPtr = NULL;
	Int *tiePtr = NULL;
	scanf("%d", &num);
	while(num!=0){
		if(num>0){
			if(num%2==0){
				addhead(&headPtr, &tiePtr, num);
			}
			else{
				addtie(&headPtr, &tiePtr, num);
			}
		}
		else{
			cut(&headPtr, &tiePtr, -num);
		}
		scanf("%d", &num);
	}
	printlist(headPtr);
	return 0;
}

void addhead(List *headPtr, List *tiePtr, int num){
	List newPtr;
	newPtr = malloc(sizeof(Int));
	if(newPtr == NULL){
		printf("memoria esaurita\n");
		exit(1);
	}
	newPtr->num = num;
	newPtr->nextPtr = *headPtr;
	if(*headPtr == NULL){
		*tiePtr  = newPtr;
		*headPtr = newPtr;
		return;
	}
	*headPtr = newPtr;
}

void addtie(List *headPtr, List *tiePtr, int num){
	List newPtr;
	newPtr = malloc(sizeof(Int));
	if(newPtr == NULL){
		printf("memoria esaurita\n");
		exit(1);
	}
	newPtr->num = num;
	newPtr->nextPtr = NULL;
	if(*tiePtr == NULL){
		*tiePtr  = newPtr;
		*headPtr = newPtr;
		return;
	}
	(*tiePtr)->nextPtr = newPtr;
	*tiePtr = newPtr;
}

void cut(List *headPtr, List *tiePtr, int num){
	List precPtr = NULL;
	List corrPtr = *headPtr;
	while((corrPtr != NULL)&&(corrPtr->num != num)){
		precPtr = corrPtr;
		corrPtr = corrPtr->nextPtr;
	}
	if(corrPtr==NULL){
		return;
	}
	else{
		if(precPtr==NULL){
			*headPtr = corrPtr->nextPtr;
			if(*headPtr == NULL){
				*tiePtr = NULL;
			}
			free(corrPtr);
			return;
		}
		precPtr->nextPtr = corrPtr->nextPtr;
		if(precPtr->nextPtr == NULL){
			*tiePtr = *headPtr;
		}
		free(corrPtr);
	}
}

void printlist(List headPtr){
	List tofreePtr;
	while(headPtr!=NULL){
		printf("%d\n", headPtr->num);
		tofreePtr = headPtr;
		headPtr = headPtr->nextPtr;
		free(tofreePtr);
	}
	return;
}