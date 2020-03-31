#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
}punto;

int compare(const void *a, const void *b){
	punto p1 = *( (punto *) a);
	punto p2 = *( (punto *) b);
	if(p1.x != p2.x) return p1.x - p2.x;
	return p2.y - p1.y;
}

int readInt(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("inserire un numero : ");
		while(getchar() != '\n');
	}while(getchar() != '\n'){}
	return num;
}

void fillarrray(int dim, punto *array){
	for (size_t i = 0; i < dim; i++){
		scanf("%d %d", &(array[i].x), &(array[i].y));
	}
}

void printarray(int dim, punto *array){
	for (size_t i = 0; i < dim; i++){
		printf("%d %d\n", array[i].x, array[i].y);
	}
}

int main(void){
	int dim = readInt();
	punto array[dim];
	fillarrray(dim, array);
	qsort(array, dim, sizeof(punto), compare);
	printarray(dim, array);
	return 0;
}