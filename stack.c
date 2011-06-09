#include <stdio.h>
#include <string.h>

#define MAX_DESCR 50

typedef struct _Record {
	int id;
	char descr[MAX_DESCR+1];

	struct _Record *next;
} Record;

Record *head = NULL;

void push(Record *r) {
	r->next = head;
	head = r;
}

Record *pop() {
	Record *r;
	
	r = head;
	if(head!=NULL)
		head = head->next;
	return r;
}

int lenght() {
	int count = 0;
	Record *r;

	r = head;
	while(r){
		count++;
		r = r->next;
	}
	return count;
}


/*Main for testing function*/

int main() {
	Record r1, r2, r3, *r;
	Record r4, r5;


	r1.id = 10;
	strcpy(r1.descr,"Descrizione 10");
	push(&r1);
	printf("push(10)\n");

	r2.id = 15;
	strcpy(r2.descr,"Descrizione 15");
	push(&r2);
	printf("push(15)\n");

	r3.id = 30;
	strcpy(r3.descr,"Descrizione 30");
	push(&r3);
	printf("push(30)\n");

	printf("lenght(): %d\n",lenght());

	r = pop();
	printf("pop(): %p %s\n", r,(r==NULL ? " " : r->descr));
	
	r = pop();
	printf("pop(): %p %s\n", r,(r==NULL ? " " : r->descr));

	r = pop();
	printf("pop(): %p %s\n", r,(r==NULL ? " " : r->descr));
	
	r = pop();
	printf("pop(): %p %s\n", r,(r==NULL ? " " : r->descr));

	return 0;
}
