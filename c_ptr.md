# C Pointers

Pointers, it's that elephant in the memory buffer that we seldom talk about but probably should.

Ever see some nerd hacking on his computer and seeing crap like this
```
0xFFFFA9840324  IM_A_DUMB_HACK
0x32489f980082  321083021
0x343249809ab3  210320183
0x97496abcdeff  PASSWORD_SECRET
```

The gibberish that begins with `0x` actually means something. They're memory addresses represented in [hexadecimal](https://en.wikipedia.org/wiki/Hexadecimal).

What does that gibberish have to do with pointers?

References:
- See: [wikipedia](https://en.wikipedia.org/wiki/Pointer_(computer_programming))
- Watch: https://www.youtube.com/watch?v=fpnE6UAfbtU

We have to answer some questions to understand why pointers are important.

Why are pointers so important?
- Understanding them is fundamental for any programmer who actually cares about how their programs function
- Pointers can improve performance.
- Pointers allow OOP to be implemented

What would programming be like without pointers?
Error-prone. Imagine trying to find a needle in a haystack 1000 times a day, every day for the rest of your career. If that thought doesn't make you want to shoot yourself in the face, then nothing will.

How are pointers implemented in hardware?

We need to visualize what pointers represent at the machine level.

In modern computers, main memory is divided into bytes. 1 byte = 1 bit, 1 bit = enum(0|1)

```
[0] <-- 1 bit

[0][1][0][1][0][1][0][1] <-- 8 bits = 1 byte
or
[01010101]
```
Each byte has a unique _**address**_ to distinguish it from other bytes in memory.

Define **address**: the specific place where a person, business, or organization can be found and where mail can be received, therefore a memory address is a particular location where some bytes can be found

A computer proram consists of code(machine instructions) and data(variables).

```
Address  Contents
   0     [00110101]
   1     [00000000]
   2     [11110000]
   3     [11100101]
             .
             .
             .
  n-1    [01010100]
```

```
variables occupy one or more **bytes** of memory.

             .
             .
             .
  2000   [        ]  \
  2001   [        ]   ----> i               i (variable) occupies the bytes at address 2000-2002
  2002   [        ]  /                      i's address is 2000
             .
             .
             .
```

What does pointing have to do with addressing?

If we store the address of variable `i` in the pointer variable `p`, we say `p` "points to" `i`

What do pointers have to do with memory?

What are pointers?
A pointer is an address, a pointer variable is just a variable that stores an address.
Addresses are represented by numbers, integers

How do we model pointers?
You show the content of `p`(the pointer variable) as an arrow directed towards `i`:

Model:

To monkeys like us, this means a lot. To a computer this means nothing. CPUs only understand bits in memory.
```
p [*]---> [   ]i  
```

To a computers pointers are basically addresses, just a bunch of numbers in memory that point to location in memory that allow you to find some bytes. We come up with the arrow as an abstraction to make the addressing easier to understand.

What is a pointer again?
A address that we store in memory that we intend to use to find that.

If pointers are just memory addresses which are themselves represented as numbers, pointers have to be stored somewhere too right?
https://superuser.com/questions/1480913/how-are-memory-location-addresses-actually-stored-in-the-cpu

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
