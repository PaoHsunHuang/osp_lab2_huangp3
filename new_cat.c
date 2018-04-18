#define _GUN_SOURCE
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
	//if there is more than one parameter, assume it as
	//the input file name
	if(argc > 1) {
	char *inputText = NULL;
	FILE *inputFile;
	size_t lineSize= 256;

	inputFile = fopen(argv[1],"r");
	//try to open argv[1]
	//if can open 
	//run though whole file and print it
	//or print out warning if can't find file
		if(inputFile != NULL){

			while(getline(&inputText,&lineSize,
			inputFile) != -1){
			printf("%s", inputText);
			}
		}else{
			printf("Can't not find direction");
		}
		fclose(inputFile);
	//if user didn't input any parameter
	//repeat what user input until press CTRL+D
	}else{
	char ch = 0;
	char *inputString = NULL;
	int x = 0;
		while(ch != EOF){
			ch = getchar();
			if(ch != EOF){
				printf("%c", ch);
			}
		}

	}
	return 0;
}

