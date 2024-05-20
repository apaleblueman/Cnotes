#include <stdio.h>

int main(){
    int some_var = 5;

    int *pointerTo_somevar = &some_var;

    printf(" var itself : %d\n pointer to var: %d \n address of somevar: %p \n pointer address itself: %p\n", 
    some_var, 
    *pointerTo_somevar, 
    &some_var,
    pointerTo_somevar );
}