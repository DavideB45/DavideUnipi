#include <stdio.h>

int read_int(const char *string);
void count(int cell, int capacity, int atoms);

int main(void){
	
	int cell = read_int("Inserire il numero di stanze : \0");
	int capacity = read_int("Inserire la capienza delle celle : \0");
	int atoms = read_int("Inserire l'ultima cosa : \0");

	count(cell, capacity + 1, atoms);

	return 0;
}

int read_int(const char *string){
	int num;
	printf("%s", string);
	while (scanf("%d", &num)!=1 || num < 0){
		while(getchar()!='\n');
		printf("Ritenta : ");
	}
	return num;
}

void count(int cell, int capacity, int atoms){
	while(cell > 0){
		printf("%d ", (int)(atoms%capacity) );
		atoms = (atoms/capacity);
		cell--;
	} printf("\n");
	return;
}
