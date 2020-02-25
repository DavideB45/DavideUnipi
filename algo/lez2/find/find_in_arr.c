#include <stdio.h>
#define DIM 10

int* FindVal(int a[], int len, int val);
int readInt(void);
void fillArr(int dim, int *array);

int main(void){
	int array[10];
	fillArr(DIM, array);
	int to_find = readInt();
	if(FindVal(array, DIM, to_find)){
		printf("trovato\n");
	} else {
		printf("non trovato\n");
	}
	return 0;
}
//[0,1,2,3,4,5,6,7,8,9]
int* FindVal(int a[], int len, int val){
	int fine = len -1, mid, inizio = 0;
	while(mid = (fine + inizio)/2, 
		a[mid] != val && fine-inizio > 1){
		
//		printf("%d::%d::%d\n", inizio, mid, fine);
		
		if(a[mid] > val){
			fine = mid;
		} else {
			inizio = mid;
		}
		
//		printf("%d::%d::%d\n", inizio, mid, fine);
	}
//	printf("%d->%d\n", mid, a[mid]);
	if(a[mid] == val){
		return a + mid;
	}
	return NULL;
}

int readInt(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("numero non valido : ");
		while(getchar()!='\n');
	}
	return num;
}

void fillArr(int dim, int *array){
	for(int i = 0; i < dim; i++){
		array[i] = readInt();
	}
}