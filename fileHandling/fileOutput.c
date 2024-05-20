#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

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
    char *mydata = "This file was made using a C program!\n";
    write(fd, mydata, strlen(mydata));

    close(fd); //close descriptor

    return 0;
}