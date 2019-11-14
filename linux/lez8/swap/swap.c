#include <stdio.h>

void swap(int *a, int *b, int *c);

int getint(void);

int main(void){
	int a, b, c;
	a = getint();
	b = getint();
	c = getint();
	swap(&a, &b, &c);
	printf("%d\n%d\n%d\n", a, b, c);
	return 0;
}

void swap(int *a, int *b, int *c){
	int temp;
	if(*a > *b){
		temp = *a;
		*a = *b;
		*b = temp;
	}
	if(*b > *c){
		temp = *b;
		*b = *c;
		*c = temp;
	}
	if(*a > *b){
		temp = *a;
		*a = *b;
		*b = temp;
	}
	return;
}

int getint(void){
	int i;
	scanf("%d", &i);
	/*while(scanf("%d", &i)!=1){
		scanf("%*[^\n]");
		scanf("%*c");
	}*/
	return i;
}
		
		
		
		
		
		
		
		
		
