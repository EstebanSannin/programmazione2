#include <stdio.h>
#include <stdlib.h>

#define BOOL int
#define FALSE 0
#define TRUE !FALSE


#define BUF_SIZE 30

static char buffer[BUF_SIZE];
static int start_write = 0;
static int start_read = 0;

static void print();
void clear();
BOOL add(char *p);
char *get();
static BOOL increment(int *counter);

/*Testing function*/
int main(){
	char *stringa="test123";
	add(stringa);
	char stringa2[10];
	get(stringa2);
	printf("eccola: %s\n",stringa2);
	printf("start_read: %d\nstart_write: %d\n",start_read,start_write);

}



/*clear(): azzera il buffer e le variabili indice*/
void clear(){
	int i;
	for(i=0; i<BUF_SIZE; i++){
		buffer[i]='\0';
	}
	start_read=0;
	start_write=0;
}

/* add(char *p): aggiunge una stringa al buffer, compreso il 
 * carattere \0 terminatore di stringa. Per fare questo viene
 * iterata la stringa d'ingresso incrementando il contatore e
 * utilizzando la funzione increment() per ampliare l'indice
 * di scrittura del buffer*/
BOOL add(char *p){
	BOOL overflow=0;
	p--;
	do{
		p++;
		buffer[start_write]=*p;
		overflow=increment(&start_write);
	} while(*p != '\0');
	return overflow;
}

/* increment(int *counter): aumenta il contatore passato come parametro.
 * Se l'indice e' arrivato a fine buffer si riparte dal primo elemento.
 * La funzione ritorna un valore booleano che indica se e' stato superato 
 * l'indice di lettura, questo fatto indica un overflow in scrittura e
 * quindi perdita di dati.*/
static BOOL increment(int *counter){
	int overflow = FALSE;
	int c = *counter;

	c++;
	if(c==BUF_SIZE){
		c=0;
	}
	if(c== start_read){
		overflow = TRUE;
	}
	*counter = c;
	return overflow;
}


char *get(char *s){
	char *p;
	p=s;
	do{
		*s = *(buffer + start_read);
		s++;

		increment(&start_read);
	} while( *(buffer + start_read) );

	start_read++;
	*s='\0';
	return p;
}
