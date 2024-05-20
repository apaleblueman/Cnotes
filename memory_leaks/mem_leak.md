# Memory Leaks

when a memory is allocated from heap and then accesed but not freed after the use , it is called memory leak aka system crashes as overtime memory consumption grows which causes system to run out of memmory for important processes!
![[./comic.png]]

Manually checking for memory leaks in a large program can be tiresome
So we can automate checking using tools like **valgrind**.
To make your code compatible with valgrind, you'll need to compile with debug symbols in your code. Do this the following way.
`gcc -o outfile codefile.c -g`

![[./valrind.png]] 