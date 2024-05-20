#include <stdio.h>
#include <stdbool.h>

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

    struct employee_type employees[MAX_EMPLOYEES];    
    initialize_employee(&employees[0]);

    printf("%d", employees[0].income);
}