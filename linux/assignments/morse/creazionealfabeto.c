#include <stdio.h>

typedef struct lettera{
    char simbol;
    struct lettera *prossimoPtr;
}lettera;
typedef lettera *simbolPtr;

int main(void){
    char carattere[36];
    lettera *morse[36];
    int i = 0;
    do{
        scanf("%c", &carattere[i]);   
        simbolPtr headPtr = malloc(sizeof(lettera));
        simbolPtr correntePtr = headPtr;
        do{
            getchar();
            correntePtr->simbol = getchar();
            if(correntePtr->simbol!='\n'){
                correntePtr->prossimoPtr = malloc(sizeof(lettera));
                if(correntePtr->prossimoPtr==NULL){
                    printf("memoria esaurita\n");
                    deall(headPtr);
                    headPtr = NULL;
                }
                else{
                    correntePtr = correntePtr->prossimoPtr;
                }
            }
        } while (correnteptr->simbol!= '\n');
    } while (/* condition */);
    
}

void dealloc(simbolPtr correntePtr){
    if(correntePtr!=NULL){
        dealloc(correntePtr->prossimoPtr);
        free(correntePtr);
    }
}