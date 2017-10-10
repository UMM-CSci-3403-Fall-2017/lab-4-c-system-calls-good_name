#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

bool is_vowel(char c) {
    /* TODO
     * Returns true if c is a vowel (upper or lower case), and
     * false otherwise.
     */
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
    /*TODO
     * Copy all the non-vowels from in_buf to out_buf.
     * num_chars indicates how many characters are in in_buf,
     * and this function should return the number of non-vowels that
     * that were copied over.
     */
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
    /*TODO
     * Copy all the non-vowels from inputFile to outputFile.
     * Create input and output buffers, and use fread() to repeatedly read
     * in a buffer of data, copy the non-vowels to the output buffer, and
     * use fwrite to write that out.
     */
}

int main(int argc, char *argv[]) {
	FILE *inputFile;  
	FILE *outputFile;
	char buffer[BUF_SIZE];
	
	inputFile = fopen("test.txt", "rw+");
	
	fread(buffer,sizeof(char),BUF_SIZE,inputFile);
    	
	//printf("We got [%s]\n",buffer);

	fwrite(buffer,sizeof(char),strlen(buffer)-sizeof('a'), stdout);
	
	outputFile = fopen("test2.txt", "ab+");
	fwrite(buffer,sizeof(char),strlen(buffer)-sizeof('a'), outputFile);

	fflush(stdout);
	fclose(inputFile);
	fclose(outputFile);

	//disemvowel(inputFile, outputFile);

	return 0;
}

