/*"- write a C program to read and print the N student details using structure and Dynamic Memory Allocation.
- create a structure with N number of student details and print the inputted details.
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
    int n;

    printf("Enter number of students :");
    scanf("%d", &n);

    struct student *stud = (struct student*)malloc(n * sizeof(struct student));

    for(int i = 0; i < n; i++)
    {
        printf("\nEnter details of Student %d\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &stud[i].rollno);

        getchar();

        printf("Enter Name: ");
        fgets(stud[i].name, sizeof(stud[i].name), stdin);

        printf("Enter Marks: ");
        scanf("%d", &stud[i].marks);
    }

    printf("\n========= Student Details =========\n");

    for(int i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);

        printf("Roll Number : %d\n", stud[i].rollno);
        printf("Name  : %s", stud[i].name);
        printf("Marks : %d\n", stud[i].marks);
    }
    
    free(stud);

    return 0;
}