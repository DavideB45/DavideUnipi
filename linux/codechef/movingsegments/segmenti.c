#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ITEARTION 100

typedef struct cammion{
	int L;
	int R;
	int V;
	struct cammion *nextPtr;
}cammion;
typedef cammion *camPtr;

int read_int(void);
void ceckPtr(void *Ptr);
void insert_sort(camPtr *hPtr);
_Bool si_incontrano(camPtr corrPtr);
void parcheggia(camPtr *hPtr);

int main(void){
	int testcase ;
	int N_cammion;
	camPtr hPtr = NULL;

	clock_t inizio = clock();

	testcase = read_int();
	for(int i = 0; i < testcase; i++){
		printf("Quanti cammion ci sono ? ");
		N_cammion = read_int();
		for (int j = 0; j < N_cammion; j++){
			insert_sort(&hPtr);
		}
		
		if(si_incontrano(hPtr)){
			printf("Non puoi ancora superare (si incrociano) (NO)\n");
		} else {
			printf("Non ci sono piu' cammion (non si incrociano) (SI)\n");
		}
		parcheggia(&hPtr);
	}

	clock_t fine = clock();
	printf("N_CLOCK = %lu\n", fine-inizio);
	return 0;
}

int read_int(void){
	int num;
	while(scanf("%d", &num)!=1){
		scanf("%*[\n]");
		scanf("%*c");
		printf("numero non valido");
	}
	return num;
}

void ceckPtr(void *Ptr){
	if(Ptr==NULL){
		printf("memoria esaurita\n");
		exit(EXIT_FAILURE);
	}
}

void insert_sort(camPtr *hPtr){
	camPtr corrPtr = *hPtr;
	camPtr precPtr = NULL;
	camPtr newCammion = calloc(1, sizeof(cammion));
	ceckPtr(newCammion);
	int L = read_int();
	getchar();
	int R = read_int();
	getchar();
	int V = read_int();
	while(corrPtr!=NULL && corrPtr->V < V){
		precPtr = corrPtr;
		corrPtr = corrPtr->nextPtr;
	}
	while(corrPtr!=NULL && corrPtr->L < L && corrPtr->V == V){
		precPtr = corrPtr;
		corrPtr = corrPtr->nextPtr;
	}
	newCammion->L = L;
	newCammion->R = R;
	newCammion->V = V;
	newCammion->nextPtr = corrPtr;
	if(precPtr==NULL){
		*hPtr = newCammion;
	} else {
		precPtr->nextPtr = newCammion;
	}
	
}

_Bool si_incontrano(camPtr corrPtr){
	//controllo che ci sia almeno un cammion
	if(corrPtr!=NULL && corrPtr->nextPtr != NULL){
		
		camPtr nextC = corrPtr->nextPtr;
		_Bool trovato = 0;
		while(corrPtr != NULL && nextC != NULL && !trovato){
			if(corrPtr->V == nextC->V && corrPtr->R > nextC->L){
				trovato = 1;
			} else {
				corrPtr = nextC;
				nextC = nextC->nextPtr;
			}
		}
		if(trovato){
			return 1;
		} else {
			return 0;
		}

	} else {//c'e' un solo cammion o 0 cammion
		return 0;
	}
	
}

void parcheggia(camPtr *hPtr){
	camPtr tofree ;
	while((*hPtr)!=NULL){
		tofree = (*hPtr);
		(*hPtr) = (*hPtr)->nextPtr;
		free(tofree);
	}
}