/*"- Write a C program which allocates an array dynamically.
- Implement logic that returns 2nd large element from the array"*/

#include<stdio.h>
#include<stdlib.h>

int secondLargest(int* arr, int size){

    int largest = arr[0];
    int secondLargest = arr[0];

    for(int i = 0; i < size; i++){

        if(arr[i] > largest){
            secondLargest = largest;
            largest = arr[i];
        }
        if(arr[i] > secondLargest && largest != arr[i]){
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int main(){

    int size,secondLagest;
    int* ptr = NULL;

    printf("enter the size of array :");
    scanf("%d",&size);

    ptr = (int*)malloc(size * sizeof(int));

    printf("enter the elements :");
    for(int i = 0; i < size; i++){

        scanf("%d",&ptr[i]);
    }
    secondLagest = secondLargest(ptr, size);

    printf("second Largest Element : %d",secondLagest);
    free(ptr);

    return 0;
}