#include <stdio.h>

int readInt(void);
void fillArray(int dim, int *array);
int n_common(int dim1, int *array1, int dim2, int *array2);

int main(void){
	int dim1 = readInt();
	int array1[dim1];
	fillArray(dim1, array1);
	int dim2 = readInt();
	int array2[dim2];
	fillArray(dim2, array2);
	printf("%d", n_common(dim1, array1, dim2, array2));
	return 0;
}

int readInt(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("numero non valido : ");
		while(getchar() != '\n');
	}
	return num;
}

void fillArray(int dim, int *array){
	for (size_t i = 0; i < dim; i++){
		array[i] = readInt();
	}
}

int n_common(int dim1, int *array1, int dim2, int *array2){
	int A_i = 0, B_i = 0, tot = 0;
	while(A_i < dim1 && B_i < dim2){
		if(array2[B_i] == array1[A_i]){
			tot++;
			B_i++;
			A_i++;
		} else {
			if(array1[A_i] < array2[B_i]){
				A_i++;
			} else {
				B_i++;
			}
		}
	}
	return tot;
}