#include <stdio.h>
#include <stdlib.h>


int main(void){
	int colonne;
	printf("Inserire numero gare : ");
	while (scanf("%d", &colonne)!=1){
		while(getchar()!='\n');
	}
	while(getchar()!='\n');

	int array[colonne];
	int tot_sfide = 0;


	//inserimento sfide
	for (size_t i = 0; i < colonne; i++){
		printf("Inserire codice sfida : ");
		while (scanf("%d", &array[i])!=1){
			while(getchar()!='\n');
		}
		while(getchar()!='\n');
	}
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
	while(scanf("%d", &partecipanti)!=1){
		while(getchar()!='\n');
	}
	while(getchar()!='\n');
	
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
			while (scanf("%d", &punti)!=1){
				while(getchar()!='\n');
			} getchar();
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