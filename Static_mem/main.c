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

int initialize_employee(struct employee_type *e){
    static int numEmployees = 0 ;       
    numEmployees ++;
    e->id = numEmployees;
    e->income=0;
    e->staff=false;


    
    return numEmployees;
}
int main(){

    int n = 4; //Assume this value came from a database header
    struct employee_type *employees = malloc(sizeof(struct employee_type)*MAX_EMPLOYEES);  
    printf("%p\n%d\n",&employees,*employees);
    if(employees == NULL){
        printf("Allocator failed!\n");
        return -1;
    }
    for(int i=0; i<n; i++){
        initialize_employee(&employees[i]);
        printf("ID for employee %d is %d\n", i, employees[i].id);
    }
    printf("%p\n", &employees[0]);
    free(employees);
    employees = NULL;
    
} 