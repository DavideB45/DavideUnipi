#include <stdio.h>

int read_positive_int(void);

int mcd(int N, int M);

int MCM(int N, int M);

int main(void){
	int N;
	int M;                    
	N = read_positive_int();
	M = read_positive_int();
	printf("%d\n%d", mcd(N, M), MCM(N, M));
	return 0;
}

int read_positive_int(void){
	int n;
	while(scanf("%d", &n)!=1 || n<0){
		scanf("%*[^\n]");
		scanf("%*c");
		printf("Inserisci un intero positivo.\n");
	}
	return n;
}

int mcd(int N, int M){
	int resto;
	if(M==0){
		return N;
	}
	else{
		resto = N%M;
		if(resto==0){
			return M;
		}
		else{
			return mcd(M, resto);
		}
	}
}

int MCM(int N, int M){
	int min = mcd(N, M);
	return min*(N/min)*(M/min);
}
