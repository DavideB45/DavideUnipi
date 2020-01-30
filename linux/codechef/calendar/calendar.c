#include <stdio.h>
#include <stdlib.h>

#define EVENT_FORMAT "%5[0-9:]%*[ ]%5[0-9:]"
#define FOR_HUMAN "nn:nn nn:nn"
#define START 0
#define END 1

int read_Int(_Bool positivo);
void clean_buffer(void);
void fill_day(int N_thing, char day[N_thing][2][6]);
void print_day(int N_thing, char day[N_thing][2][6]);

int main(void){
	printf("quanti eventi hai? ");
	int N_thing_1 = read_Int(1);
	char day_1[N_thing_1][2][6];
	fill_day(N_thing_1, day_1);
	print_day(N_thing_1, day_1);
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