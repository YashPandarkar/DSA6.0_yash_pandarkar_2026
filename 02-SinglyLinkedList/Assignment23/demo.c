/*"create a linnked list and delete a node after key node (given by user)
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_| 
                 key: 3
O/P ---->  |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_NULL_|"*/

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

    printf("\n=====linked list display======\n");
    for(sn* p = head; p != NULL; p = p->next){

        printf("%d ",p->data);
    }
}
sn* delete_after(sn* head, int key){

    sn* temp = head;
    while(temp->data != key && temp != NULL){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("key not found");
    }
    sn* tempp = temp->next;
    temp->next = tempp->next;

    free(tempp);

    return head;
}
int main(){

    sn* start = NULL;
    
    start = create(start);
    display(start);

    start = delete_after(start,3);
    display(start);
    
    return 0;
}