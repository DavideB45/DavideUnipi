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
int controllo(char toceck);
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
	long back;
	while(!feof(fPtr)){
		traducibile = 0;
		back = ftell(fPtr);
		//controlla che la riga possa essere tradotta
		do{
			fscanf(fPtr,"%c", &x);
			traducibile = controllo(x);
		}while(traducibile!=-1);
		printf("\n");
		if(x=='\r'){
			fseek(fPtr, back, SEEK_SET);
			traduzione(alfabeto, morse, fPtr);
			printf("\n");
		}
		else{
			fscanf(fPtr, "%*[^\n]\n");
			printf("errore nell'input\n");
		}
		//avanza uno '\n'
	};
	fclose(fPtr);
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

int controllo(char toceck){
	if(toceck==' ' || isalnum(toceck)){
		printf("%c ", toceck);
		return 1;
	}
	return -1;
}

void traduzione(char alfabeto[],  char *morse[], FILE *fPtr){
	char lettera;
	int indice;
	
	while(fscanf(fPtr, "%c", &lettera), lettera!='\r'){
		if(lettera!=' '){
			lettera = tolower(lettera);
			indice = isalpha(lettera) ? (lettera-'a') : (lettera - '0' + 'z' - 'a' + 1);
			printf("%d %c %s   ", lettera, lettera, morse[indice]);
		}
		else{
			printf("     ");
		}
	}
	fgetc(fPtr);
}