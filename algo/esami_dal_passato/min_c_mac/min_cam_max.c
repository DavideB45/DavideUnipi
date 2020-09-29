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
void min_max_path(nodePtr corrPtr, int *min, int *sum);


int main(void){
	int n_element = readint();
	nodePtr root = NULL;
	int new_val;
	for(size_t i = 0; i < n_element; i++){
		new_val = readint();
		insert(new_val, &root);
	}

	int min, sum;
	min_max_path(root, &min, &sum);
	printf("%d\n", min);


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

void min_max_path(nodePtr corrPtr, int *min, int *sum){
	if(corrPtr==NULL){
		*min = 0;
		*sum = 0;
		return;
	} else {
		int lmin, lsum;
		min_max_path(corrPtr->left, &lmin, &lsum);
		int rmin, rsum;
		min_max_path(corrPtr->right, &rmin, &rsum);
		if(rsum > lsum){
			*sum = rsum + corrPtr->value;
			*min = corrPtr->value;
		} else {
			*sum = lsum + corrPtr->value;
			*min = corrPtr->left == NULL ? corrPtr->value : lmin;
		}
	}
}