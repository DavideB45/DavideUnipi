#include <stdio.h>
#include <stdlib.h>

char* product(char *str, int k);
char *readStr();
int readInt();

int main(void){
	char *str = readStr();
	int num = readInt();
	char *mult = product(str, num);
	printf("%s", mult);

	free(str);
	free(mult);
	return 0;
}

int readInt(){
	int num;
	while(scanf("%d", &num) != 1){
		while(getchar() != '\n');
	}
	return num;
}

char *readStr(){
	int dim = 5, pos = 0;
	char *comb = malloc(dim*sizeof(char));
	char read;
	while(read = getchar(), read != '\n'){
		if(pos < dim){
			comb[pos] = read;
		} else {
			dim *= 2;
			comb = realloc(comb, dim);
			comb[pos] = read;
		}
		pos++;
	}
	comb[pos] = '\0';
	return realloc(comb, pos);
}

char* product(char *str, int k){
	char *
}