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
#define CLOCKS_PER_MICROSECOND (CLOCKS_PER_SEC / 1000000)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void _Menu(unsigned int* p_num);

void PopulateFile();

int _CountTotalCharaters(FILE* rfile);

char* _LineFeed(){
	FILE* rfile = fopen("x","r");
	int sizeofLine;

	if (!rfile){
		printf("File not detected, aborting program\n");
		exit(1);
	}
	//Represents each line, will put in a for loop
	
	//sizeofLine = _CountTotalCharaters(rfile);
	//printf("The amount of characters in this line is %d\n",sizeofLine);

	char* line = malloc(sizeofLine); //Cannot use char* line[sizeofLine], stores values in static memory which is freed once the function ends
									 //To have continued access to memory after function invocation use malloc to use dynamically sourced memory

	if (line == NULL){
		printf("Error");
		exit(1);	
	}

	fgets(line,sizeofLine,rfile);
	printf("The values in the line are ---> %s",line);
	return line;

}

long int _TwoSum(char* test,int size,float* time){
	int arr[size];
	int i = 0;
	int length = 0;
	char* parsed_str;
	long totalSum = 0;
	time_t start,end;


	parsed_str = strtok(test,",");
	while(parsed_str != NULL){
		arr[i] = atoi(parsed_str);
		parsed_str = strtok(NULL,",");	
		//printf("%ld\n",arr[i]);
		i++;
	}

	length = i;
	

	start = clock();
	for(int a = 0; a < length; ++a){
			//printf("Numbers: %d\n",arr[a]);
		for(int j = 1 + a; j < length; ++j){
			totalSum += arr[a] + arr[j];
		}

	}
	end = clock();

	*time = (float)(end - start)/CLOCKS_PER_MICROSECOND;
	return totalSum;
}

void PerformTwoSum(){
	FILE* rfile = fopen("x","r");
	char* parsed_str1;
	char* parsed_str2;
	int count = 1;
	float time = 0;

	//char* line  = _LineFeed();
	char* line = NULL;
	size_t size = 0;
		
	while(getline(&line,&size,rfile) != -1){
		printf("\nLine %d's total sum is %ld.\n",count,_TwoSum(line,size,&time));
		printf("The value of time is %f microseconds.\n\n",time);
		count++;
	}

}

int main(){

	PopulateFile();
	PerformTwoSum();

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


void _Menu(unsigned int* p_num){
	printf("Two Sum program\n");
	printf("How many test do you want to perform: ");
	scanf("%d",p_num);
	printf("%d %s will be performed\n",*p_num,(*p_num > 1 ? "tests" :"test"));
}


void PopulateFile(){
	
	unsigned int trials, hlength;

	_Menu(&trials);
	FILE* wfile = fopen("x","w");

	if (!wfile){
		printf("File not detected, aborting program\n");
		exit(1);
	}

	for(int i = 0; i < trials; ++i){
		hlength = ((random() % 401) + 100); // length can be between 100 and 500
		for(int j = 0; j < hlength - 1; ++j){
			fprintf(wfile,"%ld,",random()%10001);		
		}
		fprintf(wfile,"%ld\n",random()%10001);		
	}
	pclose(wfile);
}

int _CountTotalCharaters(FILE* rfile){
	int c, count;

	while( c != EOF && c != '\n' ){
		c = fgetc(rfile);
		count++;
	}

	return count;
}
