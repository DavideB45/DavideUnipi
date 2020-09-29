#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 101

typedef struct nodo{
	int love_value;
	char name[MAXLEN];
	struct nodo * nextPtr;
}object;

typedef struct table{
	int dim;
	int fillness;
	object ** array;
}table;

int readInt(void);
int ash_fun(char * parola, int mod);
int compare(const void* A, const void * B);
table * create_table(int num_insert);
object** array_from_table(table * T);
void print_most_loved(int num, object** array);

int main(void){
	int tot_read = readInt();
	table * T = create_table(tot_read);

	int n_obj = T->fillness;
	if(n_obj > 15) n_obj = 15;

	object** array = array_from_table(T);
	print_most_loved(n_obj, array);
}

int readInt(void){
	int num;
	while(scanf("%d", &num) != 1){
		printf("qualcosa e' andato storto : ");
		while(getchar() != '\n');
	}
	return num;
}

int ash_fun(char * parola,int mod){
	int tot = 0;
	while(*parola != '\0'){
		tot = tot + *parola;
		parola++;
	}
	return tot % mod;
}

int compare(const void* A, const void * B){
	object * uno = *(object **) A;
	object * due = *(object **) B;
	if(uno->love_value != due->love_value){
		return -(uno->love_value - due->love_value);
	}
	return strcmp(uno->name, due->name);
}

table * create_table(int num_insert){
	table * T = calloc(1, sizeof(table));
	T->array = calloc(num_insert*2, sizeof(object*));
	T->dim = num_insert*2;
	object* newobject;
	int hash_value;
	object *corrPtr;
	for(size_t i = 0; i < num_insert; i++){
		newobject = calloc(1, sizeof(object));
		scanf("%s", newobject->name);
		newobject->love_value = readInt();

		hash_value = ash_fun(newobject->name, T->dim);
		if(T->array[hash_value]==NULL){
			T->array[hash_value] = newobject;
			T->fillness++;
		} else {
			corrPtr = T->array[hash_value];
			while(corrPtr != NULL && strcmp(corrPtr->name, newobject->name) != 0){
				corrPtr = corrPtr->nextPtr;
			}
			if(corrPtr == NULL){
				T->fillness++;
				newobject->nextPtr = T->array[hash_value];
				T->array[hash_value] = newobject;
			} else {
				if(corrPtr->love_value < newobject->love_value)
					corrPtr->love_value = newobject->love_value;
				free(newobject);
			}
		}
	}
	return T;
}

object** array_from_table(table * T){
	object * corrPtr;
	object** array = malloc((T->fillness)*sizeof(object*));
	int j = 0;
	for(size_t i = 0; i < T->dim; i++){
		if(T->array[i] != NULL){
			corrPtr = T->array[i];
			while(corrPtr != NULL){
				array[j++] = corrPtr;
				corrPtr = corrPtr->nextPtr;
			}
		}
	}
	/*for (size_t i = 0; i < T->fillness; i++){
		printf("%20s\t%d\n", array[i]->name, array[i]->love_value);
	}*/
	
	qsort(array, T->fillness, sizeof(object*), compare);
	return array;
}

void print_most_loved(int num, object** array){
	for (size_t i = 0; i < num; i++){
		printf("%s\n", array[i]->name );
	}
}
