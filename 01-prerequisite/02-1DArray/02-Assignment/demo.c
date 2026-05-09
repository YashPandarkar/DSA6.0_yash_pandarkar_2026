/*"- Write a C program which allocates an array dynamically.
- Implement logic which accepts only unique elements in array"*/

#include<stdio.h>
#include<stdlib.h>

int* acceptUnique(int* ptr,int size){

    ptr = (int*)malloc(size * sizeof(int));

    for(int i = 0; i < size; i++){

        printf("enter the element :");
        scanf("%d",&ptr[i]);

        for(int j = i - 1; j >= 0; j--){

            if(ptr[i] == ptr[j]){
                printf("\nonly unique elements are accepted\n");
                i--;
            }    
       }
    }
    return ptr;
}

int main(){

    int size, newSize;
    int* ptr = NULL;

    printf("enter the size of array :");
    scanf("%d",&size);

    ptr = acceptUnique(ptr, size);
   
    for(int i = 0; i < size; i++){
        printf("%d ", ptr[i]);
    }
    free(ptr);

    return 0;
}