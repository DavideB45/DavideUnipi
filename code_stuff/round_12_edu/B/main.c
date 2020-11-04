#include <stdio.h>
#include <stdlib.h>

int *riempi_negozio(int n_ogg);//dire quanti oggetti si hanno e crea lo scaffale
int prendi_ogg(int ID_ogg, int *scaffale, int n_ogg);//mette l'oggetto ID_ogg in prima pos e restituisce il tempo per prenderlo

int main(void){
	int n;//numero clienti
	int m;//numero oggetti per cliente
	int k;//numero di oggetti diversi

	scanf("%d %d %d", &n, &m, &k);
	int* scaffale = riempi_negozio(k);

	int ID_ogg;
	int time = 0;
	for (size_t i = 0; i < n; i++){//ogni persona
		for(size_t j = 0; j < m; j++){//ogni oggetto della persona i
			scanf("%d", &ID_ogg);
			time += prendi_ogg(ID_ogg, scaffale, k);
			printf("%d\n", time);
		}
	}
	printf("tempo speso : %d\n", time);
	return 0;
}

int *riempi_negozio(int n_ogg){
	int* arr = malloc(n_ogg*sizeof(int));
	int j;
	for (size_t i = 0; i < n_ogg; i++){
		scanf("%d", &j);//oggetto j
		arr[j - 1] = i;//questo array va visto al contrario
		//indice array = ID_oggetto
		//contenuto array = posizione_oggetto
	}
	return arr;
}

int prendi_ogg(int ID_ogg, int* scaffale, int n_ogg){
	ID_ogg--;//correzione valore oggetto
	int pos = scaffale[ID_ogg];//salvo la pos iniziale di oggetto
	
	printf("pre :");
	for (size_t i = 0; i < n_ogg; i++){
		printf(" %d ", scaffale[i]);
	}printf("\n");
	
	for (size_t i = 0; i < n_ogg; i++){
		if(scaffale[i] < pos)//se l'oggetto i era in posizione precedente rispetto a ID_ogg
			scaffale[i]++;//aumento la sua posizione
	}scaffale[ID_ogg] = 0;//metto l'oggetto all'inizio dello scaffale

	printf("pos :");
	for (size_t i = 0; i < n_ogg; i++){
		printf(" %d ", scaffale[i]);
	}printf("\n");	

	printf("%d\t", pos + 1);
	return pos + 1;//il +1 e' per sistemare il tempo che parte da 1  non da 0
}