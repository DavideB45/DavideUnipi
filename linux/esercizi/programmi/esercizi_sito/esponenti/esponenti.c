#include <stdio.h>
#include <math.h>

float read_positive_float(void);

int read_positive_int(void);

float sum_pow(float x, int n, float res);

int main(void){
	float x;
	int n;
	n = read_positive_int();
	x = read_positive_float();
	printf("%.2f\n", sum_pow(x, n, 0));
	return 0;
}

float read_positive_float(void){
	float x;
	while(scanf("%f", &x)!=1 || x<0){
		scanf("%*[^\n]");
		scanf("%*c");
		printf("Inserici un numero reale positivo.\n");
	}
	return x;
}

int read_positive_int(void){
	int n;
	while(scanf("%d", &n)!=1 || n<0){
		scanf("%*[^\n]");
		scanf("%*c");
		printf("Inserici un intero positivo.\n");
	}
	return n;
}

float sum_pow(float x, int n, float res){
	if(n<0){
		return res;
	}
	else{
		return sum_pow(x, n - 1, res + pow((double)x, (double)n));
	}
}








