#include <stdio.h>

//19 minuti con gedit

void read(size_t dim, int array[dim]);
void print(size_t dim, int array[dim]);

void merge_sort(size_t dim, int *array);
void sort(size_t inizio, size_t fine, int *array);
void merge(size_t sx, size_t centro1, size_t centro2, size_t fine, int *array);

int main(void){
    int dim;
    
    printf("Inserire la dimensione dell'array : ");
    while(scanf("%d", &dim)!=1 || dim < 1){
        printf("Inserire numeri validi : ");
        while(getchar()!='\n');
    }
    
    int array[dim];
    read(dim, array);
    
    merge_sort(dim, array);
    
    print(dim, array);
    
    return 0;
}

void read(size_t dim, int array[dim]){
    for(int i = 0; i < dim; i++){
        printf("Inserire num in posizione %d: ", i);
        while(scanf("%d", &array[i])!=1){
            printf("Inserire un numero intero : ");
            while(getchar()!='\n');
        }
    }
}

void print(size_t dim, int array[dim]){
    for(int i = 0; i < dim-1; i++){
        printf("%d::", array[i]);
    } printf("%d\n", array[dim-1]);
}


void merge_sort(size_t dim, int *array){
    sort(0, dim - 1, array);
}

void sort(size_t inizio, size_t fine, int *array){
    if(inizio - fine >= 1){
        size_t centro1 = (inizio + fine)/2;
        size_t centro2 = centro1 + 1;
        
        sort(inizio, centro1, array);
        sort(centro2, fine, array);
        merge(inizio, centro1, centro2, fine, array);
     }
}

void merge(size_t sx, size_t centro1, size_t centro2, size_t fine, int *array){
    size_t sxI = sx, dxI = centro2, coI = 0;
    int combinato[fine-sx+1];
    while(sxI <= centro1 && dxI <= fine){
        if(array[sxI] < array[dxI]){
            combinato[coI++] = array[sxI++];
        } else {
            combinato[coI++] = array[dxI++];
        }
    }
    while(sxI <= centro1){
        combinato[coI++] = array[sxI++];
    }
    while(dxI <= fine){
        combinato[coI++] = array[dxI++];
    }
    coI = 0;
    for(int i = sx; i <= fine; i++){
        array[i] = combinato[coI++];
    }
}
        



































