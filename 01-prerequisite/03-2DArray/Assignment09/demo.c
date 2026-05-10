/*"accept n elements in  2D - array and perform 90 degree right rotaion and 90 degree left rotation (rotate N elements (N is an user input)).
(Allocate the (N x M) 2D - array dynamically)"*/

#include<stdio.h>
#include<stdlib.h>

int main(){

    int n1, m1, right, left;
    int** ptr1 = NULL;

    printf("\nenter the rows of matrix1 :");
    scanf("%d",&n1);

    printf("\nenter the column of matrix1 :");
    scanf("%d",&m1);

    ptr1 = (int**)malloc(n1 * sizeof(int*));
    for(int i = 0; i < n1; i++){

       ptr1[i] = (int*)malloc(m1 * sizeof(int));
    }

    printf("\nenter the elements :");
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < m1; j++){

            scanf("%d",&ptr1[i][j]);
        }
    }
    printf("\n Matrix :\n\n");
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < m1; j++){

            printf(" %d ",ptr1[i][j]);
        }
        printf("\n");
    }

    printf("enter the number of right rotations");
    scanf("%d",right);

    for(int k = 0; k < right; k++){
        for(int i = 0; i < n1; i++){
             for(int j = 0; j < m1; j++){








            }
        }
    }
    printf("\n right rotation :\n\n");
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < m1; j++){

            printf(" %d ",ptr1[i][j]);
        }
        printf("\n");
    }
    printf("enter the number of left rotations");
    scanf("%d",left);

    for(int k = 0; k < left; k++){
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < m1; j++){








             }
        }
    }
    printf("\n left rotation :\n\n");
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < m1; j++){

            printf(" %d ",ptr1[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n1; i++) {
        free(ptr1[i]);
    }
    free(ptr1);
   
    return 0;
}    