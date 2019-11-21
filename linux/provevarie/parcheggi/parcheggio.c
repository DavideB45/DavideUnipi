#include <stdio.h>
#include <stdlib.h>
#include <time.h>

_Bool lancio_dado(int posti_liberi){
	int risultato;
	risultato = rand() % 5 + 1;
	if(risultato%2 == 0 && posti_liberi != 0){
		return 1;
	}
	else{
		return 0;
	}
}


int esce(int posti[]){
	int indice_uscita;
	indice_uscita = rand() % 99;
	while(posti[indice_uscita]==-1){
		//indice_uscita++;
		indice_uscita = (indice_uscita + 1)%100;
		//if(indice_uscita == 99){
			//indice_uscita = 0;
		//}
	}
	posti[indice_uscita]  = -1;	
}

void entra(int posti[]){
	int posto_assegnato = -1;
	int targa;
	int ind_parcheggio = 0;
	targa = rand () % 1000;
	do{
		if(posti[ind_parcheggio] == -1){
			posti[ind_parcheggio] = targa;
			posto_assegnato = 1;
		}
		ind_parcheggio++;
	}while(posto_assegnato<0);
	return;
}



void inizializza(int posti[]){
	for(int i = 0; i<100; i++){
		posti[i] = -1;
	}
	return;
}

void parcheggio_out(int posti[]){
	for(int i = 0; i<100; i++){
		if(posti[i]!=-1){
			printf("posto %d: %d\n", i, posti[i]);
		}
	}
	return;
}

void sortizzatutto(int posti[]){
	int ultimo_posto_occupato = 99;
	/*for(int i = 99; i>0; i--){
		if(posti[i]!=-1){
			ultimo_posto_occupato = i;
			break;
		}
	}*/
	int temp;
	for(int i = 0; i<ultimo_posto_occupato + 1; i++){
		for(int j = 0; j<ultimo_posto_occupato + 1; j++){
			if(posti[i]<posti[j] /*|| posti[i]==-1*/){
				temp = posti[j];
				posti[j] = posti[i];
				posti[i] = temp;
			}
		}
	}
	return;
}

typedef struct{
	int value;
}a;
typedef a *aPtr;

int main(void){
	srand(time(NULL));
	int posti[100];
	int posti_liberi = 100;
	int primo_posto_libero = 0;
	//int ultimo_posto_occupato;
	inizializza(posti);
	for(int iterazione = 0; iterazione<400; iterazione++){
		if(lancio_dado(posti_liberi)){
			entra(posti);
			posti_liberi--;
		}
		else{
			if(posti_liberi != 100){
				esce(posti);
				posti_liberi++;
			}
		}
	}
	if(posti_liberi == 100){
		printf("non ci sono posti liberi\n");
	}
	else{
		sortizzatutto(posti);
		parcheggio_out(posti);
	}
	return 0;
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
