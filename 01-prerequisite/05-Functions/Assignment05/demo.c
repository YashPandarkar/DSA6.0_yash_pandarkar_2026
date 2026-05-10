//write a function to reverse the  strings

#include<stdio.h>

char* reverse(char* str){

    int count = 0;
    char temp;

    for(int i = 0; str[i] != '\0'; i++){

        count++;
    }
    for(int i = 0; i < count/2; i++){

        temp = str[i];
        str[i] = str[count - 1 - i]; 
        str[count - 1 - i] = temp;

    }
    return str;
}

int main(){

    char str1[100] = "yash pandarkar";
    char* ptr1 = str1;

    ptr1 = reverse(ptr1);
    
    printf("\nreverse string : ");
    while(*ptr1 != '\0'){

       printf("%c", *ptr1);
        ptr1++;
    }

    return 0;
}