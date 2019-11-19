#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

const int BITS = sizeof(int)*CHAR_BIT;

struct equazione{
	_Bool indice;//1=numero 0=operatore;
	int var;
	struct equazione *prossimoPtr;
};
typedef struct equazione Eq;
typedef Eq *EqPtr;


_Bool inserimento(EqPtr *headPtr, EqPtr *codaPtr, char c1);//modifica l'imput in una lista
_Bool risultato(EqPtr eqPtr, int *res);//risolve l'espressione (restituisce 0 se c'e' overflaw)
_Bool operazione(int a, int b, int c, int *res);//svolge un operazione elementare (+-x)
void dealloc(EqPtr *headPtr);//libera la memoria occupata dalla lista
void compldue(int res);//esegue il complemento a due


int main(void){
	Eq *headPtr = NULL;
	Eq *codaPtr = NULL;
	int res;
	_Bool overflaw;
	char c;
	scanf("%c", &c);
	while(c!='f'){
		overflaw = inserimento(&headPtr, &codaPtr, c);
		if(!overflaw){
			overflaw = risultato(headPtr, &res);
			headPtr = NULL;
			if(!overflaw){
				printf("%d in C2: ", res);
				compldue(res);
			}
			else{
				dealloc(&headPtr);
			}
		}
		else{
			while(getchar()!='\n');//pulizio buffer input
			dealloc(&headPtr);
		}
		scanf("%c", &c);
	}
	return 0;
}

_Bool inserimento(EqPtr *headPtr, EqPtr *codaPtr, char c1){
	int num;
	int num_prec;
	char c2;
	Eq *nuovoPtr;
	do{
		c2 = getchar();
		nuovoPtr = malloc(sizeof(struct equazione));
		if(nuovoPtr != NULL){
			if(isdigit(c1) || isdigit(c2)){
			//e' un numero
				nuovoPtr->indice = 1;
				if(isdigit(c1)){
				//salva numero positivo
					if(isdigit(c2)){
						num = (c1-'0')*10 + (c2-'0');
						c1 = getchar();
					}
					else{
						num = (c1-'0');
						c1 = c2;
					}
					while(isdigit(c1)){
						num_prec = num;
						num = num*10 + (c1-'0');
						if(num<num_prec){
							printf("Overflow!\n");
							return 1;
						}
						c1 = getchar();
					}
				}
				else{
				//salva numero negativo
					num = -(c2-'0');
					c1 = getchar();
					while(isdigit(c1)){
						num_prec = num;
						num = num*10 - (c1-'0');
						if(num>num_prec){
							printf("Overflaw!\n");
							return 1;
						}
						c1 = getchar();
					}
				}
			}
			else{
			//e' un operatore
				num = c1;
				nuovoPtr->indice = 0;
				if(c2!='\n'){
					c1 = getchar();
				}
			}
			//assegnamento dei valori
			nuovoPtr->var = num;
			nuovoPtr->prossimoPtr = NULL;
			if(*headPtr == NULL){
				*headPtr = nuovoPtr;
				*codaPtr = nuovoPtr;
			}
			else{
				(*codaPtr)->prossimoPtr = nuovoPtr;
				*codaPtr = nuovoPtr;
			}
		}
		else{
			printf("Memoria esaurita\n");
			return 1;
		}
		if(c1 == ' '){
			c1 = getchar();
		}
	}while(c2!='\n');
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
		else{
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
		if(i%4==0){
			putchar(' ');
		}
	}
	putchar('\n');
}
