/*"- Create a structure ""Students"" with below member variables:
    - Name of student,
    - Roll no. Of Student,
    - array of 5 Subject marks,
    - Total Percentage 
    
- Calculate the Percentage for ""N"" number of students,
- Display all details for all students,
- Display the details of topper.
(use array of structure)"*/

#include<stdio.h>
#include<stdlib.h>

struct student
{
    char name[50];
    int rollno;
    int marks[5];
    int per;
};

int main()
{
    int n, sum = 0;

    printf("Enter number of students :");
    scanf("%d", &n);

    struct student* stud = (struct student*)malloc(n * sizeof(struct student));
    struct student* topper = NULL;

    for(int i = 0; i < n; i++)
    {
        sum = 0;
        printf("\nEnter details of Student %d\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &stud[i].rollno);

        getchar();

        printf("Enter Name: ");
        fgets(stud[i].name, sizeof(stud[i].name), stdin);

        printf("Enter Marks of 5 subjects : ");
        for(int j = 0; j < 5; j++){

            scanf("%d", &stud[i].marks[j]);
            sum = sum + stud[i].marks[j];
        }
        stud[i].per = sum/5;
    }
    topper = &stud[0];
    
    printf("\n========= Student Details =========\n");

    for(int i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);

        printf("Roll Number : %d\n", stud[i].rollno);
        printf("Name  : %s \n", stud[i].name);
        printf("Marks of 5 subjects : \n");
        for(int j = 0; j < 5; j++){

            printf("subject %d : %d\n", j + 1, stud[i].marks[j]);
        }
        printf("percentage : %d \n",stud[i].per);

        if(stud[i].per > topper->per){

            topper = &stud[i];
        }    
    }
    printf("\n========= Topper Student Details =========\n");

        printf("Roll Number : %d\n",topper->rollno);
        printf("Name  : %s \n", topper->name);
        printf("Marks of 5 subjects : \n");
        for(int j = 0; j < 5; j++){

            printf("subject %d : %d\n", j,topper->marks[j]);
        }
        printf("percentage : %d \n",topper->per);

    free(stud);

    return 0;
}