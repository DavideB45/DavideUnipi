#include <stdio.h>
#include <stdlib.h>

typedef struct num{
	int val;
	struct num *nextPtr;
}Num;
typedef Num* List;
typedef enum{false, true} boolean;

void insert(int num, List *headPtr);
boolean ceck(List corrPtr);

int main(void){
	List headPtr = NULL;
	int num;
	scanf("%d", &num);
	while (num>0){
		insert(num, &headPtr);
		scanf("%d", &num);
	}
	if(headPtr==NULL || ceck(headPtr)){
		printf("True\n");
	}
	else{
		printf("False\n");
	}
	return 0;
}

void insert(int num, List *headPtr){
	List newPtr = malloc(sizeof(Num));
	if (newPtr==NULL){
		printf("memoria esaurita\n");
		exit(EXIT_FAILURE);
	}
	newPtr->nextPtr = *headPtr;
	newPtr->val = num;
	*headPtr = newPtr;
	return;
}

boolean ceck(List corrPtr){
	if (corrPtr->nextPtr==NULL){
		return true;
	}
	else{
		if (corrPtr->val > corrPtr->nextPtr->val){
			return ceck(corrPtr->nextPtr);
		}
		else{
			return false;
		}
	}
}