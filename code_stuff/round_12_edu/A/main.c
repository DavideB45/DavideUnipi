#include <stdio.h>

typedef struct hour{
	int hh;
	int mm;
}hour;

void sub_time(hour *, int hour, int min); 
void add_time(hour *, int hour, int min);
int compare_time(hour* A, hour* B);// || A > B + || A = B 0 || A < B- || 

int main(void){
	hour start;
	int a, ta;//distacco tra gli autobus //tempo mercorrenza A->B
	int b, tb;//distacco tra gli autobus //tempo mercorrenza B->A
	
	scanf("%d %d", &a, &ta);
	scanf("%d %d", &b, &tb);
	scanf("%d:%d", &(start.hh), &(start.mm));

	sub_time(&start, 0, tb);//calcolo il tempo in cui e' partito il primo autobus che vedro'
	
	hour five_am;
	five_am.hh = 5;
	five_am.mm = 0;
	int tot;
	
	if( compare_time(&start, &five_am) ){//se la strada e' gia' piena
		tot = (ta+tb)/b;
	} else {// se la strada non e' piena (o lo e' appena diventata)
		add_time(&start, 00, tb);//ripristino questo
		sub_time(&start, 5, 00);//ore e min passati dalle 5
		int min_ = 60*(start.hh) + start.mm;//calcolo i minuti passati dalle 5
		tot = ta/b + min_/b;
	}

	printf("%d\n", tot);
	return 0;
}

void sub_time(hour *base, int hour, int min){
	add_time(base, -hour, -min);
}

void add_time(hour *base, int hour, int min){
	base->hh = base->hh + hour;
	base->mm = base->mm + min;
	return;
}

int compare_time(hour* A, hour* B){
	if(A->hh != B->hh){
		return A->hh - B->hh;
	} else {
		return A->mm - B->mm;
	}
}