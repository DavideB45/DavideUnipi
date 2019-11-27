#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readString(void){
	char tempsting[20];
	scanf("%s", tempsting);
	printf("%ld	", sizeof(tempsting));
	int dim = 1;
	int i = 0;
	while(tempsting[i]!='\0'){
		dim++;
		i++;
	}
	printf("%ld	", dim*sizeof(char));
	return strcpy(calloc(dim, sizeof(char)), tempsting);
}

long unsigned int sizeartigianale(char string[]){
	return sizeof(char)*strlen(string);
}

int main(void){
	char *string;
	int coso = 1;
	do{
		string = readString();
		printf("%p %ld %s\n", string, sizeartigianale(string), string);
	}while(strcmp(string,"fine")!=0);
	return 0;
}
