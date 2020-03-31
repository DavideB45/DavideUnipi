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
    if(fine - inizio >=  1){
        //printf("inizio = %d fine = %d\n", inizio, fine);
        int index = fine - 1, piv_pos = fine;
        while(index >= inizio){
            if(array[index] > array[piv_pos]){
                swap(array + piv_pos, array + index, array + piv_pos - 1);
                piv_pos--;
            }
            index--;
        }
        //printf("piv = %d  p_pos = %d\n", array[piv_pos], piv_pos);
        quickSort(array, inizio, piv_pos - 1);
        quickSort(array, piv_pos + 1, fine);
    }
}

void printArray(int dim, int *array){
    for (size_t i = 0; i < dim; i++){
        printf("%d ", array[i]);
    }// printf("\n");
}
