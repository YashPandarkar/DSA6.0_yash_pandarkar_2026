/*write a c program to Create a doubly linked list and Sort the doubly linked list while creation.*/

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
node* insert_node(node* head, int data){

    node* new = (node*)malloc(sizeof(node));

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if(head == NULL){
        return new;
    }
    if(head->next == NULL){

        if(head->data >= data){

            new->next = head;
            head->prev = new;

            return new;
        }
    }
    node* p = head;
    for(    ; p->next != NULL && p->next->data < data; p = p->next);
    
    new->next = p->next;
    new->prev = p;
    
    if(p->next != NULL){
        p->next->prev = new;
    }
    p->next = new;

    return head;
}
void display(node* head){

    printf("\n============display linked list===========\n\n");
    printf("[START]<-->");
    for(node* p = head;  p != NULL; p = p->next){

        printf("[%d]<-->",p->data);
    }      
    printf("[END]\n");  
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
    start = insert_node(start,70);
    start = insert_node(start,30);
    start = insert_node(start,50);
    start = insert_node(start,40);
    start = insert_node(start,80);
    start = insert_node(start,20);
    start = insert_node(start,30);
    start = insert_node(start,60);
    start = insert_node(start,10);

    display(start);
    
    return 0;
}