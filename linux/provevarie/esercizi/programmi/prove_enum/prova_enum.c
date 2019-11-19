#include <stdio.h>

int main(void)
{
	enum numeri_int {A = 1, B = 2, C = 3};
	enum numeri_int x;
	enum numeri_int y;
	
	printf("inserisci A B C : ");

	scanf("%[A,B,C]", &x);
	scanf("%*[^\n]");

	scanf("%[A,B,C]", &y);
	scanf("%*c");

	printf("%f", (float)x/y);
	
}


