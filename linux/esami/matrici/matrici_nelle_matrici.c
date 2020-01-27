#include <stdio.h>

int readint();
void fillmatrix(int row, int col , int matr[row][col]);
void print_xcol(int row, int col, int matr[row][col], _Bool is_to_print[col]);

_Bool find_A_in_B(int a_row, int a_col, int a[a_row][a_col], int b_row, int b_col, int b[b_row][b_col]);
_Bool* find_condition(int row, int col, int matr[row][col]);

int main(void){
	int a_row = readint();
	getchar();
	int a_col = readint();
	int a[a_row][a_col];
	fillmatrix(a_row, a_col, a);
	
	int b_row = readint();
	getchar();
	int b_col = readint();
	int b[b_row][b_col];
	fillmatrix(b_row, b_col, b);


	if(b_col*b_row >= a_col*a_row){
		if(find_A_in_B(a_row, a_col, a, b_row, b_col, b)){
			_Bool* to_print = find_condition(a_row, a_col, a);
		} else {
			printf("NO\n");
		}
	} else {
		if(find_A_in_B(b_row, b_col, b, a_row, a_col, a)){
			_Bool* to_print = find_condition(b_row, b_col, b);
		} else {
			printf("NO\n");
		}
	}
}

int readint(){
	int num;
	while (scanf("%d", &num)!=1){
		printf("NO : \n");
	}
	return num;
}

void fillmatrix(int row, int col , int matr[row][col]){
	for (size_t i = 0; i < row; i++){
		for (size_t j = 0; j < col; j++){
			matr[i][j] = readint();
		}	
	}
}