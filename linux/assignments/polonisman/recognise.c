#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//lista di valori su cui operare
struct numeri{
	_Bool indice//1=numero 0=operatore
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


OperPtr inserimento(NumPtr numPtr, OperPtr opPtr);
_Bool risultato(NumPtr firstnumPtr, OperPtr firstopPtr, int *res);
_Bool overflaw();
void compldue(int res);


int main(void){
	Num *firstnumPtr = NULL;
	Oper *firstopPtr = NULL;
	int res;
	firstnumPtr = inserimento(firstnumPtr, firstopPtr);
	//--------------PRINT-LIST--------------------//
	//--------------------------------------------//
	while(firstnumptr->prossimoPtr!=NULL){
		if(firstnumPtr->indice){
			printf("%d-->", firstnumPtr->num);
		}
		else{
			printf("%d-->", firstnumPtr->num);
		}
	}
	printf("%d-->", firstnumPtr->num);
	//--------------------------------------------//
	//--------------------------------------------//
	return 0;
}

////////////////////CASI///////////////////////////
/*	
	
	c = -      1' '
	c = -      129' '
	c = -      ' '
	c = 1      ' '
	c = 1      234

*/
//////////////////////////////////////////////////
OperPtr inserimento(NumPtr numPtr, OperPtr opPtr){
	int c;
	scanf("%d", &c);
	if(c<=9 && c>=0){
		numPtr->num = num*10 + c;
	return 0;
}















