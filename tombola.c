#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define frand() ((double) rand()/(RAND_MAX+1.0)*90)
int extact[90];
void super_enalotto();
int main(){
	int x=0,i;
	int estratti = 0;
	int number;
	srand((unsigned)time(NULL));
	for(i=0; i<90; i++)
		extact[i]=0;
	while(estratti < 90){
		number = frand()+1;
		if(extact[number]!=1){
			x++;
			printf("%2d ",number);
			if(x==10){
				printf("\n");
				x=0;
			}
			extact[number]=1;
			estratti++;
		}
	}
	printf("Super enalotto\n");
	super_enalotto();
	return 0;
}

/* Estrae 6 numeri casuali nel range 1-90 estremi compresi */
void super_enalotto(){
	int i;
	int estratti = 0;
	int number;
	srand((unsigned)time(NULL));
	for(i=0; i<90; i++)
		extact[i]=0;
	while(estratti < 6){
		number = frand()+1;
		if(extact[number]!=1){
			printf("%2d ",number);
			extact[number]=1;
			estratti++;
		}
	}
	printf("\n");
}
