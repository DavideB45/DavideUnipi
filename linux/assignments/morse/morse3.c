#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ALFABETO 36

//riempie i due alfabeti e restituisce il puntatore alla fine degli alfabeti
void riempiCodice(FILE *fPtr, char *morse[]);
//restrtuisce un puntatore ad una stringa letta fino a '\n'
char *readString(FILE *fPtr);
//controlla che non vi siano caratteri non appartenenti all'alfabeto nella riga
int controllo(char toceck);
//traduce una riga di testo
void traduzione(char *morse[], FILE *fPtr);

int main(void){
	char *morse[ALFABETO];
	FILE *fPtr;//apertura file
	if((fPtr = fopen("input.txt", "r"))==NULL){
		printf("File not found\n");
		exit(1);
	}

	//lettura alfabeto da file
	riempiCodice(fPtr, morse);
	while(fgetc(fPtr)!='\n');
	
	char x ;
	int traducibile;
	long back;
	while(!feof(fPtr)){
		traducibile = 0;
		back = ftell(fPtr);//salvo l'inizio della riga
		//controlla che la riga possa essere tradotta
		do{
			fscanf(fPtr,"%c", &x);
			traducibile = controllo(x);
		}while(traducibile!=-1);
		//ece dal wile quando trova uno '\r' o un errore nell'input
		if(x=='\r'){//e' traducibile
			fseek(fPtr, back, SEEK_SET);//torno a inizio riga
			traduzione(morse, fPtr);
		}
		else{//non e' traducibile
			fscanf(fPtr, "%*[^\n]\n");//salta la riga
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
}

int controllo(char toceck){
	if(toceck==' ' || isalnum(toceck)){
		return 1;
	}
	return -1;
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