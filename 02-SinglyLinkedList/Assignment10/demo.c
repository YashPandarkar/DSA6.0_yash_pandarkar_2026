/*write a c program to Create a Singly linked list and Delete the node at the Head position*/

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
struct student* delete_head(struct student* node){

   if(node == NULL){

    printf("linked list is empty ");
    return node;

   }
   struct student* temp = node;
   node = node->next;

   free(temp);
   return (node);
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
    printf("\nlinked list is :");
    display(node);

    printf("\n");
    node = delete_head(node);
    printf("\nlinked list is :");
    display(node);

    return 0;
}