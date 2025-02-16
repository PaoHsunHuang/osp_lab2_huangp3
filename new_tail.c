#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
size_t lineSize = 256;
int lineNum = 5;

int numberCheck (char *argv){
	int num = 0;
	char inputString[lineSize];
	//convert to number, lose any char beside number
	num = atoi(argv);
	sprintf(inputString, "%d", num);

	//compare to original string, if they are smae 
	//string is a number, if not there are some char inside
	//return the correct number, if string is num
	if((strcmp(argv,inputString) == 0)){
	lineNum = num;
	return 1;
	}else{
	printf("'%s' is not number\n",argv);
	return 0;
	}

}
int main(int argc, char *argv[]){

	//user input parameter
	//nned to check is it file or flag -n
	FILE *inputFile = NULL;
	int flagCheck = 0;//1 = right flag, 0 = wrong flag
	int numCheck = 1;//1 = it is number, 0 = it is not

	//if ther is only one paramter
	//it must be open file, and argument 1
	//must be the file name
	if(argc == 2){
	inputFile = fopen(argv[1],"r");
	if(inputFile == NULL){
		printf("Can not find direction\n");
		return 0;
	}

	}
	//if there is two parameter
	//it musy be -n and the number
	if(argc == 3){
		if(strcmp(argv[1], "-n") == 0){
		flagCheck = 1;
		}else if(strcmp(argv[1], "-N") == 0){
		flagCheck = 1;
		}else{
		printf("flag is incorrect\n");
		return 0;
		}
		numCheck = numberCheck(argv[2]);
		if(numberCheck == 0){
		return 0;
		}
	}

	if(argc == 4){
		//if 1 argument is flag -n,
		//2 argument is the line number

		//if 2 argument is flag -n,
		//3 argument is the line number

		//if something else this command line
		//content error, leave program
		if(strcmp(argv[1], "-n") == 0){
		numCheck = numberCheck(argv[2]);
		inputFile = fopen(argv[3],"r");

		} else if(strcmp(argv[1], "-N") == 0){
		numCheck = numberCheck(argv[2]);
		inputFile = fopen(argv[3],"r");

		} else if(strcmp(argv[2], "-n") == 0){
		numCheck = numberCheck(argv[3]);
		inputFile = fopen(argv[1],"r");

		} else if(strcmp(argv[2], "-n") == 0){
		numCheck = numberCheck(argv[3]);
		inputFile = fopen(argv[1],"r");

		}else{
		printf("flag is incorrect\n");
		return 0;
		}
		if(inputFile == NULL){
		printf("Can not find direction\n");
		return 0;
		}
	}
	//set varaible for save string
	char saveString[lineNum][lineSize];
	char *inputText;
	char ch;
	//if there is a file use file,
	//if no use the input that user type in
	if(inputFile != NULL){
		while((ch = getline(&inputText,
			&lineSize, inputFile))!= -1){
//		start from the last element,
//		since last one will be delet anyway
		for(int i = (lineNum - 1); i != 0; i--){
		strcpy(saveString[i],saveString[i-1]);
		}
		strcpy(saveString[0],inputText);
	}

	fclose(inputFile);
	}else{
		while((ch  = getchar())!= EOF){
		ungetc(ch,stdin);
		getline(&inputText,&lineSize,stdin);

		for(int i = (lineNum - 1); i !=  0; i = i - 1){
		strcpy(saveString[i],saveString[i-1]);
		}
		strcpy(saveString[0],inputText);
		}
	}
	//print out the string
	for(int i = 0; i < lineNum; i++){
		printf("%s",saveString + i);
	}
	return 0;
}

