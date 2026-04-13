//write a Program to read  array elements and print with addresses.

#include<stdio.h>

int main(){

    int arr[10];

    printf("enter the array :");
    for(int i = 0;i< 10;i++){

        scanf("%d",&arr[i]);
    }
    for(int i = 0;i < 10;i++){

        printf("\n %d element : %d ",i,arr[i]);
        printf("\nAddress : %p",&arr[i]);
    }
    return 0;
}