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
int search(int value, nodePtr corrPtr, int depth);

int main(void){
	int n_element = readint();
	nodePtr root = NULL;
	int new_val;
	for(size_t i = 0; i < n_element; i++){
		new_val = readint();
		insert(new_val, &root);
	}

	int depth;
	while(new_val = readint(), new_val >= 0){
		depth = search(new_val, root, 0);
		if(depth > -1)
			printf("%d\n", depth);
		else
			printf("NO\n");
	}
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

int search(int value, nodePtr corrPtr, int depth){
	if(corrPtr == NULL){
		return -1;
	}
	if(corrPtr->value == value){
		return depth;
	}
	if(value < corrPtr->value)
		return search(value, corrPtr->left, depth + 1);
	return search(value, corrPtr->right, depth + 1);
}
