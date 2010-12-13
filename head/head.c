/*
 * NAME: head.c
 *
 *
 *
 *  AUTHOR: Stefano Viola (estebanSannin)
 * LICENSE: GPLv3
 * CONTACT: stefanoviola[@]sannioglug[.]org
 *
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* start Prototype declaration */

void usage();

/*end Prototypr declaration */


/* START PROGRAM*/

int main(int argc, char *argv[]){
	int i;
	int line;
	if (argc < 2){
		line = 10;
	}else if (argc > 2){
		usage();
		exit(0);
	}else{
		if(!strcmp(argv[1],"--help")){
			usage();
			exit(1);
		}

		int parm = atoi(argv[1]);
		if (parm < 0)
			line = parm* (-1);
		else{

			printf("head: Opzione non valida. -- \"%s\"\n",argv[1]);
			printf("Usare `head --help' per ulteriori informazioni.\n");

			//line = 10;
			exit(1);
		}

	}
	int c;
	c = getchar();
	for (i=0; i<line; i++){
		while (c!=EOF) {
			putchar(c);
			c = getchar();
			if (c == '\n')
				break;
		}
	}
	printf("\n");
	return 0;
}
void usage(){

	printf("-HEAD- USAGE:\n"
			"\thead < file    ---> print to stdout the first 10 line of file\n"
			"\thead -n < file ---> print n line of file \n"
			"\thead -h 	  ---> print this message.\n");

}

/* END PROGRAM */
