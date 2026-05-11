/*write a c program to Delete duplicate values(nodes) in doubly linked list.*/

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
node* removeDuplicates(node* head){

    node* temp = NULL;

    if(head == NULL){
        printf("List is empty");
        return NULL;
    }
    for(node* p = head; p != NULL; p = p->next){

        for(node* q = p->next; q != NULL;    ){

            if(p->data == q->data){

                temp = q;

                q->prev->next = q->next;
                if(q->next != NULL){
                    q->next->prev = q->prev;
                }
                q = q->next;
                free(temp);

            }else{
                q = q->next;
            }
        }
    }
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
    start = insert_end(start,10);
    start = insert_end(start,10);
    start = insert_end(start,30);
    start = insert_end(start,50);
    start = insert_end(start,40);
    start = insert_end(start,30);
    start = insert_end(start,20);
    start = insert_end(start,30);
    start = insert_end(start,50);
    start = insert_end(start,10);
    start = insert_end(start,40);

    start = removeDuplicates(start);
    
    display(start);
    destroy(start);

    return 0;
}