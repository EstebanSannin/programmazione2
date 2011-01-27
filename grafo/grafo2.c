#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESCR 	50
#define FALSE 		0
#define TRUE 		!FALSE


typedef struct _Record {
	int from;
	int to;
	char descr[MAX_DESCR+1];

	struct _Record *next;
} Record;

Record *list = NULL;

void insert_after(Record *r, Record *n){
	n->next = r->next; // n->next puntera' a cosa puntava l'ultimo elemento della lista e all'elemento r->next (ex current) puntera' al nuovo
	r->next = n;
}

Record *last(){
	Record *curr;
	curr = list;

	while(TRUE){
		if(!curr->next)
			break;
		curr = curr->next;
	}

	return curr;
}

int add(const int from, const int to, const char *descr){
	Record *r;
	r = malloc(sizeof(Record));
	if(r != NULL){
		r->from = from;
		r->to = to;
		strcpy(r->descr, descr);

		Record *curr;
		curr = last();
		insert_after(curr,r);

		return TRUE;
	}else
		return FALSE;
}

int remove_n(const int from){
	Record *curr;
	Record *prev = NULL;
	curr = list;

	while(curr){
		if(curr->from == from){
			prev->next = curr->next;
			free(curr);

			return TRUE;
		}

		prev = curr;
		curr = curr->next;
	}

	return FALSE;
}

Record *get(const int from){
	Record *curr;
	curr = list;

	while(curr){
		if(curr->from==from)
			break;
		curr = curr->next;
	}

	return curr;
}

void print(){
	Record *curr;
	curr = list;

	printf("\n");
	printf("        From        To        Descrizione\n");
	printf("============================================\n");

	while(curr){
		printf("%10d %10d  %20s\n", curr->from, curr->to,
				curr->descr);
		curr = curr->next;
	}

	printf("\n");
}

int get_to(const int from){
	int to;

	return to;

}

int *ampiezza(int from, int *vect){
	Record *curr;
	curr = list;
	int j;
	static int memory[10];
	static int i = 1;
	memory[from]=1;
	static int count = 0;
	while(curr){
		if(curr->from==from){
			if(memory[curr->to]!=1 ){
				vect[i]=curr->to;
				i++;
			}
			memory[curr->to] = 1;
		}
		curr = curr->next;
	}

	int len = i;
	count++;
	if(count<len){
		ampiezza(vect[count],vect);	
	}
}


int main(){
	Record r1, *r;

	r1.from=1;
	r1.to=2;
	strcpy(r1.descr, "Nodo 1 ---> 2");
	r1.next=NULL;
	list=&r1;

	add(1, 3, "Nodo 1 ---> 3");
	add(3, 4, "Nodo 3 ---> 4");
	add(4, 1, "Nodo 4 ---> 1");
	add(2, 5, "Nodo 2 ---> 5");
	add(5, 2, "Nodo 5 ---> 2");

	print();

	int *vect=calloc(10,sizeof(int));
	int node;
	
	printf("Inserire nodo di partenza: ");
	scanf("%d",&node);
	
	vect[0]=node;
	ampiezza(node,vect);
	
	int i=0;
	printf("Ampiezza: ");
	while(vect[i]!=0){
		printf("%d ",vect[i]);

		i++;
	}
	putchar('\n');


	return 0;
}
