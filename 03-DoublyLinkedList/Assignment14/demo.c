/*write a c program to create two doubly linked lists, sort them individually and then merge the two sorted lists*/

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
    if(data <= head->data){

        new->next = head;
        head->prev = new;

        return new;
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
node* mergeList(node* list1, node* list2){

    node* merge = NULL;

    for(node* p = list1; p != NULL; p = p->next){

        merge = insert_node(merge, p->data);
    }
    for(node* q = list2; q != NULL; q = q->next){

        merge = insert_node(merge, q->data);
    }

    return merge;
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

    node *list1 = NULL, *list2 = NULL, *merge = NULL;

    list1 = create(10);
    list1 = insert_node(list1,70);
    list1 = insert_node(list1,30);
    list1 = insert_node(list1,50);
    list1 = insert_node(list1,40);
    list1 = insert_node(list1,80);

    display(list1);

    list2 = create(43);
    list2 = insert_node(list2,30);
    list2 = insert_node(list2,60);
    list2 = insert_node(list2,10);
    list2 = insert_node(list2,54);
    list2 = insert_node(list2,27);
    list2 = insert_node(list2,87);

    display(list2);

    merge = mergeList(list1, list2);

    display(merge);

    destroy(list1);
    destroy(list2);
    destroy(merge);
    
    return 0;
}