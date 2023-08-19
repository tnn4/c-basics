C Compilation

## Compilation Steps

Compiling a C program comes in multiple steps.

Preprocess 
- the program is given to the preprocessors which obey commands that begin with `#` called `directives`
- a preprocessor acts like an editor, it can modify the program before going to the next step

`main.c`
```
#include <stdio.h> // <-- These are the directives

void main(){

}
```

Compile
- the modified program is given to the `compiler` which translate it into machine instructions(`object code`)
- object code files end with `.o` on Linux and `.obj` on Windows

```
program.c program2.c --> [compiler] --> program.o program2.

[c,c,c,c,c]
     |
     V
[Compiler] 
     |
     V
[o,o,o,o,o]
```

Link
- In the final step, the `linker` combines the compiler's `object code` and additional code needed to make a complete executable program.
- This additional code can include library functions like `printf`

Link object files visual
```
o   = object(.o) files
exe = executable file 

[o,o,o,o,o,o,o,o,o] <-- list of object files
     |
     v
 [Linker]
     |
     v
  o--o--o
  |  |  |
  o--o--o 
  |  |  |
  o--o--o
     |
     V
   [exe] <-- this is the binary/ machine code that the CPU '(exe)cutes'
```

Big picture

```
C Compilation

[c,c,c,c,c] <-- c files you wrote, and libraries you #included
     |
     V
[Compiler] 
     |
     V
[o,o,o,o,o,o] <-- list of object files
     |
     v
 [Linker]
     |
     v
  o--o--o
  |  |  |
  o--o--o 
     |
     V
   [exe] <-- this is the binary/ machine code that the CPU '(exe)cutes'
```

What are `.o`, `.a`, `.so` files.
- https://stackoverflow.com/questions/7718299/whats-an-object-file-in-c
- https://stackoverflow.com/questions/9809213/what-are-a-and-so-files

`.o`, object file = result of the compilation step

`.a`, archive file = statically linked libraries

`.so`, shared object file = dynamically linked libraries, they are linked during runtime, after the creation of `.o` files, so if there are any changes in `.so` no recompile is needed.