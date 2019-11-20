#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct equazione{
	_Bool indice;//1=numero 0=operatore;
	int var;
	struct equazione *prossimoPtr;
}Eq;
typedef Eq *EqPtr;

_Bool geteq(EqPtr *headPtr, EqPtr *codaPtr);
char* getstring(int *lenght, char *string, int *len);

int main(void){
	EqPtr headPtr = NULL;
	EqPtr codaPtr = NULL;
	int res;
	if(geteq(&headPtr, &codaPtr)){
		printf("Ciao\n");
		return 0;
	}
	//--------------PRINT-LIST--------------------//
	//--------------------------------------------//
	EqPtr tofreePtr = headPtr;
	while(headPtr!=NULL){
		if(headPtr->indice){
			printf("%d-->", headPtr->var);
		}
		else{
			printf("%d-->", headPtr->var);
		}
		free(tofreePtr);
		headPtr = headPtr->prossimoPtr;
		tofreePtr = headPtr;
	}
	//--------------------------------------------//
	//--------------------------------------------//
	return 0;
}

_Bool geteq(EqPtr *headPtr, EqPtr *codaPtr){
	int length = 0;
	char* value = getstring(0, value, &length);
	if(strcmp(value, "fine")==0){
		return 1;
	}
	else{
		if(isdigit(value[length])){
			headPtr->var = 
		}
	}
}