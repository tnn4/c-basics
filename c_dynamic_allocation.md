# C Dynamic Memory Allocation

## Dynamically allocate strings

It is sometimes impossible to to anticipate how long an array of chars(strings) can be. We can allocate strings dynamically and determine how long a string needs to be at runtime.

__Using malloc to allocate memory for string__

`malloc` prototype:

`void* malloc(size_t size);`

`malloc` allocates block of `size` bytes and returns a [generic pointer(void *)](https://stackoverflow.com/questions/11626786/what-does-void-mean-and-how-to-use-it) to it.

__Remember to account for the null char__

```c
p = malloc(n+1); // this can be used without casting
```

```c
p = (char *) malloc(n+1); //  but explicit casting to char* could make your code easier to maintain
```

Warning: Memory allocated using `malloc` isn't cleared or initialized, so `p` will point to an uninitialized array of `n+1` characters

```
p[*]
  |
  v
 [ ][ ][ ][ ][...][ ]
  0  1  2  3   4   n
```

Calling `strcpy` is one way to init an array:
`strcpy(p, "abc")`
```
p[*]
  |
  v
 [a][b][c][\0][...][ ]
  0  1  2  3   4    n
```

## Dynamically allocate arrays

```c
int *a;

a = malloc(n * sizeof(int));

// Now you can treat `a` as an array name even though it technically is a pointer

// Initialize the `a` "array" with initial value 0 (since its an int array)
for (i=0; i<n;  i++){
    a[i] = 0;
}

```
WARN: Always use `sizeof` when calculating how much space is needed for an array.

## Deallocating Storage (to avoid memory leaks)

```
p = malloc(...);
q = malloc(...);

```
This is what the memory looks like
```
p[*] --> [ ]
q[*] --> [ ]
```

```
p = q;
```

```
p[*] [ ]<-- this block of memory is now garbage
   \______ 
          |
          v 
p[*] --> [ ]   
```

A block of memory that is no longer accessible is **garbage**.

Unlike Java or C# programs which have automatic **_garbage collection_**. C programs,  do not automatically clean garbage for you. That is the programmer's job. This adds maintainence difficulty in return for performance gains.

You have to call the `free` function to release memory.

`free`

`void free(void *ptr)`

```c
p = malloc(...);
q = malloc(...);
free(p);
p = q;
```

## Dangerous "Dangling Pointers"

Reusing a piece of memory that previously `free`d is an error.

```c
// Bad code
char *p = malloc(4); // allocate memory for a string of len 3
...
free(p); // p's memory has been released into the , p is now a dangling pointer
...
strcpy(p, "abc"); // ** WRONG ** , try to use dangling pointer p, you're trying to use memory that's no longer yours, this is a programming crime so the OS will crash and yell at you
```
## Linked Lists

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
- accessing a node is fast if node is close to beginning, slow if node is close to n so O(n/2)

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
                                        new_node[*] --->[ ][ ]

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
