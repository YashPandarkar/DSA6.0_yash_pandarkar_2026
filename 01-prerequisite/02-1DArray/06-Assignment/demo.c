/*Accept n elements in an array and revert the array*/

#include<stdio.h>
#include<stdlib.h>

int* reverse(int* arr, int size){

    int temp;

    for(int i = 0; i < size/2; i++){

        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;

    }
    return arr;
}

int main(){

    int size;
    int* ptr = NULL;

    printf("\nenter the size of array :");
    scanf("%d",&size);

    ptr = (int*)malloc(size * sizeof(int));

    printf("\nenter the elements :");
    for(int i = 0; i < size; i++){

        scanf("%d",&ptr[i]);
    }
    printf("\nArray :");
    for(int i = 0; i < size; i++){

        printf(" %d",ptr[i]);
    }

    ptr = reverse(ptr, size);

    printf("\nArray :");
    for(int i = 0; i < size; i++){

        printf(" %d",ptr[i]);
    }
    free(ptr);
    return 0;
}