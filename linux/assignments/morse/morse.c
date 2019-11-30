#include <stdio.h>
#include <string.h>


void riempiCodice(char morse[][10], char alfabeto[]);

int ricerca(char c, char alfabeto[]);

void inserimentoFrase(char frase[]);

_Bool controlloInserimento(char alfabeto[], char frase[]);

void traduzione(char alfabeto[], char frase[],char morse[][10], int x);

int main(void){
	char frase[200] = {'\0'};//salva puntatore a inizio riga, contare i caratteri poi salvarli
	char alfabeto[36];
	char morse[36][10];
	riempiCodice(morse, alfabeto);
	
	while(scanf("%c", &frase[0])==1){
	inserimentoFrase(frase);
	
	if(controlloInserimento(alfabeto, frase)){
		traduzione(alfabeto, frase, morse, 0);
		printf("\n");
	}
	else{
		printf("Errore nell'input\n");
	}
	}
	return 0;
}

void riempiCodice(char morse[][10], char alfabeto[]){
	char c;
	int y;
	scanf("%c", &c);
	int x = 0;
	do{
		//riempimento del vettore con caratteri alfanumerici
		alfabeto[x] = c;
		c = getchar();
		c = getchar();
		y = 0;
		//riempimento matrice contenente il simbolo del carattere in mose
		do{
			morse[x][y] = c;
			y++;
			c = getchar();
			if(c == '\n'){
				//indica la fine della stringa corrispodente ad un carattere
				morse[x][y] = '\0';
			}
		}while(c!='\n');
		x++;
		c = getchar();
	}while(c!='*');
	scanf("%*[^\n]");
	scanf("%*c");
	return;
}

void inserimentoFrase(char frase[]){
	int i = 1;
	while((frase[i] = getchar())!='\n'){
		i++;
	}
	return;
}

int ricerca(char c, char alfabeto[]){
	for(int i = 0; i<36; i++){
		if(c<='Z' && c>='A'){
			c = c + 32;
		}
		if(c==alfabeto[i]){
			return i;
		}
	}
	switch (c){
	case '\n':
		//printf("\n");
	return -3;
	case ' ':
		//printf("    ");
	return -2;
	default :
	return -1;
	}
}

_Bool controlloInserimento(char alfabeto[], char frase[]){
	int i = 0;
	while(frase[i]!='\n'){
		if(ricerca(frase[i], alfabeto)==-1){
			return 0;
		}
		i++;
	}
	return 1;
}

void traduzione(char alfabeto[], char frase[],char morse[][10], int x){
	int lettera;
		lettera = ricerca(frase[x], alfabeto);
			if(lettera>=0){
					printf("%s   ", morse[lettera]);
			}
			else{
				switch (lettera){
				case -3:
				return;
				case -2:
					printf("    ");
				break;
				}
			}
		traduzione(alfabeto, frase, morse, x+1);
		return;
}