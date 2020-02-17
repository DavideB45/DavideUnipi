#include <stdio.h>
int main(void){
	int num, sum = 0;
	while(scanf("%d", &num), num != 0)
		sum += num; 
	printf("%d\n", sum);
	return 0;
}
