#include <stdio.h>
#include <stdlib.h>
#include <string.h>


////////////////////////
/*FUNZIONI DI SUPPORTO*/
////////////////////////

//legge da input i valori della matrice
void read(size_t righe, size_t colonne,char matrice[righe][colonne]);
//copia gli inidirizzi delle righe in un array
void copyinarray(size_t righe, size_t colonne, char matrice[righe][colonne],char *array[righe]);
//visualizza la matrice sfruttando l'array costruito n=con la funzione sopra
void print(size_t righe, char *array[righe]);


///////////////////////////
/*FUMZIONI DI ORDINAMENTO*/
///////////////////////////

//ordinano un array di puntatori a carattere
void merge_sort(size_t dim, char *array[dim]);
void sort(size_t inizio, size_t fine, char *array[fine-inizio+1]);
void merge(size_t sx, size_t centro1, size_t centro2, size_t fine, char *array[fine-sx+1]);

////////////
//  MAIN  //
////////////
int main(void){
	size_t righe, colonne;
	//lettura numero righe
	printf("Inserire il numero di righe : ");
	while (scanf("%lu", &righe)!=1){
		printf("Ritenta : ");
		while(getchar()!='\n');
	}
	//lettura numero colonna
	printf("Inserire il numero di colonne : ");
	while (scanf("%lu", &colonne)!=1){
		printf("Ritenta : ");
		while(getchar()!='\n');
	}
	
	//creazione strutture (matice e array)
	char matrice[righe][colonne];
	read(righe, colonne, matrice);
	char *array[righe];
	copyinarray(righe, colonne, matrice, array);
	print(righe, array);
	
	//ordinamento array
	merge_sort(righe, array);
	
	//stampa ordinata
	print(righe, array);
	return 0;
}


////////////////////////
/*FUNZIONI DI SUPPORTO*/
////////////////////////
void read(size_t righe, size_t colonne,char matrice[righe][colonne]){
	int len;
	for(size_t i = 0; i < righe; i++){
		while(scanf("%s%n", &matrice[i][0], &len)!=2 && len>colonne){
			printf("Input error: ");
			while (getchar()!='\n');			
		}
	}
}

void copyinarray(size_t righe, size_t colonne, char matrice[righe][colonne],char *array[righe]){
	for(int i = 0; i < righe; i++){
		array[i] = matrice[i];
	}
}

void print(size_t righe, char *array[righe]){
	printf("\n");	
	for (size_t i = 0; i < righe; i++){
		printf("%s\t%p\n", array[i], array[i]);
	}
}


///////////////////////////
/*FUMZIONI DI ORDINAMENTO*/
///////////////////////////
void merge_sort(size_t dim, char *array[dim]){
	sort(0, dim-1, array);
}
void sort(size_t inizio, size_t fine, char *array[fine-inizio+1]){
	if(fine - inizio >= 1){
		//calcolo meta'
		size_t centro1 = (fine + inizio)/2;
		size_t centro2 = centro1 + 1;
		//chiamate ricorsive per suddividere l'array fino agli elementi base
		sort(inizio, centro1, array);
		sort(centro2, fine, array);
		merge(inizio, centro1, centro2, fine, array);
	}
}
void merge(size_t sx, size_t centro1, size_t centro2, size_t fine, char *array[fine-sx+1]){
	char **support = calloc(fine-sx+1, sizeof(char*));
	size_t sxI = sx, dxI = centro2, suI = 0;
	while(sxI <= centro1 && dxI <= fine){
		//if(array[sxI][0] < array[dxI][0])
		if(strcmp(array[sxI], array[dxI]) < 0){
			support[suI++] = array[sxI++];
		} else {
			support[suI++] = array[dxI++];
		}
	}
	//copia le parti rimanenti
	while(sxI <= centro1){
		support[suI++] = array[sxI++];
	}
	while(dxI <= fine){
		support[suI++] = array[dxI++];
	}
	//copia ordinata nell'array principale
	suI = 0;
	for(int i = sx; i <= fine; i++){
		array[i] = support[suI++];
	}
	free(support);
}