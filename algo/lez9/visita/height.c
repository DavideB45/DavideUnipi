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
int height(nodePtr corrPtr);
int max(int A, int B);

int main(void){
	int n_element = readint();
	nodePtr root = NULL;
	int new_val;
	for(size_t i = 0; i < n_element; i++){
		new_val = readint();
		insert(new_val, &root);
	}
	printf("%d\n", height(root));
	return 0;
}

int readint(void){
	int num;
	scanf("%d", &num);
	return num;
}

int max(int A, int B){
	return A > B ? A : B;
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


int height(nodePtr corrPtr){
	if(corrPtr == NULL)
		return 0;
	return max(height(corrPtr->left), height(corrPtr->right)) + 1;
}
