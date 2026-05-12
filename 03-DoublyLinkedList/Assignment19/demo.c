/*"create a linnked list and insert a node after key node (given by user)
I/P  ---->   |_1_|_AA_| <--> |_2_|_BB_| <--> |_3_|_CC_| <--> |_4_|_DD_|_NULL_| 
                 key: 3
                 data: 100, ZZ
O/P ---->  |_1_|_AA_| <--> |_2_|_BB_| <--> |_3_|_CC_| <--> |_100_|_ZZ_| <--> |_4_|_DD_|_NULL_|"*/

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
node* insert_node(node* head,int data, int key){

    if(head == NULL){
        printf("List is empty");
        return NULL;
    }
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    new->prev = NULL;

    node* p = head;
    for(    ; p != NULL; p = p->next){
      
        if(p->data == key){

          break;
        }
    }
    if(p == NULL){
        printf("invalid position ");
        return head;
    }
    new->next = p->next;
    if(p->next != NULL){

        p->next->prev = new;
    }
    
    p->next = new;
    new->prev = p;

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
    display(start);

    start = insert_node(start, 41, 50);
    start = insert_node(start, 45, 10);
    start = insert_node(start, 87, 40);
    
    display(start);
    destroy(start);

    return 0;
}