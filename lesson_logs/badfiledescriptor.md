### Log Entry - File Descriptor Management in C

**Date:** May 22, 2024

**Issue:** Received "bad file descriptor" error when using `fstat` in a C program.

**Symptoms:**
- `fstat` returned an error message indicating a "bad file descriptor".

**Root Cause:**
- The file descriptor was explicitly closed before calling `fstat`.

**Solution:**
- Ensure that the file descriptor is open and valid when making system calls that require it.
- Move `fstat` call before the `close(fd)` call.

**Corrected Code:**
```c
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

struct header_type {
    unsigned short version;
    unsigned short employees;
    unsigned int filesize;
};

int main(int argc, char *argv[]) {
    struct stat dbStat = {0}; // an empty stat buffer for fstat to populate

    // Check number of arguments is right (2 args: one filename and one command name)
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }

    // Open the file
    int fd = open(argv[1], O_RDWR | O_CREAT, 0644); // O_CREAT will create the file if it doesn't exist
    if (fd == -1) {
        perror("open");
        return -1;
    }

    // Read the file header
    struct header_type db_header = {0}; // Initialize header to zero

    if (read(fd, &db_header, sizeof(db_header)) != sizeof(db_header)) {
        perror("read");
        close(fd);
        return -1;
    }

    printf("Filesize reported by header: %d \n", db_header.filesize);

    // Get file stats using fstat while the file descriptor is still open
    if (fstat(fd, &dbStat) != 0) {
        perror("fstat");
        close(fd);
        return -1;
    }

    printf("Size reported by fstat: %ld\n", dbStat.st_size);

    // Close the file descriptor
    close(fd);
    return 0;
}
```