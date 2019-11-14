#include <stdio.h>
#include <ctype.h>
#include <string.h>
 
int scegli(void);

char* inserimento(char *frase);

char* caps(char *frase);

char* traduci(char *frase);

int isvocale(char c);

void firstcons(char *tokenPtr, int minuscolo);

int main(void){
	char frase[100];
	char *Ptr;
	char* (*menu[3])(char*) = {inserimento, caps, traduci};
	int opzione;
	do{
		/*printf("1. inserimento\n");
		printf("2. vedi la frase\n");
		printf("3. traduci\n");
		printf("4. esci\n");*/
		opzione = scegli();	
		if(opzione != 4){
			(*menu[opzione-1])(frase);
		}
	}while(opzione!=4);
	printf("Ciao!\n");
	return 0;
}

int scegli(void){
	int opz;
	printf("Scegliere l'operazione:\n");
	while(scanf("%d", &opz)!=1||opz<1||opz>4){
		printf("inserire un numero da 1 a 4\n");
		scanf("%*[^\n]");
		scanf("%*c");
	}
	scanf("%*[^\n]");
	scanf("%*c");
	return opz;
}

char* inserimento(char *frase){
	printf("Inserire stringa:\n");
	fgets(frase, 100, stdin);
	return frase;
}

char* caps(char *frase){
	int i = 0;
	do{
		if(isalpha(frase[i])){
			printf("%c", toupper(frase[i]));
		}
		else{
			printf(" ");
		}
		i++;
	}while(frase[i]!='\n');
	printf("\n");
	return frase;
}

char* traduci(char *frase){
	int i = 0;
	char *tokenPtr = NULL;
	tokenPtr = strtok(frase, " ");
	while(tokenPtr!=NULL){
		if(isvocale(*tokenPtr)){
			i = 0;
			do{
				printf("%c", tokenPtr[i]);
				i++;
			}while(tokenPtr[i]!='\n' && tokenPtr[i]!='\0');
			printf("way ");
		}
		else{
			enum{UPPER, LOWER};
			if(isupper(*tokenPtr)){
				firstcons(tokenPtr, UPPER);
				printf("ay ");
			}
			else{
				firstcons(tokenPtr, LOWER);
				printf("ay ");
			}
		}
		tokenPtr = strtok(NULL, " ");
	}
	printf("\n");
	return frase;
}

int isvocale(char c){
	c = tolower(c);
	switch (c){
		case 'a':
			return 1;
		case 'e':
			return 1;
		case 'i':
			return 1;
		case 'o':
			return 1;
		case 'u':
			return 1;
		default:
			return 0;
	}
}

void firstcons(char *tokenPtr, int minuscolo){
	char lettera;
	int i = 0;
	int k = 0;
	do{
		lettera = tokenPtr[i];
		if(isvocale(lettera) || (lettera=='y' && i>0)){
			k = i;
			if(minuscolo){
				//printf("%s", &tokenPtr[i]);
				do{
					printf("%c", tolower(tokenPtr[k++]));
					//k++;
				}while(isalpha(tokenPtr[k]));
			}
			else{
				printf("%c", toupper(lettera));
				k++;
				do{
					printf("%c", tolower(tokenPtr[k]));
					k++;
				}while(isalpha(tokenPtr[k]));
			}
		}
		i++;
	}while(!isvocale(lettera) && k<i);
	i--;
	for(int j = 0; j<i; j++){
		printf("%c", tolower(tokenPtr[j]));
	}
	return;
}





















