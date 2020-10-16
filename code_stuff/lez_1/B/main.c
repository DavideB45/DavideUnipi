#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int size;
	char* string;
}String;
typedef String* StringPtr;

StringPtr ReadString(void);
int ReadInt(char*);
void RotateString(int l, int r, int k, StringPtr str);
void DestroyString(StringPtr str);

int main(void){
	StringPtr string = ReadString();
	int count = ReadInt("inserisci il numero di traslazioni");
	int start, end, k;

	for (size_t i = 0; i < count; i++){
		start = ReadInt("inizio : ");
		end = ReadInt("fine : ");
		k = ReadInt("numero rotazioni : ");
		RotateString(start, end, k, string);
		printf("%s\n", string->string);
	}

	return 0;	

}


StringPtr ReadString(void){
	
	StringPtr str = malloc(sizeof(String));
	str->string = calloc(10, sizeof(char));
	
	int read_count = 10;
	scanf("%10s%n", str->string, &read_count);
	str->size = read_count;

	printf("%s, %d, %d\n", str->string, str->size, read_count);

	while (read_count >= 10){
		realloc(str->string, str->size + 10);//error
		scanf("%10s%n", (str->string + str->size), &read_count);
		str->size = str->size + read_count;
		printf("%s, %d, %d\n", str->string, str->size, read_count);
	}
	
}

int ReadInt(char* request){
	printf("%s", request);
	int num;
	scanf("%d", &num);
	return num;
}

void RotateString(int l, int r, int k, StringPtr str){
	char to_move;
	for (size_t i = 0; i < k; i++){
		to_move = str->string[r-1];
		for(int j = r; j > l; j--){
			
		}
	}
	
	
}

void DestroyString(StringPtr str);