#include <stdio.h>  // printf
#include <stdlib.h> // getenv
#include <string.h> // strcpy

#define DEBUG 1
#define BUFSIZE 128

void println(char *);

int main(void) {

    if ( __STDC__ == 1){
        println("This compiler conforms to the C Standard.");
        printf("The C standard version is: %ld\n", __STDC_VERSION__);
    } else {
        println("This compiler does not conform to the C Standard.");
    }

    // Conditional compilation allows us to write debug code
    #if DEBUG
        println("I'm in debug mode.");
    #endif

    char *envvar = "test";

    
    if (!getenv(envvar)){
        fprintf(stderr, "The environment variable %s was not found.\n", "test");
        exit(1);
    }
    
    // Make sure there envar actually exist
    if (!getenv("test")){
        fprintf(stderr, "The environment variable %s was not found.\n", "test");
        exit(1);
    }
    
    char *str_holder; // this only sets aside enough memory for the pointer
    char str[BUFSIZE + 1];
    // str = "sample string"; // not legal
    str_holder = str;

    char *str_holder2;
    strcpy(str_holder, getenv("test"));

    printf("str_holder contains: %s", str_holder);
    

    println("\n[OK]\n");
    return 0;
}

void println(char *astring){
    printf("%s\n", astring);
}
