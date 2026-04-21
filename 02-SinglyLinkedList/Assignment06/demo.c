/*
"      write a c program to Create a Singly Linked list and  Display the addition of two consecutive nodes to the next node 
	  
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_| 

O/P ---->    |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_AABB_|_700_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_800_| --> |_7_|_CCDD_|_NULL_|
"
*/

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
struct student* addition(struct student* node){

    for(struct student* p = node; p != NULL && p->next != NULL; p = p->next){
        
        struct student* new = (struct student*)malloc(sizeof(struct student));
       
        new->rollno = p->rollno + p->next->rollno;
        new->next = p->next->next;
        p->next->next = new;
        p = new;
    }
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

    node = addition(node);
    display(node);

    return 0;
}