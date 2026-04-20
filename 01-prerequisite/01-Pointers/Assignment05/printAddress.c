//write Program to print addresses and size of all types of pointer variables.

#include<stdio.h>

int main(){

    int* a;
    char* str;
    float* f;
    double* d;

    printf("\nAddress of a : %p\nSize of a : %lu",a,sizeof(a));
    printf("\nAddress of str : %p\nSize of str : %lu",str,sizeof(str));
    printf("\nAddress of f : %p\nSize of f : %lu",f,sizeof(f));
    printf("\nAddress of d : %p\nSize of d : %lu",d,sizeof(d));
}