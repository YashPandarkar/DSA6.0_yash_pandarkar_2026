/*"create a linnked list and delete a node after key node (given by user)
I/P  ---->   |_1_|_AA_| <--> |_2_|_BB_| <--> |_3_|_CC_| <--> |_4_|_DD_|_NULL_| 
                 key: 3
O/P ---->  |_1_|_AA_| <--> |_2_|_BB_| <--> |_3_|_CC_|_NULL_|"*/

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
node* delete_node(node* head, int key){

    if(head == NULL){
        printf("List is empty");
        return NULL;
    }
    
    node* p = head;
    for(    ; p->next != NULL; p = p->next){
      
        if(p->data == key){

          break;
        }
    }
    p = p->next;

    if(p == NULL){
        printf("invalid key position ");
        return head;
    }
    
    if(p->next == NULL){

        p->prev->next = NULL;
        free(p);
        return head;
    }
    
    p->prev->next = p->next;
    p->next->prev = p->prev;

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
    start = insert_end(start,60);
    start = insert_end(start,70);
    start = insert_end(start,80);

    display(start);

    start = delete_node(start, 70);
    start = delete_node(start, 10);
    start = delete_node(start, 50);
   
    display(start);
    destroy(start);

    return 0;
}