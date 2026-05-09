/*"- Write a C program which allocates two array dynamically.
- Implement logic to merge and sort two array."*/

#include<stdio.h>
#include<stdlib.h>

int* merge(int* arr1, int size1, int* arr2, int size2){

    int* ptr = (int*)malloc((size1 + size2) * sizeof(int));

    for(int i = 0; i < size1+size2; i++){

        if(i < size1){
            ptr[i] = arr1[i];

        }else{
            ptr[i] = arr2[i-size1];
        }
    }
    int temp = 0;

    for(int i = 0; i < size1+size2; i++){
        for(int j = i + 1; j < size1+size2; j++){

            if(ptr[i] > ptr[j]){

                temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
        
            }
        }
    }
    return ptr;  
}

int main(){

    int size1 ,size2;
    int* ptr1 = NULL, *ptr2 = NULL, *ptr = NULL;

    printf("enter the size of array 1 :");
    scanf("%d",&size1);
    ptr1 = (int*)malloc(size1 * sizeof(int));

    printf("enter the elements :");
    for(int i = 0; i < size1; i++){

        scanf("%d",&ptr1[i]);
    }

    printf("enter the size of array 2 :");
    scanf("%d",&size2);
    ptr2 = (int*)malloc(size2 * sizeof(int));

    printf("enter the elements :");
    for(int i = 0; i < size2; i++){

        scanf("%d",&ptr2[i]);
    }
    ptr = merge(ptr1,size1,ptr2,size2);

    printf("merge and sorted array :");
    for(int i; i < size1+size2; i++){
        printf(" %d",ptr[i]);
    }

    free(ptr1);
    free(ptr2);
    free(ptr);

    return 0;
}