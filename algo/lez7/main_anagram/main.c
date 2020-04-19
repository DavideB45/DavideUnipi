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
void merge(int inizio, char**array , char fine);
void sort(int sx, int centro1, int centro2,int fine, char **array);




int main(void){
	//char uno[20];
	//char due[20];
	//while(1){
	//	scanf("%s", uno);
	//	scanf("%s", due);
	//	printf("%+d\n", compare_anagrams(uno, due));
	//}
	
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
		array[i] = malloc(20*sizeof(char));
		if(array[i] == NULL){
			printf("qualcosa e' andato storto\n");
			exit(EXIT_FAILURE);
		}
		scanf("%s", array[i]);
	}
}
void printArray(int dim, char **array){
	for (size_t i = 0; i < dim; i++){
		printf("%s\n", array[i]);
	}
}

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////WORKING//////////////////////////////////////

int compare_anagrams(char *A, char *B){
	//counting elements difference between A and B
	int total_array[127];
	for (size_t i = 0; i < 127; i++){
		total_array[i] = 0;
	}
	
	int i = 0;
	//adding A
	while(A[i] != '\0'){
		total_array[(int)A[i++]]++;
	}
	i = 0;
	//subtracting B
	while(B[i] != '\0'){
		total_array[(int)B[i++]]--;
	}
	for(i = 0; i < 127; i++){
		if(total_array[i] < 0){
			return -1;//winner = B
		}
		if(total_array[i] > 0){
			return 1;//winnner = A
		}
	}
	return 0;//same anagram(hoping)
}

int compare_words(const void *A,const void *B){
	return strcmp(*(char**)A,*(char**) B);
}

void dual_sort(int dim, char **array){
	//prima le ordino per parola
	//poi con un ordinamento stabile per anagramma
	//qsort(array, dim, sizeof(char**), compare_words);
	merge(0, array, dim - 1);
}

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////////MERGESORT/////////////////////////////////////

void merge(int inizio, char**array , char fine){
	if(inizio - fine >= 1){
		int centro1 = (inizio + fine)/2;
		int centro2 = centro1 + 1;
		merge(inizio, array, centro1);
		merge(centro2, array, fine);
		sort(inizio, centro1, centro2, fine, array);
	}
}

void sort(int sx, int centro1, int centro2,int fine, char **array){
	int sx_i = sx;
	int dx_i = centro2;
	char *combined[fine - sx + 1];
	int c_i = 0;
	while(sx_i <= centro1 && dx_i <= fine){
		if(compare_anagrams(array[sx_i], array[dx_i]) < 0){
			combined[c_i++] = array[dx_i++];
		} else {
			combined[c_i++] = array[sx_i++];
		}
	}
	while(sx_i < centro2){
		combined[c_i++] = array[sx_i++];
	}
	while(dx_i <= fine){
		combined[c_i++] = array[dx_i++];
	}
	c_i = 0;
	for(size_t i = sx; i < fine; i++){
		array[i] = combined[c_i++];
	}
}