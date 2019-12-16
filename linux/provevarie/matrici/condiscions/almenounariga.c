//cercare una riga in cui tutti gli elementi
//sono numeri pari

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void read(size_t righe, size_t colonne, int matrice[colonne][righe]);
void print(size_t righe, size_t colonne, int matrice[colonne][righe]);
_Bool condizione(size_t righe, size_t colonne, int matrice[colonne][righe]);

int main(void){
	srand(time(NULL));
	_Bool condiz = 1;
	size_t colonne;
	size_t righe;
	int righegenerate = 0;
	do{
		righe = rand()%900;
		righegenerate += righe;
		/*printf("inserire righe: ");
		while (scanf("%lu", &righe)!=1){
			while(getchar()!='\n');
		}*/
		colonne = rand()%20 + 15;
		/*printf("inserire colonne: ");
		while (scanf("%lu", &colonne)!=1){
			while(getchar()!='\n');
		}*/
		int matrice[righe][colonne];
		read(righe, colonne, matrice);
		print(righe, colonne, matrice);
		condiz = condizione(righe, colonne, matrice);
		if(condiz){
			printf("\nla condizione e' verificata\n");
		} else {
			printf("\nla condizione non e' verificata\n");
		}
	}while(!condiz);
	printf("sono state generate ben %d righe di numeri \n", righegenerate);
}

void read(size_t righe, size_t colonne, int matrice[righe][colonne]){
	for (size_t i = 0; i < righe; i++){
		for (size_t j = 0; j < colonne; j++){
			/*printf("inserire nella cella [%lu][%lu] ", i, j);
			while(scanf("%d", &matrice[i][j])!=1){
				printf("inserimento errato : ");
				while (getchar()!='\n');*/
			matrice[i][j] = rand() % 100;
			//}
		}
	}
}

void print(size_t righe, size_t colonne, int matrice[righe][colonne]){
	for (size_t i = 0; i < righe; i++){
		printf("riga %3lu\t\t", i);
		for (size_t j = 0; j < colonne; j++){
			printf("%2d ", matrice[i][j]);
		}
		printf("\n");
	}
}

_Bool condizione(size_t righe, size_t colonne, int matrice[righe][colonne]){
	int indiceCol = 0;
	int indiceRig = 0;
	_Bool condizione = 0;
	_Bool dispari = 0;
	while(!condizione && indiceRig < righe){
		while(!dispari && indiceCol < colonne){
			dispari = 1==(matrice[indiceRig][indiceCol])%2;
			indiceCol++;
		}
		if(dispari==0 && colonne==indiceCol){//non c'e' un numero dispari
			condizione = 1;
		} else {
			indiceCol = 0;
			indiceRig++;
			dispari = 0;//dispari era '1'
		}
	}
	
	printf("\nriga = %d\n", indiceRig);
	printf("colonna = %d\n", indiceCol);
	
	return condizione;
}
