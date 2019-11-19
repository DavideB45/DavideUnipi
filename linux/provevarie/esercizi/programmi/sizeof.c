#include <stdio.h>

int main(void)
{
	int x;
	while(scanf("%d", &x) != 1)
	{
		scanf("%*[^\n]");
		scanf("%*c");
	}
	printf("%d", sizeof(int)*x);
	return 0;
}
