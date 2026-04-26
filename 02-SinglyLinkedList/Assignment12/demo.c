/*write a c program to Create a Singly linked list and Delete the node at the last position*/

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

        printf("%d",p->data);
    }
}
sn* delete_at_end(sn* head){

    sn* p = NULL;
    for(p = head;p->next->next != NULL;p = p->next);

    free(p->next->next);
    p->next = NULL;

    return head;
}
int main(){

    sn* start = NULL;

    start = create(start);
    display(start);

    start = delete_at_end(start);
    display(start);

    return 0;
}