#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void read(int righe, int colonne,int  matrice[righe][colonne]);
void print(int righe,int colonne, int matrice[righe][colonne]);


//restituiscono indici non valori di somme
int maxcol(int righe,int colonne, int matrice[righe][colonne]);
int maxriga(int righe, int colonne, int matrice[righe][colonne]);

int main(void){
	int righe, colonne;
	printf("Inserire righe : ");
	while(scanf("%d", &righe)!=1 || righe < 1){
		printf("Valore non valido : ");
		while(getchar()!='\n');
	}
	printf("\rInserire colonne : ");
	while(scanf("%d", &colonne)!=1 || colonne < 1){
		printf("Valore non valido : ");
		while(getchar()!='\n');
	}

	srand(time(NULL));
	int matrice[righe][colonne];
	read(righe, colonne, matrice);
	print(righe, colonne, matrice);
	
	printf("colonna massima = %d\n", maxcol(righe, colonne, matrice));
	printf("riga massima = %d\n", maxriga(righe, colonne, matrice));
	return 0;
}

void read(int righe,int colonne, int matrice[righe][colonne]){
	for(int i = 0; i < righe; i++){
		for(int j = 0; j < colonne; j++){
			/*while(scanf("%d", &matrice[i][j])!=1);
			while(getchar()!='\n');*/
			matrice[i][j] = rand() % 20;
		}
	}
}
void print(int righe,int colonne, int matrice[righe][colonne]){
	for(int i = 0; i < righe; i++){
		for(int j = 0; j < colonne; j++){
			printf("%4d", matrice[i][j]);
		}
		printf("\n\n");
	}
}



int maxcol(int righe,int colonne, int matrice[righe][colonne]){
	int max = 0;
	int rowtot;
	int maxI = 0;
	for(int i = 0; i < colonne; i ++){
		
		rowtot = 0;
		for(int j = 0; j < righe; j++){
			rowtot += matrice[j][i];
		}
		if(rowtot > max){
			max = rowtot;
			maxI = i;
		}

	}
	printf("colonna = %d\tsomma = %d\n", maxI, max);
	return maxI;
}
int maxriga(int righe, int colonne, int matrice[righe][colonne]){
	int max = 0;
	int rowtot;
	int maxI = 0;
	for(int i = 0; i < righe; i ++){
		
		rowtot = 0;
		for(int j = 0; j < colonne; j++){
			rowtot += matrice[i][j];
		}
		if(rowtot > max){
			max = rowtot;
			maxI = i;
		}

	}
	printf("riga = %d\tsomma = %d\n", maxI, max);
	return maxI;
}