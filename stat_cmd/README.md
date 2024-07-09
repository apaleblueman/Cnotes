# Stat Command and Function
---
As a rule of thumb, we assume every data input is malicious. This assumption allows us to write code that is both effective and secure.

For example, we can check the metadata of a file in conjunction with the file header. By cross-checking the file size indicated in the header against the actual file size, we can detect potential file corruption or tampering. This can be done using **stat**.

using **fstat** (a command similar to fstat in stat command suite) we can populate a stat structure that has a lot of interesting attributes(such as filesize).

* fstat returns 0 on success and 1 on failure and it takes a file descriptor and a pointer to a stat buffer as arguments.

```c
  struct stat {
               dev_t     st_dev;         /* ID of device containing file */
               ino_t     st_ino;         /* Inode number */
               mode_t    st_This  is stat structure which gets populatedrdev;        /* Device ID (if special file) */
               off_t     st_size;        /* Total size, in bytes */
               blksize_t st_blksize;     /* Block size for filesystem I/O */
               blkcnt_t  st_blocks;      /* Number of 512B blocks allocated */
  }
```
*This^  is stat structure which gets populated*


