#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void read_file_as_bytes(char * file_name);

int main(){
    printf("Hello World!");

    exit(EXIT_SUCCESS);
}

// c: https://stackoverflow.com/questions/22059189/read-a-file-as-byte-array
void read_file_as_bytes(char * file_name){
    FILE * fileptr;
    char * buffer;
    long filelen;
    
// Open the file

    // FILE * fopen(const char *filename, const char *mode)
    fileptr = fopen(file_name, "rb"); // Open file in binary mode
                            
// Determine file size
    
    fseek(fileptr, 0, SEEK_END);      // Jump to end of file
    filelen = ftell(fileptr);         // Get the current byte offset in the file
    rewind(fileptr);                  // Jump to the beginning of the file

// Allocate memory for the file

    buffer = (char *)malloc(filelen * sizeof(char)); // Allocate enough memory for the file, c: https://en.cppreference.com/w/c/memory/malloc
                                                     // (char *)malloc : typecast malloc to a c-string(char *)
                                                     // sizeof operator queries the size of object or type -> size_t
                                                     // size_t is the result of sizeof and is an unsigned integer, c: https://en.cppreference.com/w/c/types/size_t
    fread(buffer, filelen, 1, fileptr);              // Read the entire file
    
    fclose(fileptr);                                 // Close the file
}