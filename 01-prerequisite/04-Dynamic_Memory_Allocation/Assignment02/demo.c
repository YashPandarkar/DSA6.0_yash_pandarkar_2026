/*"- write a C program to input and print text using Dynamic Memory Allocation.
- create memory for text string at run time using malloc() function, 
- text string will be inputted by the user and displayed.
- Using free() function  release the occupied memory."*/

#include<stdio.h>
#include<stdlib.h>

int main(){

    char* str = NULL;

    str = (char*)malloc(50 * sizeof(char));

    printf("enter the string :");
    
    fgets(str, 50, stdin);
   
    printf("String is : %s",str);
    
    free(str);

    return 0;
}