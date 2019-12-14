#include <stdio.h>


//riempie una matrice quadrata (se ci sono errori nell'inseimento ritorna 0)
_Bool read(size_t dim, float matrice[dim][dim]);

//se verifica le condizioni ritorna 1 altrimenti 0
//indSomma = indice di somma massima
_Bool condizioni(size_t dim, float matrice[dim][dim], int *indSomma, float *sommaMax);


int main(void){
	size_t dim;//dimensione righe e colonne
	while(scanf("%lu", &dim)!=1){
		printf("numero non valido");
		while (getchar()!='\n');
	}
	float matrice[dim][dim];
	if(read(dim, matrice)){
		int colonna;
		float somma;
		if(condizioni(dim, matrice, &colonna, &somma)){
			printf("Indice di somma massima: %d\n", colonna);
			printf("Valore di somma massima: %.2f\n", somma);
		} else {
			printf("errroereerereeqre\n");
		}
	}
	return 0;
}

_Bool read(size_t dim, float matrice[dim][dim]){
	char c;
	//inserimento di tutti i valori
	for (size_t i = 0; i < dim; i++){
		for (size_t j = 0; j < dim; j++){
			if(scanf("%f%c", &matrice[i][j], &c)!=2 || (c!=' ' && c!='\n' && c!='\t')){
				printf("L'input non e' corretto\n");
				return 0;
			}
		}
	}
	return 1;
}

_Bool condizioni(size_t dim, float matrice[dim][dim], int *indSomma, float *sommaMax){
	size_t colonna = 0;//indice di colonna
	size_t riga = 0;//indice di riga
	_Bool errori = 0;//viene reso 1 se compare un errore
	*indSomma = 0;
	float somma = 0;
	while (!errori && riga < dim){
		//controllo diagonale
		if(matrice[riga][riga]!=0){
			errori=1;
		}
		while (!errori && colonna < dim){
			//controllo simmetria
			if(matrice[riga][colonna]!=matrice[colonna][riga]){
				errori = 1;
			} else {
				//calcolo valore colonna
				somma += matrice[riga][colonna];
				colonna++;
			}
		}
		if(somma > *sommaMax){
			*sommaMax = somma;
			*indSomma = riga;
		}
		somma = 0;
		riga++;
		colonna = 0;
	}
	return errori==0;
}