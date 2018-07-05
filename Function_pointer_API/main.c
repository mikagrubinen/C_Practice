#include "stdio.h"
#include "stdint.h"
#include "foo.h"


/* create API structure */
struct container con;

/* user defined function to be used by API function calls */
void print_something();


int main()
{
	con.fptr = print_something;
	foo(&con);

	return 0;
}


void print_something(){
	printf("Helooooo\n");
}