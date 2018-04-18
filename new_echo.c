#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	char *inputText = NULL;

	//for loop run though ever parameter
	//and print it to stdout
	for(int k = 1; k < argc; ++k){
	printf("%s  ",argv[k]);
	fflush(stdout);

	}

	printf("\n");

	return 0;
}

