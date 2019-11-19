#include <stdio.h>

void base(int b);
void altezza(int h, int b);

int main(void){
	int b, h;
	while(scanf("%d", &h)!=1 || h<1){
		printf("h incorretto. Introdurre un intero maggiore di 0.");
		scanf("%*[^\n]");
		scanf("%*c");
	}
	while(scanf("%d", &b)!=1 || b<1){
		printf("l incorretto. Introdurre un intero maggiore di 0.");
		scanf("%*[^\n]");
		scanf("%*c");
	}
	base(b);
	altezza(h-2, b-2);
	base(b-1);
	return 0;
}

void base(int b){
	while(b>0){
		printf("*");
		b--;
	}
	printf("\n");
	return;
}

void altezza(int h, int b){
	int i;
	while(h>0){
		h--;
		i=0;
		printf("*");
		while(i<b){
			i++;
			printf(" ");
		}
		printf("*\n");
	}
	return;
}
