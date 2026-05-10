/*"- write a C program to create memory for int, char and float variable at run time.
- create memory for int, char and float variables at run time using malloc() function
- and before exiting the program release the memory allocated at run time by using free() function."*/
 
#include<stdio.h>
#include<stdlib.h>

int main(){

    int* p = NULL;
    char* q = NULL;
    float* r = NULL;

    p = (int*)malloc(sizeof(int));
    q = (char*)malloc(sizeof(char));
    r = (float*)malloc(sizeof(float));

    *p = 10;
    *q = 'A';
    *r = 3.15;

    printf("\n%d",*p);
    printf("\n%c",*q);
    printf("\n%f",*r);

    free(p);
    free(q);
    free(r);

    return 0;
}