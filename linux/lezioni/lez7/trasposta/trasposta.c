#include <stdio.h>

void moltiplica(int y, int A[][y], int x){
	int tot = 0;
	int max = (x>y) ? x : y;
	int min = (x<y) ? x : y;
	
	for(int i = 0; i<x; i++){
		for(int j = 0; j<x; j++){
			tot = 0;
			for(int t = 0; t<y; t++){
				tot += A[i][t]*A[j][t];
			}
			printf("%d ", tot);
		}
		printf("\n");
	}
	return;
}

void PrintMatrix(int r, int c, int A[][c]){
	for(int i = 0; i<r; i++){
		for(int j = 0; j<c; j++){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int x, y;
	scanf("%d", &x);
	scanf("%d", &y);
	int A[x][y];
	for(int i = 0; i<x; i++){
		for(int j = 0; j<y; j++){
			scanf("%d", &A[i][j]);
		}
	}
	//PrintMatrix(x, y, A);
	moltiplica(y, A, x);
	return 0;
}
