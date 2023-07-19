# C Miscellania

Put uncategorized info here. Sort them when you can.

##### top

Table of Contents
- [globals in resource constrained environments](#global-variables-in-resource-constrained-environments)

## naming conventions 
- see: https://stackoverflow.com/questions/1722112/what-are-the-most-common-naming-conventions-in-c



[top](#top)

## global variables in resource constrained environments

`Global variables: just don't use global variables. They are evil.` - unless you are working on embedded project and you have 1024 bytes of RAM and 8MHz CPU.

Yes @Kamil, that can be painful. But even in that case, it is a good practice to create a static global struct variable with all the global context, create a pointer as local variable in the main function and pass that pointer only to the functions that need to access the global data. 

see: https://stackoverflow.com/questions/1722112/what-are-the-most-common-naming-conventions-in-c

[top](#top)

[implement hash table](https://gist.github.com/cellularmitosis/9db34df37d3df91709ad3e4faf93c417)
