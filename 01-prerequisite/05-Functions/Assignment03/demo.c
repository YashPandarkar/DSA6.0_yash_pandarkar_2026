//Write a separate function to copy one string into another string

#include<stdio.h>

char* copy(char str1[], char* str2){

    char* start = str2;

    for(int i = 0; str1[i] != '\0'; i++, str2++){

        *str2 = str1[i];

    }

    *str2 = '\0';

    return (start);
}

int main(){

    char str[] = "yash vijay pandarkar";
    char str1[50];
    char* ptr = str1;

    ptr = copy(str,ptr);
    
    printf("original string : ");
    for(int i = 0; str[i] != '\0'; i++){
        printf("%c",str[i]);
    }

    printf("\ncopy String : ");
    while(*ptr != '\0'){

       printf("%c", *ptr);
        ptr++;
    }

    return 0;
}