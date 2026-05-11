/*"write a c program to Re-Arrange doubly linked list in pair format.
input -> 6 <-> 1 <-> 9 <-> 4 <-> 3 <-> 8 <-> 2
output -> 1 <-> 6 <-> 4 <-> 9 <-> 3 <-> 8 <-> 2

If first value is greater than second then swap  , if 3rd value is less than 4th then swap same for remaining pair"*/

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
node* reArrange(node* head){

    int temp;

    for(node* p = head, * q = head->next; q != NULL && q->next != NULL; p = p->next->next, q = q->next->next){
       
        if(p->data > q->data){

            temp = p->data;
            p->data = q->data;
            q->data = temp;
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
    start = insert_end(start,34);
    start = insert_end(start,70);
    start = insert_end(start,40);
    start = insert_end(start,52);
    start = insert_end(start,10);
    start = insert_end(start,53);
    start = insert_end(start,21);
    start = insert_end(start,56);
    start = insert_end(start,18);
    start = insert_end(start,67);
    start = insert_end(start,71);

    display(start);

    start = reArrange(start);
    display(start);

    destroy(start);

    return 0;
}