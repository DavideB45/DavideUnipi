#include <stdio.h>
#include <string.h>


int main(void){
	char string[15];
	_Bool exc = 1;
	scanf("%s", string);
	char curr_ch = string[0];

	int i = 1;
	while (string[i] != '\0'){
		if(string[i] == curr_ch){
			if(exc == 1){
				string[i]++;
				if(string[i] == string[i + 1]){//se aumentando diventa il prossimo aumento di nuovo
					string[i]++;
				}
				if(string[i] > 'z'){//
					string[i] = 'a';//
				}					//
			}
			exc = !exc;
		} else {
			exc = 1;
			curr_ch = string[i];//ho un nuovo carattere iniziale
		}
		i++;
	}

	printf("%s\n", string);

	return 0;
}