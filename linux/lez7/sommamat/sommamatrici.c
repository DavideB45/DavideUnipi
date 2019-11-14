#include <stdio.h>

int main(){
	int A[4][3], B[4][3], C[4][3];
	for(int i = 0; i<4; i++){
		for(int j = 0; j<3; j++){
			scanf("%d", &A[i][j]);
		}
	}
	for(int i = 0; i<4; i++){
		for(int j = 0; j<3; j++){
			scanf("%d", &B[i][j]);
		}
	}
	for(int i = 0; i<4; i++){
		for(int j = 0; j<3; j++){
			C[i][j]=A[i][j]+B[i][j];
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}


