#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int  main(){
    //a file descriptor with file that doesnot exist 
    int fd = open("./idontexist.md", O_RDONLY);
    //if error is seen
    if(fd == -1){
        //print string meaning of that error
        perror("open");//usually command name is put in perror for semantics
        return -1;  //exit  
    }
}