//
// Created by davide on 3/4/20.
//
#include <stdio.h>
#include <stdlib.h>

int readInt();
void fillArray(int dim, int *array);
void quickSort(int *array, int inizio, int fine);
void printArray(int dim, int *array);
void swap(int *piv, int *index, int *number_before);

int main(void){
    //printf("Inserire dimensione : ");
    int dim = readInt();
    int *array = malloc(dim*sizeof(int));
    fillArray(dim, array);

    quickSort(array, 0, dim - 1);

    //printf("\n");
    printArray(dim, array);

    free(array);
    return 0;
}

int readInt(){
    int num;
    while(scanf("%d", &num) != 1){
        printf("numero  non valido : ");
        while(getchar() != '\n'){}
    }
    return num;
}

void fillArray(int dim, int *array){
    for (size_t i = 0; i < dim; i++){
        //printf("inserire in pos %lu : ", i);
        array[i] = readInt();
    }

}

void swap(int *piv, int *index, int *number_before){
    int temp = *piv;
    *piv = *index;
    *index = *number_before;
    *number_before = temp;
}

void quickSort(int *array, int inizio, int fine){

}

void printArray(int dim, int *array){
    for (size_t i = 0; i < dim; i++){
        printf("%d ", array[i]);
    } printf("\n");
}
