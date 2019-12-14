#include <stdio.h>
#include <stdlib.h>

void read(size_t row, size_t column, char matrix[row][column]);
void print(size_t row, size_t column, char matrix[row][column]);

int main(void){
	size_t row, column;
	printf("inserire righe e colonne : ");
	while(scanf("%lu %lu", &row, &column)!=2){
		printf("P.S. sono 2 numeri interi positivi : ");
		while(getchar()!='\n');
	}
	while(getchar()!='\n');
	char matrix[row][column];
	read(row, column, matrix);
	print(row, column, matrix);
}

void read(size_t row, size_t column, char matrix[row][column]){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			scanf("%c", &matrix[i][j]);
			while(getchar()!='\n');
		}
	}
}

void print(size_t row, size_t column, char matrix[row][column]){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			printf("%c\t", matrix[i][j]);
		}
		printf("\n\n");
	}
}