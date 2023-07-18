## Linked Lists

First see: [dynamic allocation](c_dynamic_allocation.md)

Dynamic storage allocation is useful for building lists, trees, graphs and other linked data structures.

The most basic linked data structure: a linked list.

Fun fact: Although C programmers love linked lists, Rust programmers are not so enthusiastic: [Learning Rust With Entirely Too Many Linked Lists](https://rust-unofficial.github.io/too-many-lists/)


```
[ ][*]-->[ ][*]-->[ ][/]
The last node in the list has a null pointer
```
Linked lists are more flexible than arrays:
- can more easily insert, delete nodes in a linked list, allowing it to grow or shrink
- BUT: you lose random access
- any element in an array can be accessed in the same amount of time, so O(1)
- accessing a node is fast if node is close to beginning, BUT: slow if node is close to n, average search time = O(n/2)

Declare (simple) Node type

```c
struct node {
  int value;
  struct node *next;
};
```

Now we need a way to keep track of where the list begins:
```c
struct node *first = NULL;
```

How to create a node:
1. Allocate memory for the node
2. Store data in the node
3. Insert node into the list

code:
```c
struct node *new_node;

new_node = malloc(sizeof(struct node));
```
memory:
```
new_node [*] --> [     ][    ]
                  value  next
```

code:
```c
(*new_node).value = 10; // notice that we applied indirection operator(*) to new_node
                        // the parentheses around around *new_node are mandatory  because the
                        // . operator would otherwise take precedence
```
memory:
```
new_node [*] --> [  10 ][    ]
                  value  next
```

Shorcut:
Use `->` (right arrow selection) operator if you don't want deref(*) and dot(.)

traditional | `->`
--- | ---
`(*new_node).value = 10` | `new_node->value = 10;` 

Read into your linked list :

`scanf("%d", &new_node->value);`

Notice that `&new_node-> value === &(*new_node).value`. We do this because we're trying to pass the pointer to value not value itself.

Let's use linked lists to ability to insert anywhere to our advantage which is something arrays can't do.

new_node->next = first;

first = new_node;

Let's trace the process of inserting two nodes into an empty list. Null pointers are represented as diagonal lines (/)

```c
struct node {
  int value;
  struct node *next;
};
```

```

[/]      null pointer
[*] ---> pointer

first = NULL;                           first    [/] <-- null pointer
                                        new_node [ ]

new_node = malloc(sizeof(struct node)); first    [/]
                                        new_node [*] --> [ ][ ]

new_node->value = 10                    first    [/]
                                        new_node [*] --> [10][ ]

new_node->next = first;                 first    [/]
                                        new_node [*] --> [10][/]

first = new_node;
                                        first[*]
                                                \
                                                 v
                                                [10][*]
                                                 ^
                                                /
                                        new_node

new_node = malloc(sizeof(struct node)); first[*] ---> [10][/]
                                        
                                        new_node[*] ---> [ ][ ]

new_node->value = 20;                   first[*] ---> [10][/]
                                        
                                        new_node[*] ---> [20][/]

new_node->next = first;                 first[*] --------------
                                                               \
                                                              [10][/]
                                                               /
                                        new_node[*]-->[20][*]--


first = new_node;                       first[*]
                                                \
                                                 v
                                                [20][*]--->[10][*]
                                                 ^
                                                /
                                        new_node
```

Inserting a node is such a common operation we should turn it into a function:

```
struct node* add_to_list(struct node *list, int n) {
  struct node *new_node;

  new_node = malloc(sizeof(struct node));
  if (new_node == NULL) {
    printf("[Error]: malloc failed in add_to_list\n");
    exit(EXIT_FAILURE);
  }

  new_node->value = n;
  new_node->next = list;
  return new_node;
}
```

```
struct node* read_numbers(void){
  struct node *first = NULL:
  int n;

  printf("Enter a series of integers ( 0 to terminate ): *);
  for (;;) {
    scanf("%d", &n);
    if (n==0) {
      return first;
    }
    first = add_to_list(first,n);
  }
}
```

## Searching a Linked List

idiom `for (p=first; p != null; p = p->next)`

The assignment p = p->next advances the `p` pointer from one node to the next.

## Deleting a Node from a Linked List

1. Search for the node to be deleted
2. Alter the previous node so it "bypasses" the deleted node
3. Call `free` to reclaim space occupied by the deleted node

Step 1 is harder than it looks bc if we search the list in obvious way we end up with pointer to node to be deleted. We won't have data to change the previous node.

There are various solution. One we can used is the "trailing pointer".
- Keep a pointer to previous node (prev)
- Keep a pointer to current node (cur)

If `list` points to the list to be searched, and `n` is the integer to be deleted. The following loop implements step 1
```c
for (cur = list; prev=NULL; cur != NULL && cur->value != n; prev=cur, cur=cur->next)
```

Let's break it down:
```
cur != NULL && cur->value != n; prev=cur,cur=cur->next

NOTICE: cur-> value, points to a value
        cur-> next,  points to a pointer

idiom: -> to a value gets us that value
       -> to a pointer gets us to another location in memory

if there is a value at `cur` and its not n, move to the next node (set previous to current then push current to next)

prev, cur, next
 ^     ^    ^
prev  cur   |  1
      prev cur 2
```

This is how to perform the bypass.
code:
`prev->next = cur->next`, this makes the pointer in the previous node point to the node _after_ the current node
```
                    prev       cur
                     [*]       [*]
                      |         |
                      v         v
list [*]-->[30][*]-->[40][*]  [20][*]--> ([10][/])
                          \                ^
                           \______________/
```
Now we can release memory occupied by the current node:
`free(cur)`

Let's put it all together in `delete_from_list`:
```
struct node* delete_from_list(struct node *list, int n){
  struct node *cur, *prev;

  for (cur = list, prev = NULL;
    cur != NULL && cur->value != n;
    prev = cur, cur = cur->next)
  ;

  if (cur == NULL)
    return list;             // n not found
  if (prev == NULL)
    list = list->next;
  else
    prev->next = cur-> next; // do bypass
  free(cur)
  return list;
}
```
