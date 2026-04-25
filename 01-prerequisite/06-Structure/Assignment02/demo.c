/*"- write a C program to read and print an employee's detail using structure.
- read and print the employee's details like name, employee id, salary etc using structure."*/

#include<stdio.h>
#include<string.h>

struct employee{

    int empid;
    char name[20];
    int salary;

};

int main(){

    struct employee e;

    e.empid = 134;
    strcpy(e.name, "yash");
    e.salary = 890000;

    printf("\nemployee id : %d",e.empid);
    printf("\nname : %s",e.name);
    printf("\nsalary : %d",e.salary);

    return 0;
}
