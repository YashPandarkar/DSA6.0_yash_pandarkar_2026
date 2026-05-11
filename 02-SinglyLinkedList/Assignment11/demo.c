/*write a c program to Create a Singly linked list and Delete the node in the given position*/

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
sn* delete_at_position(sn* head,int pos){

    if(head == NULL){
        printf("List is empty\n");
        return head;
    }

    sn* p = NULL;

    if(pos == 1){
        p = head->next;
        free(head);
        return p;
    }
       p = head;

    for(int i = 1;i < pos-1 && p != NULL;i++){

        p = p->next;
    }
    if(p == NULL || p->next == NULL){
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

    start = delete_at_position(start,3);
    display(start);

    return 0;
}