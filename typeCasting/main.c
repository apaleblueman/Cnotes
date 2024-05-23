#include <stdio.h>

int main(int argc, char *argv[]){
    unsigned int x = 4;

    int sx = (int)(x); //type casting unsigned int into a normal signed int

    // this will probably resultin data lost due cutting of top 32 bits 
    // This is because unsigned int is 32 bits while short is 16 bits
    unsigned int bigx = 0xfffffefe;
    short kindabig = (short)bigx;

    // This is opposite as we are converting from small  to large
    short short2 = -1; // 0xffff or 1111
    int wasshort = (int)short2;//0xffffffff 

}