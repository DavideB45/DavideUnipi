#include <stdio.h>
#include <stdlib.h>

int read_int(void);
void ceckPtr(void *Ptr);
int** insert(int row, int col, int **matr);
void multiply_matrices(int **A,int **B,int n,int m,int s, int C[][n]);
void print_matr(int row, int col, int C[row][col]);

int main(void){
	int **A = NULL;
	int **B = NULL;

	int N = read_int();
	int M = read_int();
	int S = read_int();
//int A[N][M]
//int B[M][S]
int C[N][S];
	A = insert(N, M, A);
//	print_matr(N, M, A);
	B = insert(M, S, B);
//	print_matr(M, S, B);

	multiply_matrices(A, B, N, M, S, C);

	//print_matr(N, S, C);
	return 0;
}

int read_int(void){
	int num;
	while(scanf("%d", &num)!=1){
		printf("Solo interi\n");
		scanf("%*[^\n]");
		scanf("%*c");
	}
	scanf("%*[^\n]");
	scanf("%*c");
//	scanf("%d", &num);
	return num;
}

void ceckPtr(void *Ptr){
	if(Ptr==NULL){
		printf("Memoria finita\n");
		exit(EXIT_FAILURE);
	}
}

int** insert(int row, int col, int **matr){
	matr = calloc(row, sizeof(int*));
	for (size_t i = 0; i < row; i++){
		matr[i] = calloc(col, sizeof(int));
	}
	for (size_t i = 0; i < row; i++){
		for(size_t j = 0; j < col; j++){
			*(*(matr + i) + j) = read_int();
		}
	}
	return matr;
}

void print_matr(int row, int col, int C[row][col]){
	for (size_t i = 0; i < row; i++){
		for (size_t j = 0; j < col; j++){
			printf("%3d", C[i][j]);
		}
		printf("\n");
	}
}

void multiply_matrices(int **A,int **B,int n,int m,int s, int C[][n]){
	int tot;
	for (size_t i = 0; i < n; i++){
		for (size_t j = 0; j < s; j++){
			tot = 0;
			for (size_t k = 0; k < m; k++){
				//k->m
				//i->n
				//j->s
				tot += A[i][k]*B[k][j];
			}
			printf("%d ", tot);
			//C[i][j] = tot;
		}
		printf("\n");
	}
}