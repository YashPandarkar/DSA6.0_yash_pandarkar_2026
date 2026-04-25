/*"- write a C program to create, declare and initialize structure.
- define a structure ""student"", which includes the details of students,
- declare an object of the structure and initialize the structure members."*/

#include<stdio.h>
#include<string.h>

struct student{

    int rollno;
    char name[20];
    int marks;

};

int main(){

    struct student s;

    s.rollno = 1;
    strcpy(s.name, "yash");
    s.marks = 89;

    printf("\nroll no : %d",s.rollno);
    printf("\nname : %s",s.name);
    printf("\nmarks : %d",s.marks);

    return 0;
}
