//Write a function which reads pointers of 2 different array as arguments, 
//return the pointer of array which elements are sum of  two array element.

#include<stdio.h>
#include<stdlib.h>

int* sum(int* arr1,int size1,int* arr2,int size2){

    int* arr3 = (int*)malloc(size1 * sizeof(int));

    if(size1 == size2){

        for(int i = 0;i < size1 ;i++){

            arr3[i] = arr1[i] + arr2[i];
        }

        return arr3;
    }else{

    printf("arrays are not same ");
    return NULL;

    }
}
int main(){

    int arr1[5] = {1,2,3,4,5};
    int arr2[5] = {6,7,8,9,0};

    int* arr3;

    arr3 = sum(arr1,5,arr2,5);

    printf("first array : ");
    for(int i = 0;i < 5 ;i++){

        printf("%d ",arr1[i]);
    }
    printf("\nsecond array : ");
    for(int i = 0;i < 5 ;i++){

        printf("%d ",arr2[i]);
    }

    printf("\nthird array : ");
    for(int i = 0;i < 5 ;i++){

        printf("%d ",arr3[i]);
    }
    
    return 0;
}