#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum{OPERATORE, NUMERO} indicatore;
typedef struct elem{
	indicatore ind;
	int value;
	struct elem *next;
}Elem;
typedef Elem * Espression;

//crea una lista da un'espressione inserita da tastiera
//restituisce 0 se si inserisce la stringa di termine 
_Bool getinput(Espression *startPtr, Espression *endPtr);
int getstring(int lenght, char **string);

int main(void){
	Espression startPtr = NULL;
	Espression endPtr = NULL;
	while (getinput(&startPtr, &endPtr)){
		//resto del programma
	}
	//printf("Ciao\n");
	return 0;
}

_Bool getinput(Espression *startPtr, Espression *endPtr){
	char *string;
	getstring(0, &string);
	printf("%s\n", string);
	return 0;
}
//lenght e' neccessario per calloc
//*string serve per mettere il risultato :|
int getstring(int lenght,char **string){
	char c;
	c = getchar();//lo assegna al ritorno 
	if(c=='\n'){//termine riga con '\n' termine parola con ' ' possono essere usati insieme
		*string = calloc(lenght + 1, sizeof(char));//alloca lo spazio GIUSTO per la stinga
		*(*string + lenght) = '\0';
		return lenght;//ritorna la lunghezza (indice max dell' array + 1)
	}
	printf("%c\n", c);
	getstring(++lenght, string);//incrementa string e poi basta
	printf("%c\n", c);
	*(*string+lenght) = c;//quando torna nella funzione lenght ha il suo valore precedente 
					   //quindi lenght indica correttamente il valore dell'indice per c 
	return lenght;//ritorna lenght per poter saprere la lunghezza dell'array (indmax + i)
}