#include<stdio.h>
#include<stdlib.h>

struct student{
    int rollno;
    char name[50];
    int marks;
};

int main(){

    struct student* s = (struct student*)malloc(sizeof(struct student));

    printf("Enter the rollno: ");
    scanf("%d", &s->rollno);

    printf("Enter the name: ");
    scanf(" %[^\n]", s->name);   

    printf("Enter the marks: ");
    scanf("%d", &s->marks);

    printf("\n--- Student Details ---\n");
    printf("Rollno: %d\n", s->rollno);
    printf("Name: %s\n", s->name);
    printf("Marks: %d\n", s->marks);

   
    return 0;
}