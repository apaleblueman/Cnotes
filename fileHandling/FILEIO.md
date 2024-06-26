# File I/O in C
---
## File Descriptors

These are integer that just represents to kernel a handle of files on disk.
There are 3 file descriptors for every single program:
* 0 -> stdin for input
* 1 -> stdout for output
* 2 -> stderr for errors (much like output however separate)

💡 Everything in linux is a file, even sockets used in network progrmming are files and handled using file descriptors
### Example 
![[../g_libc/perror.png]]
*here fd is a file descriptor*

## Commandline arguments

We can use main() function in our c program by giving it parameters such as argc and argv as such :
`int  main( int argc, char *argv[])`
where argc is number of arguments and *argv[] is a vector to commandline arguments

we can use these to dynamically write filenames instead of hardcoding them in our code. As expected this would work much like `touch` command in linux.

now the modified code looks like 
```
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int  main( int argc, char *argv[]){
    //check number of arguments is right (2 args one filename and one command name)
    if (argc != 2){
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }
    //a file descriptor with file that doesnot exist 
    int fd = open(argv[1], O_RDWR | O_CREAT, 0644);//or operation here so either one value will be used
    //if error is seen
    if(fd == -1){
        //print string meaning of that error
        perror("open");//usually command name is put in perror for semantics
        return -1;  //exit  
    }
}
```

# Writing to Files

we use write function to write data to files(check man page for write in manual 2 )

> 💡programming tip : Always use return statements to end your programm with approriate error value (commonly 0 for success , -1 for error)


```
//writing to that file
//making a write buffer
char *mydata = "This file was made using a C program!\n";
write(fd, mydata, strlen(mydata));

close(fd); //close descriptor

return 0;
```
---
# File input(Reading data)

> 💡Data may not always be in string format ,It might be binary blobs in form  of db header.
```
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

struct header_type{
    unsigned short version;
    unsigned short employees;
    unsigned int filesize;
};

int  main( int argc, char *argv[]){

    //check number of arguments is right (2 args one filename and one command name)
    if (argc != 2){
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }
    //a file descriptor with file that doesnot exist 
    int fd = open(argv[1], O_RDWR | O_CREAT, 0644);//or operation here so either one value will be used
    //if error is seen
    if(fd == -1){
        //print string meaning of that error
        perror("open");//usually command name is put in perror for semantics
        return -1;  //exit  
    }
    //writing to that file
    //making a write buffer
    // char *mydata = "This file was made using a C program!\n";
    // write(fd, mydata, strlen(mydata));

    //reading from a file or database header
    //creating a read buffer
    struct header_type db_header = {0} ;//setting buffer to null

    //checking for file corruption using filesize
    if(read(fd, &db_header, sizeof(db_header)) !=  sizeof(db_header)){
        perror("read");
        close(fd);
        return -1;
    }
 
    //printing a part of read data from binary blob 
    printf("%d filesize\n", db_header.filesize);
    close(fd); //close descriptor

    return 0;
}

```
![[./RW.png]]


# Metadata
---
**Stat** command/function is used to check metadata of a file

man page on *stat* tells a there are certain kinds of stat functions based on usage , we are gonna use fstat that takes a file descriptor
![[./manstat.png]]
