/*"Write a c program which demonstrate a nested structure 
- define a structure employee inside a structure person.
- structure person data: Name, Age, Date of birth, blood group.
- structure employee data: Company name, Emp id, salary, years of experiance.                     
- create objects of structure and display the all details of a person."*/

#include<stdio.h>
#include<string.h>

struct employee{

    int empid;
    char companyname[20];
    int salary;
    int yoe;

};
struct person{

    char name[20];
    int age;
    int dob;   
    char bloodgroup[5];
    struct employee e;

};

int main(){

    struct person p;

    strcpy(p.name, "yash");
    p.age = 20;
    p.dob = 17052005;
    strcpy(p.bloodgroup, "B+");
    p.e.empid = 1234;
    strcpy(p.e.companyname, "nexabyte");
    p.e.salary = 10000000;
    p.e.yoe = 5;

    printf("\nname               : %s",p.name);
    printf("\nage                : %d",p.age);
    printf("\ndate of birth      : %d",p.dob);
    printf("\nblood group        : %s",p.bloodgroup);
    printf("\nemployee id        : %d",p.e.empid);
    printf("\ncompany name       : %s",p.e.companyname);
    printf("\nsalary             : %d ",p.e.salary);
    printf("\nyear of experience : %d ",p.e.yoe);

    return 0;
}
