#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct transizione{
	char read;
	char nextstate[3];//intende che e' ina stringa
	struct transizione *nextPtr;	
} trz;
typedef trz *trzPtr;

typedef struct stato{
	char name[3];
	trzPtr transition;
} State;

void ceck_Ptr(void *Ptr);
void clean_buffer(void);
int read_int(void);
void read_state(State *x_state);
void add_trz(trzPtr *firstPtr);
_Bool readable(int dim ,State *statearr, char *string);
_Bool ceck_end(char *string);

void printatutto(int N_state,State *state_arr){
	trzPtr corrPtr;
	for (size_t i = 0; i < N_state; i++){
		printf("%s", state_arr[i].name);
		corrPtr = state_arr[i].transition;
		while(corrPtr!=NULL){
			printf(";(%s,%c)", corrPtr->nextstate, corrPtr->read);
			corrPtr = corrPtr->nextPtr;
		} printf("\n");
		
	}
	
}

int main(void){
	int N_state = read_int();
	State state_arr[N_state];
	for (size_t i = 0; i < N_state; i++){
		read_state(&(state_arr[i]));
	}
	//printatutto(N_state, state_arr);
	char string[100];
	while (scanf("%s", string),  ceck_end(string)){
		if(readable(N_state, state_arr, string)){
			printf("%s\n", string);
		} else {
			//printf("non traducibile\n");
		}
		
	}
	
}


void ceck_Ptr(void *Ptr){
	if (Ptr==NULL){
		printf("Memory Full\n");
		exit(EXIT_FAILURE);
	}
}

void clean_buffer(void){
	scanf("%*[^\n]");
	scanf("%*c");
}

int read_int(void){
	int num;
	while(scanf("%d", &num)!=1){
		printf("Numero non leggibile\n");
		clean_buffer();
	}
	clean_buffer();
	return num;
}

void read_state(State *x_state){
	//printf("readPre\n");
	scanf("%[^;]", x_state->name);
	//printf("readpost\n");
	x_state->transition = NULL;
	add_trz(&(x_state->transition));
	clean_buffer();
}

void add_trz(trzPtr *firstPtr){
	char read;
	char next_state[3];
	trzPtr corrPtr;
	trzPtr precPtr;

	trzPtr newPtr;
	while(scanf(";(%[^,],%c)", next_state, &read)==2){
		//printf(";(%s,%c)\n", next_state, read);
		corrPtr = *firstPtr;
		precPtr = NULL;
		while(corrPtr!=NULL && corrPtr->read < read){
			precPtr = corrPtr;
			corrPtr = corrPtr->nextPtr;
		}

		newPtr = calloc(1, sizeof(trz));
		newPtr->nextPtr = corrPtr;
		newPtr->read = read;
		strcpy(newPtr->nextstate, next_state);

		if(precPtr==NULL){
			*firstPtr = newPtr;
		} else {
			precPtr->nextPtr = newPtr;
		}	
	}
	//printf("ooW\n");
}

_Bool readable(int dim ,State *statearr, char *string){
	int i = 0, j = 0;
	_Bool error = 0;
	int currstate = 0;
	trzPtr corrPtr;
	while(string[i]!='\0' && !error){
		//printf("State = %s %p\n", statearr[j].name, &(statearr[i]));
		//printf("lettera = %c\n", string[i]);
		corrPtr = (statearr[currstate]).transition;
		while (corrPtr!=NULL && corrPtr->read < string[i]){
			corrPtr = corrPtr->nextPtr;
		}
		if(corrPtr==NULL || corrPtr->read != string[i]){
			error = 1;
		} else {
			i++;
			j = 0;
			//printf("state = %s\n", corrPtr->nextstate);
			while(strcmp(corrPtr->nextstate , statearr[j].name)!=0 && j < 10){
				//printf("state = %s\n", statearr[j].name);
				j++;
			}
			currstate = j;
		}
	}
	//printf("State out = %s %p\n", statearr[j].name, &(statearr[i]));
	return (string[i]=='\0' && statearr[j].name[0]=='F');
}

_Bool ceck_end(char *string){
	return (strncmp(string, "FINE", 4)!=0);
}