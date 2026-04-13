//write a  Program to count vowels and consonants in a string using pointer.

#include<stdio.h>

int main(){

    int count1 = 0,count2 = 0;
    char string[30];
    char *str;

    printf("enter the string :");
    fgets(string,sizeof(string),stdin);

    str = string;

    for(int i = 0;str[i] != '\0';i++){

        if((str[i] >= 65 && str[i] <= 90)||(str[i] >= 97 && str[i] <= 122)){

            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){

                count1++;
            }else{
                count2++;
            }
        }
    }
    printf("\nvowels : %d ",count1);
    printf("\nconsonents : %d ",count2);

    return 0;
}