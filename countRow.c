/*Contare tutte le righe contenute in un file*/

#include <stdio.h>

main(){
	int c, row=0;
	while((c = getchar())!=EOF){
		if(c == '\n')
			row++;
	}
	printf("row: %d\n",row);
}
