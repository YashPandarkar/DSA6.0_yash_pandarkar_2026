/*Accept n elements in an array and display the differance between the sum of 1st half  and 2nd half of that array*/

#include<stdio.h>
#include<stdlib.h>

int differance(int* arr, int size){

    int count = 0, diff = 0;
    for(int i = 0; i < size/2; i++){

        diff = diff + arr[i];
        count++;
    }
    for(int i = count; i < size; i++){

        diff = diff - arr[i];
    }
    if(diff < 0){
        diff = -(diff);
    }
    return diff;
}


int main(){

    int size = 0, diff;
    int* ptr = NULL;

    do{

        if(size % 2 != 0){
            printf("\nsize should be even ");
    
        }

        printf("\nenter the size of array :");
        scanf("%d",&size);

    }while(size % 2 != 0);

    ptr = (int*)malloc(size * sizeof(int));

    printf("\nenter the elements :");
    for(int i = 0; i < size; i++){

        scanf("%d",&ptr[i]);
    }
    
    diff = differance(ptr, size);
    printf("\nthe diffrerance between first half and second half of array is %d",diff);

    free(ptr);
    return 0;
}