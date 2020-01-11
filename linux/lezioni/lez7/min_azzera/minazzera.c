#include <stdio.h>

int main(void){
	int array[10], min;
	for(int i = 0; i<10; i++){
		scanf("%d", &array[i]);
		if(i==0){
			min = array[0];
		}
		if(min>array[i]){
			min = array[i];
		}
		if(i%2==1){
			array[i] = 0;
		}
	}
	for(int i = 0; i<10; i++){
		printf("%d\n", array[i]);
	}
	printf("%d\n", min);
	return 0;
}
