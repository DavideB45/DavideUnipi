#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readint(void);
void fillArray(int dim, char **array);
void printArray(int dim, char **array);

//############//
int compare_anagrams(char *A, char *B);
int compare_words(const void *A,const  void *B);
void dual_sort(int dim, char **array);
//MERGE SORT//
void merge_sort(int inizio, char**array , char fine);
void merge(int sx, int centro1, int centro2,int fine, char **array);




int main(void){
	int dim = readint();
	char *array[dim];
	fillArray(dim, array);
	dual_sort(dim, array);
	printArray(dim, array);
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////SUPPORT/////////////////////////////////////
int readint(void){
	int num;
	while(scanf("%d", & num) != 1){
		printf("errore nell'input : ");
		while(getchar() != '\n');
	}while(getchar() != '\n');
	return num;
}
void fillArray(int dim, char **array){
	for(size_t i = 0; i < dim; i++){
		array[i] = (char*) malloc(20*sizeof(char));
		if(array[i] == NULL){
			printf("qualcosa e' andato storto\n");
			exit(EXIT_FAILURE);
		}
		scanf("%s", array[i]);
	}
}
void printArray(int dim, char **array){
	for (size_t i = 0; i < dim; i++){
		if(i > 0 && compare_anagrams(array[i-1], array[i]) != 0){
			printf("\n");
		}
		printf("%s ", array[i]);
	}
}

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////WORKING//////////////////////////////////////

int compare_anagrams(char *A, char *B){
	int equal[128];
	for(size_t i = 0; i < 128; i++){
		equal[i] = 0;
	}
	int j = 0;
	while(A[j]){
		equal[(int)*A]--;
		j++;
	}
	j = 0;
	while(B[j]){
		equal[(int)*B]++;
		j++;
	}
	for(size_t i = 0; i < 128; i++){
		if(equal[i] != 0){
			return equal[i];
		}
	}
	return 0;
}

int compare_words(const void *A,const  void *B){
	return strcmp(*(char ** )A, *(char ** ) B);
}

void dual_sort(int dim, char **array){
	qsort(array, dim, sizeof(char*), compare_words);
	merge_sort(0, array, dim - 1);
}

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////////MERGESORT/////////////////////////////////////

void merge_sort(int inizio, char**array , char fine){
	if(fine - inizio > 1){
		int centro1 = (inizio + fine)/2;
		int centro2 = (centro1) + 1;
		merge_sort(inizio, array, centro1);
		merge_sort(centro2, array, fine);
		merge(inizio, centro1, centro2, fine, array);
	}
}

void merge(int sx, int centro1, int centro2,int fine, char **array){
	char *supp[fine - sx + 1];
	int s_i = 0, a_i = sx, b_i = centro2;
	while(a_i < centro2 && b_i <= fine){
		if(compare_anagrams(array[a_i], array[b_i]) <= 0){
			supp[s_i++] = array[a_i++];
		} else {
			supp[s_i++] = array[b_i++];
		}
	}

	while(a_i < centro2){
		supp[s_i++] = array[a_i++];
	}
	while(b_i <= fine){
		supp[s_i++] = array[b_i++];
	}

	s_i = 0;
	for(size_t i = sx; i <= fine; i++){
		array[i] = supp[s_i++];
	}
	
}
