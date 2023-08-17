## C OOP

OOP is taught exceptionally poorly because it glosses over the fact that all its concepts can be implemented from a procedural language like C.

read http://staff.washington.edu/gmobus/Academics/TCES202/Moodle/OO-ProgrammingInC.html

Before you can grasp OOP, you need to know the basics of data structures and (late binding)/(higher order functions).

higher order functions take functions as arguments and return functions.
- `fn_1(fn_2,...,fn_n) -> fn_result`

For example it's hard to grok polymorphism which is basically passing around a pointer to data and a bunch of functions that operate on the data.
Or understanding the concept of structuring data instead of just using primitives to and passing around (higher order functions)/(pointers to functions).

`higher order function == pointer to functions`

Here's a way to do OOP in C if you want to avoid C++:

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

see:
- http://staff.washington.edu/gmobus/Academics/TCES202/Moodle/OO-ProgrammingInC.html
- https://softwareengineering.stackexchange.com/questions/16025/why-is-oop-difficult
- https://stackoverflow.com/questions/674722/struggling-with-c-coming-from-object-oriented-land
- opaque pointers - https://stackoverflow.com/questions/7553750/what-is-an-opaque-pointer-in-c
