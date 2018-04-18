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
	//print a line
	//for no parameter line feed
	//and the space after print all parameter
 	printf("\n");

	return 0;
}

