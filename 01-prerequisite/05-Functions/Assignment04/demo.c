//write a function to concatenate  two strings

#include<stdio.h>

char* concatinate(char* str1, char* str2){

    char* start = str1;
    for(    ; *str1 != '\0'; str1++);

    for(    ; *str2 != '\0'; str1++, str2++){

        *str1 = *str2;
    }
    *str1 = '\0';

    return (start);
}

int main(){

    char str1[100] = "yash ";
    char str2[50] = "pandarkar";
    char* ptr1 = str1;
    char* ptr2 = str2;

    ptr1 = concatinate(ptr1,ptr2);
    
    printf("\nAfter concatination : ");
    while(*ptr1 != '\0'){

       printf("%c", *ptr1);
        ptr1++;
    }

    return 0;
}