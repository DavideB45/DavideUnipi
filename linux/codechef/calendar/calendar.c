#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EVENT_FORMAT "%5[0-9:]%*[ ]%5[0-9:]"
#define FOR_HUMAN "nn:nn nn:nn"
#define START 0
#define END 1

int read_Int(_Bool positivo);
void clean_buffer(void);
void fill_day(int N_thing, char day[N_thing][2][6]);
void find_time(int N_thing1, char day1[N_thing1][2][6], int N_thing2, char day2[N_thing2][2][6]);
void print_day(int N_thing, char day[N_thing][2][6]);

int main(void){

	printf("N impegni persona 1 = ");
	int N_thing_1 = read_Int(1);
	char day_1[N_thing_1][2][6];
	fill_day(N_thing_1, day_1);

	printf("N impegni persona 2 = ");
	int N_thing_2 = read_Int(1);
	char day_2[N_thing_2][2][6];
	fill_day(N_thing_2, day_2);
	
	printf("\n");
	find_time(N_thing_1, day_1, N_thing_2, day_2);

	printf("\n");
	print_day(N_thing_1, day_1);
	printf("\n");
	print_day(N_thing_2, day_2);
	printf("\n");
	return 0;
}



//se deve essere positivo 
//positivo deve essere 1
int read_Int(_Bool positivo){
	int num;
	while(scanf("%d", &num)!=1 || (!positivo || num < 0)){
		printf("numero non valido : ");
		clean_buffer();
	} clean_buffer();
	return num;
}

void clean_buffer(void){
	scanf("%*[^\n]");
	scanf("%*c");
}

void fill_day(int N_thing, char day[N_thing][2][6]){
	for(int i = 0; i < N_thing; i++){
		printf("inserire evento numero %d: ", i+1);
		day[i][0][5] = '\0';
		day[i][1][5] = '\0';
		while(scanf(EVENT_FORMAT, day[i][START], day[i][END]) != 2){
			printf("formato = %s\n", FOR_HUMAN);
			printf("Riprova : ");
			clean_buffer();			
		} clean_buffer();
	}
}

void print_day(int N_thing, char day[N_thing][2][6]){
	for(int i = 0; i < N_thing; i++){
		printf("%d: %s -> %s\n", i+1, day[i][START], day[i][END]);
	}
}

void find_time(int N_thing1, char day1[N_thing1][2][6], int N_thing2, char day2[N_thing2][2][6]){
	int i_1 = 0, i_2 = 0;
	char last_end[6], next_ev[6];
	_Bool found = 0;
	while((i_1 < N_thing1 && i_2 < N_thing2) && !found){
		
		//calcolo chi finisce per ultimo
		if(strcmp(day1[i_1][END], day2[i_2][END]) > 0){
			//finisce per ultimo il primo
			strncpy(last_end , day1[i_1][END], 6);
			//i_1++;
		} else {
			//finisce per ultimo il secondo	
			strncpy(last_end, day2[i_2][END], 6);
			//i_2++;
		}
		i_1++;
		i_2++;
		//calcolare evento piu' vicino
		if(strcmp(day1[i_1][START], day2[i_2][START]) < 0){
			//inizia prima 1
			strncpy(next_ev, day1[i_1][START], 6);
		} else {
			//inizia prima 2
			strncpy(next_ev, day2[i_2][START], 6);
		}

		if(strcmp(last_end, next_ev) < 0){
			printf("dalle %s alle %s\n", last_end, next_ev);
		}
		
	}
}
