#include <stdio.h>  // printf
#include <stdlib.h> // getenv
#include <string.h> // strcpy

#define DEBUG 1
#define NODE_SIZE 31
#define BUFSIZE 128

void println(char *);
// Linked Lists
struct Node* add_to_list(struct Node *, char *);
struct Node* search_list(struct Node *, char *);
struct Node* delete_from_list(struct Node *, char *);
struct Node* search_list_and_print(struct Node *, char *);
void print_list(struct Node *);

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

    print_list(first);

    search_list_and_print(first, "not found"); // should fail
    search_list_and_print(first, "another node"); // should find match

    
    println("deleting node with value: 'another node'");
    
    delete_from_list(first, "another node");

    print_list(first);

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
void print_list(struct Node *list){
    
    println("\nPrinting list");
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

struct Node* search_list(struct Node *list, char *value_to_match){
    /*while( list != NULL) {
        // you have to use strcmp
        if ( strcmp(list->value, value_to_match) == 0 ){
            return list;
        } else {

        }
    }
    */
    int i = 0;
    int length;
    // This loop never terminates
  //for(; list != NULL; list->next){
    
    // but this does!
    for(; list != NULL; list=list->next){
        // see: https://stackoverflow.com/questions/8257714/how-can-i-convert-an-int-to-a-string-in-c
        // length = snprintf(NULL, 0, "%d", i);
        // char num_as_str[length+1];
        // println(num_as_str);
        printf("i = %d\n", i);
        if (strcmp(list->value, value_to_match) == 0){
            println("match");
            return list;
        } else {
            println("no match");
        }
        i++;
    }

    // return NULL if there is no match
    return NULL;
}

struct Node* search_list_and_print(struct Node *list, char *value_to_match){
    
    println("\nSearching list");
    struct Node* result = search_list(list, value_to_match);
    if (result == NULL){
        println("There was no match.");
    } else {
        println("Found a match.");
    }
}

/* Delete node from list */
// 1. Locate node to delete
// 2. Alter previous node so it "bypasses" the deleted node
// 3. Call 'free' to reclaim space taken by deleted node

// Tricky part: if we search the obvious way with only one pointer, we won't have the information of the previous node, only the deleted one
// We need to use a trailing pointer, where we keep both `prev` and `curr` so we can next prev to bypass the deleted node
struct Node* delete_from_list(struct Node *list, char *value_to_delete){
    
    struct Node *cur, *prev;
    
    // 1. Locate node to delete
    for (cur = list, prev = NULL;
        cur != NULL && strcmp(cur->value, value_to_delete) != 0; // cur->value != value_to_delete;
        prev = cur, cur=cur->next)
    ;
    if (cur == NULL)
        return list; /* value not found */
    if (prev == NULL)
        list = list->next; /* value is first node */
    else {
        // 2. This is where we perform the bypass
        prev->next = cur->next;
    }
    free(cur); // 3. reclaim space
    return list;
}
