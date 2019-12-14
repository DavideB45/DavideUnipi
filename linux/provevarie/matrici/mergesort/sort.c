#include <stdio.h>
#include <stdlib.h>
#define DIM 3


void merge(int *array, int dim);
void sort(int *arrA, int *arrB, int dimA, int dimB);

int main(){
    int array[DIM];
    printf("RIEMPIRE IL PRIMO ARRAY\n");
    for(int i = 0; i<DIM; i++){
        printf("inserire il numero %d: ", i);
        while(scanf("%d", &array[i])!=1){
            printf("inserire un numero: ");
            while(getchar()!='\n');
        }
    }
    printf("RIEMPIRE IL SECONDO ARRAY\n");
    int secondo[DIM];
    for(int i = 0; i<DIM; i++){
        printf("inserire il numero %d: ", i);
        while(scanf("%d", &secondo[i])!=1){
            printf("inserire un numero: ");
            while(getchar()!='\n');
        }
    }
    sort(array, secondo, DIM, DIM);
    /*merge(array, DIM);
    for(int i = 0; i<DIM; i++){
        printf("%d::", array[i]);
    }
    printf("[]\n");*/
}

void merge(int *array, int dim){
    //sort();
}

void sort(int *arrA, int *arrB, int dimA, int dimB){
    int aInd = 0, bInd = 0;
    int *combined = calloc(dimA+dimB, sizeof(int));
    int cInd = 0;
    while(aInd<dimA && bInd<dimB){
        if(arrA[aInd]<arrB[bInd]){
            combined[cInd] = arrA[aInd];
            aInd++;
        } else {
            combined[cInd] = arrB[bInd];
            bInd++;
        }
        cInd++;
    }
    if(aInd==dimA){
        for(int i = cInd; i<dimB+dimA+1; i++){
            combined[i] = arrB[bInd];
            bInd++;
        }
    } else {
        for(int i = aInd; i<dimA; i++){
            combined[cInd] = arrA[i];
            cInd++;
        }
    }
    for (size_t i = 0; i < dimA+dimB; i++){
        printf("%d::", combined[i]);
    } printf("[]\n");
}