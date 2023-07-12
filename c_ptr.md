# C Pointers

## Pointer syntax

"To point or not to point, that is the question." - Hamlet, probably

c: https://stackoverflow.com/questions/3280729/in-c-what-is-the-correct-syntax-for-declaring-pointers

Is it `int* p` or is it `int *p`?
- It depends on who you ask and at what time of day you ask them.
- Jokes aside, it's preference
- For C++ `int* p` is preferred because the typeness is emphasized
- In C `int *p`, b/c "The syntax of the declaration for a variable mimics the syntax of expressions in which the variable might appear."

Pointer variables hold an address.

int i = 0; // This is an integer type

int* i 

## Multiple assignments


`int *p1, p2`, one is a pointer, one is not

is not the same as

`int *p1, *p2`