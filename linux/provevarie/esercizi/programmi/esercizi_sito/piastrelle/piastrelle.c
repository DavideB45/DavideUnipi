#include <stdio.h>


int read_positive_int(void){
	int n;
	while(scanf("%d", &n)!=1 || n<0){
		scanf("%*[^\n]");
		scanf("%*c");
		printf("Errore. Inserisci un intero positivo.\n");
	}
	return n;
}

/*long long int conta_possibilita(int l){
	if(l == 1){
		return 2;
	}
	else{
		if(l == 2){
			return 7;
		}
		else{
			return 2*conta_possibilita(l-1)+3*conta_possibilita(l-2);
		}
	}
}*/
long long int conta_possibilita(int l, long long int possib, long long int next){
	if(l == 1){
		return possib;
	}
	if(l == 2){
		return next;
	}
	else{
		return conta_possibilita(l-1, 2*possib + 3*next, next);
	}
}
int main(void){
	int l;
	l = read_positive_int();
	printf("%lld\n", conta_possibilita(l, 2, 7));
	return 0;
}
