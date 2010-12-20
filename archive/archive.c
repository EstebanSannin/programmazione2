#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

#define BUFFSIZE 8192
#define PERMS 0666

int main(int argc, char **argv){
	int fin,i,fout;
	if(argc<3)
		exit(1);
	struct stat fsbuf;
	int number_file=argc-2;
	char *archive_name=argv[1];
	char buf[BUFFSIZE];

	if ((fout = creat(argv[1], PERMS)) == -1){
		printf("can't create %s, mode %03o",argv[2], PERMS);
		exit(1);
	}
	write(fout, &number_file, sizeof(int));
	for(i=0; i<number_file; i++){
		if((fin=open(argv[2+i],O_RDONLY))!=-1){
			char buf[BUFFSIZE];
			int n;
			stat(argv[2+i],&fsbuf);
			char *name=argv[2+i];
			write(fout, name, strlen(name)+1);
			write(fout, &fsbuf, sizeof(fsbuf));
			printf("size: %d\n",sizeof(fsbuf));
		//	write(fout, &fsbuf.st_size, sizeof(fsbuf.st_size));
			while( (n=read(fin, buf, BUFFSIZE)) > 0)
			{
				if (write(fout, buf, n) != n){
					perror("main");
					exit(errno);
				}

			}
		}
	}
	close(fin);
}
