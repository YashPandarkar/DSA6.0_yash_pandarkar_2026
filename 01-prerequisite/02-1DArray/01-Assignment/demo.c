/*"- Write a C program which allocates an array dynamically.
- Implement logic to check the frequency of each element throughout the array"*/

#include<stdio.h>
#include<stdlib.h>

void frequency(int* ptr,int size){

    int count = 0;
    int flag = 0;

    for(int i = 0; i < size; i++){

         count = 0;
         flag = 0;

        for(int k = i - 1; k >= 0; k--){

            if(ptr[i] == ptr[k]){
                flag = 1;
            }
        }
        if(flag == 0){
            
            for(int j = 0; j < size; j++){

                if(ptr[i] == ptr[j]){
                    count++;
                }
            }
            printf("\nfrequency of %d is %d",ptr[i], count);
        }
    }
}

int main(){

    int size;
    int* ptr = NULL;

    printf("enter the size of array :");
    scanf("%d",&size);

    ptr = (int*)malloc(size * sizeof(int));

    printf("enter the elements :");
    for(int i = 0; i < size; i++){

        scanf("%d",&ptr[i]);
    }

    frequency(ptr, size);
    free(ptr);

    return 0;
}