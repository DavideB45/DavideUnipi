#include <stdio.h>
#include <stdlib.h>

int readInt(void);
void fillArray(int dim, int *arr);
void invArray(int dim, int *arr);
void printArray(int dim, int *arr);

int main(){
	int dim = readInt();
	int arr[dim];
	fillArray(dim, arr);
	invArray(dim, arr);
	printArray(dim, arr);
	return 0;
}

int readInt(void){
	int num;
	while(scanf("%d", &num)!=1){
		printf("inserire un numero intero : ");
		while(getchar()!='\n');
	}
	return num;
}

void fillArray(int dim, int *arr){
	for(int i = 0; i < dim; i++){
		arr[i] = readInt();
	}
}

void invArray(int dim, int *arr){
	int temp;
	for(int i = 0; i < dim/2; i++){
		temp = arr[i];
		arr[i] = arr[dim-i-1];
		arr[dim-i-1] = temp;
	}
}

void printArray(int dim, int *arr){
	for(int i = 0; i < dim; i++){
		printf("%d\n", arr[i]);
	}
}