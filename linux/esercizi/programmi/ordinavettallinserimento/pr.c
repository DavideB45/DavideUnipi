#include <stdio.h>
#define N 10


int main(){
	int vet[N];
	int temp;
	for(int i = 0; i<N; i++){
		while(scanf("%d", &vet[i])!=1){
			scanf("%*[^\n]");
			scanf("%*c");
		}
		if(vet[i]<vet[i-1]){
			for(int j = 0; j<i; j++){
				if(vet[i] < vet[j]){
				for(int k = j-1;k>=0; k--){
					vet[k] = vet[k];  
				}
				}
			}
		}
	}
	for(int i = 0; i<N; i++){
		printf("%d ", vet[i]);
	}
	printf("\n");
	return 0;
}
	
		
