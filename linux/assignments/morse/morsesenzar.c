#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ALFABETO 36

//riempie la matrice con l'alfabeto morse
void riempiCodice(FILE *fPtr, char *morse[]);
//restrtuisce un puntatore ad una stringa letta fino a '\r'
char *readString(FILE *fPtr);
//controlla la riga (1=traducibile   0=non traducibile)
_Bool controllo(FILE *fPtr);
//traduce una riga di testo
void traduzione(char *morse[], FILE *fPtr);

int main(void){
	char *morse[ALFABETO];
	FILE *fPtr;//apertura file
	if((fPtr = fopen("input.txt", "r"))==NULL){
		printf("File not found\n");
		exit(EXIT_FAILURE);
	}

	//lettura alfabeto da file
	riempiCodice(fPtr, morse);
	
	_Bool traducibile;
	long back;
	while(!feof(fPtr)){
		traducibile = 0;
		back = ftell(fPtr);//salvo l'inizio della riga
		traducibile = controllo(fPtr);//verifico che possa essere tradotta
			
		if(traducibile){//e' traducibile
			fseek(fPtr, back, SEEK_SET);//torno a inizio riga
			traduzione(morse, fPtr);
		}
		else{//non e' traducibile
			fscanf(fPtr, "%*[^\n]\n");//salta la riga corrente
			printf("Errore nell'input\n");
		}
	}
	fclose(fPtr);
	return 0;
}

char *readString(FILE *fPtr){
	char tempsting[20];
	fscanf(fPtr, "%[^\r]\r\n", tempsting);
	int toalloc = strlen(tempsting)+1;//dimensione della stringa
	//copia di tempstring in una memoria allocata e restituita dalla funzione
	return memcpy(calloc(toalloc, sizeof(char)), tempsting, toalloc);
}

void riempiCodice(FILE *fPtr, char *morse[]){
	char c;
	int i = 0;//indice per l'inserimento dei valori
	while(fscanf(fPtr, "%c:", &c), c!='*'){
		morse[i] = readString(fPtr);
		i++;
	}
	while(fgetc(fPtr)!='\n');//toglie gli asterischi
}

_Bool controllo(FILE *fPtr){
	char toceck = fgetc(fPtr);
	if(toceck==' ' || isalnum(toceck)){
		return controllo(fPtr); 
	}
	if(toceck=='\r'){
		return 1;//puo' essere tradotta
	}
	return 0;//non puo' essere tradotta
}

void traduzione(char *morse[], FILE *fPtr){
	char lettera;
	int indice;
	//traduce fino a che trova uno '\r'
	while(fscanf(fPtr, "%c", &lettera), lettera!='\r'){
		if(lettera!=' '){
			lettera = tolower(lettera);//calcola la posizione della lettera da tradurre
			indice = isalpha(lettera) ? (lettera-'a') : (lettera - '0' + 'z' - 'a' + 1);
			printf("%s   ",morse[indice]);
		}
		else{
			printf("    ");
		}
	}
	printf("\n");
	fgetc(fPtr);
}