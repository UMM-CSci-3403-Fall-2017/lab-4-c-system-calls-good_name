#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

bool is_vowel(char c) {
	
	//initialize boolean and vowel array	
	bool vowel = false;
	char vowels[] = "aeiouAEIOU";
	
	//check if char is vowel
	for(int i = 0; i < strlen(vowels); i++){
		if(c==vowels[i]){
			vowel=true;
		}
	}
	
	//returns true if c is a vowel	
	return vowel;
}	


int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
    
	//find amount of non vowels
	int num_non_vowels = 0;
	for(int i = 0; i < num_chars; i++){
		if(!is_vowel(in_buf[i])){
			num_non_vowels++;
		}
	}
	
	//copy non-vowels from input buffer to output buffer
	int out_ind = 0;	
	for(int i = 0; i < num_chars; i++){
		if(!is_vowel(in_buf[i])){
			out_buf[out_ind]=in_buf[i];
			out_ind++;
		}
	}
	
	//returns amount of non-vowels
	return num_non_vowels;

}

void disemvowel(FILE* inputFile, FILE* outputFile) {
	
	//initialize vars
	char in_buf[BUF_SIZE];
	char out_buf[BUF_SIZE];
	size_t num_in;
	int num_out;
	
	//loop until end of file, reading input buffer and writing
	//disemvoweled version to output buffer
	while(!feof(inputFile)){
		num_in = fread((void *) in_buf, sizeof(char), BUF_SIZE, inputFile);
		num_out = copy_non_vowels(num_in, in_buf, out_buf);
		fwrite(out_buf,sizeof(char), num_out, outputFile);
	}	
}

int main(int argc, char *argv[]) {
	FILE *inputFile;  
	FILE *outputFile;
	
	inputFile = fopen("in.txt", "r+");
	outputFile = fopen("test_out.txt", "w+");

	disemvowel(inputFile, outputFile);
		
	fclose(inputFile);
	fclose(outputFile);

	return 0;
}
