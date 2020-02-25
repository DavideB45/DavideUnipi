#include <stdio.h>

int my_strlen(char *s);
char* readStr(void); 

int main(void){
	char *s = readStr;
	scanf("%s", s);
	printf("%d\n", my_strlen(s));
}

int my_strlen(char *s){
	int i = 1;
	while(s++, *s)
		i++;
	return i;
}

char* readStr(void){
	char
}