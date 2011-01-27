#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESCR 	50
#define FALSE 		0
#define TRUE 		!FALSE


typedef struct _Record {
	int id;
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

int add(const int id, const char *descr){
	Record *r;
	r = malloc(sizeof(Record));
	if(r != NULL){
		r->id = id;
		strcpy(r->descr, descr);

		Record *curr;
		curr = last();
		insert_after(curr,r);

		return TRUE;
	}else
		return FALSE;
}

int remove_n(const int id){
	Record *curr;
	Record *prev = NULL;
	curr = list;

	while(curr){
		if(curr->id == id){
			prev->next = curr->next;
			free(curr);

			return TRUE;
		}
		
		prev = curr;
		curr = curr->next;
	}

	return FALSE;
}

Record *get(const int id){
	Record *curr;
	curr = list;

	while(curr){
		if(curr->id==id)
			break;
		curr = curr->next;
	}

	return curr;
}

void print(){
	Record *curr;
	curr = list;

	printf("        Id  Descrizione\n");
	printf("=========================\n");

	while(curr){
		printf("%10d  %s\n", curr->id,
			curr->descr);
		curr = curr->next;
	}

	printf("\n");
}


int main(){
	Record r1, *r;

	r1.id=10;
	strcpy(r1.descr, "Descrizione 10");
	r1.next=NULL;
	list=&r1;

	add(15, "Descrizione 15");
	add(30, "Descrizione 30");
	add(23, "Descrizione 23" );

	print();

	r=last();
	printf("Descrizione ultimo nodo: %s\n",r->descr);

	printf("\nRimuovo l'elemento 30\n");
	remove_n(30);
	print();

	printf("\nRimuovo l'elemento 15\n");
	remove_n(15);
	print();

	return 0;
}
