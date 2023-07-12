// # Comments

// This is a single line comment
/*
    This is a multi-line comment
*/

// Preprocess
// directives (#<directive>) are commands for the preprocessor
// NOTE: there are no semicolons after a directive

// # Headers
// The #include directive tells the preprocessor to open a specified file and
// insert its contents into the current file

// The include directive has two forms:

// #include <filename> for C's own library
// For example, the compiler will look inside `usr/include`

// #include "path/to/filename" for our own headers
// THe compiler looks in the current directory
// Then the default system header locations

// The places that will be searched for can be altered with
// -I path
// It is best not to put absolute paths in the #include directives
// For max portability use relative paths

// stdio.h is a header file
#include <stdio.h>

// Compile: This program will become machine instructions (object code)
// Object files have .o extension in UNIX in .obj in Windows

// Link: The object code will be linked together into a executable

// # GCC
// gcc is one of the most popular C compilers and is supplied with Linux


// # Function Prototypes
// This is a prototype
// You need to declare a function prototype in the header
void read_an_int();

void initialization_example() {
    // We can give a variable an intial value when it is declared
    // The value 8 is said to be an initializer
    int init1=8;
}

// Run: gcc a.c -o a
// Run: ./a
int main(void) {
    printf("Hello world! I C you.\n");
    read_an_int();
    return 0;
}




// w/o a prototype on top, Putting this here causes an implicit declaration error 

// You are using a function for which the compiler has not seen a declaration ("prototype") yet.
void read_an_int() {
    // declare i
    int i; 
    
    // the d is called a format specifier
    // C: https://en.wikipedia.org/wiki/C_data_types
    scanf("%d", &i); // read an integer store into i
    printf("You entered: %d\n", i);
}
