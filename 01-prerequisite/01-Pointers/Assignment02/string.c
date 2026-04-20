//write a Program to print a string using pointer.

#include<stdio.h>

int main(){

    char name[20];
    char *str;

    
    printf("enter the string :");
    fgets(name,sizeof(name),stdin);

    str = name;

    while(*str != '\0'){

        printf("%c",*str);
        str++;
    }
}