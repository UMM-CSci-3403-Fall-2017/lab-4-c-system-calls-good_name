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
	bool vowel = false;

	if((c == 'a'|| c == 'e'|| c == 'i'|| c == 'o'|| c == 'u'|| c == 'A'|| c == 'E'|| c == 'I'|| c== 'O'|| c == 'U')){
			vowel = true;
	}

	return vowel;
}	


int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
    /*TODO
     * Copy all the non-vowels from in_buf to out_buf.
     * num_chars indicates how many characters are in in_buf,
     * and this function should return the number of non-vowels that
     * that were copied over.
     */
	int num_non_vowels = 0;
	
	
	for(int i = 0; i < num_chars; i++){
		if(!is_vowel(in_buf[i])){
			num_non_vowels++;
		}
	}
	
	int out_ind = 0;
	
	for(int i = 0; i < num_chars; i++){
		if(!is_vowel(in_buf[i])){
			out_buf[out_ind]=in_buf[i];
			out_ind++;
		}
	}

	return num_non_vowels;

}

void disemvowel(FILE* inputFile, FILE* outputFile) {
    /*TODO
     * Copy all the non-vowels from inputFile to outputFile.
     * Create input and output buffers, and use fread() to repeatedly read
     * in a buffer of data, copy the non-vowels to the output buffer, and
     * use fwrite to write that out.
     */	

	
	char in_buf[BUF_SIZE];
	char out_buf[BUF_SIZE];
	size_t in;
	
	while(!feof(inputFile)){
	
		in = fread((void *) in_buf, sizeof(char),BUF_SIZE,inputFile);
		copy_non_vowels(in, in_buf, out_buf);
		//printf("%s\n %zd\n", out_buf, in);		
		fwrite(out_buf,sizeof(char), in-sizeof('a'), outputFile);
	}
	
	//fwrite(out_buf,sizeof(char),strlen(buffer)-sizeof('a'), stdout);
	
	//outputFile = fopen("out.txt", "w+");
	//fwrite(out_buf,sizeof(char),strlen(buffer)-sizeof('a'), outputFile);

	//fflush(stdout);
	//fclose(inputFile);
	//fclose(outputFile);

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

