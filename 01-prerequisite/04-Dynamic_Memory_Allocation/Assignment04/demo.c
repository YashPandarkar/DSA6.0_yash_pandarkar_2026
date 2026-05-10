/*"- write a C program to read and print the student details using structure and Dynamic Memory Allocation.
- create a structure with student details and print the inputted details. 
- Memory to store and print structure will be allocated at run time by using malloc() and released by free()."*/

#include<stdio.h>
#include<stdlib.h>

struct student
{
    int rollno;
    char name[50];
    int marks;
};

int main()
{
    struct student* stud = (struct student*)malloc(sizeof(struct student));

    printf("\nEnter Roll Number: ");
    scanf("%d", &stud->rollno);

    getchar();

    printf("\nEnter Name: ");
    fgets(stud->name, sizeof(stud->name), stdin);

    printf("\nEnter Marks: ");
    scanf("%d", &stud->marks);

    printf("\n========= Student Details =========\n");

    printf("Roll Number : %d\n", stud->rollno);
    printf("Name  : %s", stud->name);
    printf("Marks : %d\n", stud->marks);

    free(stud);

    return 0;
}