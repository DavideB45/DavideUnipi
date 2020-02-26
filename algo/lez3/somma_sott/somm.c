#include <stdio.h>
#include <stdlib.h>

int readInt(void);
void fill_array(int dim, int *array);
int max_sum(int dim, int *array);


int main(void){
	int dim = readInt();
	int *array = malloc(dim*sizeof(int));
	fill_array(dim, array);
	printf("%d\n", max_sum(dim, array));
	return 0;
}

int readInt(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("input errato : ");
		while(getchar() != '\n');
	}
	return num;
}

void fill_array(int dim, int *array){
	for (size_t i = 0; i < dim; i++)
		array[i] = readInt();
}

int max_sum(int dim, int *array){
	int max = 0;
	int sum = 0;
	for (int i = 0; i < dim; i++){
		sum += array[i];
		if(sum < 0){
			sum = 0;
		}
		if(max < sum){
			max = sum;
		}
	}
	return max;
}
