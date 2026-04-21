/*write a c program to Create a Singly linked list and Insert a node at the last*/

#include<stdio.h>
#include<stdlib.h>

struct student {
   
    int rollno;
   
    struct student* next;
};
void display(struct student* node){

    for(struct student* p = node; p != NULL; p = p->next){
        
        printf("\nRoll Number : %d", p->rollno);
    }
}
struct student* insert_last(struct student* node, int data){

    struct student* new = (struct student*)malloc(sizeof(struct student));
    
    new->rollno = data;
    new->next = NULL;

    struct student* p = node;

   for(     ; p->next != NULL; p = p->next);

   p->next = new;

   return node;
}
struct student* create(){

    int choice;
    struct student* head = NULL;
    struct student* last = NULL;

    do{
        struct student* node = (struct student*)malloc(sizeof(struct student));

        printf("Enter rollno: ");
        scanf("%d", &node->rollno);

        node->next = NULL;

        if(head == NULL){
            head = node;
            last = node;
        } else {
            last->next = node;
            last = node;
        }

        printf("Enter 1 to add next node, 0 to stop: ");
        scanf("%d", &choice);

    } while(choice == 1);

    return head;
}

int main(){

    struct student* node = NULL;

    node = create();
    display(node);

    node = insert_last(node,12);
    display(node);

    return 0;
}