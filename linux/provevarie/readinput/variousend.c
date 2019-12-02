#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readString(void){
	char tempsting[20];
	int len;
	scanf("%[^\n^E^ ]", tempsting);
	getchar();
	//strcat(tempsting, "\0");
	int dim = 0;
	while(tempsting[dim]!='\0'){
		dim++;
	}
	printf("dim = %d strlen = %d ", dim, strlen(tempsting));
	return strcpy(calloc(dim + 1, sizeof(char)), tempsting);
}

int main(void){
	char *string;
	int coso = 1;
	do{
		string = readString();
		printf("%s\n",string);
	}while(strcmp(string,"fine")!=0);
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////
///*								   BEST	WAY										*///
////////////////////////////////////////////////////////////////////////////////////////
/*/ char *readString(FILE *fPtr){													 /*/
/*/		char tempsting[20];//stringa temporanea										 /*/
/*/		fscanf(fPtr, "%[^\n]\n", tempsting);//lettura da file fino a '\n'			 /*/
/*/		//copia di tempstring in una memoria allocata e restituita dalla funzione	 /*/
/*/		return strcpy(calloc(strlen(tempsting)+1, sizeof(char)), tempsting);		 /*/
/*/}																				 /*/
////////////////////////////////////////////////////////////////////////////////////////