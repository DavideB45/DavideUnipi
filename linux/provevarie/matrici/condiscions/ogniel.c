#include <stdio.h>
#include <stdlib.h>

void read(size_t righe, size_t colonne, char **matrice);
void print(size_t row, size_t column, char **matrix);

_Bool ceck(size_t righe, size_t colonne, char **matrice);

int main(void){
	int righe, colonne;
	printf("inserire righe e colonne : ");
	while (scanf("%d %d", &righe, &colonne)!=2 || righe<1 || colonne<1){
		printf("Errore : ");
		while (getchar()!='\n');
	}
	while (getchar()!='\n');
	char **matrice = calloc(righe, sizeof(char*));
	for (size_t i = 0; i < righe; i++){
		matrice[i] = calloc(colonne, sizeof(char));
	}
	
	read(righe, colonne, matrice);
	print(righe, colonne, matrice);

	if(ceck(righe, colonne, matrice)){
		printf("tutto ok\n");
	} else {
		printf("errore\n");
	}

}

void read(size_t row, size_t column, char **matrix){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			scanf("%c", &matrix[i][j]);
			while(getchar()!='\n');
		}
	}
}
void print(size_t row, size_t column, char **matrix){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			printf("%c\t", matrix[i][j]);
		}
		printf("\n\n");
	}
}



_Bool ceck(size_t righe, size_t colonne, char **matrice){
	_Bool condizione = 1;
	int colonna = 0, riga = 0;

	do{

		do{

			//se non e' divisibile ne per 2 ne per tre
			if( (matrice[riga][colonna]%2 == 1)  &&  (matrice[riga][colonna]%3 != 0)){
				condizione = 0;
				printf("condizione non verificata per [%d][%d]\n", riga, colonna);
			}

		}while(++colonna, colonna < colonne  /*&&  condizione*/);
		colonna = 0;

	}while(++riga, riga < righe  /*&&  condizione*/);
	
	return condizione;
}