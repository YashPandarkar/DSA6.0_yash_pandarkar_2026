//write a function to find the length of a string.

#include<stdio.h>

int count(char str[]){

    int count = 0;

    for(int i = 0; str[i] != '\0'; i++){

        count++;
    }

    return (count);
}

int main(){

    char str[] = "yash vijay pandarkar";

    int result = count(str);

    printf("count :%d", result);

    return 0;
}