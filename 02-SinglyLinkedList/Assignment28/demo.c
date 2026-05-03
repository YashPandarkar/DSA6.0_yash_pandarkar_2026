/*"Merge list: create two linnked lists and concatenate the list2 in list1.

I/P:
list_1  ---->   |_3_|_CC_|_300_| --> |_2_|_BB_|_200_| --> |_4_|_DD_|_NULL_| --> |_1_|_AA_|_NULL_|
list_2  ---->   |_10_|_AAAA_|_10000_| --> |_20_|_BBBB_|_NULL_|

O/P: 
list_1  ---->   |_3_|_CC_|_300_| --> |_2_|_BB_|_200_| --> |_4_|_DD_|_NULL_| --> |_1_|_AA_|_NULL_|
list_2  ---->   |_10_|_AAAA_|_10000_| --> |_20_|_BBBB_|_NULL_|
merged_list  ----> |_1_|_AA_|_150_| --> |_2_|_BB_|_250_| --> |_3_|_CC_|_350_| --> |_4_|_DD_|_450_| --> |_10_|_AAAA_|_550_| --> |_20_|_BBBB_|_NULL_|"*/

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
sn* merge_list(sn* head1, sn* head2){

    sn* last = NULL;
    sn* head = NULL;

    while(head1 != NULL){

        sn* new = (sn*)malloc(sizeof(sn));

        new->data = head1->data;
        new->next = NULL;

        if(last == NULL){

            head = new;
            last = new;

        }else{
            last->next = new;
            last = new;
        }
        head1 = head1->next;
    }
    while(head2 != NULL){

        sn* new = (sn*)malloc(sizeof(sn));
        new->data = head2->data;
        new->next = NULL;

        last->next = new;
        last = new;

        head2 = head2->next;
    }
    return head;
}
int main(){

    sn* start1 = NULL;
    sn* start2 = NULL;
    sn* start3 = NULL;

    start1 = create(start1);
    start2 = create(start2);
    start3 = merge_list(start1, start2);

    display(start1);
    display(start2);
    display(start3);
   
    return 0;
}