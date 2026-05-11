/*"write a c program to Swap doubly linked list without using swapping. 
hint -> Adust the pointer instead of swapping the data
I/P  ---->   |_1_|_AA_| <--> |_2_|_BB_| <--> |_3_|_CC_| <--> |_4_|_DD_| <--> |_5_|_EE|_NULL_|  

O/P  ---->   |_3_|_CC_| <--> |_4_|_DD_| <--> |_1_|_AA_| <--> |_2_|_BB_| <--> |_5_|_EE_|_NULL_|"*/

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
node* swap(node* head){

    if(head == NULL || head->next == NULL || head->next->next == NULL || head->next->next->next == NULL){
        return head;
    }

    node* p = head;
    node* q = p->next->next;
    node* temp;

    while(q != NULL && q->next != NULL && p != NULL && p->next != NULL){
       
        temp = q->next->next;
        p->next->next = temp;

        if(temp != NULL){

            temp->prev = p->next;
        }

        if(p == head){
            q->prev = NULL;
            head = q;

        }else{
            q->prev = p->prev;
            p->prev->next = q;
        }

        q->next->next = p;
        p->prev = q->next;

        // p->next = q->next;
        // q->next->prev = p;

        p = temp;
        if(p != NULL && p->next != NULL && p->next->next != NULL){

            q = p->next->next;
        }
        else{
            break;
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

    start = swap(start);
    display(start);

    destroy(start);

    return 0;
}