/* 
 * Plan to execute:
 *
 * 1) Automate populating text file with random integers
 * 2) Feed from populated text file to program
 * 3) Take values and move to array
 * 4) Use nested for loop to solve problem
 * 5) Output results to output file
 *
 */




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _Menu(int* p_num);


void PopulateFile(){
	
	int trials;
	unsigned int hlength; 

	_Menu(&trials);
	FILE* wfile = fopen("x","w");

	if (wfile == NULL){
		printf("File not detected, aborting program\n");
		exit(1);
	}

	for(int i = 0; i < trials; ++i){
		hlength = (random() % 401) + 100; // length can be between 100 and 500
		for(int j = 0; j < hlength - 1; ++j){
			fprintf(wfile,"%ld,",random()%10001);		
		}
		fprintf(wfile,"%ld\n",random()%10001);		
	}
	printf("Done nig");



}





int main(){

	char line[10]; // Take in 

	PopulateFile();


	//Variable to store line string
//	int num;
//
//	FILE* infile = fopen("x","r");
//	
//	// Get file
//	fgets(line,10,infile);
//	char* parsed_str = strtok(line," ,.");
//
//	while(parsed_str != '\0'){
//		printf("%d ",atoi(parsed_str));
//		parsed_str = strtok('\0', " ,.");
//	}
//
//	for(unsigned int i = 0; i < 10; ++i){
//		printf("%ld\n",random()%100);
//	}
//

	

	return 0;
}


void _Menu(int* p_num){
	printf("Two Sum program\n");
	printf("How many test do you want to perform: ");
	scanf("%d",p_num);
	printf("%d tests will be performed",*p_num);
}




