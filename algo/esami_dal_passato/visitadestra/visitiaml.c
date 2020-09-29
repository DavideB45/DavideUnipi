#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	_Bool print;
	struct node * left;
	struct node * right;
}node;
typedef node * nodePtr;

int readint(void);
void insert(int value, nodePtr * corrPtr);
void visitamistica(nodePtr root,int * left,int *right);

void in_order(nodePtr root){
	if (root == NULL){
		return;
	}
	in_order(root->left);
	if(root->print){
		printf("%d\n", root->value);
	}
	in_order(root->right);
	
	
}

int main(void){
	int n_element = readint();
	nodePtr root = NULL;
	int new_val;
	for(size_t i = 0; i < n_element; i++){
		new_val = readint();
		insert(new_val, &root);
	}

	int lnode, rnode;
	visitamistica(root, &lnode, &rnode);
	in_order(root);

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

void visitamistica(nodePtr root,int * left,int *right){
	if(root == NULL){
		*left = *right = 0;
		return;
	}
	int lnode, rnode, t;
	
	visitamistica(root->left, &lnode, &t);
	visitamistica(root->right, &t, &rnode);
	
	if(rnode < lnode){
		root->print = 1;
	}
	*left = lnode + 1;
	*right = rnode + 1;
	return;
}
