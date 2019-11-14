#include <stdio.h>

int main(void){
	int a = 0;
	int b = 1;
	int c, n;
	while(scanf("%d", &n)!=1 || n<0){
		printf("Inserire un intero positivo\n");
		scanf("%*[^\n]");
		scanf("%*c");
	}
	do{
		printf("%d\n", a);
		c = a + b;
		a = b;
		b = c;
	}while(n>=a);
	return 0;
}
		
