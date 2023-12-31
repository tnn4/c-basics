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

## [Linked Lists](c_linked_list.md)

For example of how dynamic memory allocation is used for data structures

see: [Linked Lists](c_linked_list.md)
