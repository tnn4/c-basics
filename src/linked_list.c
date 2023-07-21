#include <stdio.h>  // printf
#include <stdlib.h> // getenv
#include <string.h> // strcpy

#define DEBUG 1
#define BUFSIZE 128

void println(char *);

struct Node {
    char value[16];
    struct Node *next;
};

int main(void) {

    println("\n** Linked List Example **\n");

    /* Linked List Example */
    // Allocate Memory for the Node
    // Store data in the Node
    // Insert Node into List

    struct Node *first = NULL;

    struct Node *new_node;

    new_node = malloc(sizeof(struct Node));

    // *(new_node).value = "I'm new node";
    // *(p).value = p->value
    // p->value = *(p).value
    // strcpy(*(new_node).value, "I'm new node"); // WRONG
    // strcpy(*(new_node)->value, "I'm new node") // WRONG but compiles 
    strcpy(new_node->value, "new node");
    // strcpy *((*new_node)).value

    printf("\n%s", new_node->value);

    println("\n[OK]\n");
    return 0;
}

void println(char *astring){
    printf("%s\n", astring);
}
