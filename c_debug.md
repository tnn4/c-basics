https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Debugging.html

install gfb on debian: `sudo apt install gdb`

gdb commands
```
help
    Get a description of gdb's commands. 
run
    Runs your program. You can give it arguments that get passed in to your program just as if you had typed them to the shell. Also used to restart your program from the beginning if it is already running.

quit
    Leave gdb, killing your program if necessary.

break
    Set a breakpoint, which is a place where gdb will automatically stop your program. Some examples:

        break somefunction stops before executing the first line somefunction.

        break 117 stops before executing line number 117. 

list
    Show part of your source file with line numbers (handy for figuring out where to put breakpoints). Examples:

        list somefunc lists all lines of somefunc.

        list 117-123 lists lines 117 through 123. 

next
    Execute the next line of the program, including completing any procedure calls in that line. 

step
    Execute the next step of the program, which is either the next line if it contains no procedure calls, or the entry into the called procedure. 
    
finish
    Continue until you get out of the current procedure (or hit a breakpoint). Useful for getting out of something you stepped into that you didn't want to step into. 
    
cont

    (Or continue). Continue until (a) the end of the program, (b) a fatal error like a Segmentation Fault or Bus Error, or (c) a breakpoint. If you give it a numeric argument (e.g., cont 1000) it will skip over that many breakpoints before stopping. 
print

    Print the value of some expression, e.g. print i. 
display

    Like print, but runs automatically every time the program stops. Useful for watching values that change often.
```