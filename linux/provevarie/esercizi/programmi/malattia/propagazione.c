#include <stdio.h>
#define costantecontagio 1
int malati();
int popolazione = 0;
int infetti;

int main(void){
	int sani = 0;
	int giorno = -1;
	printf("inserire la popolazione iniziale: ");
	while(scanf("%d", &popolazione) != 1 || popolazione < 0){
		scanf("%*[^\n]");
		printf("\ninserire un numero valido di persone: ");
	}
	printf("inserire il numero di giorni: ");
	while(scanf("%d", &giorno) != 1 || giorno < 0){
		scanf("%*[^\n]");
		printf("\ninserire un umero di giorni valido: ");
	}
	//calcola il numero di malati 
	popolazione = malati(giorno);
	return 0;
}

int malati(int giorno){

	if(giorno == 0)
		infetti = 1;
	
	else{
			infetti = malati(--giorno)+costantecontagio*(popolazione-malati(--giorno))*malati(--giorno);	
			printf("infetti = %d\n", infetti);
	}
	return infetti;
}
