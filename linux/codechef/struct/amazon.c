#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int num;//id del nodo
	int links_N;//numero di link
	struct nodo *bracci[8];//array di link
	struct nodo *orderPtr;//prossimo in ordine crescente
} Nodo;
typedef Nodo *NodoPtr;

typedef struct val{
	int val;
	struct val *nextPtr;
} Val;
typedef Val *ValPtr;



int readint(void);;;
void ceckPtr(void *Ptr);
NodoPtr addnew(int value);//genera un nodo
void pushV(ValPtr *headPtr, int commonvalue);//per la lista di pos comuni



void printcommon(ValPtr corrPtr);//stampa lista Val
void printList(NodoPtr corrPtr);//stampa la lista ordinata
void printarray(int dim, int *array);//stampa un array di numeri
void freelist(ValPtr *corrPtr);
void freestruct(NodoPtr *corrPtr);


//so muove dovunque si possa arrivare con move_of spostamenti
void movefrof(NodoPtr startPtr, int move_of, int *stati, int *array, int prec);
//crea una lista con elementi comuni a 2 array
ValPtr findcommon(int dim1, int *array1, int dim2, int*array2);



//lega 2 nodi
void link(NodoPtr A, NodoPtr B);
//crea una lista ordinata dei nodi e ne collega due alla volta
int insort(NodoPtr *headPtr);
//cerca un numero e restituisce il puntatore al nodo precedente
NodoPtr researc(int num, NodoPtr corrPtr);
//restituisce il puntatore al numero (se non c'e' lo crea)
NodoPtr gaveNpointer(NodoPtr *headPtr,NodoPtr precPtr, int a_node);

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main(){

	NodoPtr headPtr = NULL;
	
	int j = insort(&headPtr);
	for(int i = 0; i < j-1; i++){
		insort(&headPtr);
	}
	printList(headPtr);
	
	int *array_A = calloc(1, sizeof(int));
	printf("Da che numero vuoi partire ? ");
	int from = readint();
	NodoPtr start = researc(from, headPtr);
	if(start == NULL){
		start = headPtr;
	} else {
		start = start->orderPtr;
	}
	printf("Quante mosse vuoi fare ? ");
	int of = readint();
	int stati_A = 0;
	movefrof(start, of, &stati_A, array_A, -1);
	printarray(stati_A, array_A);
	
	int *array_B = calloc(1, sizeof(int));
	printf("Da che numero vuoi partire ? ");
	from = readint();
	start = researc(from, headPtr);
	if(start == NULL){
		start = headPtr;
	} else {
		start = start->orderPtr;
	}
	printf("Quante mosse vuoi fare ? ");
	of = readint();
	int stati_B = 0;
	movefrof(start, of, &stati_B, array_B, -1);
	printarray(stati_B, array_B);

	ValPtr commonList = findcommon(stati_B, array_B, stati_A, array_A);
	printcommon(commonList);

	free(array_A);
	free(array_B);
	freelist(&commonList);
	freestruct(&headPtr);

	return 0;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int readint(void){
	int num;
	while(scanf("%d", &num)!=1){
		printf("non accettabile : ");
		while(getchar()!='\n');
	}
	return num;
}

void ceckPtr(void *Ptr){
	if(Ptr==NULL){
		printf("Memoria esaurita\n");
		exit(EXIT_FAILURE);
	}
}

NodoPtr addnew(int value){
	NodoPtr new = calloc(1, sizeof(Nodo));
	new->num = value;
	new->links_N = 0;
	return new;
}

void pushV(ValPtr *headPtr, int commonvalue){
	ValPtr  newPtr = calloc(1, sizeof(Val));
	ceckPtr(newPtr);
	newPtr->val = commonvalue;
	newPtr->nextPtr = (*headPtr);
	*headPtr = newPtr;
}

void freelist(ValPtr *corrPtr){
	ValPtr tofree;
	while((*corrPtr)!=NULL){
		tofree = (*corrPtr);
		(*corrPtr) = (*corrPtr)->nextPtr;
		free(tofree);
	}
}
void freestruct(NodoPtr *corrPtr){
	NodoPtr tofree;
	while((*corrPtr)!=NULL){
		tofree = (*corrPtr);
		(*corrPtr) = (*corrPtr)->orderPtr;
		free(tofree);
	}
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printList(NodoPtr corrPtr){
	while(corrPtr!=NULL){
		printf("il numero %d punta a :\n", corrPtr->num);
		for(int i = 0; i < corrPtr->links_N; i++){
			printf("->%d\n", ((corrPtr->bracci)[i])->num);
		}
		corrPtr = corrPtr->orderPtr;
	}
}

void printcommon(ValPtr corrPtr){
	while(corrPtr!=NULL){
		printf("%d->", corrPtr->val);
		corrPtr = corrPtr->nextPtr;
	} printf("NULL\n");
}

void printarray(int dim, int *array){
	for(int i = 0; i < dim; i++){
		printf("%d::", array[i]);
	} printf("fine\n");
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void link(NodoPtr A, NodoPtr B){
	
	(A->bracci)[A->links_N] = B;//gli dico dove andare
	++(A->links_N);// sposto l'indice per dopo
	
	(B->bracci)[B->links_N] = A;
	++(B->links_N);
}

NodoPtr researc(int num, NodoPtr corrPtr){
	NodoPtr precPtr = NULL;
	//scorre la lista fino alla fine o fino a che compare un valore >= di num
	while(corrPtr!=NULL && num > corrPtr->num){
		precPtr = corrPtr;
		corrPtr = corrPtr->orderPtr;
	}
	return precPtr;
}

NodoPtr gaveNpointer(NodoPtr *headPtr,NodoPtr prec_Ptr, int a_node){

	NodoPtr corrPtr;
	
	if(prec_Ptr==NULL){//modifica in testa
		
		corrPtr = (*headPtr);
		if(corrPtr==NULL || (corrPtr->num != a_node)){//il numero va aggiunto
			prec_Ptr = addnew(a_node);//creo un puntatore da ggiungere alla lista
			prec_Ptr->orderPtr = corrPtr;//collego il successivo
			(*headPtr) = prec_Ptr;//modifico la head
		} else {
		//il numero c'e' ma devo spostare il puntatore
			prec_Ptr = (*headPtr);
		}
		
	} else {// modifica nel mezzo o in coda
	
		corrPtr = prec_Ptr->orderPtr;
		if(corrPtr==NULL || (corrPtr->num != a_node)){//il numero va aggiunto
		//se corrPtr e' NULL lo aggiungo in coda senno' nel mezzo in quanto mancante
			corrPtr = addnew(a_node);
			corrPtr->orderPtr = prec_Ptr->orderPtr;
			prec_Ptr->orderPtr = corrPtr;
		}
		prec_Ptr = prec_Ptr->orderPtr;
	
	}
	return prec_Ptr;
}
	
	
		
int insort(NodoPtr *headPtr){
	int a_val = readint();
	getchar();//salta lo spazio
	int b_val = readint();
	
	//nodo che precede il numero o il minimo valore maggiore di esso
	NodoPtr A_Ptr = researc(a_val, *headPtr);
	//diventa quello giusto
	A_Ptr = gaveNpointer(headPtr, A_Ptr, a_val);
	
	//nodo che precede il numero o il minimo valore maggiore di esso
	NodoPtr B_Ptr = researc(b_val, *headPtr);
	//diventa quello giusto
	B_Ptr = gaveNpointer(headPtr, B_Ptr, b_val);
	
	link(A_Ptr, B_Ptr);//lega i nodi
	
	return a_val;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void movefrof(NodoPtr startPtr, int move_of, int *stati, int *array, int prec){
	if(move_of > 0){
		for(int i = 0; i < startPtr->links_N; i++){
			if(((startPtr->bracci)[i])->num != prec){//il problema potrebbe essere qui'
				movefrof((startPtr->bracci)[i], move_of - 1, stati, array, startPtr->num);
			}
		}
	} else {
		array[(*stati)] = startPtr->num;
		++(*stati);
		realloc(array , ((*stati)+1)*sizeof(int));
	}
}

ValPtr findcommon(int dim1, int *array1, int dim2, int*array2){
	ValPtr headPtr = NULL;
	ValPtr corrPtr = NULL;
	for (size_t i = 0; i < dim1; i++){
		for(int j = 0; j < dim2; j++){
			if(array1[i]==array2[j]){
				corrPtr = headPtr;
				while(corrPtr!=NULL && corrPtr->val!=array1[i]){
					corrPtr = corrPtr->nextPtr;
				}
				if(corrPtr==NULL){
					pushV(&headPtr, array1[i]);
				}
			}
		}
	}
	return headPtr;
}