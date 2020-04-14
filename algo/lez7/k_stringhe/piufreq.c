#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stringa{
	char *str;
	int count;
}stringa;

int readInt(void);
void fillArray(int dim, char *array[dim]);
void printArray(int dim, char *array[dim]);
int compare(void *A, void *B);


int main(void){
	int tot = readInt();
	int top = readInt();

	char *parole[tot];
	fillArray(tot, parole);

	qsort(parole, tot, sizeof(char*), compare);


}


int readInt(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("metti un numero : ");
		while(getchar() != '\n');
	} while(getchar() != '\n');
	return num;
}

void fillArray(int dim, char *array[dim]){
	for(size_t i = 0; i < dim; i++){
		scanf("%s", array[i]);
	}
}

int compare(void *A, void *B){
	char *APtr = (char*) A;
	char *BPtr = (char*) B;
	return strcmp(APtr, BPtr);
}

void printArray(int dim, char *array[dim]);

