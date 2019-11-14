//programma che verifica se avviene un overflaw
#include <stdio.h>

int main(){
	char a,b;
	printf("inserire due interi separati da uno spazio: ");
	while(scanf("%d %d", &a, &b) != 2){
		printf("\nreinserire numeri interi: ");
		scanf("%*[^\n]%*c");
	}
	if(a>a+b || b>a+b)
		printf("overflaw\n");
	else
		printf("%d\n", a+b);
	return 0;
}
//note dal futuro 
//questo programma fa schifo
/*
if((a>0 && a>res) || (a<0 && a<res))){
	printf("Overflaw\n");
}
else{
	printf("%d", res);
}*/
