#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int key;
	struct node *nextPtr;
}node;
typedef node* nodePtr;

typedef struct dictionary{
	nodePtr* array;
	int a;
	int b;
	int dim;
}dictionary;

int readint(void);//legge interi
void insertlist(int val, nodePtr *headPtr);//inserisce in testa
dictionary createdict(int dim, int a, int b);//restitutisce un puntatore
void filldictionary(dictionary *dict);//mette cose e intanto conta
int function(int key, dictionary * dict);//funzione hash
int max_len(dictionary *dict);//ritorna la lunghezza della lista piu' lunga

int main(void){
	int n = readint();
	int a = readint();
	int b = readint();
	dictionary dict = createdict(n, a, b);
	filldictionary(&dict);
}

int readint(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("errore nell'input : ");
		while(getchar() != '\n');
	}
	return num;
}

void insertlist(int val, nodePtr *headPtr){
	nodePtr newPtr = (nodePtr) malloc(sizeof(node));
	newPtr->key = val;
	newPtr->nextPtr = *headPtr;
	*headPtr = newPtr;
}

dictionary createdict(int dim, int a, int b){
	dictionary *paolo = (dictionary*) malloc(sizeof(dictionary));
	paolo->a = a;
	paolo->b = b;
	dim = dim*2;
	paolo->dim = dim;
	paolo->array = (nodePtr*) calloc(dim, sizeof(nodePtr*));
	return *paolo;
}

int function(int key, dictionary * dict){
	return ( (dict->a*key) % 999149 % dict->dim );
}

void filldictionary(dictionary *dict){
	int collision = 0;
	int to_read = (dict->dim)/2;
	int number;
	int position;
	//printf("%d\n", to_read);
	for(int i = 0; i < to_read; i++){
		number = readint();
		position = function(number, dict);
	//	printf("pos = %d   val = %p\n", position, dict->array[position]);
		if(dict->array[position] != NULL)
			collision++;
		insertlist(number, &(dict->array[position]));
	//	printf("pos = %d   val = %p\n", position, dict->array[position]);
	}
	printf("%d\n", max_len(dict));
	printf("%d\n", collision);
}

int max_len(dictionary *dict){
	int max = 0, cur_list;
	nodePtr corrPtr;
	for(int i = 0; i < dict->dim; i++){
		corrPtr = dict->array[i];
		cur_list = 0;
		while(corrPtr != NULL){
			corrPtr = corrPtr->nextPtr;
			cur_list++;
		}
		if(cur_list > max){
			max = cur_list;
		}
	}
	return max;
}