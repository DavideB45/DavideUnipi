#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

_Bool isparen(char);
_Bool isoprtr(char);
char* getstring(int lenght, char *string);

int main(void){
    int parentesi = 0;
    int uguaglianze = 0;
    char *array = getstring(0, array);
    int i = 0;
    printf("%s", array);
    while(array[i]!='\n'){
        if(array[i]=='('){parentesi++;}
        if(array[i]==')'){parentesi--;}
        if(parentesi<0){printf("errore di parentesi\n");return 0;}
        if(array[i]=='='){uguaglianze++;}
        if(uguaglianze==2){printf("troppe uguaglianze\n");return 0;}
        if(isalpha(array[i])&&isalpha(array[i+1])){printf("lettera+lettera\n");return 0;}
        if(isalpha(array[i])&&isalnum(array[i+1])){printf("lettera+lettera/numero\n");return 0;}
        if(isoprtr(array[i])&&isoprtr(array[i+1])){printf("operatori vicini is bad\n");return 0;}
        if(array[i]==')'&&isalnum(array[i+1])){printf("parentesi+qualcosa\n");return 0;}
        if(isalnum(array[i])&&array[i+1]=='('){printf("qualcosa+parentesi\n");return 0;}
        if(array[i]==')'&&array[i+1]=='('){printf("parentesi+parentesi\n");return 0;}
        i++;
    }
    if(parentesi!=0){printf("parentesi non chiuse\n");return 0;}
    else{printf("pare tutto ok\n");return 0;}
}

_Bool isoprtr(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='='){return 1;}
    else{return 0;}
}
_Bool isparen(char c){
    if(c==')' || c=='('){return 1;}
    else{return 0;}
}

char* getstring(int lenght, char *string){
	
    char c;
	c = getchar();
    while(c == ' '){c = getchar();}
	
    if(c=='\n'){
		string = calloc(lenght + 2, sizeof(char));
        string[lenght] = '\n';
        string[lenght+1] = '\0';
		return string;
	}
	
    string = getstring(lenght + 1, string);
    string[lenght] = c;
	return string;
}