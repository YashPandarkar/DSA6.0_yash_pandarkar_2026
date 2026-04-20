/*"write a c program to Create a Singly linked list and Display the alternate nodes 

I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_400_| --> |_5_|_EE_|_NULL_|. 

O/P  ---->  |_1_|_AA_|_100_| --> |_3_|_CC_|_300_| --> |_5_|_EE_|_NULL_|
"*/

#include<stdio.h>
#include<stdlib.h>

struct student {
    char name[20];
    int rollno;
    int standard;
    char div;
    struct student* next;
};

void display_alternate(struct student* node){

    int flag = 0;

    for(struct student* p = node; p != NULL; p = p->next){

        if(flag == 0){

            printf("\nName : %s", p->name);
            printf("\nRoll Number : %d", p->rollno);
            printf("\nStandard : %d", p->standard);
            printf("\nDivision : %c\n", p->div);
        }
        flag = !flag;
    }
}

struct student* create(){

    int choice;
    struct student* head = NULL;
    struct student* last = NULL;

    do{
        struct student* node = (struct student*)malloc(sizeof(struct student));

        printf("Enter name: ");
        scanf("%s", node->name);

        printf("Enter rollno: ");
        scanf("%d", &node->rollno);

        printf("Enter standard: ");
        scanf("%d", &node->standard);

        printf("Enter division: ");
        scanf(" %c", &node->div);

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

    display_alternate(node);

    return 0;
}