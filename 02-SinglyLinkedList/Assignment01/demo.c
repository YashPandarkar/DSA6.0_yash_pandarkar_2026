/*"write a c program to create and display a node. with structure ""Student"" with following data members:   
-Name 
-Roll no
-standard
-Division
"
*/
#include<stdio.h>
#include<stdlib.h>

struct student {

    char name[20];
    int rollno;
    int standard;
    char div;
};

void display(struct student* node){

    printf("\nName : %s",node->name);
    printf("\nRoll Number : %d",node->rollno);
    printf("\nStandard : %d",node->standard);
    printf("\nDivision : %c",node->div);

}
int main(){

    struct student* node;

    node = (struct student*)malloc(sizeof(struct student));

    printf("enter a name :");
    scanf(" %s",node->name);

    printf("enter the rollno :");
    scanf(" %d",&node->rollno);

    printf("enter the standard :");
    scanf(" %d",&node->standard);

    printf("enter the division :");
    scanf(" %c",&node->div);

    display(node);

    return 0;
}