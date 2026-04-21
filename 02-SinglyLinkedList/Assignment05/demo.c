
/*" write a c program to Create a singly linked list and search a particular node. 
          
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_400_| --> |_5_|_EE_|_500_| --> |_6_|_FF_|_NULL_|  
Enter : Key = 5
O/P ---->  
 |_5_|_EE_|_500_|"
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
void search(struct student* node, int data){

    int flag = 0;
    for(struct student* p = node; p != NULL; p = p->next){
        
       if(p->rollno == data){
            
            flag = 1;
       }
    }
    if(flag == 1){

        printf(" found !");

    }else{

        printf(" Not found !");
    }
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

    printf("\n search for 5 :");
   search(node, 5);
  
    return 0;
}