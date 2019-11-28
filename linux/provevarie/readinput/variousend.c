#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readString(void){
	char tempsting[20];
	int len;
	scanf("%[^\n^E^ ]", tempsting);
	getchar();
	strcat(tempsting, "\0");
	int dim = 1;
	int i = 0;
	while(tempsting[i]!='\0'){
		dim++;
		i++;
	}
	return strcpy(calloc(dim, sizeof(char)), tempsting);
}

int main(void){
	char *string;
	int coso = 1;
	do{
		string = readString();
		printf("%s\n",string);
	}while(strcmp(string,"fine")!=0);
	return 0;
}
