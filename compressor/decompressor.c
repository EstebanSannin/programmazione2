#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include"rlestruct.h"
#define EXTENSION ".rle"

main(int argc, char **argv)
{
	FILE *fin, *fout;
	if(argc==2){
		char rle[4];
		int i=0, dim=strlen(argv[1]);
		int name_dim=dim-4;
		while(i<=4){
			rle[i]=argv[1][i+name_dim];
			i++;
		}
		if(!strcmp(EXTENSION, rle))
			printf("estenzione valida\n");
		else{
			printf("Estenzione file non valida!\n");
			exit(1);
		}
		char file[name_dim+1];
		i=0;
		while(i<name_dim){
			file[i]=argv[1][i];
			i++;
		}
		file[name_dim]='\0';

		if(fin=fopen(argv[1],"r"))
		{
			if(fout=fopen(file,"w"))
			{
				rleType data;
				char c;
				int error;
				fread(&data,sizeof(data),1,fin);
				while(!feof(fin)){
					for(i=0;i<data.count;i++){
						fwrite(&data.c,sizeof(data.c),1,fout);
						//putc(data.c,fout);
					}
					fread(&data,sizeof(data),1,fin);
				}
				fclose(fout);
			}
			else // cannot open fout
			{
				perror(strcat(argv[1],".rle"));
				exit(ferror(fout));
			}
			fclose(fin);
		}
		else //cannot open fin
		{
			perror(argv[1]);
			exit(2);
		}
	}
	else //wrong number of parameters
		fprintf(stderr,"Syntax: %s file\n",argv[0]);
}

