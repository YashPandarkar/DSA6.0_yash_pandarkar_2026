/*"write a c program to Create Menu Driven for doubly linked list which consist following functions:- 
           -create(),
          - Insert(),
          - Delete(),
          - Display(),
          - Reverse()."*/

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
node* insert_at_position(node* head, int data ,int pos){

    node* new = (node*)malloc(sizeof(node));

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if(pos == 1){

        new->next = head;
        if(head != NULL){
            head->prev = new;
        }
        return new;
    }
    node* p = head;
    for(int i = 1; i < pos - 1 && p != NULL; i++, p = p->next);

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
node* reverse(node* head){

    int temp;
    node* p = head; 

    for(    ; p->next != NULL; p = p->next);

    for(node* q = head; q != p && q->prev != p; q = q->next, p = p->prev){

       temp = p->data;
       p->data = q->data;
       q->data = temp;
    } 
    return (head);
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

    node* start = NULL;
    int choice, pos, data;

    do{
        printf("\n1. create ");
        printf("\n2. insert at position ");
        printf("\n3. delete at position ");
        printf("\n4. display ");
        printf("\n5. reverse ");
        printf("\n6. destroy and exit ");
        printf("\n\nEnter the choice :");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("enter the data :");
                scanf("%d",&data);
                start = create(data);
            break;

            case 2:
                printf("\nenter the data :");
                scanf("%d",&data);
                printf("\nenter the position :");
                scanf("%d",&pos);
                start = insert_at_position(start, data, pos);
            break;

            case 3:
                printf("\nenter the position :");
                scanf("%d",&pos);
                start = delete_at_position(start, pos);
            break;

            case 4:
                display(start);
            break;

            case 5:
                start = reverse(start);
                printf("linked list is reversed ");
            break;

            case 6:
                printf("exiting the programm ");
                return 0;

            default:
                printf("input is invalid ");
        }

    }while(choice);

    return 0;
}