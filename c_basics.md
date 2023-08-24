# C Basics

## Header Files

Why does c need header files(`.h`)?

Header files makes your life easier.

https://gcc.gnu.org/onlinedocs/cpp/Header-Files.html

Header files eliminate code redundancy (DRY).
With a header file, the related declarations appear in only one place.

'Including a header file produces the same results as copying the header file into each source file that needs it.'

## Compile

Preprocessing
```c
// Preprocess
// directives (#<directive>) are commands for the preprocessor
// NOTE: there are no semicolons after a directive
```

`include` header
```c
// The #include directive tells the preprocessor to open a specified file and
// copy the header file into each source file that needs it
```


// The `include` directive has two forms:

```c
#include <filename> // for C's own std library
// For example, the compiler will look inside `usr/include`

#include "path/to/filename" // for our own headers
// The compiler looks in the current directory
// Then the default system header locations

```

```
The places that will be searched for can be altered with `-I path`.
It is best not to put absolute paths in the #include directives
For max portability use relative paths
``````

```c
// stdio.h is a header file
// it defines variable types, macros, and functions for input/output
#include <stdio.h>
```


Compile: This program will become machine instructions (object code)
Object files have .o extension in UNIX in .obj in Windows

Link: The object code will be linked together into a executable

`gcc` is one of the most popular C compilers and is supplied with Linux

Fun fact: For a cross-platform solution, you can use the [Zig](https://ziglang.org/) compiler as a drop in replacement:

`zig cc -o my_code my_code.c`

https://stackoverflow.com/questions/3375697/what-are-the-useful-gcc-flags-for-c


__naming conventions__
- see: https://stackoverflow.com/questions/1722112/what-are-the-most-common-naming-conventions-in-c

# Language Features

## Comments

Use them

```c
// This is a single line comment

/*
    This is a multi-line comment
*/
```

## Structs vs Typedef

Structs When we need to store a collection of data items: use structs

struct variables
```c
struct {
    int   id;
    char *name;
} struct_var1, struct_var2;
```

struct tags
```c
struct struct_1 {
    int   id;
    char *name;
}; // <-- note the semicolon

// initialization
struct struct_1 s1 = { 1, "struct with tag" };
```

typedef
- Note: use `struct tags` for linked lists, not typedef
```c
typedef struct {
    int  id;
    char *name;
} struct_t;

struct_t s_t1 = {1, "struct as type" };
``` 

Array of Structures

```c
struct dialing_code {
    char *country;
    int code;
};

const struct dialing_code country_codes[] = 
{
    {"Argentina", 54}, {"Bangladesh", 880},
    {"Brazil", 55}, {"Myanmar", 95},
    ...
    {"US", 1}, {"Vietnam", 84}
};
```

# Unions

unions consist of a group of members

the compile only allocates the enough space for the largest member in that group, because only one type of that set can be used


```c
union {
    int    i;
    double d;
} u;

struct {
    int    i;
    double d;
} s;

Memory difference

* members of s are stored at different addresses
* members of u are stored at the same addresses
* this means that unions take up less memory BUT they can only store one of the members at a time

Assume that: 
- int    takes 2 bytes
- double takes 4 bytes

Structure     Union
i []          i[]d
i []          i[]d
d []           []d          
d []           []d
d []
d []

```

## Enums

enums are enumerations which means countable

in the context of programming enumerated means: a discret set of meaningful values

E.g. 

- Boolean = {T, F}
- Color = {r,g,b}
- Representing the suits of a card = {Hearts, Spade, Club, Diamon}
- States of a Finite State Machine = {Go, Slow, Stop}

Implementation in C:

You can use macros (not recommended b/c verbosity, but possible)
```c
#define SUIT     int
#define CLUBS    0
#define DIAMONDS 1
#define HEARTS   2
#define SPADES   3

SUIT s;
s = HEARTS
```

Or you can use `enumerated type`:

```c
// enum variable
enum {CLUBS, DIAMONDS, HEARTS, SPADES} s1,s2;

// enum type
enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};
suit s1,s2;
```

Bool is just an enum with two values
```
typedef enum {TRUE, FALSE} Bool;
```

**You can assign your own constants**

By default the compiler assigns the first enum as 0 then counts upward, i.e. {0,1,2,...} so:
```c
===
enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};
suit s1,s2;
===

is the same as

===
enum suit {CLUBS=0, DIAMONDS=1, HEARTS=2, SPADES=3};
suit s1,s2;
===

but this is legal too

===
enum suit {CLUBS=1000, DIAMONDS=99, HEARTS=23, SPADES=321};
suit s1,s2;
===

you can assign your enum any constant you wish

```

WARNING: Although in C, enums are just thinly disguised integers, treating them as just integers defeats their purpose. Treat enum members as a discrete type.

E.g.

Using enums for error codes

```c

fn do_something(){
    printf("I did something");
    return 0;
}

fn got_error() {
    printf"I erred");
    return 1;
}

====

enum err {NO_ERROR=0, AN_ERROR=1};

fn do_something_e() { 
    printf("I did something");
    return NO_ERROR;
}

fn got_error_e() {
    printf"I erred");
    return AN_ERROR;
}

See how these functions are mechanically the same, but to the programmer one set is more descriptive.
```

## Functions

Unlike languages like Javascript, Java, C#, where functions can be declared anywhere in the source (JS has hoisting and Java, C# don't require header files) function order does matter in C. C needs to functions to be declared at the top or in header files (`.h`) before they can be used.

```c
// # Function Prototypes
// This is a prototype
// You need to declare a function prototype in the header
void read_an_int();

void initialization_example() {
    // We can give a variable an intial value when it is declared
    // The value 8 is said to be an initializer
    int init1=8;
}

// Run: gcc a.c -o a
// Run: ./a
int main(void) {
    printf("Hello world! I C you.\n");
    read_an_int();
    return 0;
}


// WARN: If the function prototype was not declared on top, this function will cause an implicit declaration error
void read_an_int() {
    // declare i
    int i; 
    
    // the d is called a format specifier
    // C: https://en.wikipedia.org/wiki/C_data_types
    scanf("%d", &i); // read an integer store into i
    printf("You entered: %d\n", i);
}
```

See: [basic C source example](src/basic.c)

## type aliasing
- redefine name of already existing data type
- i.e. type alias
- `typdef unsigned char byte_t`

## arrow operator
`foo->bar` is equivalent to `(*foo).bar`, i.e. it gets the *member* called `bar` from the *struct* that `foo` points to.

see: https://stackoverflow.com/questions/2575048/arrow-operator-usage-in-c

__indirection with pointers example__

```c
#include <stdio.h>  
int main()  {  
    // Create an int binding/container and attach/store it with value 1
    int x=1;
    
    // Create ptr to int, pointers have types too
    int *ptr;
    
    // Store the address of x into ptr, NOTE: we're storing the address which is distinct from the value
    // think of this as creating a link to endpoint x with the entry `ptr`
    ptr=&x;
    
    // Dereference the address to get to the value value, i.e *(address) -> value
    *ptr=8;
    printf("value of x is : %d", x);  
    return 0;
}
```


