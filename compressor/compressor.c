#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include"rlestruct.h"

main(int argc, char **argv)
{
	printf("%d\n",MAXLEN);
	FILE *fin, *fout;
	if(argc==2){
		if(fin=fopen(argv[1],"r"))
		{
			if(fout=fopen(strcat(argv[1],".rle"),"w"))
			{
				rleType data;
				char c;
				fread(&c, sizeof(c), 1, fin);
				data.count=1;
				data.c=c;
				int error;
				fread(&c, sizeof(c), 1, fin);
				while(!feof(fin))
				{
					if(c!=data.c || data.count==MAXLEN)
					{
						fwrite(&data,sizeof(data),1,fout);
						if(error=ferror(fout))
						{
							perror(strcat(argv[1],".rle"));
							exit(error);
						}
						data.c=c;
						data.count=1;
					}
					else
						data.count++;
					fread(&c, sizeof(c), 1, fin);
				}
				fwrite(&data,sizeof(data),1,fout);
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
