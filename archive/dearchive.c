#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <utime.h>

#define PERMS 0666

int main(int argc, char **argv){
	int fin,i,j,x,fout;
	struct stat fsbuf;
	struct utimbuf time_file;
	char *filename,c;
	filename= (char *) malloc(100*sizeof(char));

	if(argc!=2)
		exit(1);

	if((fin=open(argv[1],O_RDONLY))!=-1){

		int n;
		n=read(fin, &c, sizeof(int));
		if(n!=sizeof(int))
			exit(1);
		printf("numero file: %d\n", c);
		int number_file= c;

		for(i=0; i<number_file; i++){
			n=read(fin, &c, 1);
			j=0;
			filename= (char *) malloc(100*sizeof(char));

			while(c!='\0'){
				filename[j]= c;
				n=read(fin, &c, 1); j++;
			}

			filename[j+1]='\0';
			printf("\nnome file %s\n",filename);
			n=read(fin, &fsbuf, sizeof(fsbuf));
			printf("permessi: %o\n",fsbuf.st_mode);
			if ((fout = creat(filename, fsbuf.st_mode)) == -1){
				printf("can't create %s, mode %03o",filename, PERMS);
				exit(1);
			}
			//read(fin, &fsbuf.st_size, sizeof(fsbuf.st_size));
			int dim=fsbuf.st_size;
			n=0;
			while(n!=dim){
				n+=read(fin, &c, 1);
				write(fout, &c, 1);
			}
			close(fout);
			printf("userid: %d , usergroup: %d\n",fsbuf.st_uid, fsbuf.st_gid);
			chown(filename, fsbuf.st_uid, fsbuf.st_gid);
			time_file.actime=fsbuf.st_atime;
			time_file.modtime=fsbuf.st_mtime;
			utime(filename, &time_file);
			printf("size: %d\n",dim);
			*filename = 0;
		}
	}
}

