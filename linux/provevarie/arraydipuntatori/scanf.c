#include <stdio.h>
#include <limits.h>
#include <string.h>

char *generaParole(void){
	auto char array[15];
	char *puntatore;
	scanf("%c", &array[0]);
	int i = 1;
	while((array[i] = getchar()) != '\n'){i++;}
	array[i] = '\0';
	puntatore = array;
	return puntatore;
}

int main(){
	char *parole[3] = {NULL};
	
	parole[0] = generaParole();
	parole[1] = generaParole();
	parole[2] = generaParole();
	
	printf("Parola 0 = %s\n", parole[0]);
	printf("indirizzo parola[0] = %p\n\n", &parole[0]);
	
	
	printf("Parola 1 = %s\n", parole[1]);
	printf("indirizzo parola[1] = %p\n\n", &parole[1]);
	

	printf("Parola 2 = %s\n", parole[2]);
	printf("indirizzo parola[2] = %p\n\n", &parole[2]);
	
	
	parole[2] = parole[2] + 6;
	printf("valore parola[2] + 6 = %s\n", parole[2]);
	printf("indirizzo parola[2] + 6 = %p\n\n", &parole[2]);
	
	return 150;
}
