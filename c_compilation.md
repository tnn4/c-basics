C Compilation

Compiling a C program comes in multiple steps.

Preprocess 
- the program is given to the preprocessors which obey commands that begin with `#` called `directives`
- a preprocessor acts like an editor, it can modify the program before going to the next step

```
#include <stdio.h> // <-- These are the directives

void main(){

}
```

Compile
- the modified program is given to the `compiler` which translate it into machine instructions(`object code`)
- object code files end with `.o` on Linux and `.obj` on Windows

```
object.o another_object.o
```

Link
- In the final step, the `linker` combines the compiler's `object code` and additional code needed to make a complete executable program.
- This additional code can include library functions like `printf`

