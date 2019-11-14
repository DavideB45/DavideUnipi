#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//lista di valori su cui operare
struct numeri{
	int num;
	struct numeri *prossimoPtr;
};
typedef struct numeri Num;
typedef Num *NumPtr;
//lista di operandi da applicare
struct operandi{
	char oper;
	struct operandi *prossimoPtr;
};
typedef struct operandi Oper;
typedef Oper *OperPtr;


_Bool inserimento(NumPtr numPtr, OperPtr opPtr);
_Bool risultato(NumPtr firstnumPtr, OperPtr firstopPtr, int *res);
_Bool overflaw();
void compldue(int res);


int main(void){	
	Num *firstnumPtr = NULL;
	Oper *firstopPtr = NULL;
	int res;
	_Bool overflaw;
	overflaw = inserimento(firstnumPtr, firstopPtr);
	if(!overflaw){
		//overflaw = risultato(firstnumPtr, firstopPtr, &res);
		if(!overflaw){
			printf("il risultato e': %d\n", res);
		}
	}
	//dealloc;
	return 0;
}

_Bool inserimento(NumPtr numPtr, OperPtr opPtr){
	char c;
	int num;
	int num_prec;
	Num *prec_num_Ptr;
	Oper *prec_op_Ptr;
	scanf("%c", &c);
	do{
		if(isdigit(c)){
			prec_num_Ptr = numPtr;
			numPtr = malloc(sizeof(struct numeri));
			if(numPtr != NULL){
				num = 0;
				while(isdigit(c)){
					num_prec = num;
					num = num*10 + (c-'0');
					if(num<num_prec){
						printf("Overflaw!\n");
						return 1;
					}
					c = getchar();
				}
				numPtr->num = num;
				numPtr->prossimoPtr = NULL;
				if(prec_num_Ptr!=NULL){
					prec_num_Ptr->prossimoPtr = numPtr;
				}
			}
			else{
				printf("Memoria esaurita\n");
				return 1;
			}	
		}
		else{
			prec_op_Ptr = opPtr;
			opPtr = malloc(sizeof(struct operandi));
			if(opPtr != NULL){
				opPtr->oper = c;
				opPtr->prossimoPtr = NULL;
				if(prec_op_Ptr!=NULL){
					prec_op_Ptr->prossimoPtr = opPtr;
				}
			}
			else{
				printf("Memoria esaurita\n");
				return 1;
			}
		c = getchar();
		}
	}while(c!='\n');
	return 0;
}
