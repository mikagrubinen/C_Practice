/* defs.h header file contains the data type declarations */

/* function pointer type definition */
typedef void (*fptr_t)();

/* API structure */
struct container {
	fptr_t fptr;
};