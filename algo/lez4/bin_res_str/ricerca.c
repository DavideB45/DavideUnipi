#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readInt(void);
char* readstr(void);
void fillArray(int dim, char *array[dim]);
int research(int dim, char *array[dim]);

int main(void){
	int dim = readInt();
	char *array[dim];
	fillArray(dim, array);
	while(0 != readInt()){
		printf("%d\n", research(dim, array));
	}
}


int readInt(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("inserire un numero migliore : ");
		while(getchar() != '\n');
	}
	while(getchar() != '\n'){}
	return num;
}

char* readstr(void){
	int dim = 5;
	int letters = 0;
	char read;
	unsigned char * parola = calloc(5, sizeof(unsigned char));
	while(read = getchar(), read != '\n'){
		if(dim > letters){
			parola[letters] = read;
		} else {
			dim = dim*2;
			parola = realloc(parola, dim);
			parola[letters] = read;
		}
		letters++;
	}
	parola[letters] = '\0';
	return realloc(parola, letters + 1);
}

void fillArray(int dim, char *array[dim]){
	for (size_t i = 0; i < dim; i++){
		array[i] = readstr();
		//printf("strlen = %d, str = %s\n", strlen(array[i]), array[i]);
	}
	
}


int research(int dim, char *array[dim]){
	int inizio = 0;
	int fine = dim;
	int mid;
	char *str = readstr();
	while(mid = (fine + inizio)/2, strcmp(array[mid], str)!=0 && fine - inizio >= 1){
		//printf("%d  %d %d\n", inizio, mid,fine);
		if(strcmp(array[mid], str) < 0){
			inizio = mid + 1;
		} else {
			fine = mid - 1;
		}
		//printf("%d  %d\n", inizio, fine);
	}
	if(strcmp(array[mid], str) != 0){
		free(str);
		return -1;
	}
	free(str);
	return mid;
}
