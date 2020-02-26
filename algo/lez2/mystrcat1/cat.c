#include <stdio.h>
#include <stdlib.h>

char* my_strcat1(char *s1, char *s2);
char *readStr();

int main(void){
	char *str1 = readStr();
	char *str2 = readStr();
	char *comb = my_strcat1(str1, str2);
	printf("%s\n", comb);
	free(comb);
	free(str2);
	free(str1);
	return 0;
}

char* my_strcat1(char *s1, char *s2){
	int dim_1 = -1;
	while(s1[++dim_1]);
	int dim_2 = -1;
	while(s2[++dim_2]);

	char *combined = calloc(dim_1 + dim_2 + 1, sizeof(char));
	for(size_t i = 0; i < dim_1; i++){
		combined[i] = s1[i];
	}
	for(size_t i = 0; i < dim_2; i++){
		combined[i + dim_1] = s2[i];
	}
	
	return combined;
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