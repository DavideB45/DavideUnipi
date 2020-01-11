#include <stdio.h>
#define DIM 7

//trova primo e ultimo pari
void primoultimopari(int arr[], int dim, int *primaocc, int *ultimaocc);

void riempiarray(int arr[], size_t dim);

int getint(void);

int main(void){
	int arr[DIM];
	int first = -1, last = -1;
	riempiarray(arr, DIM);
	primoultimopari(arr, DIM, &first, &last);
	//nulla o uno solo
	if(first == -1){
		printf("%d\n", first);
	}
	else{
		printf("%d %d\n");
	}
	return;
}

void riempiarray(int arr[], size_t dim){
	for(int i = 0; i < dim; i++){
		*(arr + i) = getint();
	}
}

int getint(void){
	int num;
	while(scanf("%d", &int)!=1){
		scanf("%*[^\n]");
		scanf("%*c");
	}
	return num;
}

void primoultimopari(int arr[], int dim, int *primaocc, int *ultimaocc){
	int i = 0;
	do{
		if(*primaocc==-1 && *(arr + i)%2==0){
			*primaocc = i;
		}
		if(*ultimaocc==-1 && *(arr + dim - i)%2==0){
			*ultimaocc = dim - i;
		}
		i++;
	}while((*primaocc == -1 || *ultimaocc == -1) && i<dim);
	return;
}















