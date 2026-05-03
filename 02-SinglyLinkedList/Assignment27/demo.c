/*"Append list: create two linnked lists and append the list2 in list1.

I/P:
list_1  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_| 
list_2  ---->   |_10_|_AAAA_|_10000_| --> |_20_|_BBBB_|_NULL_|

O/P: 
list_1  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_40000_| --> |_10_|_AAAA_|_10000_| --> |_20_|_BBBB_|_NULL_|
list_2  ---->   |_10_|_AAAA_|_10000_| --> |_20_|_BBBB_|_NULL_|"*/

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
sn* upend_list(sn* head1, sn* head2){

    sn* temp = head1;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head2;

    return head1;
}
int main(){

    sn* start1 = NULL;
    sn* start2 = NULL;

    start1 = create(start1);
    start2 = create(start2);
    display(start1);
    
    start1 = upend_list(start1, start2);

    display(start1);
    display(start2);
   
    return 0;
}