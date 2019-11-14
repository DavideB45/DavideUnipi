#include <stdio.h>

//riempie la matrice e il vettore rispettivamente con alfabeto morse e alfabeto
void riempi_codice(char morse[][10], char alfabeto[]){
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
//cerca il numero dell'array nel quale si trova il carattere
int ricerca(char c, char alfabeto[]){
	if(c<='Z' && c>='A'){
		c = c + 32;
	}
	for(int i = 0; i<36; i++){
		if(c==alfabeto[i]){
			return i;
		}
	}
	switch (c){
	case '\n':
		printf("\n");
	return -2;
	case ' ':
		printf("    ");
	return -2;
	default :
	return -1;
	}
}


_Bool traduci(char c, char morse[][10], char alfabeto[]){
	int lettera;
	if(c=='\n'){
		return 0;
	}
	else{
		lettera = ricerca(c, alfabeto);
		//come impedire di stampare tutta la riga?
		if(lettera==-1){
			return 1;
		} 
		else{
			if(lettera>=0){
					printf("%s   ", morse[lettera]);
					c=getchar();
					
			}
			else{
				if(c!='\n'){
					c = getchar();
				}
			}
		}
		return traduci(c, morse, alfabeto);
	}
}


int main(void){
	char testo[200] = {'\0'};//riempire passare al controllo poi tradurre se e' corretto
	char alfabeto[36];
	char morse[36][10];
	riempi_codice(morse, alfabeto);
	/*for(int i = 0; i<36; i++){
		printf("%c:%s\n", alfabeto[i], morse[i]);
	}*/
	char c;
	//provare a stampare l'errore controllando dall'inserimento
	while(scanf("%c", &c)==1){
		if(traduci(c, morse, alfabeto)==1){
			printf("Errore nell'input\n");
			scanf("%*[^\n]");
			scanf("%*c");
		}
		else{
			printf("\n");
		}
	}
	
return 0;
}












