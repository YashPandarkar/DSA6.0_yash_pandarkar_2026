/*"write a c program to Create and Display Singly Linked list. with structure ""Student"" with following data members:
-Name 
-Roll no
-standard
-Division"*/

#include<stdio.h>
#include<stdlib.h>

struct student {
    char name[20];
    int rollno;
    int standard;
    char div;
    struct student* next;
};

void display(struct student* node){

    for(struct student* p = node; p != NULL; p = p->next){
        printf("\nName : %s", p->name);
        printf("\nRoll Number : %d", p->rollno);
        printf("\nStandard : %d", p->standard);
        printf("\nDivision : %c\n", p->div);
    }
}

struct student* create(){

    int choice;
    struct student* head = NULL;
    struct student* last = NULL;

    do{
        struct student* node = (struct student*)malloc(sizeof(struct student));

        printf("Enter name: ");
        scanf("%s", node->name);

        printf("Enter rollno: ");
        scanf("%d", &node->rollno);

        printf("Enter standard: ");
        scanf("%d", &node->standard);

        printf("Enter division: ");
        scanf(" %c", &node->div);

        node->next = NULL;

        if(head == NULL){
            head = node;
            last = node;
        } else {
            last->next = node;
            last = node;
        }

        printf("Enter 1 to add next node, 0 to stop: ");
        scanf("%d", &choice);

    } while(choice == 1);

    return head;
}

int main(){

    struct student* node = NULL;

    node = create();

    display(node);

    return 0;
}