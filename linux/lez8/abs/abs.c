#include <stdio.h>

void differenza(float *a, float *b){
	*a = *a - *b;
	*b = *b - (*a + *b);
	return;
}

int main(void){
	float a, b;
	scanf("%f", &a);
	scanf("%*[^\n]");
	scanf("%*c");
	scanf("%f", &b);
	differenza(&a, &b);
	printf("%.2f\n", a);
	printf("%.2f\n", b);
	return 0;
}
