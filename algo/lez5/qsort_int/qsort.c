#include <stdio.h>
#include <stdlib.h>

int compare(const void *A,const void* B){
	int val1, val2, mod1, mod2;
	val1 = *( (int *) A);
	val2 = *( (int *) B);
	mod1 = abs(val1 % 2);
	mod2 = abs(val2 % 2);
	if(mod1 != mod2) return mod1 - mod2;
	if(mod1 == 0) return val1 - val2;
	else return val2 - val1;
}

int readInt(void){
	int num;
	scanf("%d", &num);
	return num;
}

void fillarray(int dim, int array[dim]){
	for (size_t i = 0; i < dim; i++){
		array[i] = readInt();
	}
}

void printarray(int dim, int array[dim]){
	for (size_t i = 0; i < dim; i++){
		printf("%d\n",array[i]);
	}
}


int main(void){
	int dim = readInt();
	int array[dim];
	fillarray(dim, array);
	qsort(array, dim, sizeof(int), compare);
	printarray(dim, array);
}