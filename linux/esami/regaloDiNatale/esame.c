#include <stdio.h>
#include <stdlib.h>

int readInt(void);
void fillArray(int dim, int array[dim]);

int main(void){
	int colonne;
	printf("Inserire numero gare : ");
	colonne = readInt();

	int array[colonne];
	int tot_sfide = 0;

	fillArray(colonne, array);

	//creazione funzione per trovare l'indice della sfida
	for(int i = 0; i < colonne; i++){
		if(array[i]>0){
			//allocare QUI per la pila
			for(int j = i + 1; j < colonne; j++){
				if(array[i]==array[j]){
					array[j] = -tot_sfide;
				}
			} array[i] = -tot_sfide;
			tot_sfide++;
		}
	}
	for (size_t i = 0; i < colonne; i++){
		printf("%d::", array[i]);
	} printf("\n");
	


	int partecipanti;
	printf("inserire il numero di sfidanti : ");
	partecipanti = readInt();
	
	//creazione griglia pulita
	int punti;
	int griglia_punteggi[partecipanti][tot_sfide];
	for(int i = 0; i < partecipanti; i++){
		for (size_t j = 0; j < tot_sfide; j++){
			griglia_punteggi[i][j] = 0;
		}
	}


	for(int i = 0; i < partecipanti; i++){
		//riempimento dei punteggi di uno uomo
		for (size_t j = 0; j < colonne; j++){
			printf("inserire gara %d del giocatore %d : ", i, j);
			colonne = readInt();
			//printf("punti = %d\nindice i = %d\n/array[j] = %d\n", punti, i, -array[j]);
			griglia_punteggi[i][-array[j]] += punti;
		}	
	}

//printf della matrice mistica
	for(int i = 0; i < partecipanti; i++){
		for (size_t j = 0; j < tot_sfide; j++){
			printf("%d ", griglia_punteggi[i][j]);
		} 
		printf("\n");	
	}

	
}


int readInt(void){
	int number;
	while (scanf("%d", &number)!=1){
		while(getchar()!='\n');
	}
	while(getchar()!='\n');
	return number;
}

void fillArray(int dim, int array[dim]){
	//inserimento sfide
	for (size_t i = 0; i < dim; i++){
		printf("Inserire codice sfida : ");
		array[i] = readInt();
	}
	return;
}