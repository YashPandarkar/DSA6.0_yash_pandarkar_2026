/*write a c program to Create a doubly linked list and Delete a node at given position.*/

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
node* delete_at_position(node* head,int pos){

    if(head == NULL){
        printf("List is empty");
        return NULL;
    }
    if(pos == 1){

        if(head->next == NULL){
            free(head);
            return NULL;
        }
        node* temp = head;
        head = head->next;
        head->prev = NULL;

        free(temp);
        return head;
    }
    node* p = head;
    for(int i = 1; i < pos && p != NULL; i++,  p = p->next);
      
    if(p == NULL){

        printf("invalid position ");
        return head;
    }

    p->prev->next = p->next;
    if(p->next != NULL){
        p->next->prev = p->prev;
    }
   
    free(p);
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
    start = insert_end(start,20);
    start = insert_end(start,30);
    start = insert_end(start,40);
    start = insert_end(start,50);

    start = delete_at_position(start, 5);
    
    display(start);
    destroy(start);

    return 0;
}