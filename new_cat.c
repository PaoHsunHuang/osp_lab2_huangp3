#define _GUN_SOURCE
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	char *inputText = NULL;
	FILE *inputFile;
	size_t lineSize= 256;

	if(argc > 1) {
	inputFile = fopen(argv[1],"r");

		if(inputFile != NULL){

		while(getline(&inputText,&lineSize,inputFile) != -1){
		printf("%s", inputText);
		}
		}else{
		printf("Can't not find direction");
		}
	fclose(inputFile);
	}

	//int i = argc;
	//printf("input: %d data\n",argc);

	//for(int k = 0; k < argc; ++k){
	//printf("data %d = %s\n",k ,argv[k]);
	//}

	return 0;
}

