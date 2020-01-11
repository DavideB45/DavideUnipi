#include <stdio.h>

int main(void){
	int array[10];
	for(int i = 0; i<10; i++){
		scanf("%d", &array[i]);
	}
	for(int i = 9; i>= 0; i--){
		if(array[i]%2 == 0){
			printf("%d\n", array[i]/2);
		}
		else{
			printf("%d\n", array[i]);
		}
	}
	return 0;
}
