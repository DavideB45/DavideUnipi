#include <stdio.h>
int verifica_condizione(int array[], int dim){
	for(int i = 1; i<dim-1; i++){
	    if( array[i] == array[i+1]-array[i-1]){
	        return i;
	    }
	}
    return -1;
}
int main(void){
	int array[10];
	for(int i = 0; i<10; i++){
		scanf("%d", &array[i]);
	}
	printf("%d", verifica_condizione(array, 9));
	return 0;
}
