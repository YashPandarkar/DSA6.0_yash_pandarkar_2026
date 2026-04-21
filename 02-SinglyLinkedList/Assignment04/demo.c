/*"write a c program to Create a Singly linked list and swap the two consecutive nodes 
	  
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_400_| --> |_5_|_EE_|_500_| --> |_6_|_FF_|_NULL_|  


O/P  ---->   |_2_|_BB_|_100_| --> |_1_|_AA_|_200_| --> |_4_|_DD_|_300_| --> |_3_|_CC_|_400_| --> |_6_|_FF_|_500_| --> |_5_|_EE_|_NULL_|
"*/

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
struct student* swap(struct student* node){

    struct student* p = node;

    while(p != NULL && p->next != NULL){
        
        int temp = p->rollno;
        p->rollno = p->next->rollno;
        p->next->rollno = temp;

        p = p->next->next; 
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

   node = swap(node);
   display(node);

    return 0;
}