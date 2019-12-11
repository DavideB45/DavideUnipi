#include <stdio.h>
#include <stdlib.h>

/*riempie l'array fino a che la somma degli elementi e' >= 100*/
int insert(float *array, int indice, float sum);
/*trova e restituisce l'intero massimo*/
int findmax(float *array, size_t dim, int max);
/*trova i divisori interi e ne restituisce il numero*/
int divisori(float *array, size_t dim, int *divisori, int max);

void printfloatarray(float *array, size_t dim);
void printintarray(int *array, size_t dim);

int main(void){
    float array[100];
    int dim = insert(array, 0, 0);
    printf("Array:\n");
    printfloatarray(array, dim);

    int max = findmax(array, dim, -1);
    printf("max = %d\n", max);

    int divarr[dim];/*array che contiene i divisori*/
    int divdim = divisori(array, dim, divarr, max);
    printf("Divisori:\n");
    printintarray(divarr, divdim);
    return 0;
}

int insert(float *array, int indice, float sum){
    if(sum<100){
        /*controllo dell'input*/
        while(scanf("%f", &array[indice])!=1){
            printf("Errore nell' input\n");
            while(getchar()!='\n');
        }
        sum = sum + array[indice];
        return insert(array, ++indice, sum);
    } else {
        return indice;
    }
}

int findmax(float *array, size_t dim, int max){
    if(dim == 0){
        /*ho scorso tutto l'array => ritorno il valore massimo*/
        return max;
    } else {
        int num = (int)array[dim-1];
        /*verifica le condizioni x essere il maxint*/
        if(num >= 0 && num == array[dim-1] && num>max){
            max = num;
        }
        return findmax(array, --dim, max);
    }
}

int divisori(float *array, size_t dim, int *divisori, int max){
    int i;
    int ndiv = 0;
    for(i = 0; i < dim; i++){
        /*se il valore e' divisore intero di max viene salvato*/
        if(array[i] == (int) array[i] && (max % (int)array[i]==0) ){
            divisori[ndiv] = array[i];
            ndiv++;
        }
    }
    return ndiv;
}

void printfloatarray(float *array, size_t dim){
    int i;
    for(i = 0; i < dim; i++){
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

void printintarray(int *array, size_t dim){
    int i;
    for(i = 0; i < dim; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}