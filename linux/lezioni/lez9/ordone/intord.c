#include <stdio.h>
#include <stdlib.h>

typedef struct num{
	int val;
	struct num *nextPtr;
}Num;
typedef Num* List;

void insertsort(List *headPtr, int num);
void printlist(List corrPtr);
List insalatamista(List A, List B);

int main(void){
	List A = NULL;
	List B = NULL;
	int num;
	//inserimento in A
	scanf("%d", &num);
	while(num>0){
		insertsort(&A, num);
		scanf("%d", &num);
	}	
	//inserimento in B
	scanf("%d", &num);
	while(num>0){
		insertsort(&B, num);
		scanf("%d", &num);
	}
	List C = insalatamista(A, B);
	printlist(C); 
}

void insertsort(List *headPtr, int num){
	List newPtr = malloc(sizeof(Num));
	if(newPtr==NULL){
		printf("menoria esaurita\n");
		exit(1);
	}
	newPtr->val = num;
	//creahead
	if(*headPtr == NULL){
		newPtr->nextPtr = NULL;
		*headPtr = newPtr;
		return;
	}
	//insert in head
	if((*headPtr)->val > num){
		newPtr->nextPtr = *headPtr;
		(*headPtr) = newPtr;
		return;
	}
	//cerco il punto in cui inserire il novo valore
	List corrPtr = *headPtr;
	List precPtr = NULL;
	while((corrPtr != NULL) && (corrPtr->val < num)){
		precPtr = corrPtr;
		corrPtr = corrPtr->nextPtr;
	}
	if((corrPtr != NULL) && (num==corrPtr->val)){
		free(newPtr);
		return;
	}
	newPtr->nextPtr = precPtr->nextPtr;
	precPtr->nextPtr = newPtr;
	return;
}

List insalatamista(List A, List B){
	List C = NULL;
	List Ctie = NULL;
	List tempPtr;
	while(A!=NULL && B!=NULL){
		if(A->val == B->val){
			if((tempPtr = malloc(sizeof(Num)))==NULL){
				printf("menoria esaurita\n");
				exit(1);
			}
			tempPtr->val = A->val;
			if(C==NULL){
				Ctie = tempPtr;
				C = tempPtr;
			}
			else{
				Ctie->nextPtr = tempPtr;
				Ctie = tempPtr;
			}
		}
		if(A->val<B->val){
			A = A->nextPtr;
		}
		else{
			B = B->nextPtr;
		}
	}
	return C;
}

void printlist(List corrPtr){
	while(corrPtr!=NULL){
		printf("%d\n", corrPtr->val);
		corrPtr = corrPtr->nextPtr;
	}
	return;
}