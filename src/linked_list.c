#include <stdio.h>  // printf
#include <stdlib.h> // getenv
#include <string.h> // strcpy

#define DEBUG 1
#define NODE_SIZE 31
#define BUFSIZE 128

void println(char *);
struct Node* add_to_list(struct Node *, char *);
void iterate_list(struct Node *);

struct Node {
    char value[NODE_SIZE + 1];
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

    first = add_to_list(first, "another node");
    first = add_to_list(first, "another node 2");

    iterate_list(first);

    println("\n[OK]\n");
    return 0;
}

void println(char *astring){
    printf("%s\n", astring);
}

// list - pointer to first node in old list
// value - string to store in new node
struct Node* add_to_list(struct Node *list, char *value){
    struct Node *new_node;
    new_node = malloc(sizeof(struct Node));

    if (new_node == NULL){
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }

    //new_node->value = value;
    strcpy(new_node->value, value);
    new_node->next = list;

    return new_node;
}

// print out values of the linked list
void iterate_list(struct Node *list){
    int i = 0;
    while( list != NULL){
        printf("[%d]:%s\n", i, list->value);
        list = list->next;
        i++;
        if (i == 100){
            break;
        }
    }
}
