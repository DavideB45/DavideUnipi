#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct dipendente {
	int matr;
	char nome[20];
	int mmAssunzione;
	int aaAssunzione;
	int stipendio;
} Dipendente;

//mostra tutte le info di un dipendente
void printdip(Dipendente dip);


//main
int main(void){
	Dipendente nome[4];
	FILE *fPtr;
	if((fPtr = fopen("input.txt", "rb"))==NULL){
		printf("File not found\n");
		exit(1);
	}
	//inserimento dipendeti da file
	for(size_t i = 0; i<4; i++){
		fread(&nome[i], sizeof(Dipendente), 1, fPtr);
	}
	//visualizzazione tutti i dipendenti
	printf("Matr\tNome\tMM\tAA\tStipendio\n");
	for(size_t i = 0; i<4; i++){
		printdip(nome[i]);
	}
	//riformulazione stipendi
	for (size_t i = 0; i < 4; i++){
		if(nome[i].aaAssunzione<2000 || (nome[i].aaAssunzione==2000 && nome[i].mmAssunzione<5)){
			nome[i].stipendio += nome[i].stipendio*22/100;
		}
	}
	//visualizzzazione stipendi superiori a 1200
	printf("Matr\tNome\tStipendio\n");
	for (size_t i = 0; i < 4; i++){
		if(nome[i].stipendio>1200){
			printf("%d\t%s\t%d\n",
				nome[i].matr,
				nome[i].nome,
				nome[i].stipendio
			);
		}
	}
	return 0;
}

void printdip(Dipendente dip){
	printf("%d\t", dip.matr);
	printf("%s\t", dip.nome);
	printf("%d\t", dip.mmAssunzione);
	printf("%d\t", dip.aaAssunzione);
	printf("%d\n", dip.stipendio);
	return;
}