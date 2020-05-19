#include <stdio.h>
#include <stdlib.h>

///////////////////////////QUEUE/////////////////////////////////
/////////////////////////////////////////////////////////////////
typedef struct queue{
	int *elements;
	int head;
	int tail;
	int size;
}queue;

void init_queue(queue * Q, int size) {
	Q->elements = (int *) malloc(sizeof(int) * size);
	Q->size = size;
	Q->head = 0;
	Q->tail = 0;
}

void enqueue(queue * Q, int element){
	Q->elements[Q->tail++] = element;
}

int dequeue(queue * Q){
	return Q->elements[Q->head++];
}

void deinit_queue(queue * Q) {
	free(Q->elements);
	Q->size = 0;
	Q->head = Q->tail = 0;
}

//////////////////////GESTIONE GRAFO/////////////////////////////
/////////////////////////////////////////////////////////////////
typedef struct nodo{
	int *edges;
	int tot_nodi;
}link;
typedef link* linkArray;

linkArray* create_graph(int dim);

int BFS(int start, int arrive, linkArray* E, int dim);

////////////////////////////SUPPORT///////////////////////////////
/////////////////////////////////////////////////////////////////
int readInt(void);
void fillarray(int dim, int *array);

int main(void){
	int dim = readInt();
	linkArray* E = NULL;
	E = create_graph(dim);

	/*for (size_t i = 0; i < dim; i++){
		printf("%d ", E[i]->tot_nodi);
	}puts("");*/
	

	int n_q = readInt();
	int from, to;
	for (size_t i = 0; i < n_q; i++){
		scanf("%d %d", &from, &to);
		printf("%d\n", BFS(from, to, E, dim));
	}
	return 0;
}

linkArray *create_graph(int dim){
	linkArray *E = malloc(dim*sizeof(link));
	int n_link;
	for (size_t i = 0; i < dim; i++){
		n_link = readInt();
		E[i] = malloc(sizeof(link));
		E[i]->edges = malloc(n_link*sizeof(int));
		E[i]->tot_nodi = n_link;
		fillarray(n_link, E[i]->edges);
	}
	return E;
}

int BFS(int start, int arrive, linkArray* E, int dim){
	if(start == arrive)
		return 0;
	
	int *distance = (int*) malloc(dim*sizeof(int));
	for(size_t i = 0; i < dim; i++){
		distance[i] = -1;
	}
	distance[start] = 0;
	
	queue Q;
	init_queue(&Q, dim);
	enqueue(&Q, start);
	int corr_node;
	/*for (size_t i = 0; i < dim; i++){
		printf("%ld  :  ", i);
		for (size_t j = 0; j < E[i]->tot_nodi; j++){
			printf("%d ", E[i]->edges[j]);
		}puts("");
	}*/
	
	while(Q.head != Q.tail){
		/*printf("H = %d   T = %d   SEQ = ",Q.head, Q.tail);
		for (size_t i = Q.head; i < Q.tail; i++){
			printf("%d ", Q.elements[i]);
		}puts("");*/
		
		corr_node = dequeue(&Q);
		for(size_t i = 0; i < E[corr_node]->tot_nodi; i++){
			//printf("Dp = %d   Da = %d\nNp = %d   Na = %d\n", distance[corr_node], distance[E[corr_node]->edges[i]], corr_node, E[corr_node]->edges[i]);
			
			if(distance[E[corr_node]->edges[i]] == -1){

				enqueue(&Q, E[corr_node]->edges[i]);
				distance[E[corr_node]->edges[i]] = distance[corr_node] + 1;
				
				if(E[corr_node]->edges[i] == arrive){
					distance[arrive]  = distance[corr_node] + 1;
					break;
				}	
			}
		}
	}

	int result = distance[arrive];
	free(distance);
	deinit_queue(&Q);
	return result;
}


int readInt(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("errore nell' input : ");
		while(getchar() != '\n');
	}
	return num;
}

void fillarray(int dim, int *array){
	for (size_t i = 0; i < dim; i++){
		scanf("%d", &(array[i]));
	}	
}
