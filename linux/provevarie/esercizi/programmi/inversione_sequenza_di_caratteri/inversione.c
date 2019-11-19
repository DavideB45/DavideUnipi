#include <stdio.h>

void inversione(void);

int main(void)
{
	char c ;
	printf("inserire sequenza che finisce con: ");
	scanf("%c", &c);
	inversione();
	printf("%c\n", c);
}

void inversione(void)
{
	char c;
	int a;
	c = getchar();
	if(c != '\n')
	{
		inversione();
		printf("%c", c);
	}

}
