/*"- Create a structure ""Item"" which includes below member variables:
- itemName, quantity, price, amount.
- calculate the amount by accessing the member variable with the help of structure pointer."*/

#include<stdio.h>

struct item{

    char itemName[20];
    int quantity;
    int price;
    int amount;
};

int main(){

    struct item* ptr;

    printf("\nenter the item name :");
    fgets(ptr->itemName, sizeof(ptr->itemName),stdin);

    printf("\nenter the quantity :");
    scanf("%d",&ptr->quantity);

    printf("\nenter the price :");
    scanf("%d",&ptr->price);

    ptr->amount = ptr->quantity * ptr->price;

    printf("\nthe amount is :");
    printf("%d",ptr->amount);

    return 0;
}