#include <stdio.h>
#include <stdlib.h>

typedef enum {BIANCO, ROSSO, BLU} colore;

typedef struct vertice{
	colore col;
	int *link;
	int tot_link;
}vertice;
typedef vertice* Grafo;

int readInt(void);
_Bool is_bipartito(int n_v, Grafo E);
_Bool rec_color(Grafo E, int corr_v, colore prec_color);
Grafo create_graph(int dim);
void fillArray(int dim, int *array);

int main(void){
	int dim = readInt();
	Grafo E = create_graph(dim);
	
	printf("%d\n", is_bipartito(dim, E));
	return 0;
}

int readInt(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("errore nell' input : ");
		while(getchar() != '\n');
	}
	return num;
}

_Bool is_bipartito(int n_v, Grafo E){
	_Bool is_well_colored = rec_color(E, 0, ROSSO);
	if(!is_well_colored){
		return 0;//ci sono cose che puntano a altre cose
	}
	for(size_t i = 0; i < n_v; i++){
		if(E[i].col == BIANCO)
			return 0;//non e' connesso il ciccetto
	}
	return 1;//il grafo e' bipartito
}

_Bool rec_color(Grafo E, int corr_v, colore prec_color){
	E[corr_v].col = (prec_color == ROSSO)? BLU : ROSSO;
	int next;
	for(size_t i = 0; i < E[corr_v].tot_link; i++){
		next = E[corr_v].link[i];//vertice su cui incide il collegamento che sto considerando
		
		if(E[next].col == BIANCO){//se lo devo visitare
			if(!rec_color(E, next, E[corr_v].col)){//se qualcosa punta a uno dello stesso insieme
				return 0;//il grafo ha qualche problema
			}
		} else {
			if(E[next].col == E[corr_v].col){
				return 0;//il fratm punta a uno dello stesso sottoinsieme
			}		
		}
	}
	return 1;//e' andato tutto bene
}

Grafo create_graph(int dim){
	Grafo G = malloc(dim*sizeof(vertice));
	for (size_t i = 0; i < dim; i++){
		G[i].tot_link = readInt();
		G[i].col = BIANCO;
		G[i].link = malloc((G[i].tot_link)*sizeof(int));
		fillArray(G[i].tot_link, G[i].link);
	}
	return G;
}

void fillArray(int dim, int *array){
	for (size_t i = 0; i < dim; i++){
		array[i] = readInt();
	}
}
