# C Miscellania

##### top

Table of Contents
- [naming conventions](#naming-conventions)
- [type aliasing](#type-aliasing)
- [arrow operator](#arrow-operator)
- [indirection with pointers](#indirection-with-pointers)
- [OOP in c](#oop-in-c)
- [globals in resource constrained environments](#global-variables-in-resource-constrained-environments)

## naming conventions 
- see: https://stackoverflow.com/questions/1722112/what-are-the-most-common-naming-conventions-in-c

[top](#top)

## type aliasing
- redefine name of already existing data type
- i.e. type alias
- `typdef unsigned char byte_t`

[top](#top)

## arrow operator
`foo->bar` is equivalent to `(*foo).bar`, i.e. it gets the *member* called `bar` from the *struct* that `foo` points to.

see: https://stackoverflow.com/questions/2575048/arrow-operator-usage-in-c

```c
struct max {
   int cognome;
   int nome;
   float media;
}

max a;
a.cognome = 5;
a.media = 10.2;

//  if the struct variable is a pointer, you use an arrow operator
max * b = malloc(sizeof(max));
b -> cognome = 5;
b -> media = 10.2;
//Or if you hate arrows
(*b).cognome = 5;
(*b).media = 10.2;
```
see: https://stackoverflow.com/questions/2575048/arrow-operator-usage-in-c

[top](#top)

## indirection with pointers

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

[top](#top)

## binding vs assignment

tl;dr - in a programming context, they're basically the same

long version - there are conceptual collision of these terms in mathematics, everyday speech and computer science which creates ambiguity problems

see: https://cs.stackexchange.com/questions/39525/what-is-the-difference-between-assignment-valuation-and-name-binding
see: https://eloquentjavascript.net/02_program_structure.html

primes
- 89767
- 4567987

[top](#top)

## OOP in C

I would amend S. Lott's answer to use an [opaque pointer(wikipedia)](http://en.wikipedia.org/wiki/Opaque_pointer#C), to perform data hiding of the members of the struct:

1. Define your class however you want using normal OO design.
2. Member variables of your class go into a C language struct.
3. you do not want to expose the member variables of your object (since these would be "private" in an OO language)
    - In the header file, declare an opaque pointer, i.e. `typedef struct mystruct_s *mystruct_t; // first argument to all your methods`
    - the  type `mystruct_t` which is a pointer to the opaque structure `mystruct_s`, anything you declare as `mystruct_t` will be an opaque pointer
    - example definition of `mystruct_s`:
```c

struct mystruct_s {
    uint16_t *data;     // a pointer to the actual data array of uint16_t.
    size_t sz;          // the allocated size of data.
    size_t used;        // number of segments of data in use.
    int sign;           // the sign of the number (-1, 0, 1).
};

// users of the header file canno see this
   ```
4. For all the methods you want to be "public", put their signatures in your .h file. Method bodies should go into the .c file, and "private" methods should be only defined in the .c file and also declared static so their symbols do not collide with symbols defined in other files.

Clever naming conventions like underscores are unnecessary using this method, but it means that all your member variables will be private. Functions can be public or private, although public functions they are part of a global namespace so you might want to qualify their names with a "package" name like mystruct_push(), mystruct_pop(), etc.

You also need to make it clear if the caller or the library is responsible for calling malloc() and free(). Most likely you will have mystruct_t *create() and void destroy(mystruct_t *target) methods.

see: https://stackoverflow.com/questions/674722/struggling-with-c-coming-from-object-oriented-land
see: opaque pointers - https://stackoverflow.com/questions/7553750/what-is-an-opaque-pointer-in-c

[top](#top)

## global variables in resource constrained environments

`Global variables: just don't use global variables. They are evil.` - unless you are working on embedded project and you have 1024 bytes of RAM and 8MHz CPU.

Yes @Kamil, that can be painful. But even in that case, it is a good practice to create a static global struct variable with all the global context, create a pointer as local variable in the main function and pass that pointer only to the functions that need to access the global data. 

see: https://stackoverflow.com/questions/1722112/what-are-the-most-common-naming-conventions-in-c

[top](#top)

[implement hash table](https://gist.github.com/cellularmitosis/9db34df37d3df91709ad3e4faf93c417)