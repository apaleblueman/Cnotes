//AUTHOR: APALEBLUEMAN
#include<stdio.h>
#include "file.h"
int main(int argc, char *argv[]){
	int fd, numEmployees = 0;
	if(argc != 2){
		printf("Usage: %s <filename>\n",argv[0]);
		return 0;
	}
	fd = open_file_rw(argv[1]);
	if(fd == -1){
		return -1;
	}
	return 0;
}

