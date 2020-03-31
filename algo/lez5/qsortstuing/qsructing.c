#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char string[101];
	int len;
}word;

int compare(const void *a,const void *b){
	word str1 = *( (word*) a);
	word str2 = *( (word*) b);
	if(str1.len != str2.len) return str1.len - str2.len;
	return strcmp(str1.string, str2.string);
}

int readInt(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("inserire un numero : ");
		while(getchar() != '\n');
	}while(getchar() != '\n'){}
	return num;
}

void fillarray(int dim, word *array){
	for (size_t i = 0; i < dim; i++){
		scanf("%s", array[i].string);
		array[i].len = strlen(array[i].string);
	}
}

void printarray(int dim, word array[dim]){
	for (size_t i = 0; i < dim; i++){
		printf("%s\n", array[i].string);
	}
}

int main(void){
	int dim = readInt();
	word array[dim];
	fillarray(dim, array);
	qsort(array, dim, sizeof(word), compare);
	printarray(dim, array);
}