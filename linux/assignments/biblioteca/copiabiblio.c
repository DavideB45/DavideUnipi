#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct libro{
	int isbn;
	char* titolo;
	char* autore;
	int copiteTot;
	int copiedDisp;
	struct libro* nextPtr;
}Libro;
typedef Libro* Elenco;
typedef enum{Eof, CSV} indice;//utilizzato per sapere a quale carattere il programma deve interrompere la lettura

int choise(void);//restituisce la scelta dell'utente
char *readString(indice x);//restituisce un pintatore alla stringa letta da stdin
_Bool inserimento(Elenco *headPtr);//inserice un libro
//opzioni per l'utente
void stampaCatalogo(Elenco correntePtr);//stampa il catalogo
void ricerca(Elenco correntePtr);//chiede autore e titolo e li manda alla funzione cerca
void cerca(Elenco correntePtr, char *autore, char *titolo);//mostra n copie disponibili
void prestito(Elenco correntePtr);//per prendere in prestito un libro
void restituzione(Elenco correntePtr);//per restituire un libro


int main(void){
	int scelta;
	Elenco headPtr = NULL;
	void (*menu[4])(Elenco) = {stampaCatalogo,ricerca,prestito,restituzione};
	//inserisce libri fino a che viene inserito un isbn = 0
	while(inserimento(&headPtr));
	while(scelta=choise(),scelta!=4){
		(*menu[scelta])(headPtr);
	}
	printf("Bye\n");
}

int choise(void){
	int scelta;
	printf("Scegli un opzione:\n\
1) Stampa catalogo.\n\
2) Cerca.\n\
3) Prestito.\n\
4) Restituzione.\n\
5) Esci.\n\
Scelta:  ");
	while(scanf("%d", &scelta)!=1 || scelta<1 || scelta>5){
		scanf("%*[^\n]");
		scanf("%*c");
		printf("Errore. Scelta non valida.\n");
	}
	while(getchar()!='\n');
	return scelta-1;
}

char *readString(indice x){
	char tempsting[100];
	int i = 0, dim = 1;
	if(x == CSV){
		scanf("%[^,],", tempsting);
	}
	else{
		scanf("%[^\n]", tempsting);
		while(getchar()!='\n');
	}
	while(tempsting[i]!='\0'){//misura la stringa
		dim++;
		i++;
	}
	return strcpy(calloc(dim, sizeof(char)), tempsting);//alloca lo spazio e copia la stringa letta
}

_Bool inserimento(Elenco *headPtr){
	int isbn;
	scanf("%d,", &isbn);
	if (isbn==0){
		while(getchar()!='\n');
		return 0;
	}
	Elenco newPtr = *headPtr;
	//verifica che il libro non sia gia presente
	while(newPtr!=NULL && isbn!=newPtr->isbn){
		newPtr = newPtr->nextPtr;
	}
	//aggiunge una copia se il libro e' stato trovato
	if(newPtr!=NULL){
		newPtr->copiteTot++;
		newPtr->copiedDisp++;
		while(getchar()!='\n');
		return 1;
	}
	newPtr = malloc(sizeof(Libro));
	if(newPtr == NULL){
		printf("memoria esaurita\n");
		exit(1);
	}
	//asegnamento informazioni
	newPtr->titolo = readString(CSV);
	newPtr->autore = readString(Eof);
	newPtr->copiedDisp = 1;
	newPtr->copiteTot = 1;
	newPtr->isbn = isbn;
	newPtr->nextPtr = NULL;
	Elenco corrPtr = *headPtr;
	Elenco precPtr = NULL;
	//ricerca per insertion sort
	while(corrPtr!=NULL && strcmp(newPtr->autore, corrPtr->autore)>0){//ricerca per autore
		precPtr = corrPtr;
		corrPtr = corrPtr->nextPtr;
	}
	while(corrPtr!=NULL && strcmp(newPtr->autore, corrPtr->autore)==0 && strcmp(newPtr->titolo, corrPtr->titolo)>0){//ricerca per titolo
		precPtr = corrPtr;
		corrPtr = corrPtr->nextPtr;
	}
	newPtr->nextPtr = corrPtr;
	//inserimento del nuovo libro
	if(precPtr==NULL){//inserimento in testa
		*headPtr = newPtr;
	}
	else{//inserimento nel mezzo o in coda
		precPtr->nextPtr = newPtr;
	}
	return 1;
}

void stampaCatalogo(Elenco correntePtr){
	while(correntePtr!=NULL){
		printf("%d - %s - %s (%d/%d)\n",
		correntePtr->isbn,\
		correntePtr->autore,\
		correntePtr->titolo,\
		correntePtr->copiedDisp,\
		correntePtr->copiteTot);
		correntePtr = correntePtr->nextPtr;
	}
	return;
}

void ricerca(Elenco correntePtr){
	printf("Inserire nome autore: ");
	char*autore = readString(Eof);
	printf("Inserire titolo: ");
	char*titolo = readString(Eof);
	cerca(correntePtr, autore, titolo);
	free(autore);
	free(titolo);
}
void cerca(Elenco correntePtr, char *autore, char *titolo){
	if(correntePtr==NULL){//se il libro non e' stato trovato
		printf("Libro non trovato.\n");
		return;
	}
	if(strcmp(correntePtr->autore,autore)==0 && strcmp(correntePtr->titolo,titolo)==0){//quando il libro viene trovato
		if(correntePtr->copiedDisp==0){
			printf("Non ci sono copie disponibili del libro richiesto.\n");
			return;
		}
		printf("%d copie disponibili.\n", correntePtr->copiedDisp);
		return;
	}
	else{//chiamata ricorsiva
		cerca(correntePtr->nextPtr,autore,titolo);
	}
}

void prestito(Elenco correntePtr){
	int isbnp;
	printf("ISBN: ");
	scanf("%d", &isbnp);
	while(correntePtr!=NULL && correntePtr->isbn!=isbnp){//ricerca libro
		correntePtr = correntePtr->nextPtr;
	}
	if(correntePtr == NULL){
		printf("Libro non trovato.\n");
		return;
	}
	if(correntePtr->copiedDisp==0){
		printf("Non ci sono copie disponibili del libro richiesto.\n");
	}
	else{
		printf("Operazione completata.\n");
		correntePtr->copiedDisp--;
	}
	return;
}

void restituzione(Elenco correntePtr){
	int isbnr;
	printf("ISBN: ");
	scanf("%d", &isbnr);
	while(correntePtr!=NULL && correntePtr->isbn!=isbnr){//ricerca libro
		correntePtr = correntePtr->nextPtr;
	}
	if(correntePtr == NULL){
		printf("Libro non trovato.\n");
		return;
	}
	if(correntePtr->copiedDisp==correntePtr->copiteTot){
		printf("Non risultano copie in prestito.\n");
	}
	else{
		printf("Operazione completata.\n");
		correntePtr->copiedDisp++;
	}
	return;
}