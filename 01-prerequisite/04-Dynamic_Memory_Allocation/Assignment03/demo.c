/*"- write a C program to read a one dimensional array, print sum of all elements along with inputted array elements using Dynamic Memory Allocation.
- allocate memory for one dimensional array and print the array elements along with sum of all elements. 
- Memory will be allocated in this program using malloc() and released using free()."*/

#include<stdio.h>
#include<stdlib.h>

int main(){

    int sum = 0;
    int* arr = NULL;

    arr = (int*)malloc(10 * sizeof(int));

    for(int i = 0; i < 10; i++){
        arr[i] = (i+1) * 10;
    }
    for(int i = 0; i < 10; i++){

        sum = sum + arr[i];

    }
    printf("\nSum of Array :%d\n",sum);

    free(arr);
}