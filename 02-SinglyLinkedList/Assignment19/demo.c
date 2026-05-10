/*"write a c program to Create a Singly linked list  and perform menu driven which includes following functions: 
          - create(),
          - Insert(),
          - Delete(),
          - Reverse(),
          - print()"*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{

    int data;
    struct node* next;
}sn;

sn* create(sn*head){

    sn* last = NULL;
    int choice;

    do{
        sn* p = (sn*)malloc(sizeof(sn));

        printf("Enter roll no: ");
        scanf("%d",&p->data);

        p->next = NULL;

        if(head == NULL){
            head = p;
        } else {
            last->next = p;
        }
            last = p;

        printf("Enter 1 to continue: ");
        scanf("%d",&choice);

    }while(choice == 1);

    return head;
}
sn* insert_at_position(sn* node, int data, int position){

    sn* new = (sn*)malloc(sizeof(sn));
    
    new->data = data;
    new->next = NULL;

    if(position == 1){

        new->next = node;
        return new;
    }
    sn* p = node;

   for(int i = 1; i < position-1 && p != NULL; i++, p = p->next);

   if(p == NULL){

    printf("wrong position ");

    return node;

   }

   new->next = p->next;
   p->next = new;

   return node;
  
}
sn* delete_at_position(sn* head,int pos){

    if(head == NULL){
        printf("List is empty\n");
        return head;
    }

    sn* p = NULL;

    if(pos == 1){
        p = head->next;
        free(head);
        return p;
    }
       p = head;

    for(int i = 1;i < pos-1 && p != NULL;i++){

        p = p->next;
    }
    if(p == NULL && p->next == NULL){
        printf("invalid input");
        return head;
    }
    
    sn* q = p->next;
    p->next = q->next;

    free(q);
    
    return head;
}
sn* reverse(sn* head){

    sn* r = NULL;
    sn* p = head;
    sn* q = NULL;

    while(p != NULL){

        q = p->next;
        p->next = r;
        r = p;
        p = q;
    }
    return r;
}
void display(sn* head){

    printf("\n=====linked list display======\n\n");
    printf("[START]-->");
    for(sn* p = head; p != NULL; p = p->next){

        printf("[%d]-->",p->data);
    }
    printf("[END]\n");
}

int main(){

    sn* start = NULL;
    int choice, pos, data;

    do{
        printf("\n1. create ");
        printf("\n2. insert at position ");
        printf("\n3. delete at position ");
        printf("\n4. reverse ");
        printf("\n5. display ");
        printf("\n6. exit ");
        printf("\n\nEnter the choice :");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                start = create(start);
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
                start = reverse(start);
                printf("linked list is reversed ");
            break;

            case 5:
                display(start);
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