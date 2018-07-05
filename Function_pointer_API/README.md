This is simplified way to show how to allow user defined functions to be called with API function calls. 

API files:
	defs.h
	foo.h
	foo.c

User creates main.c and defines his own functions. To use user defined functions and for them to be called from API, user first needs to create API structure and to assign his function to struct member which is defined as a function pointer. 