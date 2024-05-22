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
    struct stat dbStat = {0}; //an empty stat buffer for fstat to populate
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
    
    if(read(fd, &db_header, sizeof(db_header)) !=  sizeof(db_header)){
        perror("read");
        close(fd);
        return -1;
    }
 
    
    printf("filesize reported by header :%d \n", db_header.filesize);
    // close(fd); //close descriptor 
    if(fstat(fd, &dbStat) != 0){
        perror("fstat");
        close(fd);
        return -1;
    }
    printf("Size reported by fstat :%ld\n", dbStat.st_size);
    if(dbStat.st_size != db_header.filesize){
        printf("this file might have been tampered with!\n");
        close(fd);
        return -2; //defcon 2 ! (hacker might have been here)
    }
    return 0;
}
