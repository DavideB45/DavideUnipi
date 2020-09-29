#include <stdio.h>
#include <stdlib.h>

typedef struct punto{
	int x;
	int y;
	int c;
}punto;
typedef punto * Array_di_punti; 

//creo un albero per contare il numero di colori
//poi non iserisco i duplicati
typedef struct node{
	int colorID;
	struct node * left;
	struct node * right;
}node;
typedef node * nodePtr;

int readint(void);
void read_points(int number, Array_di_punti points);
int color_count(Array_di_punti points, int tot_points, punto * start, punto * end);
_Bool is_between(punto * start,punto * end,punto * point);
_Bool add_if(nodePtr * root,int new_color);
void clean_tree(nodePtr corrptr);

int main(void){
	int N_points = readint();
	int N_interr = readint();
	Array_di_punti array = malloc(N_points*sizeof(node));
	read_points(N_points, array);
	
	punto start, end;
	for(size_t i = 0; i < N_interr; i++){
		scanf("%d %d %d %d", &(start.x), &(start.y), &(end.x), &(end.y));
		printf("%d\n", color_count(array, N_points, &start, &end));
	}
}

int readint(void){
	int num;
	scanf("%d", &num);
	return num;
}

void read_points(int number, Array_di_punti points){
	for(size_t i = 0; i < number; i++){
		points[i].x = readint();
		points[i].y = readint();
		points[i].c = readint();
	}
}

int color_count(Array_di_punti points,int tot_points, punto * start, punto * end){
	nodePtr rootPtr = NULL;
	
	//printf("\n\n");
	int dim_tree = 0;
	for(size_t i = 0; i < tot_points; i++){
		
		//printf("is = %d\n", is_between(start, end, points + i));
		//printf("s = %d %d e = %d %d |||| p = %d %d\n", start->x, start->y, end->x, end->y ,points[i].x, points[i].y);
		
		if(is_between(start, end, points + i)){
			if(add_if(&rootPtr, points[i].c)){
				//printf("%d %d %d\n", points[i].x, points[i].y, points[i].c);
				dim_tree++;
			}
		}
	}
	clean_tree(rootPtr);
	return dim_tree;
}

_Bool is_between(punto * start,punto * end,punto * point){
	//printf("  => %d %d %d %d\n", (start->x <= point->x) , (start->y >= point->y)  ,  (end->x >= point->x) , (end->y <= point->y));
	return ( (start->x <= point->x) && (start->y <= point->y) ) && ( (end->x >= point->x) && (end->y >= point->y) );
}

_Bool add_if(nodePtr * root,int new_color){
	if(*root==NULL){
		*root = calloc(1, sizeof(node));
		(*root)->colorID = new_color;
		return 1;
	}
	if((*root)->colorID == new_color){
		//printf("presente\n");
		return 0;
	} else {
		if((*root)->colorID < new_color){//se va aggiunto a sx
			if((*root)->left==NULL){//il colore non e' presente
				(*root)->left = calloc(1, sizeof(node));
				(*root)->left->colorID = new_color;
				return 1;
			} else {//devo continuare a cercare
				return add_if(&((*root)->left), new_color);
			}
		} else {
			if((*root)->right == NULL){//il colore non e' presente
				(*root)->right = calloc(1, sizeof(node));
				(*root)->right->colorID = new_color;
				return 1;
			} else {//devo continuare a cercare
				return add_if(&((*root)->right), new_color);
			}
		}
	}
}

void clean_tree(nodePtr corrptr){
	if(corrptr == NULL){
		return;
	} else {
		clean_tree(corrptr->left);
		clean_tree(corrptr->right);
		free(corrptr);
	}
}