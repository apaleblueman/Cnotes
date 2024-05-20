//AUTHOR: APALEBLUEMAN

#include<stdio.h>
#include<stdbool.h>
#define MAX_IDS 32
#define MAX_EMPLOYEES 1000

struct __attribute__((__packed__)) employee_type{
	int id;
	char firstname[64];
	char lastname[64];
	float income;
	bool ismanager;
};

int main(int argc, char *argv[]){

	struct employee_type employees[MAX_EMPLOYEES];
	int i = 0;
	for(i=0;i<MAX_EMPLOYEES; i++){
		employees[i].income=0;
		employees[i].ismanager=false;
	}
	printf("%f\n", employees[69].income);
}



