#include <stdio.h>
int main(void){char *s = "stringa\n";char *temp = s;while(*s)printf("%c", *s++);s = temp;scanf("%6c", s);while(*s)printf("%c\\", *s++);return 0;}
/*
VALGRIND
	gcc -Wall -g prog.c
	valgrind ./a.out
*/