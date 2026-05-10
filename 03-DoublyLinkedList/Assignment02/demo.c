/*write a c program to Create Doubly linked list and display it in reverse order.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
}node;
node* create(int data){

    node* new = (node*)malloc(sizeof(node));

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    return new;
}
void reverse_display(node* head){

    node* p = head;
    for(    ; p->next != NULL; p = p->next);

    printf("\n============display reverse linked list===========\n");
    printf("linked list :");
    for(    ; p != NULL; p = p->prev){

        printf(" %d",p->data);
    }
}
node* insert_end(node* head,int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        return newNode;
    }

    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}
void destroy(node* head){

    node* p = head;
    while(p != NULL){

       node* temp = p->next;
       free(p);
       p = temp; 
    }
}
int main(){

    node* start = create(10);
    start = insert_end(start,20);
    start = insert_end(start,30);
    start = insert_end(start,40);
    start = insert_end(start,50);

    reverse_display(start);
    destroy(start);

    return 0;
}