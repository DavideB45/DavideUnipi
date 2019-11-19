#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//crea una lista da un'espressione inserita da tastiera
//restituisce 0 se si inserisce la stringa di termine 
char* getstring(int lenght, char *string);

int main(void){
	/*char string[2];
	string[2] = '\0';
	string[1] = 'o';
	string[0] = 'i';*/
	char *string;
	string = getstring(0, string);
	printf("%s\n", string);
	return 0;
}

//lenght e' neccessario per calloc
//*string serve per mettere il risultato :|
char* getstring(int lenght, char *string){
	char c;
	c = getchar();//lo assegna al ritorno 
	if(c=='\n'){//termine riga con '\n' termine parola con ' ' possono essere usati insieme
		string = calloc(lenght + 1, sizeof(char));//alloca lo spazio GIUSTO per la stinga
		string[lenght] = '\0';//indica la fine della stringa (togliere per l'assignment)
		printf("%d\n", lenght);
		return string;//ritorna la lunghezza (indice max dell' array + 1)
	}
	string = getstring(++lenght, string);//incrementa string e poi basta
	string[lenght] = c;//quando torna nella funzione lenght ha il suo valore precedente 
					   //quindi lenght indica correttamente il valore dell'indice per c
	printf("%s str\n", string); 
	return string;//ritorna lenght per poter saprere la lunghezza dell'array (indmax + i)
}