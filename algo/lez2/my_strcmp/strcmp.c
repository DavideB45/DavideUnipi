#include <stdio.h>
#define DIM 100

int my_strcmp(char* s1, char* s2);

int main(void){
	char s1[DIM], s2[DIM];
	scanf("%s", s1);
	scanf("%s", s2);
	printf("%+d\n", my_strcmp(s1, s2));
	return 0;
}

int my_strcmp(char* s1, char* s2){
	int s1_i = -1, s2_i = -1;
	while((s1[++s1_i] == s2[++s2_i]) && (s1[s1_i]!='\0' && s2[s2_i]!='\0'));
	if(s1[s1_i] > s2[s2_i])
		return 1;
	if(s1[s1_i] < s2[s2_i])
		return -1;
	return 0;
}