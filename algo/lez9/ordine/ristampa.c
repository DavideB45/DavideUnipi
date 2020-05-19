#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node * left;
	struct node * right;
}node;
typedef node * nodePtr;

int readint(void);
void insert(int value, nodePtr * corrPtr);
void print_order(nodePtr corrPtr);

int main(void){
	int n_element = readint();
	nodePtr root = NULL;
	int new_val;
	for(size_t i = 0; i < n_element; i++){
		new_val = readint();
		insert(new_val, &root);
	}
	print_order(root);
	return 0;
}

int readint(void){
	int num;
	scanf("%d", &num);
	return num;
}

void insert(int value, nodePtr * corrPtr){
	if(*corrPtr == NULL){
		*corrPtr = (nodePtr) calloc(1, sizeof(node));
		(*corrPtr)->value = value;
		return;
	} else {
		if(value < (*corrPtr)->value)
			insert(value, &((*corrPtr)->left));
		else
			insert(value, &((*corrPtr)->right));
	}
}

void print_order(nodePtr corrPtr){
	if(corrPtr == NULL)
		return;
	print_order(corrPtr->left);
	printf("%d\n", corrPtr->value);
	print_order(corrPtr->right);
}
