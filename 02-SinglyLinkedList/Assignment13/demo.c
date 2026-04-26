/*write a c program to Create a Singly linked list and Delete the node depending on user input key/value*/

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
sn* delete_by_key(sn* head,int key){

    if(head == NULL){
        printf("List is empty\n");
        return head;
    }

    sn* p = NULL;

    if(key == head->data){
        p = head->next;
        free(head);
        return p;
    }
       p = head;

    for(    ;p->next->data != key && p != NULL;p = p->next);

    if(p == NULL && p->next == NULL){
        printf("invalid input");
        return head;
    }
    
    sn* q = p->next;
    p->next = q->next;

    free(q);
    
    return head;
}
int main(){

    sn* start = NULL;

    start = create(start);
    display(start);

    start = delete_by_key(start,4);
    display(start);

    return 0;
}