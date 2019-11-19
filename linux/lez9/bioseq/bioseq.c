#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    int nseq = 0;
    int maxlenght = 0;
	int corrlenght = 0;
    int nnucleotidi = 0;
    FILE *fPtr;
    char seqPtr[101];
    //apertura file
    if((fPtr = fopen("input.txt", "r")) == NULL){
        printf("Err file not found");
        exit(1);
    }
    while(fgets(seqPtr, 101, fPtr)!=NULL){
		if(seqPtr[0] == '>'){
			nseq++;
			if(corrlenght>maxlenght){
				maxlenght = corrlenght;
			}
			corrlenght = 0;
		}
		else{
			corrlenght = corrlenght + (strlen(seqPtr)-1);
			nnucleotidi = nnucleotidi + (strlen(seqPtr)-1);
		}
	}
	fclose(fPtr);
	printf("Numero sequenze: %d\n", nseq);
	printf("Lunghezza della sequenza più lunga: %d\n", maxlenght);
	printf("Numero totale di nucleotidi: %d\n", nnucleotidi);
	return 0;
}