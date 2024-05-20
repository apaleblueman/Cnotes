# Dynamic Memory Allocation

We can use built-in C memory allocator "malloc" to allocate certain size or chunk of memory.
WE must free the allocated memory after use and set any pointers using that memory to NULL in order to avoid pointer dangling.

When a pointer is allocated a memory using malloc It can either point to a single memory element or chunk or it can point to any or infinite elements as we can change memory address pointed to (*->&) by that pointer and move accross memory array (+ve forward) or (-ve backwards)