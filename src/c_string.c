#include <string.h> // strcat(s1,s2)

#include <time.h>
#define __STDC_WANT_LIB_EXT2__ 1
#include <stdio.h>
#include <stdlib.h>
#include <errno.h> // ENOMEM

void read_file_as_bytes(char * file_name);
void char_ptr_example();

int main(){
    printf("Hello World!\n");

    char_ptr_example();

    exit(EXIT_SUCCESS);
}

void char_ptr_example(){
    

    char c = 't'; // This a char

    char s[] = "test"; // This is a c-string

                                         // This is also a c-string
    char s2[] = {'t', 'e', 's', 't', 0}; // The 0 at he end is `NUL` terminator
    

    // WARN:
    // Don't confuse null character('\0') with zero character('0')
    // ASCII.code('\0') == 0 vs ASCII.code('0') == 48

    // char* store the starting memory location of a C-string

    // Set our char* the memory location of the _first_ element of s
    char * p  = &(s[0]); // === char * p = s
    // Almost the same as
    char * p2 = s;

    *(p + 0) == 't'; // p[0] == 't';
    *(p + 1) == 'e'; // p[1] == 'e';
    *(p + 2) == 's'; // ...
    *(p + 3) == 't'; // ...
    *(p + 4) == 0;   // p[4] == 0;

    // Or, alternatively
    p[0] == 't';
    p[1] == 'e';
    p[2] == 's';
    p[3] == 't';
    p[4] == 0; // NUL

    int BOOL_STRING_LEN=strlen("FALSE\n") + 1;

    int i;
    char truthiness[BOOL_STRING_LEN];

    // format a string: https://stackoverflow.com/questions/804288/creating-c-formatted-strings-not-printing-them
    char* s1;
    char* final_s;

    
    // verify that *(p + i) == p[i]
    for ( i=0;i<strlen(p)+1;i++ ){
        if ( *(p + i) == p2[i] ){
            https://stackoverflow.com/questions/37225244/error-assignment-to-expression-with-array-type-error-when-i-assign-a-struct-f
            // truthiness = "TRUE"; WON'T WORK
            // array types are not assignable
            strcpy(truthiness, "TRUE\n");
        } else {
            strcpy(truthiness, "FALSE\n");
        }
        
        
        // https://stackoverflow.com/questions/73597994/implicit-declaration-of-function-asprintf
        //  s1 -> char*
        // &s1 -> char**

        // * asprintf requires char ** restrict
        // * restrict means a programmer hints to the compiler that for the lifetime of the pointer, 
        // no other pointer will be used to access the object to which it points
        if(0 > asprintf(&s1, "*(p + %d) == %c: ", i, p[i])) {
            // c: https://www.thegeekstuff.com/2010/10/linux-error-codes/
            // Return not enough memory error code
            exit(ENOMEM);
        }
        final_s = strcat(s1, truthiness);
        printf("%s", final_s); // How to turn char[] into string literal
    }
}