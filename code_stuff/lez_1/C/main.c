#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	int ID;
	float angolo;//misurato a partire da (1 , 0);
}Angolo;
typedef Angolo * AngoloPtr;

int compare(const void * A, const void * B);

int main(void){
	int n_angoli;
	scanf("%d", &n_angoli);
	AngoloPtr* arr_angoli = calloc(n_angoli, sizeof(AngoloPtr));//array di angoli
	
	int x, y;
	for (size_t i = 0; i < n_angoli; i++){
		arr_angoli[i] = malloc(sizeof(Angolo));
		arr_angoli[i]->ID = i + 1;
		scanf("%d %d", &x, &y);

		//calcolo l'angolo (in radianti)
		if(x == 0){//controllo se x = 0 => non posso fare x/y
			if(y < 0){
				arr_angoli[i]->angolo = 3*M_PI_4;
			} else {
				arr_angoli[i]->angolo = M_PI_4;
			}
		} else {
			//guardo il quadrante di appartenenza
			if(x < 0){// secondo terzo quadrante
				arr_angoli[i]->angolo = atan(y/x) + M_PI;
			} else {
				if(y > 0){//primo quadrante
					arr_angoli[i]->angolo = atan(y/x);
				} else {//terzo quadrante
					arr_angoli[i]->angolo = atan(y/x) + 2*M_PI;
				}
			}
		}
		printf("%f %ld\n", arr_angoli[i]->angolo, i);
	}
	
	qsort(arr_angoli, n_angoli, sizeof(AngoloPtr), compare);
	
	for (size_t i = 0; i < n_angoli; i++){
		printf("%d\t%f\n", arr_angoli[i]->ID, arr_angoli[i]->angolo);
	}	
}


int compare(const void * A, const void * B){
	printf("A = %f\tB = %f\n", (((AngoloPtr)A))->angolo, ((AngoloPtr)B)->angolo);
	return (((AngoloPtr)A)->angolo - ((AngoloPtr)B)->angolo);
}
