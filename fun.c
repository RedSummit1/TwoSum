#define CLOCKS_PER_MICROSECOND (CLOCKS_PER_SEC / 1000000)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void _Menu(unsigned int* p_num);

void PopulateFile();

long int _TwoSum(char* test,int size,float* time);

void PerformTwoSum();

int main(){

	PopulateFile();
	PerformTwoSum();

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
		hlength = ((random() % 401) + 100);
		for(int j = 0; j < hlength - 1; ++j){
			fprintf(wfile,"%ld,",random()%10001);		
		}
		fprintf(wfile,"%ld\n",random()%10001);		
	}
	pclose(wfile);
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
	FILE* wfile = fopen("y","w");
	char* parsed_str1;
	char* parsed_str2;
	int count = 1;
	float time = 0;
	long total = 0;

	//char* line  = _LineFeed();
	char* line = NULL;
	size_t size = 0;
	fprintf(wfile,"Total_Sum,Time\n");
	while(getline(&line,&size,rfile) != -1){
		total = _TwoSum(line,size,&time);
		fprintf(wfile,"%ld,%f\n",total,time);
		count++;
	}
	pclose(rfile);
	pclose(wfile);

}
