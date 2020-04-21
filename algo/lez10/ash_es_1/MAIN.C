#include <stdio.h>
#include <stdio.h>

typedef struct node{
	int key;
	struct node *nextPtr;
}node;
typedef node* nodePtr;

typedef struct dictionary{
	nodePtr array;
	int a;
	int b;
}dictionary;

int readint(void);
void insertlist(int val, nodePtr *headPtr);
int findlist(int key, nodePtr corrptr);
int countlist(nodePtr corrPtr);
dictionary createdict(int dim, int a, int b);
void filldictionary(dictionary *dict);
void dictstats(dictionary dict);

int main(void){
	int n = readint();
	int a = readint();
	int b = readint();
	dictionary dict = createdict(n*2, a, b);
	filldictionary(&dict);
	dictstats(dict);
}

int readint(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("errore nell'input : ");
		while(getchar() != '\n');
	}while(getchar() != '\n');
	return num;
}
void insertlist(int val, nodePtr *headPtr){
	if(findlist(val, *headPtr) == 1)
		return;
	nodePtr new = (nodePtr) malloc(sizeof(node));
	new->nextPtr = *headPtr;
	*headPtr = new;
	new->key = val;
}
int countlist(nodePtr corrPtr){
	if(!corrPtr)
		return 0;
	else
		return 1 + countlist(corrPtr->nextPtr);
}


dictionary createdict(int dim, int a, int b);
void filldictionary(dictionary *dict);
void dictstats(dictionary dict);
