#include "sentence_count.h"
#include <stdio.h>

void sentence_count(char* input_file_name, char* output_file_name){

	FILE *inPtr; // pointer for input fule 
	FILE *outPtr; // pointer for output file

	// variables declared/initialized here 
	int questions = 0;
	int exclamations = 0;
	int statements = 0;
	int total = 0;
	char x;

	// opens input file 
	inPtr = fopen(input_file_name,"r");
	// Checks if file opened successfully
	if(inPtr){
		while((x=getc(inPtr)) != EOF){
			// counts number of question marks
			if(x == '?'){ 
				questions++; 
			}
			// counts number of exclamation points
			if(x == '!'){
				exclamations++;
			}
			// counts number of periods 
			if(x == '.'){
				statements++;
			}
		}
		// adds up all sentence types for total
		total = questions + exclamations + statements;
		// closes input file 
		fclose(inPtr);

	}
	else {
		printf("File not sucessfully opened.\n");
	}

	// opens output file 
	outPtr = fopen(output_file_name,"w+");

	// writes needed info to output file 
	fputs("Questions: ",outPtr);
	fprintf(outPtr, "%d\n", questions);
	fputs("Exclamations: ",outPtr);
	fprintf(outPtr, "%d\n", exclamations);
	fputs("Statements: ",outPtr);
	fprintf(outPtr, "%d\n", statements);
	fputs("Total: ",outPtr);
	fprintf(outPtr, "%d\n", total);
	// closes output file 
	fclose(outPtr);


}
