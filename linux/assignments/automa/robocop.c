#include <stdio.h>
#include <ctype.h>

char A(char X){
	if(isalpha(X))
		return 'A';
	if(X=='0')
		return 'B';
	return '1';
}
char B(char X){
	if(X=='1')
		return 'C';
	if(isdigit(X))
		return 'I';
	return '1';
}
char C(char X){
	if(X=='1')
		return 'D';
	if(isdigit(X))
		return 'M';
	return '1';
}
char D(char X){
	if(X=='1')
		return 'E';
	if(isdigit(X))
		return 'F';
	return '1';
}
char E(char X){
	if(X=='1')
		return 'E';
	if(isdigit(X))
		return 'G';
	return '1';
}
char F(char X){
	if(isdigit(X))
		return 'G';
	return '1';
}
char G(char X){
	if(isdigit(X))
		return 'H';
	return '1';
}
char H(char X){
	if(X=='\n')
		return 'H';
	return '1';
}
char I(char X){
	if(isdigit(X))
		return 'L';
	return '1';
}
char L(char X){
	if(isdigit(X))
		return 'H';
	return '1';
}
char M(char X){
	if(isdigit(X))
		return 'G';
	return '1';
}
int main(void){
	char c;
	char stato = 'A';
	char (*move[11])(char) ={A, B, C, D, E, F, G, H, I, L, M};
	c = getchar();
	do{
		stato = move[stato-'A'](c);
		c = getchar();
		printf("%c\t", stato);
	}while(stato != '1' && c!='\n');
	if((stato == 'E' || stato == 'F' || stato == 'G' || stato == 'H')&&c=='\n'){
		printf("stringa appartenente al linuaggio\n");
	}
	else{
		printf("stringa non appartenente al linguaggio\n");
	}
	return 0;
}