/*"- write a  C program to pass an array of structures to a user define function
- create a structure which accepts student details.
- create an array of structure for ""N"" number of students.
- Pass  array  of structure to a function as an argument and search for the perticular student details."*/

#include<stdio.h>
#include<stdlib.h>

struct student{

    int rollno;
    char name[20];
    int marks;
};
void accept(struct student* arr, int size){

    for(int i = 0; i < size; i++){

        printf("enter the roll no :");
        scanf(" %d", &arr[i].rollno);

        getchar();

        printf("enter the name :");
        fgets(arr[i].name, sizeof(arr[i].name), stdin);

        printf("enter the marks :");
        scanf(" %d", &arr[i].marks);
    }
}
void display(struct student* arr, int size){


    for(int i = 0; i < size; i++){

        printf("\nroll no :");
        printf("%d",arr[i].rollno);

        printf("\nname :");
        printf("%s",arr[i].name);

        printf("marks :");
        printf("%d \n",arr[i].marks);
    }
}
void search(struct student* arr ,int size, int key){

    for(int i = 0; i < size; i++){

        if(arr[i].rollno == key){
           
            printf("\nStudent found ");

            printf("\nroll no :");
            printf("%d",arr[i].rollno);

            printf("\nname :");
            printf("%s",arr[i].name);

            printf("marks :");
            printf("%d \n",arr[i].marks);

            return;
        } 
    }
    printf("Student not found ");  
}

int main(){

    int n;
    printf("enter the number of students :");
    scanf("%d",&n);

    struct student arr[20];

    accept(arr , n);
    display(arr, n);
    search(arr , n , 2);

    return 0;
}