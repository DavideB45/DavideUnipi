#include <stdio.h>

_Bool palindroma(_Bool indicatore){
	char c;
	c = getchar(); 
	if(c=='*'){
		return 0;
	}
	palindroma(indicatore);
	if(c==getchar()){
		return indicatore;
	}
	else{
 		indicatore = 0;
		return indicatore;
	}
}

int main(void){
	char c;
for(int i = 0; i<3; i++){
	scanf("%c", &c);
	if((c=='*') || (palindroma(1) && c==getchar())){
		printf("palindrome\n");
	}
	else{
		printf("non palindrome\n");
	}
	scanf("%*c");
}
return 0;
}
		

