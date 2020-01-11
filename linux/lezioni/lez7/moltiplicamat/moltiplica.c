#include <stdio.h>

void moltiplica(int A[][2], int B[][3], int C[][3]){
	int tot = 0;
	for(int i = 0; i<4; i++){
		for(int j = 0; j<3; j++){
			tot = 0;
			for(int t = 0; t<2; t++){
				tot += A[i][t]*B[t][j];
			}
			C[i][j]=tot;
		}
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

int main (){
	static int A[4][2];
	static int B[2][3];
	static int C[4][3];
	
	// populate mat a
	for(int i = 0; i<4; i++){
		for(int j = 0; j<2; j++){
			scanf("%d", &A[i][j]);
			scanf("%*[^\n]");
			scanf("%*c");
		}
	}
	

	
	for(int i = 0; i<2; i++){
		for(int j = 0; j<3; j++){
			scanf("%d", &B[i][j]);
		}
	}
	

	
	moltiplica(A, B, C);
	/*
	for(int i = 0; i<4; i++){
		for(int j = 0; j<3; j++){
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}*/
	
	PrintMatrix(4, 3, C);
	
	return 0;
}
