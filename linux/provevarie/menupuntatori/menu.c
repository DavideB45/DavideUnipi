#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void delay(float tempo){	
	long int tempo1, tempo2;
	tempo1 = clock();
	tempo2 = clock();
	while((tempo2 - tempo1)/CLOCKS_PER_SEC<tempo){
		tempo2 = clock();
		//printf("1");
	}
}
void secondogrado(int a,int b, int c){
	int delta = b*b -4*a*c;
	float x_1 = (-b+sqrt(delta))/(2*a);
	float x_2 = (-b-sqrt(delta))/(2*a);
	printf("x_1 vale = %.2f\n", x_1);
	printf("x_2 vale = %.2f\n", x_2);
}
void primogrado(int a, int b){
	printf("x vale %.2f\n", (float) a/b);
}

void potenza(int base, int esponente){
	float res = pow(base, esponente);
	printf("%d alla %d = %.0f\n", base, esponente, res);
}
void logn(int base, int argomento){
	float res = log(argomento)/log(base);
	printf("log in base %d di %d = %.2f\n", base, argomento, res);
}

void seno(float x){
	printf("sen(%.1f) = %.2f\n", x, sin(x));
}
void coseno(float x){
	printf("cos(%.1f) = %.2f\n", x, cos(x));
}
void tangente(float x){
	printf("tan(%.1f) = %.2f\n", x, tan(x));
}

int scegli(int min, int max){
	int scelta;
	while(scanf("%d", &scelta)!=1||scelta<min||scelta>max){
		printf("inserire un numero da %d a %d\n", min, max);
		scanf("%*[^\n]");
		scanf("%*c");
	}
	scanf("%*[^\n]");
	scanf("%*c");
	return scelta;
}

void esponenti(void){
	int scelta;
	float x;
	int y;
	void (*menu[2])(int, int) = {logn, potenza};
	printf("%20s\n%25s\n", "ESPONENTI", "7 = menu principale");
	printf("1. log base x\n");
	printf("2. log base 10\n");
	printf("3. log base e\n");
	printf("4. x alla y\n");
	printf("5. quadrato di x\n");
	printf("6. cubo di x\n");
	scelta = scegli(1, 7);
	if(scelta == 7){
		return;
	}
	else{
		switch (scelta){
			case 1:
				printf("inserire base: ");
				scanf("%f", &x);
				printf("inserire l'argomento: ");
				scanf("%d", &y);
				break;
			case 2:
				scelta = 1;
				printf("inserire l'argomento: ");
				scanf("%d", &y);
				x = 10;
				break;
			case 3:
				/*scelta = 1;
				printf("inserire l'argomento\n");
				scanf("%d", &y);
				x = 2.72;
				break;*/
				printf("non disponibile :(\n");
				delay(1);
				return;
				break;
			case 4:
				scelta = 2;
				printf("inserire base: ");
				scanf("%f", &x);
				printf("inserire esponente: ");
				scanf("%d", &y);
				break;
			case 5:
				scelta = 2;
				printf("inserire base: ");
				scanf("%f", &x);
				y = 2;
				break;
			case 6:
				scelta = 2;
				printf("inserire base: ");
				scanf("%f", &x);
				y = 3;
				break;
		}
		(*menu[scelta-1])(x, y);
		scanf("%*[^\n]");
		scanf("%*c");
		getchar();
		return;
	}
}
void trigonometria(void){
	int scelta;
	float angolo;
	void (*menu[3])(float) = {coseno, seno, tangente};
	printf("%20s\n%22s\n", "TRIGONOMETRIA", "4 = torna al menu");
	printf("1. coseno\n");
	printf("2. seno\n");
	printf("3. tangete\n");
	scelta = scegli(1, 4);
	if(scelta == 4){
		return;
	}
	else{
		printf("inserisci l'angolo in radianti:");
		scanf("%f", &angolo);
		(*menu[scelta-1])(angolo);
	}
	scanf("%*[^\n]");
	scanf("%*c");
	getchar();
	return;
}
void equazioni(void){
	printf("la funzione non sara' mai aggiunta :)\n");
	getchar();;
}
void ragequit(void){
	printf("GOOD BYE!\n");
	exit(EXIT_SUCCESS);
}
int main(){
	int scelta;
	void (*menu[4])(void) = {esponenti, trigonometria, equazioni, ragequit};
	while(1){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("MAIN MENU\n");
	delay(0.4);
	printf("1. esponenti e log\n");
	printf("2. trigonometria\n");
	printf("3. equazioni\n");
	printf("4. esci\n");
	scelta = scegli(1, 4);
	(*menu[scelta-1])();
	}
}
	
	
	
	
		
	
	
	
	
	
	
	
	
	
