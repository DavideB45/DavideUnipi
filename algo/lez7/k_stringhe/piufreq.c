#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct wcount{
	char *stringa;
	int tot;
}wcount;

int readInt(void);
void fillarray(int dim, char **array);
void printarray(int dim, char **array){
	for (size_t i = 0; i < dim; i++){
		printf("%s\n", array[i]);
	}
	
}

int partition(int inizio, int fine, char **array);
void quickSotr(int inizio,int fine, char **array);

void find_top(int dim, int number, char **array);

int main(void){
	int n_string = readInt();
	int n_winners = readInt();

	char *array[n_string];
	fillarray(n_string, array);
	quickSotr(0, n_string - 1, array);
//	puts("");
	printarray(n_string, array);
	find_top(n_string, n_winners, array);

	return 0;
}

int readInt(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("ritenta : ");
		while(getchar() != '\n'){}
	} while(getchar() != '\n');
	return num;
}
void fillarray(int dim, char **array){
	for (size_t i = 0; i < dim; i++){
		array[i] = (char*) malloc(101*sizeof(char));
		scanf("%s", array[i]);
	}
}

int partition(int inizio, int fine, char **array){
	int piv = fine;
	int j = inizio - 1;
	char *temp;
	for (size_t i = inizio; i < fine; i++){
		if(strcmp(array[i], array[piv]) < 0){
			j++;
			temp = array[j];
			array[j] = array[i];
			array[i] = temp; 
		}
	}
	j++;
	temp = array[j];
	array[j] = array[piv];
	array[piv] = temp; 
	
	return j;
}
void quickSotr(int inizio,int fine, char **array){
	if(inizio < fine){
		int q = partition(inizio, fine, array);
		quickSotr(inizio, q-1, array);
		quickSotr(q+1, fine, array);
	}
}

void find_top(int dim, int number, char **array){
	wcount *vincitori = calloc(number, sizeof(wcount));;
	int tot = 1, j = number - 1;
	for (size_t i = 0; i < dim - 1; i++){
		while(i < dim && strcmp(array[i], array[i + 1]) == 0){
			tot++;
			i++;
		}
		while(j > 0 && vincitori[j].tot < tot){
	
			for (size_t i = 0; i < number; i++){
				printf("%s -> %d\n", vincitori[i].stringa, vincitori[i].tot);
			} printf("\n");

			vincitori[j].stringa = vincitori[j - 1].stringa;
			vincitori[j].tot = vincitori[j - 1].tot;
			j--;
		}
		if(tot < vincitori[j].tot){
			j++;
		}
		if(j < number){
			vincitori[j].tot = tot;
			vincitori[j].stringa = array[i];
		}
		j = number - 1;
		tot = 1;
	
	}
	printf("\n");
	for (size_t i = 0; i < number; i++){
		printf("%s -> %d\n", vincitori[i].stringa, vincitori[i].tot);
	}
	
}
