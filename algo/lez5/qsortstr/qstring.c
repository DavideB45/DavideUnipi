#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a,const void *b){
	char *str1 = *( (char**) a);
	char *str2 = *( (char**) b);
	return -strcmp(str1, str2);
}

int read_int(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("metti un numero : ");
		while(getchar() != '\n');
	} while(getchar() != '\n');
	return num;
}

char *read_str(void){
	char string[101];
	scanf("%s", string);
	return strcpy(malloc((strlen(string) + 1)*sizeof(char)), string);
}

void fillarray(int dim, char *array[dim]){
	for (size_t i = 0; i < dim; i++){
		array[i] = read_str();
		//scanf("%s", array[i]);
	}
}

void printarray(int dim, char *array[dim]){
	for (size_t i = 0; i < dim; i++){
		printf("%s\n", array[i]);
	}
}


int main(void){
	int dim = read_int();
	char *array[dim];
	fillarray(dim, array);
	qsort(array, dim, sizeof(char*), compare);
	printarray(dim, array);
}