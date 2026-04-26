/*write a c program to Create a Singly linked list and sort the linked list*/

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
sn* sort(sn* head){

    for(sn* p = head; p != NULL && p->next != NULL; p = p->next){

        for(sn* q = p->next; q != NULL; q = q->next){

            if(p->data > q->data){

                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
    return(head);
}
int main(){

    sn* start = NULL;

    start = create(start);
    display(start);

    start = sort(start);
    display(start);

    return 0;
}