/*Accept elements in 4*4 matrix and display the Transpose of matrix*/

#include<stdio.h>
#include<stdlib.h>

int main(){

    int n1, m1;
    int** ptr1 = NULL, **ptr2 = NULL;

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
    
    ptr2 = (int**)malloc(n1 * sizeof(int*));

    for(int i = 0; i < n1; i++){
        ptr2[i] = (int*)malloc(m1 * sizeof(int));
    }

    for(int i = 0; i < n1; i++){
        for(int j = 0; j < m1; j++){

            ptr2[i][j] = ptr1[j][i];
        }
    }
    printf("\n Transpose Matrix :\n\n");
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < m1; j++){

            printf(" %d ",ptr2[i][j]);
        }
        printf("\n");
    }
       
    for (int i = 0; i < n1; i++) {
        free(ptr1[i]);
    }
    free(ptr1);
   
    return 0;
}    