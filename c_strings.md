# C-strings

Strings in C are complex beasts. Tread with caution.

## Always leave room for the null character '\0'
If we need to store a string of 80 characters.
Create an array of 81 characters to store the null character at the end.

WARN: Failing to leave room for the null character may cause unpredictable behavior. Functions in the C library assume strings are null-terminated.

```
#define STR_LEN 80
...
char str[STR_LEN+1] 
```

NOTE: declearing a char array with length `STR_LEN+1` doesn't mean it will always contain `STR_LEN` characters.
- The length of the string depends on the position of the terminating `null character`, not on the length of the array.
- An array of length `STR_LEN+1` can hold an `empty string` or string of length `STR_LEN`

## Character Arrays( s[] ) vs Character Pointers ( s* )

"The devil's in the details". - Satan, probably

Although they can be similar and can usually be used interchangeably in functions, they are not the same.

E.g.
```
char  date[] = "July 4";

char* date = "June 14";
```

In the array version the characters can be modified.
In the pointer version `date` points to a string literal. string literals cannot be modified.


Character Array (char[]) | Character Pointer ( char* )
--- | ---
In the array version the characters can be modified. | `date` points to a string literal; string literals cannot be modified
In the array version `date` is an array name, | `date` is a variable that can be made to point to any other `char *`

```
char *p    // This only sets aside enough memory for a pointer
           // We still need to allocate space for the string

char str[STR_LEN+1];

p = str;
```

WARN: The code below will cause undefined behavior.
```
char *p; 

p[0] = 'a';  // NO! We haven't allocated any space for the string yet!
p[1] = '\0'; // :(
```

## Assigning strings to arrays isn't simple

Let's assign some strings.

Here's how it works in Python:
```
a_var = "a string"
print(a_var)
a_var = "another string"
print(a_var)
```
Simple isn't?

Here's how it might work in C
```
char a_var[] = "a string";
printf("%s", a_var);
a_var = "another string"; // <-- PROBLEM
printf("%s", a_var);
```
This won't compile. What the heck? What is this BS? WHY?


Initializing an array is legal:
```
// LHS            RHS
char an_var[] = "a string";
```

Unlike higher-level languages, Copying strings into a character array with `=` is not possible:
because the array name is a pointer to the first element of the array
```
// because the array name is a pointer the first element of an array
// here, we're trying to shove a multicharacter string into a single-character slot
// you're going to end up with a bad time
a_var = "another string"; 
```

Then how are we supposed to reuse array names if needed?
The standard C library's `<string.h>` has functions to deal with strings.

`strcpy` copies characters from `s2` into the array pointed to `s1`
```
char *strcpy(char *s1, const char *s2)
```

Here's how to fix the prior problem
```
#include <string.h>

// assume this code inside main()

char a_var[] = "a string";
printf("%s", a_var);
strcpy(a_var, "another string")
printf("%s", a_var);
```

This is just the tip of the iceberg.

## The Hazard of Reading Strings

"String input is like a box of chocolates, you'll never what you're going to get." - Forrest Gump, probably

Reading strings can be problematic because you might get a bigger string than the string variable can store.


[create c formatted strings (not printing them)](https://stackoverflow.com/questions/804288/creating-c-formatted-strings-not-printing-them)
- More knowledgable folks recommend using `asprintf`, `snprintf` whenever possible