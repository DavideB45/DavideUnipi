#include <stdio.h>
#define DIM 3

void riempiGriglia(char griglia[][DIM]){
	/*for(int i = 0; i<dim; i++){
		for(int j = 0; j<dim; j++){
			griglia[i][j] = getchar();
			getchar();
		}
		getchar();
	}*/	
	char c;
	int i = 0	;
	for(int a = 0; a<3; a++){
		scanf("%c", &c);
		do{
			if(c=='x' || c=='o' || c=='-'){
				//**(griglia + i)=c;
				griglia[a][i%3]=c;
				i++;
			}
			c = getchar();
		}while(c!='\n');
	}
	return;
}

int controlloriga(char griglia[][DIM], char giocatore,int riga){
	int indice = 1;
	while(*(*griglia + indice + 3*riga) == giocatore){
		indice++;
	}
	return indice;	
}
int controllocolonna(char griglia[][DIM], char giocatore, int colonna){
	int indice = 0;
	while(*(*griglia + colonna + 3*indice) == giocatore){
		indice++;
	}
	return indice;
}
_Bool controlloobliquo(char griglia[][DIM]){
	int i = 0;
	while((i<8) && (**griglia == *(*griglia+i))){
		printf("Next %d %c\n", i, *(*griglia+i));
		i += 4;
	}
	
	/*while(griglia[0][0] == griglia[i][i]){
		i++;
	}*/
	printf("%d %c\n", i, **(griglia));
	if(i == 8){
		printf("vince %c\n", griglia[0][0]);
		return 1;
	}
	i = 1;
	while(**griglia == **(griglia+i*2)){
		i++;
	}
	if(i == 8){
		printf("vince %c\n", griglia[0][2]);
		return 1;
	}
	return 0;
}

void printmatrix(char griglia[][DIM]){
	for(int i = 0; i<DIM; i++){
		for(int j = 0; j<DIM; j++){
			printf("%c ", griglia[i][j]);
		}
		printf("\n");
	}
}
int main(void){
	char griglia[DIM][DIM];
	riempiGriglia(griglia);
	
	printmatrix(griglia);
	
	//printf("riga\n");
	for(int i = 0; i<DIM; i++){
		if(controlloriga(griglia, griglia[i][0], i) == 3){
			printf("vince %c\n", griglia[i][0]);
			return 0;
		}
	}
	
	//printf("colonna\n");
	for(int i = 0; i<DIM; i++){
		if(controllocolonna(griglia, griglia[0][i], i) == 3){
			printf("vince %c\n", griglia[0][i]);
			return 0;
		}
	}
	
	//printf("obliquo\n");
	if(!controlloobliquo(griglia)){
		printf("pareggio\n");
	}
	return 0;
}
