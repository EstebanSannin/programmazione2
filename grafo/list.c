#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_DESCR 	50
#define FALSE 		0
#define TRUE 		!FALSE


typedef struct _Record {
	int id;
	char descr[MAX_DESCR+1];

	struct _Record *next;
} Record;

Record *list = NULL;

Record r1;

r1.id=10;
strcpy(r1.descr, "Descrizione 10");
r1.next=NULL;
list=&r1;

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

void add(Record *r){
	Record *curr;
	curr = last();

	insert_after(curr, r);
}

Record *remove(Record *r){
	Record *curr;
	Record *prev = NULL;
	curr = list;

	while(curr){
		if(curr == r){
			prev->next = curr->next;
			break;
		}
		
		prev = curr;
		curr = curr->next;
	}

	return curr;
}

void print(){
	Record *curr;
	curr = list;

	printf("          Id  Descrizione\n");
	printf("=========================\n");

	while(curr){
		printf("%10d  %s\n", curr->id,
			curr->descr);
		curr->next;
	}

	printf("\n");
}
