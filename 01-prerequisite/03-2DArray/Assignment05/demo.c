/*Accept elements in 3x3 matrix and check whther it is magic square or not(magic square: sum of all elements in row and column are same)*/

#include<stdio.h>
#include<stdlib.h>

int main(){

    int n1, m1, sum;
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

    if(n1 == 3 && m1 == 3){

        for(int i = 0; i < n1; i++){

            sum = 0;
            for(int j = 0; j < m1; j++){

            sum = sum + ptr1[i][j];
            }
            if(sum != 15){
                printf("this matrix is not magic square");
                for (int i = 0; i < n1; i++) {
                    free(ptr1[i]);
                }
                free(ptr1);
                return 0;
            }
        }
        for(int i = 0; i < n1; i++){

            sum = 0;
            for(int j = 0; j < m1; j++){

            sum = sum + ptr1[j][i];
            }
            if(sum != 15){
                printf("this matrix is not magic square");
                for (int i = 0; i < n1; i++) {
                    free(ptr1[i]);
                }
                free(ptr1);
                return 0;
            }
        }
        printf("this matrix is magic square ");

    }else{

        printf("this matrix is not magic square");
    }
    for (int i = 0; i < n1; i++) {
        free(ptr1[i]);
    }
    free(ptr1);
   
    return 0;
}    