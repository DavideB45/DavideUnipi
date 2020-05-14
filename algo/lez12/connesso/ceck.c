#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int n_link_ext;
	int *link;
}node;

typedef struct graph{
	int dim;
	node *go_pointer;
}graph;

int readInt(void);
void fill_graph(graph * E);

//prepara le cose per la funzione sotto
//ritorna il numero di nodi non raggiungi bili
int DFS_connect(graph * E);
//returna il number di nodi visitati
int DFS_visit_connect(graph * E, int v, int *color);

int main(){
	//creo grafo
	graph E;
	E.dim = readInt();
	E.go_pointer = (node*) malloc(E.dim*sizeof(node));
	//riempio il grafo
	fill_graph(&E);
	//guardo se e' connesso 
	printf("%d\n", DFS_connect(&E)==0);
}


int readInt(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("problemi nell'input : ");
		while(getchar());
	}
	return num;
}

void fill_graph(graph * E){
	
	for(size_t i = 0; i < E->dim; i++){//scorre tutti i nodi
		
		(E->go_pointer[i]).n_link_ext = readInt();
		E->go_pointer[i].link = malloc(((E->go_pointer[i]).n_link_ext)*sizeof(int));
		
		for (size_t j = 0; j < (E->go_pointer[i]).n_link_ext; j++){
			//getchar();
			E->go_pointer[i].link[j] = readInt();
		}
		
	}
	
}

int DFS_connect(graph * E){
	int *color = (int*) calloc(E->dim, sizeof(int));
	return E->dim - DFS_visit_connect(E, 0, color);
}
int DFS_visit_connect(graph * E, int v, int *color){
	color[v] = 1;
	int visitati = 0;
	//E->go_pointer[node].n_link_ext
	//equvale al numero di strade uscenti del nodo corrente
	node * corrPtr = &(E->go_pointer)[v];
	for (size_t i = 0; i < corrPtr->n_link_ext; i++){
		printf("cor = %d || visitati = %d\n", v, visitati);
		if(color[corrPtr->link[i]]==0){//non ancora visitato
			visitati = visitati + DFS_visit_connect(E, corrPtr->link[i], color);
		}
		
	}
	return visitati + 1;	
	//pensaci bene non funziona...
}
