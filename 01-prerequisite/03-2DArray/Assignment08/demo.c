/*"Accept  4*4 matrix and display the following patern

  * 1 1 1
  0 * 1 1
  0 0 * 1
  0 0 0 *  
  
*/

#include<stdio.h>
#include<stdlib.h>

int main(){

    int** ptr1 = NULL;

    ptr1 = (int**)malloc(4 * sizeof(int*));
    for(int i = 0; i < 4; i++){

       ptr1[i] = (int*)malloc(4 * sizeof(int));
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){

           if(i == j){

            printf(" * ");
           }
           if(i < j){

            printf(" 1 ");
           }
           if(i > j){

            printf(" 0 ");
           }
        }  
        printf("\n");
    }   
    for (int i = 0; i < 4; i++) {
        free(ptr1[i]);
    }
    free(ptr1);
   
    return 0;
}    