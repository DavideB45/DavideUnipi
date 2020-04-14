#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stringa{
	char *str;
	int count;
}stringa;

int readInt(void);
void fillArray(int dim, char *array[dim]);
void printArray(int dim, int top, char *array[dim]);
int comparestr(const void *A,const void *B);
int comparetot(const void *A,const void *B);
int lastcompare(const void *A,const void *B);

int main(void){
	int tot = readInt();
	int top = readInt();

	char *parole[tot];
	fillArray(tot, parole);

	qsort(parole, tot, sizeof(char*), comparestr);

	printArray(tot, top, parole);
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
		array[i]  = malloc(101*sizeof(char));
		scanf("%s", array[i]);
	}
}

int comparestr(const void *A,const void *B){
	char *APtr = *( (char**) A);
	char *BPtr = *( (char**) B);
	return strcmp(APtr, BPtr);
}

int comparetot(const void *A,const void *B){
	return ((stringa*) B)->count - ((stringa*) A)->count;
}

int lastcompare(const void *A,const void *B){
	return strcmp(((stringa*) A)->str , ((stringa*) B)->str);
}

void printArray(int dim, int top, char *array[dim]){
	stringa frequenza[dim];

	int i = 0, j = -1;
	while(i < dim){
		if(i > 0 && strcmp(array[i], (frequenza)[j].str) == 0){
			(frequenza)[j].count++;
		} else {
			j++;
			(frequenza)[j].count = 1;
			(frequenza)[j].str = array[i];
		}
		i++;
	}
	
	qsort(frequenza, j + 1, sizeof(stringa), comparetot);
	qsort(frequenza, top, sizeof(stringa), lastcompare);
	
	for (size_t i = 0; i < top; i++){
		printf("%s\n", (frequenza)[i].str);
	}
	
}

