//Write a Program to swap elements between two array using pointers.

#include<stdio.h>
#include<stdlib.h>

void swapping(int *arr1,int size1,int *arr2,int size2){

    if(size1 == size2){

        int temp ;

        for(int i = 0;i < size1;i++){

            temp = arr1[i];
            arr1[i] = arr2[i];
            arr2[i] = temp;
        
        }

    }else{
        printf("arrays are not equal ");
    }
}
void display(int *arr1,int size1,int *arr2,int size2){

    printf("first array : ");
    for(int i = 0;i < size1;i++){
        printf("%d ",arr1[i]);
    }
    printf("\nsecond array : ");
    for(int i = 0;i < size2;i++){
        printf("%d ",arr2[i]);
    }
}
int main(){

    int arr1[5];
    int arr2[5];
    int size1,size2;

    printf("enter the size of first array :");
    scanf("%d",&size1);
    printf("enter the elements :");
    for(int i = 0;i < size1;i++){
        scanf("%d",&arr1[i]);
    }

    printf("enter the size of second array :");
    scanf("%d",&size2);
    printf("enter the elements :");
    for(int i = 0;i < size2;i++){
        scanf("%d",&arr2[i]);
    }
    display(arr1,size1,arr2,size2);
    printf("\nafter swapping :\n");
    swapping(arr1,size1,arr2,size2);
    display(arr1,size1,arr2,size2);
    
    return 0;
}