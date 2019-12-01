#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

const int BITS = sizeof(int)*CHAR_BIT;

typedef enum{OPER, NUMBER} Ind;
struct equazione{
	Ind indice;//0=operatore 1=numero;
	int var;
	struct equazione *prossimoPtr;
};
typedef struct equazione Eq;
typedef Eq *EqPtr;

int lastchar(char *array);//conta i caratteri nell'array fino a \0
_Bool inserimento(EqPtr *headPtr, EqPtr *codaPtr, char string[]);//genera una lista contenente l'equazione da risolvere
_Bool strtoint(int *num, char *string, int dim);//trasforma una stringa in intero (ritorna 1 se c' e' overflaw)
_Bool risultato(EqPtr eqPtr, int *res);//risolve l'espressione (restituisce 0 se c'e' overflaw)
_Bool operazione(int a, int b, int c, int *res);//svolge un operazione elementare (+-x)
void dealloc(EqPtr *headPtr);//libera la memoria occupata dalla lista
void compldue(int res);//esegue il complemento a due


int main(void){
	Eq *headPtr = NULL;//puntatore all'inizio della lista
	Eq *codaPtr = NULL;//puntatore alla fine dell'equazione
	int res;//risultato
	_Bool overflaw;
	char string[12] = {0};
	scanf("%[^ ^\n^\r]", string);//legge fino a uno spazio, uno \n o uno \r
	//printf("%s", string);/////////////////////
	//res = lastchar(string);///////////////////
	//printf(" %d\n", res);/////////////////////
	while(strcmp(string, "fine")!=0){
		overflaw = inserimento(&headPtr, &codaPtr, string);
		if(!overflaw){
		overflaw = 	(headPtr, &res);
			if(!overflaw){
				headPtr = NULL;
				printf("%d in C2: ", res);//visualizza il rsultato
				compldue(res);//esegue il complemento a 2
			}
			else{
				dealloc(&headPtr);
			}
		}
		else{
			printf("Overflaw!\n");//overflaw in inserimento
			while(getchar()!='\n');//pulizia buffer input
			dealloc(&headPtr);//pulizia memoria
		}
		scanf("%[^ ^\n^\r]", string);
	}
	return 0;
}

int lastchar(char *array){
	int dim = 0;
	while(dim < 12 && array[dim]!='\0')
		dim++;
	return --dim;
}

_Bool strtoint(int *num, char *string, int dim){
	if(dim>=9 && string[0]!='-' && (strcmp(string, "2147483647")>0 || dim>9)){
		return 1;// overflaw positivo
	}
	else{
		if(dim>=10 && string[0]=='-' && (strcmp((string), "-2147483648")>0 || dim>10)){
			return 1; // overflaw negativo
		}
	}
	*num = 0;
	if(string[0]=='-'){
		//calcolo numero negativo
		for(int i = 1; i <= dim; i++){
			*num = (*num)*10 - (string[i]-'0');
		}
	}
	else{
		//calcolo numero positivo
		for(int i = 0; i <= dim; i++){
			*num = (*num)*10 + (string[i]-'0');
		}
	}
	return 0;
}

_Bool inserimento(EqPtr *headPtr, EqPtr *codaPtr, char string[]){
	int lc;//ultimo carattere della stringa
	_Bool end = 0;//indicatore per la fine della riga
	int value;
	char c;
	do{
		if(c = getchar(), c=='\n' || c=='\r'){
			if(c=='\r'){
				c = getchar(); 
			}
			end = 1;//controllo per terminare l' inserimento
		}
		EqPtr newEl = calloc(1, sizeof(Eq));
		if(newEl == NULL){
			printf("memoria esaurita\n");
			exit(1);
		}
		lc = lastchar(string);
		if(isdigit(string[lc])){
			//creazione numero
			if(strtoint(&value, string, lc)==1){
				return 1;//overflaw
			}
			else{
				//asegnamento valori
				newEl->indice = NUMBER;
				newEl->prossimoPtr = NULL;
				newEl->var = value;
			}
		}
		else{//contollo che sia un operatore valido
			if(string[0] == '-' || string[0] == '+' || string[0] == '*'){
				newEl->indice = OPER;
				newEl->prossimoPtr = NULL;
				newEl->var = string[0];
			}
			else{
				printf("operatore non valido\n");
				exit(0);
			}
		}
		if(end==0){// lettura caratteri successivi
			scanf("%[^ ^\n^\r]", string);
		}
		if(*headPtr==NULL){
			*codaPtr = newEl;
			*headPtr = newEl;//aggiunta in testa
		}
		else{
			(*codaPtr)->prossimoPtr = newEl;//aggiunta in coda
			(*codaPtr) = newEl;
		}
	}while(!end);
	return 0;
}

_Bool risultato(EqPtr eqPtr, int *res){
	Eq *primoNPtr;//puntatore al primo numero
	Eq *secondoNPtr;//puntatore al secondo numero
	Eq *correntePtr;//puntatore alla struct corrente
	//ricerca operandi e operatori
	do{
		secondoNPtr = eqPtr;
		do{
			primoNPtr = secondoNPtr;
			secondoNPtr = primoNPtr->prossimoPtr;
			correntePtr = secondoNPtr->prossimoPtr;
		}while(correntePtr->indice);
		//se operazione ritorna 1 c'e' overflaw
		if(operazione(primoNPtr->var,secondoNPtr->var, correntePtr->var, res)){
			printf("Overflow!\n");
			return 1;
		}
		else{//salva il risultato nell'headPtr e libera 2 nodi della lista
			primoNPtr->var = *res;
			primoNPtr->prossimoPtr = correntePtr->prossimoPtr;
			free(secondoNPtr);
			free(correntePtr);
		}
	}while(primoNPtr->prossimoPtr!=NULL);
	//non c'e' overflaw
	free(primoNPtr);
	return 0;
} 

_Bool operazione(int a, int b, int c, int *res){
	switch (c){
		case '+':
			*res = a + b;
			if((a>0 && b>0 && *res<0) || (a<0 && b<0 && *res>0)){
				return 1;//overflaw
			}
			return 0;
		case '-':
			*res = a - b;
			if((a>=0 && b<0 && *res<0) || (a<0 && b>0 && *res>0)){
				return 1;//overflaw
			}
			return 0;
		default:
			if((a<0)==(b<0)){
				if((b>0 && 1.0*a>INT_MAX/(1.0*b))||(b<0 && 1.0*a<INT_MAX/(1.0*b))){
					return 1;//overflaw
				}
			}
			else{	
				if((b>0 && 1.0*a<INT_MIN/(1.0*b))||(b<0 && 1.0*a>INT_MIN/(1.0*b))){
					return 1;//overflaw
					}
			}
			*res = a*b;
			return 0;
		}
}

void dealloc(EqPtr *headPtr){
	Eq *nextPtr;
	while(*headPtr != NULL){
		nextPtr = (*headPtr)->prossimoPtr;
		free(*headPtr);
		*headPtr = nextPtr;
	}
	return;
}

void compldue(int res){
	int maschera = 1 << (BITS -1);
	for(size_t i = 1; i<=BITS; i++){
		putchar(maschera&res ? '1' : '0');
		res<<=1;
		if(i%4==0){//scrive uno spazio ogni 4 numeri
			putchar(' ');
		}
	}
	putchar('\n');
}