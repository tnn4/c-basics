// This is a header file.

#include <std.io>

// You should protect header files against multiple inclusion b/c it can cause compilation errors
#ifndef BOOLEAN_H
	#define BOOLEAN_H

	#define TRUE 1
	#define FALSE 0
	typedef int Bool;
#endif

// #error Directives
// Use #error directives to check for conditions to exclude headers
#ifndef __STDC__
	#error This header requires a Standard C Compiler
#endif

// Declaration of shared variables are usually defined in header files
// WARN: Try to avoid shared variables.
extern int shared_int;


// To declare i without defining it, we must put the keyword extern at the beginning of the declaration
// extern informs the compiler that i is defined elsewhere in the program (most likely in a different source file),
// so there's no need to allocate space for it
extern int i;

// extern works for variables of all types
extern int a[]; // note how we can omit the length of the array

// # Function Prototypes
// This is a prototype
// You can declare function prototypes in the header
void read_an_int2();
