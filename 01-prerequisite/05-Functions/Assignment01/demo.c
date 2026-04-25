//Write a function to calculate the sum of all elements of an array

#include<stdio.h>

int sum(int arr[], int size){

    int sum = 0;

    for(int i = 0; i < size; i++){

        sum = sum + arr[i];
    }

    return (sum);
}

int main(){

    int arr[] = {1,2,3,4,5,6};

    int result = sum(arr , 6);

    printf("sum :%d", result);

    return 0;
}