/*"- Write a C program which allocates an array dynamically.
- Implement logic that removes duplicate elements from the array."*/

#include<stdio.h>
#include<stdlib.h>

int removeDuplicates(int* arr, int size){

    for(int i = 0; i < size; i++){

        for(int j = i + 1; j < size; j++){
            
            if(arr[i] == arr[j]){

                for(int k = j; k < size - 1; k++){
                    arr[k] = arr[k + 1];
                }

                size--;
                j--;
            }
        }
    }
    return size;  
}

int main(){

    int size, newSize;
    int* ptr = NULL;

    printf("enter the size of array :");
    scanf("%d",&size);

    ptr = (int*)malloc(size * sizeof(int));

    printf("enter the elements :");
    for(int i = 0; i < size; i++){

        scanf("%d",&ptr[i]);
    }
    newSize = removeDuplicates(ptr, size);

    printf("Array after removing duplicates : ");

    for(int i = 0; i < newSize; i++){
        printf("%d ", ptr[i]);
    }
    free(ptr);

    return 0;
}