/*"create a linnked list and insert a node before key node (given by user)
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_| 
                 key: 3
                 data: 100, ZZ
O/P ---->  |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_100_|_ZZ_|_NULL_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_|"*/

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
sn* insert_before(sn* head, int data, int key){

    sn* new = (sn*)malloc(sizeof(sn));
    new->data = data;
    new->next = NULL;

    sn* temp = head;
    while(temp->next->data != key && temp != NULL){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("key not found");
    }
    new->next = temp->next;
    temp->next = new;

    return head;
}
int main(){

    sn* start = NULL;
    
    start = create(start);
    display(start);

    start = insert_before(start, 3, 4);
    display(start);
    
    return 0;
}