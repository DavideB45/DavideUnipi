#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ALFABETO 36

//riempie i due alfabeti e restituisce il puntatore alla fine degli alfabeti
FILE* riempiCodice(FILE *fPtr, char *morse[], char alfabeto[]);
//restrtuisce un puntatore ad una stringa letta fino a '\n'
char *readString(FILE *fPtr);
//controlla che non vi siano caratteri non appartenenti all'alfabeto nella riga
int ricerca(char alfabeto[], char tofind);
//traduce una riga di testo
void traduzione(char alfabeto[],  char *morse[], FILE *fPtr);

int main(void){
	char alfabeto[ALFABETO];//alfabeto inglese
	char *morse[ALFABETO];//alfabeto morse
	
	FILE *fPtr;//apertura file
	if((fPtr = fopen("input.txt", "r"))==NULL){
		printf("File not found\n");
		exit(1);
	}
	//lettura alfabeti da file
	riempiCodice(fPtr, morse, alfabeto);
	while(fgetc(fPtr)!='\n');
	printf("\n\n");
	
	char x ;
	int traducibile;
	/*do{
		while(fscanf(fPtr,"%c", &x), x==' ');
		traducibile = ricerca(alfabeto, x);
	}while(x!='\r' && traducibile!=-1);*/
	
	traduzione(alfabeto, morse, fPtr);
	printf("\n");
	
	return 0;
}

char *readString(FILE *fPtr){
	char tempsting[20];//stringa temporanea
	fscanf(fPtr, "%[^\r]\r\n", tempsting);//lettura da file fino a '\n' o '\r'
	int toalloc = strlen(tempsting)+1;
	//copia di tempstring in una memoria allocata e restituita dalla funzione
	return memcpy(calloc(toalloc, sizeof(char)), tempsting, toalloc);
}

FILE* riempiCodice(FILE *fPtr, char *morse[], char alfabeto[]){
	char c;
	int i = 0;//indice per l'inserimento dei valori
	while(fscanf(fPtr, "%c:", &c), c!='*'){
		alfabeto[i] = c;
		morse[i] = readString(fPtr);
		printf("%c = %s\n", alfabeto[i], morse[i]);
		i++;
	}
}

int ricerca(char alfabeto[], char tofind){
	for(int i = 0; i<=ALFABETO; i++){
		if(tofind==alfabeto[i]){
			//printf("%c ",tofind);
			return i;
		}
	}
	printf("\tnon c'e' %d", tofind);
	return -1;
}


void traduzione(char alfabeto[],  char *morse[], FILE *fPtr){
	char lettera;
	int indice;
	fscanf(fPtr, "%c", &lettera);
	do{
		indice = ricerca(alfabeto, lettera);
		if(indice!=-1){
			printf("%d %c %s   ", indice, lettera, morse[indice]);
		}
		else{
			printf("     ");
		}
		fscanf(fPtr, "%c", &lettera);
	}while(lettera!='\n' && lettera!='\r');
}