/*"- Accept n elements in an array and perform right rotaion and left rotation (rotate N elements (N is an user input))
- NOTE: ALLOCATE ARRAY DYNAMICALLY"*/

#include<stdio.h>
#include<stdlib.h>

int* rightRotate(int* arr, int size, int n){

    int temp;

    for(int i = 0; i < n; i++){

        temp = arr[size-1];
        for(int j = size-1; j > 0; j--){

            arr[j] = arr[j-1];
        }
        arr[0] = temp;
    }
    return arr; 
}
int* leftRotate(int* arr, int size, int m){

    int temp;

    for(int i = 0; i < m; i++){

        temp = arr[0];
        for(int j = 0; j < size - 1; j++){

            arr[j] = arr[j+1];
        }
        arr[size - 1] = temp;
    }
    return arr; 
}

int main(){

    int size, n, m;
    int* ptr = NULL;

    printf("\nenter the size of array :");
    scanf("%d",&size);

    ptr = (int*)malloc(size * sizeof(int));

    printf("\nenter the elements :");
    for(int i = 0; i < size; i++){

        scanf("%d",&ptr[i]);
    }
    printf("\nenter the right rotations :");
    scanf("%d",&n);

    ptr = rightRotate(ptr, size, n);
    for(int i = 0; i < size; i++){

        printf(" %d",ptr[i]);
    }

    printf("\nenter the left rotations :");
    scanf("%d",&m);

    ptr = leftRotate(ptr, size, m);
    for(int i = 0; i < size; i++){

        printf(" %d",ptr[i]);
    }

    free(ptr);
    return 0;
}