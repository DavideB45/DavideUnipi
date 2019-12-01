#include <stdio.h>
#include <stdlib.h>

//riempie i due alfabeti e restituisce il puntatore alla fine degli alfabeti
FILE* riempiCodice(FILE *fPtr, char *morse[], char alfabeto[]);
int ncaratteri(FILE *fPtr);//conta i caratteri fino a '\n'
//ricerca il carattere da tradurre se non lo trova ritorna -1
int ricerca(char c, char alfabeto[]);
//controlla che non vi siano caratteri non appartenenti all'alfabeto nella riga
_Bool charcontrol(FILE *fPtr, char *morse[], char alfabeto[]);
//traduce una riga di testo
void traduzione(FILE **fPtr, char alfabeto[], char morse[][10]);

int main(void){
	char alfabeto[36];//alfabeto inglese
	char *morse[36];//alfabeto morse
	
	FILE *fPtr;//apertura file
	if((fPtr = fopen("try.txt", "r"))==NULL){
		printf("File not found\n");
		exit(1);
	}
	
	fPtr = riempiCodice(fPtr, morse, alfabeto);
	
	//charcontrol(fPtr, morse, alfabeto);
	
	//traduzione(&fPtr, alfabeto, morse);
	printf("\n");
	
	return 0;
}

int ncaratteri(FILE *fPtr){
	int n = 1;
	char c = '0';
	while(c!='\n'){
		n++;
		c = fgetc(fPtr);
	}
}

FILE* riempiCodice(FILE *fPtr, char *morse[], char alfabeto[]){
	char c;
	int i = 0;//indice per l'inserimento dei valori
	int numC;//numero di caratteri della lettera tadotta
	FILE *precPtr;
	while(fscanf(fPtr, "%c:", &c), c!=1){
		alfabeto[i] = c;
		numC = ncaratteri(fPtr);
		morse[i] = calloc(numC + 2, sizeof(char));//assegnamento spazio per la traduzione
		fscanf(fPtr, "%[^\n]%*c", morse[i]);//copia morse
		printf("%c = ", alfabeto[i]);
	}
}