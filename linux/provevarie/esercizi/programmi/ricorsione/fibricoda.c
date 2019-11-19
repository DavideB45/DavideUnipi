//programma che calcola la sequenza di fibonacci in modo ricorsivo in coda
#include <stdio.h>
int fib(int n1,int n2, int acc);
int main(){
	int n;
	printf("Inserire il numero del quale si vuole calcolare il valore: ");
	while(scanf("%d", &n) != 1 || n < 0){
		printf("ERRORE! Inserire un altro valore: ");
		scanf("%*[^\n]%*c");
	}
	printf("il numero della sequenza e': %d\n", fib(n, 0, 0));
	return 0;
}

int fib(int n1,int n2, int acc){
	if(n == 0){
		//printf("%d\n", acc);
		return 0;
	}
	if(n == 1){
		acc = 1;
		printf("%d\n", acc);
		return 1;
	}
	else{
		//acc = n-1 + acc;
		printf("%d\n", acc);
		return fib(n1-1,n1-2, acc);
	}
	/*else{
		return fib(n-1) + fib(n-2);
	}*/
}
	
	
	
