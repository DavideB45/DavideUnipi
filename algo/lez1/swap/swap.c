#include <stdio.h>

int readInt(void);
void swap(int *a, int *b);

int main(void){
	int a = readInt();
	int b = readInt();
	swap(&a, &b);
	printf("%d\n%d\n", a, b);
	return 0;
}

int readInt(void){
	int num = 0;
	scanf("%d", &num);
	return num;
}

void swap(int *a, int *b){
	int temp = *b;
	*b = *a;
	*a = temp;
}