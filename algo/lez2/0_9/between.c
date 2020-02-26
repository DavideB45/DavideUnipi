#include <stdio.h>

int readint(void);

int main(void){
	int numeri[10] = {0};
	int read;
	while(read = readint(), read >= 0){
		if(read <= 9)
			numeri[read]++;
	}
	for (size_t i = 0; i < 10; i++){
		printf("%d\n", numeri[i]);
	}
	return 0;
}

int readint(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("nun valido : ");
		while(getchar() != '\n');
	}
	return  num;
}