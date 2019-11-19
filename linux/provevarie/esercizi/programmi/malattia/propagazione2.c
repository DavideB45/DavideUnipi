#include <stdio.h>
#define costantecontagio 0.0001
int malati();
int popolazione = 0;
float infetti = 0;

int main(void){
	int giorno = -1;
	printf("inserire la popolazione iniziale: ");
	while(scanf("%d", &popolazione) != 1 || popolazione < 0){
		scanf("%*[^\n]");
		scanf("%*c");
		printf("\ninserire un numero valido di persone: ");
	}
	printf("inserire il numero di giorni: ");
	while(scanf("%d", &giorno) != 1 || giorno < 0){
		scanf("%*[^\n]");
		scanf("%*c");
		printf("\ninserire un umero di giorni valido: ");
	}
	//calcola il numero di malati 
	infetti = malati(giorno);
	printf("infetti = %f \n", infetti);
	return 0;
}

int malati(int giorno){

	if(giorno == 0){
		printf("infetti = 1.0\n");
		return 1;
	}
	
	else{
		infetti = malati(giorno - 1);
		infetti = infetti*(1+costantecontagio*popolazione)-costantecontagio*infetti*infetti;
		//infetti = infetti+costantecontagio*(popolazione-infetti)*infetti;	
		if(popolazione > infetti){
			printf("infetti = %f\n", infetti);
			return infetti;
		}
		else{
			printf("infetti = %d\n", popolazione);
			return popolazione;
		}
	}
}
