# GlibC (GNU C library)

C is a simple enough language with simplisitic functionality.
Most of advanced functionality comes from underlying GNU C library(Especially in linux).
It gets baked into every C program during compilation. 

> **Userland** code is code written for user level of CPU.

> Below that is **kernal level code** that includes instruction kernal such as syscalls and processes. We access it through syscall interface that allows usermode processes to ask kernal to do certain things such as allocating memory ,opening files etc.
> We could write code in assembly to make these syscalls however that is too tedious to maintain, so instead we depend on a library to handle all this code

## GCC (Gnu compiler collection)

gcc compiles code with GlibC.
So functions like malloc and printf are really from this library.
It adds a layer of abstarction for memory management , file I/O and network I/O etc.

*ELF (Executable link format)*
*ldd(loader diagnostics)*

**Proof**

💡To see what libraries your program is linked against, try:

`ldd ./myprogram`

## Bonus section RTFM

`man` is a linux command for accessing manual pages for any functions or programms.

> syntax : `man malloc`
 
* Always read Description of function
* Always check return value of function in man pages
* Check reason for error or error value's meaning using **errno** in man pages

*Man pages are awesome and important to learn! RTFM*

### Errno

when a function fails it returns an error value that can tell us reason for failure!

`perror` can be used to translate erro numbers into their corresponding error occured strings

meaning of these strings can again be found in man pages(did I write man pages are **very** important). 

![[./perror.png]]
![[./perrorResult.png]]