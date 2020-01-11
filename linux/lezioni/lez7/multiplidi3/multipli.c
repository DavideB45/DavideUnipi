#include <stdio.h>

int controllo(int mat[][3], int r, int c){
	if(mat[r][c]%3==0){
		if(r == 3){
			return c;
		}
		else{
			return controllo(mat, ++r, c);
		}
	}
	else{
		if(c == -1){
			return c;
		}
		else{
			return controllo(mat, 0, --c);
		}
	}
}

int main(void){
	int mat[4][3];
	for(int i = 0; i<4; i++){
		for(int j = 0; j<3; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	printf("%d\n", controllo(mat, 0, 2));
	return 0;
}
