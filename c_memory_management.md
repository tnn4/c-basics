# C Memory Management

Higher level languages like Python, Java, C#, Javascript hide memory management from us. It makes our programming lives easier, but it comes with a steep price. That price is primarily of performance and binary sizes.

Compiled languages that don't use garbage collectors are usually faster because they run less code, and because they use less memory.

Most of the time, languages like Python and Java are fast enough for most applications.

When you have to write instructions for Operating Systems which require explicit memory management or embedded systems which are computationally and memory constrained you'll have to bust out the more performant system languages: C, C++ , Rust, Assembly (not actually a language). These take more effort to design and write.

Why is C/C++ code considered unsafe?
- C is “unsafe” in the sense that it allows you to do things that make your program crash and won't do any implicit sanity or consistency checks.
- In C, neither compile-time nor run-time checks prevent a variable of one type being changed to, or interpreted as, another type; thus, there are no guarantees on the kinds of data that a given variable might hold, the allowed set of values, their representation, or the operations that may be carried out on the data.

see:
- https://www.reddit.com/r/cpp/comments/jzo1yz/c_is_unsafe/
- https://www.reddit.com/r/cpp_questions/comments/dph2py/does_cs_potential_for_unsafe_code_make_life_more/
