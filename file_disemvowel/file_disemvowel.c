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
	for(;;){	
		num_in = fread((void *) in_buf, sizeof(char), BUF_SIZE, inputFile);
		num_out = copy_non_vowels(num_in, in_buf, out_buf);
		fwrite(out_buf,sizeof(char), num_out, outputFile);
		//check if you need to loop again
		if(num_in < BUF_SIZE)
			//check for end of file
			if(feof(inputFile)){
				break;
			}
	}	
}

int main(int argc, char *argv[]) {
	FILE* inputFile;  
	FILE* outputFile;
	
	//check for improper arguments
	if(argc > 3){
		
		printf("too many arguments");
		return 1;
	
	//case one: read from a file, write to standard output	
	} else if(argc==2){
		
		inputFile = fopen(argv[1], "r+");
		outputFile = stdout;

	//case two: read from a file, write to a file
	} else if(argc==3){
		
		inputFile = fopen(argv[1], "r+");
		outputFile = fopen(argv[2], "w+");
	
	//case three: read standard input, write to standard output	
	} else {
		
		inputFile = stdin;
		outputFile = stdout;
	}
		
	//run sub-function
	disemvowel(inputFile, outputFile);
	
	//close streams
	fflush(stdout);	
	fclose(inputFile);
	fclose(outputFile);

	return 0;
}
