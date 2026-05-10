/*"write a c program to Create a Singly linked list and Display it in reverse order (Use Normal Function)
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_| 
O/P :
------  
4 DD
3 CC
2 BB
1 AA"*/

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

    printf("\n=====linked display======\n");
    for(sn* p = head; p != NULL; p = p->next){

        printf("%d ",p->data);
    }
}
void reverseDisplay(sn* head){

    int count = 0;
    for(sn* p = head; p != NULL; p = p->next){

        count++;
    }
    printf("\n=====reverse linked display======\n");

    sn* p = NULL;
    for(int i = 1;   ; i++){

        p = head;
        for(int i = 1; i <= count && p != NULL; i++, p = p->next){

            if(i == count){
                printf(" %d",p->data);
            }
        } 
        count--;
        if(count == 0){
            break;
        }
    }
}
int main(){

    sn* start = NULL;

    start = create(start);
    display(start);

    reverseDisplay(start);

    return 0;
}