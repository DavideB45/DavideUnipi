#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct strada{
	int x;
	int y;
	char orientazione;
} Strada;

int readInt(void);
void readSt(Strada *strada);
void clean(void);
void ceckPtr(void *ptr);
int maxdistance(int dim, Strada array[]);
void printdirection(int dim, Strada array[]);//free delle cose dopo averle stampate

int main(void){

	printf("inserire numero di sfide : ");
	int Nsfide = readInt();
	
	Strada *array = NULL;
	for(int i = Nsfide; i > 0; i--){
		printf("inserire il numero di starde [   ]\b\b\b");
		int Nstr = readInt();
		array = calloc(Nstr, sizeof(Strada));
		ceckPtr(array);
		
		for(int i = 0; i < Nstr; i++){
			printf("Inserire il tracciato numero %d\n", i+1);
			readSt(&(array[i]));
		}
		//printf("per non causare vittime i tracciati \
			sono di distanza max = %d", maxdistance(Nstr, array));
		//printdirection(Nstr, array);
		free(array);
	}
	
}

int readInt(void){
	int num;
	while(scanf("%d", &num)!=1){
		printf("Numero non valiudo : ");
		clean();
	}
	return num;
}

void readSt(Strada *strada){

	printf("Inserire x : ");
	strada->x = readInt();
	getchar();
	printf("Inserire y : ");
	strada->y = readInt();
	
}


void clean(void){
	scanf("%*[\n]");
	scanf("%*c");
}

void ceckPtr(void *ptr){
	if(ptr == NULL){
		printf("Memoria esaurita \n");
		exit(1);
	}
}

int maxdistance(int dim, int i, Strada array[], int maxd){
	if(maxd == -1){
		return -1;
	}
	if(i < dim && maxd != -1){
		array[i].orientazione = '|';
		int maxd = maxdistance(dim, i + 1, array, maxd);
		if(dist==-1){
			return -1;
		} else {
			array[i].orientazione = '-';
			maxd = maxdistance(dim, i + 1, array, maxd);
		}
	} else {
		//rappresenta la distanza massima che si puo raggiungere con una determinata configurazione
		//che equivale al minimo tra tutti i confronti tra due singloli punti
		int mindistance = -1;
		//distanza massima che possono avere due punti senza causare vittime
		int relmax;//sta per distanza massima relativa a 2 punti
		
		for(int j = 0; j < dim ; j++){
			for(int k = j; k < dim; k++){
				//va calcolata solo se le 2 direzioni sono diverse
				if(array[j].orientazione != array[k].orientazione){
					calcolo il max:
					if(abs(array[j].x - array[k].x) > abs(array[j].y - array[k].y)){
						relmax = abs(array[j].x - array[k].x) - 1;
					} else {
						relmax = abs(array[j].y - array[k].y) - 1;
					}
				} else {
					if(array[j].orientazione == '|'){
						if(array[j].x == array[k].x){
							relmax = abs(array[j].y - array[k].y);
						} else {
							relmax = -1;
						}
					} else {
						if(array[j].y == array[k].y){
							
						}
					}
				}
				//se sono uguali devo vedere se sono sulla stessa retta 
				//se sono sulla stessa retta devo calcolare la meta' della distanza
				//infine controllo se la distanza relativa e' minore di mindistance gli assegno il nuovo valore calcolato
				//considerare il caso in cui sia -1
			}
		}
	}
}




















