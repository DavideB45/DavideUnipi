#include <stdio.h>

float calcolo(float na, char oper, float ris);

int main(void){
	char na = 0;
	char oper;
	int end;
	do{
	end=0;
	scanf("%f", &na);
	//controllo per la fine del programma
	/*if('f' == c){
		if('i' == getchar()){
			if('n' == getchar()){
				if('e' == getchar()){
					return 0;
				}
			}
		}
	}*/
	oper = getchar();
	printf("%f", calcolo(na, oper, 0));
	}while(end<4);
	return 0;
}
//considerare che res non deve essere usato subito => aggiungere una variabile
float calcolo(float na, char oper, float ris){
	if(oper == ' '){
		oper = getchar();
	}
	switch (oper){
		case '+':
			ris = ris + na;
			break;
		case '-':
			ris = ris - na;
			break;
		case '/':
			ris = ris / na;
			break;
		case '\n':
			return ris;
		default :
			while(oper != ' '){
				na = na*10 + oper;
				oper = getchar();
			}
			return calcolo(na, oper, ris);
	}
}
			
























	
