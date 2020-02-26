#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned char *readStr(int *dim);

void merge_sort(int dim, unsigned char *parola);
void sort(int inizio, int fine, unsigned char *parola);
void merge(int inizio, int centro1, int centro2, int fine, unsigned char *parola);

int main(void){
	int dim_1, dim_2;
	unsigned char *str_1 = readStr(&dim_1);
	//printf("len = %d\nw = %s\n", dim_1, str_1);
	merge_sort(dim_1, str_1);
	//printf("len = %d\nw = %s\n", dim_1, str_1);
	unsigned char *str_2 = readStr(&dim_2);
	merge_sort(dim_2, str_2);

	printf("%d\n", strcmp(str_1, str_2) == 0);

}

unsigned char *readStr(int *dim){
	*dim = 5;
	int letters = 0;
	char read;
	unsigned char * parola = calloc(5, sizeof(unsigned char));
	while(read = getchar(), read != '\n'){
		if(*dim > letters){
			parola[letters] = read;
		} else {
			*dim = *dim*2;
			parola = realloc(parola, *dim);
			parola[letters] = read;
		}
		letters++;
	}
	parola[letters] = '\0';
	*dim = letters;
	return realloc(parola, letters + 1);
}

void merge_sort(int dim, unsigned char *parola){
	sort(0, dim - 1, parola);
}

void sort(int inizio, int fine, unsigned char *parola){
	if(fine - inizio >= 1){
		int centro1 = (fine + inizio)/2;
		int centro2 = centro1 + 1;
		sort(inizio, centro1, parola);
		sort(centro2, fine, parola);
		merge(inizio, centro1, centro2, fine, parola);
	}
}
void merge(int inizio, int centro1, int centro2, int fine, unsigned char *parola){
	int dx_i = centro2, sx_i = inizio, co_i = 0;
	unsigned char combined[fine - inizio + 1];
	while(sx_i <= centro1 && dx_i <= fine){
		if(parola[sx_i] < parola[dx_i]){
			combined[co_i++] = parola[sx_i++];
		} else {
			combined[co_i++] = parola[dx_i++];
		}
	}

	while(sx_i <= centro1){
		combined[co_i++] = parola[sx_i++];
	}
	while(dx_i <= fine){
		combined[co_i++] = parola[dx_i++];
	}
	co_i = 0;
	for (size_t i = inizio; i <= fine; i++){
		parola[i] = combined[co_i++];
	}	
}
