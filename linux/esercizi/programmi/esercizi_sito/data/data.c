#include <stdio.h>

void sostituisci(int dd, int mm, int year);

int ddmin = 0, mmmin = 0, yearmin = 8000;

int main(){
	int dd, mm, year;
	int i = 0; 
	while(i==0){
		while(scanf("%2d/%2d/%4d", &dd, &mm, &year)!=3 || dd>31 || mm>12){
			printf("Data inserita errata, inserire una data nel formato gg/mm/aaaa.\n");
			scanf("%*[^\n]");
			scanf("%*c");
		}
		if(dd==0 && mm==0 && year==0){
			break;
		}
		if(yearmin>year){
			sostituisci(dd, mm, year);
		}
		else{
			if(yearmin==year){
				if(mmmin>mm){
					sostituisci(dd, mm, year);
				}
				else{
					if(ddmin>dd){
						sostituisci(dd, mm, year);
					}
				}
			}
		}
	}
	printf("Data meno recente: %02d/%02d/%04d\n", ddmin, mmmin, yearmin);
	return 0;
}


void sostituisci(int dd, int mm, int year){
	yearmin = year;
	mmmin = mm;
	ddmin = dd;
	return;
}
