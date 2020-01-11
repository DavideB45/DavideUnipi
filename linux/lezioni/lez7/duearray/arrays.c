#include <stdio.h>

_Bool condizione(int a[], int b[], int indice, int indice2){
	if(a[indice]<b[indice2]){
		if(indice2 == 2){
			return 1;
		}
		else{
				return condizione(a, b, indice, ++indice2);
		}
	}
	else{
		if(indice == 2){
			return 0;
		}
		else{
			return condizione(a, b, ++indice, 0);
		}
	}
}

int main(){
	int a[3];
	int b[3];
	for(int i = 0; i<3; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i<3; i++){
		scanf("%d", &b[i]);
	}
	if(condizione(a, b, 0, 0)){
		printf("TRUE\n");
	}
	else{
		printf("FALSE\n");
	}
	return 0;
}
