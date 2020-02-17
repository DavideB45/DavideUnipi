#include <stdio.h>

int readInt(void);
int sumDisp(int count, int corr, int tot);

int main(void){
	printf("%d", sumDisp( readInt() , 1 , 0));
	return 0;
}

int readInt(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("inserire un numero : ");
		while(getchar()!='\n');
	}
	return num;
}

int sumDisp(int count, int corr, int tot){
	if(count == 0){
		return tot;
	} else {
		return sumDisp(count - 1, corr + 2, (tot + corr) );
	}
}