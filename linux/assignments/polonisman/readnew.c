#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef enum{NUMBER, OPERATOR} Ind;
struct equazione{
	Ind indice;//1=numero 0=operatore;
	int var;
	struct equazione *prossimoPtr;
};
typedef struct equazione Eq;
typedef Eq *EqPtr;

_Bool CeckOverflaw(char value[12]);
int CreateEq(EqPtr *headPtr);
void AddElement(EqPtr *headPtr, EqPtr *codaPtr, int value, Ind indice);
int Recognise(char value[12]);

int main(void){
    EqPtr headPtr = NULL;
    while(CreateEq(&headPtr));
    return 0;
}

int CreateEq(EqPtr *headPtr){
    char input[12] = {0};
    scanf("%[^ ,^\n]", input);
    getchar();
    if(strcmp(input,"fine")==0){
        return 0;
    }
    int length = strlen(input);
    if(input[length-1]=='\n'){
        input[length-1]='\0';
        int length = strlen(input);
    }
    printf("%d %s\n", length, input);
    
    return 1;
}