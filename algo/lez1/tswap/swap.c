#include <stdio.h>

int readint(void);
void tswap(int *x, int *y, int *z);

int main(void){
	int x = readint();
	int y = readint();
	int z = readint();

	tswap(&x, &y, &z);

	printf("%d\n%d\n%d\n", x, y, z);
	return 0;
}

int readint(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("inserire un numero : ");
		while(getchar() != '\n');
	}
	return num;
}

void tswap(int *x, int *y, int *z){
	int temp = *z;
	*z = *y;
	*y = *x;
	*x = temp;
}