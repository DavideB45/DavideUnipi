#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int readInt(void);
void fillarray(int dim, int *array);
void merge_sort(int dim, int *array);
void sort(int inizio, int fine, int *array);
void merge(int inizio, int centro1, int centro2, int fine, int *array);
void printarray(int dim, int *array);
int calcTime(int dim, int *array, int to_pic);


int main(){

	printf("Inserire il numero di test : [   ]\b\b\b");
	int test = readInt();
	int *array = NULL;
	for(int i = 0; i < test; i++){
	
		printf("Inserire il numero totale di studenti e di persone da prendere: ");
		int tot_stud = readInt();
		getchar();//salta lo spazio
		int to_pic = readInt();
		
		array = calloc(tot_stud, sizeof(int));
		fillarray(tot_stud, array);
		merge_sort(tot_stud, array);
		printarray(tot_stud, array);
		int min_t = calcTime(tot_stud, array, to_pic);
		printf("# %d : %d\n", i+1, min_t);
		free(array);
		
	}
	return 0;
}

int readInt(void){
	int num;
	while(scanf("%d", &num)!=1 || num < 0){
		printf("Numero non accettabile : ");
		scanf("%*[\n]");
		scanf("%*c");
	}
	return num;
}

void fillarray(int dim, int *array){
	for(int i = 0; i < dim; i++){
		printf("Inserire potenza del giovanotto numero %d : ", i+1);
		array[i] = readInt();
		getchar();//salta lo spazio;
	}
}

void printarray(int dim, int *array){
	for(int i = 0; i < dim; i++)
		printf("%d::", array[i]);
	printf("fine\n");
}

int calcTime(int dim, int *array, int to_pic){
	int min = INT_MAX;
	int sum;
	
	for(int i = 0; i < dim - to_pic + 1; i++){
		sum = 0;
		
		for(int j = 0; j < to_pic - 1; j++){
			sum += (array[(i + to_pic - 1)] - array[(i + j)]); 
		}
		if(sum < min){
			min = sum;
		}
		
	}
	return min;
}





void merge_sort(int dim, int *array){
	sort(0, dim - 1, array);
}

void sort(int inizio, int fine, int *array){
	if(fine - inizio > 0){
		int centro1 = (fine + inizio)/2;
		int centro2 = centro1 + 1;
		sort(inizio, centro1, array);
		sort(centro2, fine, array);
		merge(inizio, centro1, centro2, fine, array);
	}
}

void merge(int inizio, int centro1, int centro2, int fine, int *array){
	int sxI = inizio, dxI = centro2, cI = 0;
	int comb[fine-inizio+1];
	while(sxI <= centro1 && dxI <= fine){
		if(array[sxI] < array[dxI]){
			comb[cI++] = array[sxI++];
		} else {
			comb[cI++] = array[dxI++];
		}
	}
	
	while(sxI <= centro1){
		comb[cI++] = array[sxI++];
	}
	while(dxI <= fine){
		comb[cI++] = array[dxI++];
	}
	
	cI = 0;
	for(int i = inizio; i <= fine; i++){
		array[i] = comb[cI++];
	}
}


















