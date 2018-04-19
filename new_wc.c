#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(int argc, char *argv[]){

	//user input parameter
	//nned to check is it file or flag -n
	int flagCheck = 0;//0 = all, 1 = -l, 2 = -c
	int fileCheck = 0;//0 = no file, 1 = have file
	int line = 0;
	int word = 0;
	int chCount = 0;
	char ch = 0;
	int spaceCheck =0;//is last ch sapce or not,
			//0 is not,1 it is
	FILE *inputFile = NULL;
	//if ther is only one paramter
	//it could be flag or file name
	if(argc == 2){
	if(strcmp(argv[1], "-l") == 0){
	flagCheck = 1;
	}else if(strcmp(argv[1], "-L") == 0){
	flagCheck = 1;
	}else if(strcmp(argv[1], "-c") == 0){
	flagCheck = 2;
	}else if(strcmp(argv[1], "-C") == 0){
	flagCheck = 2;
	}else{
	inputFile = fopen(argv[1],"r");
	fileCheck = 1;
	}
	}
	//check which argument is flag
	//and check is file input valid or not
	if(argc == 3){
		if(strcmp(argv[1], "-l") == 0){
		inputFile = fopen(argv[2],"r");
		fileCheck = 1;
		flagCheck = 1;
		}else if(strcmp(argv[1], "-L") == 0){
		inputFile = fopen(argv[2],"r");
		fileCheck = 1;
		flagCheck = 1;
		}else if(strcmp(argv[1], "-c") == 0){
		inputFile = fopen(argv[2],"r");
		fileCheck = 1;
		flagCheck = 2;
		}else if(strcmp(argv[1], "-C") == 0){
		inputFile = fopen(argv[2],"r");
		fileCheck = 1;
		flagCheck = 2;
		}else if(strcmp(argv[2], "-l") == 0){
		inputFile = fopen(argv[1],"r");
		fileCheck = 1;
		flagCheck = 1;
		}else if(strcmp(argv[2], "-L") == 0){
		inputFile = fopen(argv[1],"r");
		fileCheck = 1;
		flagCheck = 1;
		}else if(strcmp(argv[2], "-c") == 0){
		inputFile = fopen(argv[1],"r");
		fileCheck = 1;
		flagCheck = 2;
		}else if(strcmp(argv[2], "-C") == 0){
		inputFile = fopen(argv[1],"r");
		fileCheck = 1;
		flagCheck = 2;
		}else{
		printf("Invalid flag");
		}
	}
	//if user did enter input, but can't find it,
	//print error messeage and leave program
	if((fileCheck == 1)&&(inputFile == NULL)){
	printf("Can not find direction\n");
	return 0;
	}



	//if there is a file use file,
	//if no use the input that user type in

	//count ch by increase number eveytime have newgetc
	//count line by \n
	//count word by space or \n
	//wordcount - 1, because before eof will have one extra changeline

	if(inputFile != NULL){
		while((ch = getc (inputFile))!= EOF){
		if(ch == '\n'){
		line++;
		word++;
		}

		if(ch == ' '){
			if(spaceCheck == 0){
			word++;
			spaceCheck = 1;
			}
		}else{
		spaceCheck = 0;
		}

		chCount++;
		}

	fclose(inputFile);
	}else{
		while((ch = getchar ())!= EOF){
		if(ch == '\n'){
		line++;
		word++;
		}

		if(ch == ' '){
			if(spaceCheck == 0){
			word++;
			spaceCheck = 1;
			}
		}else{
		spaceCheck = 0;
		}

		chCount++;
		}
		word--;
	}
	printf("\n");
	//flagCheck =1 print line
	if(flagCheck == 1){
	printf("line\n");
	printf("%d\n",line);
	//flagCheck = 2 print Character
	}else if(flagCheck == 2){
	printf("ch\n");
	printf("%d\n",line,word,chCount);
	}else{
	printf("line	word	ch\n");
	printf("%d	%d	%d\n",line,word,chCount);
	}
	return 0;
}

