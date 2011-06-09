#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define BUFF 1024

void help();

main(int argc, char *argv[]){
	char line[BUFF];
	char line2[BUFF];
	
	if(argc!=3)
		help();

	FILE *fp = fopen(argv[1], "r");
	FILE *fp2 = fopen(argv[2], "r");

	if(fp == NULL){
		perror(argv[1]);
		exit(2);
	}
	if(fp2 == NULL){
		perror(argv[2]);
		exit(2);
	}

	printf("Output:\n\n");
	int i = 0;
	printf("%8s %10s\n\n","line", "content");
	while (fgets(line, sizeof(line), fp) && fgets(line2, sizeof(line2), fp2) ){
		i++;
		if(strcmp(line,line2))
			printf("%8d:   %s%8d:   %s\n", i, line, i, line2);
	}
	return 0;
}

void help(){
	
	printf("\n\tSimple diff utility:\n\n");
	printf("Error: Argument required!\n\n");
	printf("Usage: diff file1 file2 \n\n");
	exit(1);

}
