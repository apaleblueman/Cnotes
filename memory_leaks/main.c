#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 1000

struct employee_type
{ 
    int id;
    int income;
    bool staff;
};

void initialize_employee(struct employee_type *e){
    e->id = 0;
    e->income=0;
    e->staff=false;
    
    return;
}
int main(){
    struct employee_type *employees = malloc(sizeof(struct employee_type)*MAX_EMPLOYEES);    
    if(employees == NULL){
        printf("Allocator failed!\n");
        return -1;
    }
    initialize_employee(&employees[0]);

    // free(employees);
    // employees = NULL;
    
} 