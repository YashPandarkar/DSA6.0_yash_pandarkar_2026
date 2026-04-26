/*write a c program to Create a Singly linked list and Find and print the middle element*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{

    int data;
    struct node* next;
}sn;

sn* create(sn*head){

    sn* last = NULL;
    int choice;

    do{
        sn* p = (sn*)malloc(sizeof(sn));

        printf("Enter roll no: ");
        scanf("%d",&p->data);

        p->next = NULL;

        if(head == NULL){
            head = p;
        } else {
            last->next = p;
        }
            last = p;

        printf("Enter 1 to continue: ");
        scanf("%d",&choice);

    }while(choice == 1);

    return head;
}
void display(sn* head){

    printf("\n=====strintg display======\n");
    for(sn* p = head; p != NULL; p = p->next){

        printf("%d ",p->data);
    }
}
void middle_node(sn* head){

    sn* p = head;
    sn* q = head;

    for(    ;q != NULL && q->next != NULL; p = p->next ,q = q->next->next);

    printf("middle node : %d",p->data);
}
int main(){

    sn* start = NULL;

    start = create(start);
    display(start);

    printf("\n");
    middle_node(start);

    return 0;
}