/* write a c program to Create Linked List using Recursion.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{

    int data;
    struct node* next;
}sn;

sn* create(sn*head){

    int choice;

    sn* new = (sn*)malloc(sizeof(sn));
    printf("enter the roll no :");
    scanf("%d",&new->data);
    new->next = NULL;
    
    head = new;

    printf("enter 1 to continue :");
    scanf("%d",&choice);

    if(choice == 1){
        new->next = create(new->next);
    }

    return new;
}
void display(sn* head){

    printf("\n=====linked list display======\n");
    for(sn* p = head; p != NULL; p = p->next){

        printf("%d ",p->data);
    }
}

int main(){

    sn* start = NULL;

    start = create(start);
    display(start);

    return 0;
}