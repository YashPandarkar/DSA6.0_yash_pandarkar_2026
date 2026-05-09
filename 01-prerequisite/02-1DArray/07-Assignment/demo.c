/*Accept n elements in an array and search a perticular element*/

#include<stdio.h>
#include<stdlib.h>

void search(int* arr, int size ,int key){

    int flag = 0;

    for(int i = 0; i < size; i++){

       if(arr[i] == key){

            flag = 1;
        }
    }
    if(flag == 1){
        printf("found ");
    }else{
        printf("not found");
    }
}

int main(){

    int size, key;
    int* ptr = NULL;

    printf("\nenter the size of array :");
    scanf("%d",&size);

    ptr = (int*)malloc(size * sizeof(int));

    printf("\nenter the elements :");
    for(int i = 0; i < size; i++){

        scanf("%d",&ptr[i]);
    }
    printf("\nenter the key :");
    scanf("%d",&key);

    search(ptr, size, key);

    free(ptr);
    return 0;
}