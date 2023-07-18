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
