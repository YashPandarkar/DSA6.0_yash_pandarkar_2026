//write a function to reverse the  strings

#include<stdio.h>

char* reverse(char* str1){

    char* temp = str1;
    char* start = str1;
    char* end = str1;

    int count = 0;

    for(    ; *end != '\0'; end++){
        count ++;
    }

    end--;

    for(int i = 0; i < count/2; i++, start++, end--){

       int temp = *start;
       *start = *end;
       *end = temp;
    }
   
    return (temp);
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