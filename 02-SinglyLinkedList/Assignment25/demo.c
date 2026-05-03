/*"create a linnked list and print the number of nodes the list have. (size of list)
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_| 
O/P ---->  4"*/

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
void display(sn* head){

    printf("\n=====strintg display======\n");
    for(sn* p = head; p != NULL; p = p->next){

        printf("%d ",p->data);
    }
}
int size_of_list(sn* head){

    int size = 0;
    for(sn* p = head; p != NULL; p = p->next){

       size++;
    }
    return size;
}
int main(){

    sn* start = NULL;
    int size;
    
    start = create(start);
    size = size_of_list(start);

    display(start);
    printf("\nsize of linked list is : %d", size);
   
    return 0;
}